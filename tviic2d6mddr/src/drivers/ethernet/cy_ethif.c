/***************************************************************************//**
* \file cy_ethif.c
* \version 1.0
*
* \brief
* Provides an API implementation of the Ethernet Interface driver
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#include "cy_ethif.h"
#include "cy_ethif_defines.h"
#include "cy_project.h"
#include <string.h>

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
*       Local Variables
***************************************/
/** Cadence driver instantiation    */
static CEDI_OBJ *cyp_ethif_gemgxlobj;

/** Ethernet configurations */
static CEDI_Config  cy_ethif_cfg[CY_ETH_DEFINE_NUM_IP];

/** Cadence driver memory requirements */
static CEDI_SysReq  cy_ethif_sysreq;

/** Private data structures required for each instance of Ethernet IPs  */
static CEDI_PrivateData * cyp_ethif_pd[CY_ETH_DEFINE_NUM_IP];

/** Variables holding Statistics register values    */
static CEDI_Statistics  * cyp_ethif_statistic[CY_ETH_DEFINE_NUM_IP];


/** 64 bits aligned Transmit Buffers along with their status    */
#if   defined ( __ghs__ )
  #pragma alignvar (8) 
#elif defined ( __ICCARM__ )
  __attribute((aligned(8))) 
#else
  #warning "This driver is supported only by GHS and IAR compiler"
#endif
uint8_t u8TxBuf[CY_ETH_TOTAL_TX_BUF][CY_ETH_SIZE_MAX_FRAME] = {0};   
cy_str_ethif_bufstatus cy_str_txBufStatus[CY_ETH_TOTAL_TX_BUF] = {0};       /** Buffer status will be CY_ETHIF_BUFFER_UNINIT */

/** 64 bits aligned Receive Buffers along with their status */
#if   defined ( __ghs__ )
  #pragma alignvar (8) 
#elif defined ( __ICCARM__ )
  __attribute((aligned(8))) 
#else
  #warning "This driver is supported only by GHS and IAR compiler"
#endif
uint8_t u8RxBuf[CY_ETH_TOTAL_RX_BUF][CY_ETH_SIZE_MAX_FRAME] = {0};          /** This includes replacement buffers (requirement from cadence driver)     */
cy_str_ethif_bufstatus cy_str_rxBufStatus[CY_ETH_TOTAL_RX_BUF] = {0};       /** Buffer status will be CY_ETHIF_BUFFER_UNINIT */

/** Private data memory allocation  */
uint8_t cy_ethif_privatedata[CY_ETH_DEFINE_NUM_IP][1800] = {0};   

/** Tx Descriptors */
/** CY_ETH_DEFINE_NUM_TXQS * CY_ETH_DEFINE_NUM_IP to avoid race condition in hardware; each BD list for particular queue must have 1 more BD */
#if   defined ( __ghs__ )
  #pragma alignvar (8) 
#elif defined ( __ICCARM__ )
  __attribute((aligned(8))) 
#else
  #warning "This driver is supported only by GHS and IAR compiler"
#endif
uint8_t cy_ethif_tx_desc_list[CY_ETH_DEFINE_NUM_IP][CY_ETH_DEFINE_NUM_TXQS][CY_ETH_DEFINE_TOTAL_BD_PER_TXQUEUE + 1][CY_ETH_BD_SIZE] = {0};                    
 
/** Rx Descriptors  */
/** Cadence driver requires another set of buffers to replace the existing buffers after a frame has been received
* so, number of required BDs would not be same as number of buffers */
#if   defined ( __ghs__ )
  #pragma alignvar (8) 
#elif defined ( __ICCARM__ )
  __attribute((aligned(8))) 
#else
  #warning "This driver is supported only by GHS and IAR compiler"
#endif
uint8_t cy_ethif_rx_desc_list[CY_ETH_DEFINE_NUM_IP][CY_ETH_DEFINE_NUM_RXQS][((CY_ETH_DEFINE_TOTAL_BD_PER_TXQUEUE + 1) * 2)][CY_ETH_BD_SIZE] = {0};     

/** Statistics registers    */
uint8_t cy_ethif_statistic[CY_ETH_DEFINE_NUM_IP][160] = {0};

static cy_ethif_callbackfunctions stccallbackfunctions [CY_ETH_DEFINE_NUM_IP] = {0};
static cy_str_ethif_queueDisablestatus stcQueueDisStatus[CY_ETH_DEFINE_NUM_IP] = {0};

/*****************************************************************************
* Local function prototypes ('static')                                                                            
*****************************************************************************/
static void Cy_EthIf_EnableInterrupts (uint8_t u8EthIfInstance, cy_stc_ethif_interruptconfig_t * pstcInterruptList);
static void Cy_EthIF_PrepareConfiguration (uint8_t u8EthIfInstance, cy_stc_ethif_configuration_t * pstcEthIfConfig);
static void Cy_EthIf_AssignMemory (uint8_t u8EthIfInstance);
static void Cy_EthIf_EventTx(void *pcy_privatedata, uint32_t u32event, uint8_t u8qnum);
static void Cy_EthIf_EventTxError(void *pcy_privatedata, uint32_t u32event, uint8_t u8qnum);
static void Cy_EthIf_EventRxFrame(void *pcy_privatedata, uint8_t u8qnum);
static void Cy_EthIf_EventRxError(void *pcy_privatedata, uint32_t a_event, uint8_t a_qnum);
static void Cy_EthIf_EventPhyManComplete(void *pcy_privatedata, uint8_t u8read, uint16_t u16ReadData);
static void Cy_EthIf_EventhrespError(void *pcy_privatedata, uint8_t u8qnum);
static void Cy_EthIf_EventLpPageRx(void* pcy_privatedata, struct CEDI_LpPageRx* pageRx);
static void Cy_EthIf_EventAn(void* pcy_privatedata, struct CEDI_NetAnStatus* netStat);
static void Cy_EthIf_EventLinkChange(void *pcy_privatedata, uint8_t a_linkstate);
static void Cy_EthIf_EventTsu (void *pcy_privatedata, uint32_t u32event);
static void Cy_EthIf_EventPauseFrame(void *pcy_privatedata, uint32_t u32event);
static void Cy_EthIf_EventPtp (void* pcy_privatedata, uint32_t u32type, struct CEDI_1588TimerVal* time);
static void Cy_EthIf_EventExternalInt(void * pcy_privatedata);
static void Cy_EthIf_EventWol(void * pcy_privatedata);
static void Cy_EthIf_EventLpi(void * pcy_privatedata);
static void Cy_EthIf_InitializeBuffers (void);
static void Cy_EthIf_ClearBuffer (uint32_t * pu32Buffer);
static uint8_t Cy_EthIF_GetBuf (bool bTransmitBuf);
static cy_en_ethif_status_t Cy_EthIf_WrapperConfig (uint8_t u8EthIfInstance, cy_str_ethif_wrapper_config * pstcWrapperConfig);
static cy_en_ethif_status_t Cy_EthIf_IPEnable (uint8_t u8EthIfInstance);
static cy_en_ethif_status_t Cy_EthIf_IPDisable (uint8_t u8EthIfInstance);
static cy_en_ethif_status_t Cy_EthIf_TSUInit (uint8_t u8EthIfInstance, cy_str_ethif_TSU_Config * pstcTSUConfig);
static cy_en_ethif_status_t Cy_EthIf_DisableQueues (uint8_t u8EthIfInstance, cy_stc_ethif_configuration_t * pstcEthIfConfig);

/*****************************************************************************
* Local Call back function supplied to Cadence driver                                                                        
*****************************************************************************/
CEDI_Callbacks Cy_EthIf_Callbacks = {
  .phyManComplete = (CEDI_CbPhyManComplete)Cy_EthIf_EventPhyManComplete,
  .txEvent        = (CEDI_CbTxEvent)Cy_EthIf_EventTx,
  .txError        = (CEDI_CbTxError)Cy_EthIf_EventTxError,
  .rxFrame        = (CEDI_CbRxFrame)Cy_EthIf_EventRxFrame,
  .rxError        = (CEDI_CbRxError)Cy_EthIf_EventRxError,
  .hrespError     = (CEDI_CbHrespError)Cy_EthIf_EventhrespError,
  .lpPageRx       = (CEDI_CbLpPageRx)Cy_EthIf_EventLpPageRx,                           
  .anComplete     = (CEDI_CbAnComplete)Cy_EthIf_EventAn,                               
  .linkChange     = (CEDI_CbLinkChange)Cy_EthIf_EventLinkChange,                       
  .tsuEvent       = (CEDI_CbTsuEvent)Cy_EthIf_EventTsu,                                
  .pauseEvent     = (CEDI_CbPauseEvent)Cy_EthIf_EventPauseFrame,                       
  .ptpPriFrameTx  = (CEDI_CbPtpPriFrameTx)Cy_EthIf_EventPtp,                           
  .ptpPeerFrameTx = (CEDI_CbPtpPeerFrameTx)Cy_EthIf_EventPtp,                          
  .ptpPriFrameRx  = (CEDI_CbPtpPriFrameRx)Cy_EthIf_EventPtp,                           
  .ptpPeerFrameRx = (CEDI_CbPtpPeerFrameRx)Cy_EthIf_EventPtp,                          
  .lpiStatus      = (CEDI_CbLpiStatus)Cy_EthIf_EventLpi,                               
  .wolEvent       = (CEDI_CbWolEvent)Cy_EthIf_EventWol,                                
  .extInpIntr     = (CEDI_CbExtInpIntr)Cy_EthIf_EventExternalInt                       
};


/*******************************************************************************
* Function Name: Cy_EthIf_Init
****************************************************************************//**
*
* \brief Initializes the Ethernet MAC, Cadence Driver, EthIf and PHY 
*
* \param pstcEth
* Pointer to register area of Ethernet MAC
*
* \param pstcEthIfConfig
* Pointer to Ethernet configuration parameters
*
* \param pstcInterruptList
* List of Interrupts to enable
* 
* \return CY_ETHIF_SUCCESS      Ethernet MAC has been initialized along with Cadence driver and external PHY
* \return CY_ETHIF_BAD_PARAM    If following conditions are met:
*                               pstcEth == NULL
*                               pstcEthIfConfig == NULL
*                               pstcInterruptList == NULL
*                               GEM_GXL Object could not be created
*                               Memory assigned by Interface layer is not enough
*                               Cadence driver could not initialize Ethernet MAC
*         CY_ETHIF_MEMORY_NOT_ENOUGH
*                               Assigned memory for BDs or for Private data is not enough 
*         CY_ETHIF_LINK_DOWN    Link is not yet up
* 
* \ Note:
* This function Initializes the Ethernet MAC, Cadence driver, EthIf layer and external PHY with the provided parameters
* Port init for the Ethernet must be done before calling Cy_EthIf_Init function
* Buffer configuration parameters shall be done in EthIf.h file
*
*******************************************************************************/
cy_en_ethif_status_t Cy_EthIf_Init(cy_pstc_eth_type_t pstcEth, cy_stc_ethif_configuration_t * pstcEthIfConfig, cy_stc_ethif_interruptconfig_t * pstcInterruptList)
{
    // local variable declaration
    uint32_t u32RetValue = 0;
    uint8_t u8EthIfInstance = 255; 
    uint8_t u8tmpcounter = 0;
    uint8_t u8tmpintrcntr = 0;
    bool bClearAll = true;
    bool bTransmitBuf = true;
    uint16_t u16SysReqTxBDLength = 0;
    uint16_t u16SysReqRxBDLength = 0;
    static bool bBufferInitialized = false;
    
    /** Parameter checks        */
#if defined (tviibh8m)
    if ((pstcEth != CY_ETH0_TYPE) && (pstcEth != CY_ETH1_TYPE))
#elif defined (tviic2d6m) || defined (tviibh4m) || defined (tviic2d4m) || defined (tviic2d6mddr)
    if (pstcEth != CY_ETH0_TYPE)
#endif
    {
        return CY_ETHIF_BAD_PARAM;
    }
    if ((pstcEthIfConfig == NULL) || (pstcInterruptList == NULL))
    {
        return CY_ETHIF_BAD_PARAM;
    }
    else if (pstcEthIfConfig->pstcWrapperConfig == NULL)
    {
        return CY_ETHIF_BAD_PARAM;
    }
        
    if (bBufferInitialized == false)
    {
        /** Create GEM_GXL object  */   
        cyp_ethif_gemgxlobj = CEDI_GetInstance();
        if (cyp_ethif_gemgxlobj == NULL)
        {
            return CY_ETHIF_BAD_PARAM;
        }
    }
    
    /** Load the Ethernet instance */
    u8EthIfInstance = (pstcEth == CY_ETH0_TYPE) ? CY_ETHIF_INSTANCE_0 : CY_ETHIF_INSTANCE_1;
        
    /** Load Init parameter */
    Cy_EthIF_PrepareConfiguration(u8EthIfInstance, pstcEthIfConfig);
    
    if (pstcEthIfConfig->bintrEnable == true)
    {
        /** Configure Interrupts    */
        Cy_EthIf_EnableInterrupts(u8EthIfInstance, pstcInterruptList);
        
        /** Load Callback functions */
        /** NOTE: Only Rx call back is supported as of now   */
        stccallbackfunctions[u8EthIfInstance].rxframecb       = pstcInterruptList->rxframecb;
        stccallbackfunctions[u8EthIfInstance].txerrorcb       = pstcInterruptList->txerrorcb;
        stccallbackfunctions[u8EthIfInstance].txcompletecb    = pstcInterruptList->txcompletecb;
        stccallbackfunctions[u8EthIfInstance].tsuSecondInccb  = pstcInterruptList->tsuSecondInccb;        
    }
    
    /** Initialize ENET MAC Wrapper */
    if (CY_ETHIF_BAD_PARAM == Cy_EthIf_WrapperConfig(u8EthIfInstance, pstcEthIfConfig->pstcWrapperConfig))
    {
        Cy_EthIf_IPDisable(u8EthIfInstance);
        return CY_ETHIF_BAD_PARAM;
    }
    
    /** Enable the IP to access EMAC registers set  */
    Cy_EthIf_IPEnable(u8EthIfInstance);     
    
    /** Probe for checking configuration parameters and calculating memory size */
    (void)cyp_ethif_gemgxlobj->probe(&cy_ethif_cfg[u8EthIfInstance], &cy_ethif_sysreq);
    
    /** Check for assigned memory and required memory match */
    u16SysReqTxBDLength = ((cy_ethif_sysreq.txDescListSize /  CY_ETH_DEFINE_NUM_TXQS)/(CY_ETH_DEFINE_TOTAL_BD_PER_TXQUEUE + 1));
    u16SysReqRxBDLength = ((cy_ethif_sysreq.rxDescListSize /  CY_ETH_DEFINE_NUM_RXQS)/(CY_ETH_DEFINE_TOTAL_BD_PER_RXQUEUE + 1));
    
    if ((u16SysReqTxBDLength != CY_ETH_BD_SIZE) || (u16SysReqRxBDLength != CY_ETH_BD_SIZE))
    {
        /** Memory not enough   */
        return CY_ETHIF_MEMORY_NOT_ENOUGH;         
    }    
    
    /** assign starting addresses to local variable */
    Cy_EthIf_AssignMemory(u8EthIfInstance);
    
    if (sizeof(cy_ethif_privatedata[u8EthIfInstance])< cy_ethif_sysreq.privDataSize)
    {
        /** Memory not enough   */
        return CY_ETHIF_MEMORY_NOT_ENOUGH;
    }   
    
    /** Initialization EMAC registers */
    u32RetValue = cyp_ethif_gemgxlobj->init((void *)cyp_ethif_pd[u8EthIfInstance], &cy_ethif_cfg[u8EthIfInstance], &Cy_EthIf_Callbacks);       
    if (u32RetValue == EINVAL || u32RetValue == ENOTSUP)
    {
        Cy_EthIf_IPDisable(u8EthIfInstance);
        return CY_ETHIF_BAD_PARAM;
    } 
    
    /** Disable Transmit and Receive Queues  */
    Cy_EthIf_DisableQueues(u8EthIfInstance, pstcEthIfConfig);    
    
    /** TSU Initialization  */
    if (NULL != pstcEthIfConfig->pstcTSUConfig)
    {
        if (CY_ETHIF_BAD_PARAM == Cy_EthIf_TSUInit(u8EthIfInstance, pstcEthIfConfig->pstcTSUConfig))
        {
            Cy_EthIf_IPDisable(u8EthIfInstance);
            return CY_ETHIF_BAD_PARAM;
        }
    }
    
    /** Initialize Buffer status    */
    if (bBufferInitialized == false)
    {
        Cy_EthIf_InitializeBuffers();
        bBufferInitialized = true;
    }
    else
    {
        /** clear all released transmit buffer  */
        Cy_EthIF_ClearReleasedBuf(bClearAll, bTransmitBuf);
        bTransmitBuf = false;
        /** clear all released receive buffer   */
        Cy_EthIF_ClearReleasedBuf(bClearAll, bTransmitBuf);
    }
    
    /** allocate assign buffers to RX BDs   */
    for (u8tmpcounter = 0; u8tmpcounter < cy_ethif_cfg[u8EthIfInstance].rxQs; u8tmpcounter++)
    {
        for (u8tmpintrcntr = 0; u8tmpintrcntr < cy_ethif_cfg[u8EthIfInstance].rxQLen[u8tmpcounter]; u8tmpintrcntr++)
        {            
            cyp_ethif_gemgxlobj->addRxBuf((void *)cyp_ethif_pd[u8EthIfInstance], 
                                            u8tmpcounter, 
                                           (CEDI_BuffAddr *)&cy_str_rxBufStatus[(u8tmpintrcntr + (u8tmpcounter*CY_ETH_DEFINE_TOTAL_BD_PER_RXQUEUE))].cy_ethif_bufaddr.vAddr, 
                                            0);
            cy_str_rxBufStatus[(u8tmpintrcntr + (u8tmpcounter*CY_ETH_DEFINE_TOTAL_BD_PER_RXQUEUE))].enBufStatus = CY_ETHIF_BUFFER_OCCUPIED;
        }
    }
    
    /** additional Receive configurations   */
    cyp_ethif_gemgxlobj->setCopyAllFrames((void *)cyp_ethif_pd[u8EthIfInstance], CY_ETH_ENABLE_1);
    cyp_ethif_gemgxlobj->setRxBadPreamble((void *)cyp_ethif_pd[u8EthIfInstance], CY_ETH_ENABLE_1);

    /** Do not drop frames with CRC error */
    cyp_ethif_gemgxlobj->setIgnoreFcsRx((void *)cyp_ethif_pd[u8EthIfInstance], CY_ETH_ENABLE_1);
        
    // Optional: Setting Filter configuration    
    // Optional: setting screen registers
    
    /** Enable MDIO */
    cyp_ethif_gemgxlobj->setMdioEnable((void *)(void *)cyp_ethif_pd[u8EthIfInstance], CY_ETH_ENABLE_1);    
    /** driver start    */
    cyp_ethif_gemgxlobj->start((void *)cyp_ethif_pd[u8EthIfInstance]);      
    
    return CY_ETHIF_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_EthIf_WrapperConfig
****************************************************************************//**
*
* \brief Function initializes Ethernet Wrapper to configure Interface mode, reference clock/divider etc
*
* \param u8EthIfInstance Ethernet Instance 
* \param pstcInterruptList pointer to structure list 
* 
*******************************************************************************/
static cy_en_ethif_status_t Cy_EthIf_WrapperConfig (uint8_t u8EthIfInstance, cy_str_ethif_wrapper_config * pstcWrapperConfig)
{
    cy_pstc_eth_type_t pstcEthConfig; 
    un_ETH_CTL_t unEthCtl;
    
    if (pstcWrapperConfig->stcInterfaceSel > CY_ETHIF_CTL_RMII_100)
    {
        return CY_ETHIF_BAD_PARAM;
    }
    
    pstcEthConfig = (u8EthIfInstance == CY_ETHIF_INSTANCE_0) ? (stc_ETH_t*)CY_ETH0_ADDR_REG_BASE : (stc_ETH_t*)CY_ETH1_ADDR_REG_BASE;
    
    if ((pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_MII_10) ||
       (pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_MII_100))
    {
       unEthCtl.stcField.u2ETH_MODE = 0;
    }
    else if (pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_GMII_1000)
    {
        unEthCtl.stcField.u2ETH_MODE = 1;
    }
    else if ((pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_RGMII_10) ||
            (pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_RGMII_100) ||
            (pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_RGMII_1000))
    {
        unEthCtl.stcField.u2ETH_MODE = 2;
    }
    else if ((pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_RMII_10) ||
            (pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_RMII_100))
    {
        unEthCtl.stcField.u2ETH_MODE = 3;
    }
    
    unEthCtl.stcField.u1REFCLK_SRC_SEL =  pstcWrapperConfig->bRefClockSource;
    unEthCtl.stcField.u8REFCLK_DIV     = (pstcWrapperConfig->u8RefClkDiv - 1);        /** NOTE: This bits are not part of eth header file as of now   */   
    
    pstcEthConfig->unCTL.u32Register = unEthCtl.u32Register;    
    
    return CY_ETHIF_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_EthIf_IPEnable
****************************************************************************//**
*
* \brief Function enables Ethernet MAC
*
* \param u8EthIfInstance Ethernet Instance 
* 
*******************************************************************************/
static cy_en_ethif_status_t Cy_EthIf_IPEnable (uint8_t u8EthIfInstance)
{
    cy_pstc_eth_type_t pstcEthConfig;
    
    pstcEthConfig = (u8EthIfInstance == CY_ETHIF_INSTANCE_0) ? (stc_ETH_t*)CY_ETH0_ADDR_REG_BASE : (stc_ETH_t*)CY_ETH1_ADDR_REG_BASE;
    pstcEthConfig->unCTL.stcField.u1ENABLED = CY_ETH_ENABLE_1;
    
    return CY_ETHIF_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_EthIf_IPDisable
****************************************************************************//**
*
* \brief Function Disables Ethernet MAC
*
* \param u8EthIfInstance Ethernet Instance 
* 
*******************************************************************************/
static cy_en_ethif_status_t Cy_EthIf_IPDisable (uint8_t u8EthIfInstance)
{
    cy_pstc_eth_type_t pstcEthConfig;
    
    pstcEthConfig = (u8EthIfInstance == CY_ETHIF_INSTANCE_0) ? (stc_ETH_t*)CY_ETH0_ADDR_REG_BASE : (stc_ETH_t*)CY_ETH1_ADDR_REG_BASE;
    pstcEthConfig->unCTL.stcField.u1ENABLED = CY_ETH_DISABLE_0;
    
    return CY_ETHIF_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_EthIf_DisableQueues
****************************************************************************//**
* \brief By default all activated queues in the IP are enabled. However, only required 
* queues for tx and rx shall be enabled to make internal process faster. 
*
* \brief Function Disables Ethernet MAC
*
* \param u8EthIfInstance Ethernet Instance 
* 
*******************************************************************************/
static cy_en_ethif_status_t Cy_EthIf_DisableQueues (uint8_t u8EthIfInstance, cy_stc_ethif_configuration_t * pstcEthIfConfig)
{
    uint8_t u8TxQueueCounter = 0;
    uint8_t u8RxQueueCounter = 0;
    cy_pstc_eth_type_t pstcEthConfig;
    // un_ETH_TRANSMIT_Q0_PTR_t unTxQ0PTR;
    // un_ETH_TRANSMIT_Q1_PTR_t unTxQ1PTR;
    // un_ETH_TRANSMIT_Q2_PTR_t unTxQ2PTR;
    // un_ETH_RECEIVE_Q0_PTR_t unRxQ0PTR;
    // un_ETH_RECEIVE_Q1_PTR_t unRxQ1PTR;
    // un_ETH_RECEIVE_Q2_PTR_t unRxQ2PTR;    
    
    pstcEthConfig = (u8EthIfInstance == CY_ETHIF_INSTANCE_0) ? (stc_ETH_t*)CY_ETH0_ADDR_REG_BASE : (stc_ETH_t*)CY_ETH1_ADDR_REG_BASE;
    
    /** Transmit Queue 0    */
    if (pstcEthIfConfig->btxq0enable == false)
    {
        /** Disable the queue pointer   */
        pstcEthConfig->unTRANSMIT_Q_PTR.stcField.u1DMA_TX_DIS_Q = 1;
        stcQueueDisStatus[u8EthIfInstance].bTxQueueDisable[0] = true;
    }
    else    
        u8TxQueueCounter++;
    
    /** Transmit Queue 1    */
    if (pstcEthIfConfig->btxq1enable == false)
    {
        /** Disable the queue pointer   */
        pstcEthConfig->unTRANSMIT_Q1_PTR.stcField.u1DMA_TX_DIS_Q = 1;
        stcQueueDisStatus[u8EthIfInstance].bTxQueueDisable[1] = true;
    }
    else    
        u8TxQueueCounter++;
    
    /** Transmit Queue 2    */
    if (pstcEthIfConfig->btxq2enable == false)
    {
        /** Disable the queue pointer   */
        pstcEthConfig->unTRANSMIT_Q2_PTR.stcField.u1DMA_TX_DIS_Q = 1;
        stcQueueDisStatus[u8EthIfInstance].bTxQueueDisable[2] = true;
    }
    else    
        u8TxQueueCounter++;    
    
    /** Receive Queue 0    */
    if (pstcEthIfConfig->brxq0enable == false)
    {
        /** Disable the queue pointer   */
        pstcEthConfig->unRECEIVE_Q_PTR.stcField.u1DMA_RX_DIS_Q = 1;
        stcQueueDisStatus[u8EthIfInstance].bRxQueueDisable[0] = true;
    }
    else    
        u8RxQueueCounter++;
    
    /** Receive Queue 1    */
    if (pstcEthIfConfig->brxq1enable == false)
    {
        /** Disable the queue pointer   */
        pstcEthConfig->unRECEIVE_Q1_PTR.stcField.u1DMA_RX_DIS_Q = 1;
        stcQueueDisStatus[u8EthIfInstance].bRxQueueDisable[1] = true;
    }
    else    
        u8RxQueueCounter++;
    
    /** Receive Queue 2    */
    if (pstcEthIfConfig->brxq2enable == false)
    {
        /** Disable the queue pointer   */
        pstcEthConfig->unRECEIVE_Q2_PTR.stcField.u1DMA_RX_DIS_Q = 1;
        stcQueueDisStatus[u8EthIfInstance].bRxQueueDisable[2] = true;
    }
    else    
        u8RxQueueCounter++;
    
    /** TODO: Temporarily in the driver. MUST be removed once IP is updated || Q3 for both Transmit and Receive has been removed from the IP 
        Changes will apply to bitfile after 0513 release */
    //rmkn u1DMA_TX_DIS_Q, u1DMA_RX_DIS_Q removed please check
    // pstcEthConfig->unTRANSMIT_Q3_PTR.stcField.u1DMA_TX_DIS_Q = 1;
    // pstcEthConfig->unRECEIVE_Q3_PTR.stcField.u1DMA_RX_DIS_Q  = 1;
    
    /** TODO: Idea of cross checking BD memory vs enabled queues */
    
    
    return CY_ETHIF_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_EthIf_TSUInit
****************************************************************************//**
*
* \brief Function enables Time stamp unit in EMAC
*
* \param u8EthIfInstance Ethernet Instance 
* \param pstcTSUConfig Pointer to TSU parameters 
*
* \return  
* 
*******************************************************************************/
static cy_en_ethif_status_t Cy_EthIf_TSUInit (uint8_t u8EthIfInstance, cy_str_ethif_TSU_Config * pstcTSUConfig)
{
    /** set 1588 timer value    */
    /** Load Timer Value        */
    if (EOK != cyp_ethif_gemgxlobj->set1588Timer((void *)cyp_ethif_pd[u8EthIfInstance], pstcTSUConfig->pstcTimerValue))
    {
        /** Reason could be Null pointer, hardware does not support TSU or pstcTimerValue.nanosecs>0x3FFFFFFF */        
        return CY_ETHIF_BAD_PARAM;
    }
    
    /** Timer increment register to achieve 1 second as precise as possible  */
    if (EOK != cyp_ethif_gemgxlobj->set1588TimerInc((void *)cyp_ethif_pd[u8EthIfInstance], pstcTSUConfig->pstcTimerIncValue))
    {
        /** Reason could be Null pointer, hardware does not support TSU */
        return CY_ETHIF_BAD_PARAM;
    }
    
    /** one step sync enabled    */
    if (EOK != cyp_ethif_gemgxlobj->set1588OneStepTxSyncEnable((void *)cyp_ethif_pd[u8EthIfInstance], (uint8_t) pstcTSUConfig->bOneStepTxSyncEnable))
    {
        /** Reason could be Null pointer, hardware does not support TSU or bOneStepTxSyncEnable > 1 */
        return CY_ETHIF_BAD_PARAM;
    }
    
    /** Set the descriptor time stamp Mode   */
    if (EOK != cyp_ethif_gemgxlobj->setDescTimeStampMode((void *)cyp_ethif_pd[u8EthIfInstance], 
               pstcTSUConfig->enTxDescStoreTimeStamp, pstcTSUConfig->enRxDescStoreTimeStamp))
    {
        /** Reason could be Null pointer, hardware does not support TSU, enTxDescStoreTimeStamp > CEDI_TX_TS_ALL, enRxDescStoreTimeStamp > CEDI_RX_TS_ALL  */
        return CY_ETHIF_BAD_PARAM;
    }
    
    /** disabled storing nanosecond in CRC field of received frame   */
    if (EOK != cyp_ethif_gemgxlobj->setStoreRxTimeStamp((void *)cyp_ethif_pd[u8EthIfInstance], (uint8_t) pstcTSUConfig->bStoreNSinRxDesc))
    {
        /** Reason could be Null pointer, hardware does not support TSU or bStoreNSinRxDesc > 1 */
        return CY_ETHIF_BAD_PARAM;
    }
    
    return CY_ETHIF_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_EthIf_EnableInterrupts
****************************************************************************//**
*
* \brief Function initializes enabled Interrupt
*
* \param u8EthIfInstance Ethernet Instance 
* \param pstcInterruptList pointer to structure list 
* 
*******************************************************************************/
static void Cy_EthIf_EnableInterrupts (uint8_t u8EthIfInstance, cy_stc_ethif_interruptconfig_t * pstcInterruptList)
{
    /*
    
    un_ETH_INT_STATUS_t unInterruptEn;
    
    unInterruptEn.stcField.u1MANAGEMENT_FRAME_SENT                              = (pstcInterruptList->bman_frame == true) ? 1 : 0;
    unInterruptEn.stcField.u1RECEIVE_COMPLETE                                   = (pstcInterruptList->brx_complete == true) ? 1 : 0;
    unInterruptEn.stcField.u1RX_USED_BIT_READ                                   = (pstcInterruptList->brx_used_read == true) ? 1 : 0;
    unInterruptEn.stcField.u1TX_USED_BIT_READ                                   = (pstcInterruptList->btx_used_read == true) ? 1 : 0;
    unInterruptEn.stcField.u1TRANSMIT_UNDER_RUN                                 = (pstcInterruptList->btx_underrun == true) ? 1 : 0;
    unInterruptEn.stcField.u1RETRY_LIMIT_EXCEEDED_OR_LATE_COLLISION             = (pstcInterruptList->btx_retry_ex_late_coll == true) ? 1 : 0;
    unInterruptEn.stcField.u1AMBA_ERROR                                         = (pstcInterruptList->btx_fr_corrupt == true) ? 1 : 0;
    unInterruptEn.stcField.u1TRANSMIT_COMPLETE                                  = (pstcInterruptList->btx_complete == true) ? 1 : 0;
    unInterruptEn.stcField.u1RECEIVE_OVERRUN                                    = (pstcInterruptList->brx_overrun == true) ? 1 : 0;
    unInterruptEn.stcField.u1RESP_NOT_OK                                        = (pstcInterruptList->bhresp_not_ok == true) ? 1 : 0;
    unInterruptEn.stcField.u1PAUSE_FRAME_WITH_NON_ZERO_PAUSE_QUANTUM_RECEIVED   = (pstcInterruptList->bpause_nz_qu_rx == true) ? 1 : 0;
    unInterruptEn.stcField.u1PAUSE_TIME_ELAPSED                                 = (pstcInterruptList->bpause_time_zero == true) ? 1 : 0;
    unInterruptEn.stcField.u1PAUSE_FRAME_TRANSMITTED                            = (pstcInterruptList->bpause_frame_tx == true) ? 1 : 0;
    unInterruptEn.stcField.u1EXTERNAL_INTERRUPT                                 = (pstcInterruptList->bext_intr == true) ? 1 : 0;
    unInterruptEn.stcField.u1PTP_DELAY_REQ_FRAME_RECEIVED                       = (pstcInterruptList->bptp_rx_dly_req == true) ? 1 : 0;
    unInterruptEn.stcField.u1PTP_SYNC_FRAME_RECEIVED                            = (pstcInterruptList->bptp_rx_sync == true) ? 1 : 0;
    unInterruptEn.stcField.u1PTP_DELAY_REQ_FRAME_TRANSMITTED                    = (pstcInterruptList->bptp_tx_dly_req == true) ? 1 : 0;
    unInterruptEn.stcField.u1PTP_SYNC_FRAME_TRANSMITTED                         = (pstcInterruptList->bptp_tx_sync == true) ? 1 : 0;
    unInterruptEn.stcField.u1PTP_PDELAY_REQ_FRAME_RECEIVED                      = (pstcInterruptList->bptp_rx_pdly_req == true) ? 1 : 0;
    
    unInterruptEn.stcField.u1PTP_PDELAY_RESP_FRAME_RECEIVED                     = (pstcInterruptList->bptp_rx_pdly_rsp == true) ? 1 : 0;
    
    unInterruptEn.stcField.u1PTP_PDELAY_REQ_FRAME_TRANSMITTED                   = (pstcInterruptList->bptp_tx_pdly_req == true) ? 1 : 0;
    unInterruptEn.stcField.u1PTP_PDELAY_RESP_FRAME_TRANSMITTED                  = (pstcInterruptList->bptp_tx_pdly_rsp == true) ? 1 : 0;
    unInterruptEn.stcField.u1TSU_SECONDS_REGISTER_INCREMENT                     = (pstcInterruptList->btsu_sec_inc == true) ? 1 : 0;
    unInterruptEn.stcField.u1RECEIVE_LPI_INDICATION_STATUS_BIT_CHANGE           = (pstcInterruptList->blpi_ch_rx == true) ? 1 : 0;
    unInterruptEn.stcField.u1WOL_INTERRUPT                                      = (pstcInterruptList->bwol_rx == true) ? 1 : 0;
    unInterruptEn.stcField.u1TSU_TIMER_COMPARISON_INTERRUPT                     = (pstcInterruptList->btsu_time_match == true) ? 1 : 0;
    
    cy_ethif_cfg[u8EthIfInstance].intrEnable = unInterruptEn.u32Register;    
    
    */
    uint32_t u32InterruptEn = 0;
    
    if (pstcInterruptList->btsu_time_match == true)
        u32InterruptEn |= CEDI_EV_TSU_TIME_MATCH;    
    if (pstcInterruptList->bwol_rx == true)
        u32InterruptEn |= CEDI_EV_WOL_RX;    
    if (pstcInterruptList->blpi_ch_rx == true)
        u32InterruptEn |= CEDI_EV_LPI_CH_RX;    
    if (pstcInterruptList->btsu_sec_inc == true)
        u32InterruptEn |= CEDI_EV_TSU_SEC_INC;    
    if (pstcInterruptList->bptp_tx_pdly_rsp == true)
        u32InterruptEn |= CEDI_EV_PTP_TX_PDLY_RSP;
    if (pstcInterruptList->bptp_tx_pdly_req == true)
        u32InterruptEn |= CEDI_EV_PTP_TX_PDLY_REQ;    
    if (pstcInterruptList->bptp_rx_pdly_rsp == true)
        u32InterruptEn |= CEDI_EV_PTP_RX_PDLY_RSP;    
    if (pstcInterruptList->bptp_rx_pdly_req == true)
        u32InterruptEn |= CEDI_EV_PTP_RX_PDLY_REQ;    
    if (pstcInterruptList->bptp_tx_sync == true)
        u32InterruptEn |= CEDI_EV_PTP_TX_SYNC;    
    if (pstcInterruptList->bptp_tx_dly_req == true)
        u32InterruptEn |= CEDI_EV_PTP_TX_DLY_REQ;    
    if (pstcInterruptList->bptp_rx_sync == true)
        u32InterruptEn |= CEDI_EV_PTP_RX_SYNC;    
    if (pstcInterruptList->bptp_rx_dly_req == true)
        u32InterruptEn |= CEDI_EV_PTP_RX_DLY_REQ;    
    if (pstcInterruptList->bpause_frame_tx == true)
        u32InterruptEn |= CEDI_EV_PAUSE_FRAME_TX;
    if (pstcInterruptList->bpause_time_zero == true)
        u32InterruptEn |= CEDI_EV_PAUSE_TIME_ZERO;
    if (pstcInterruptList->bpause_nz_qu_rx == true)
        u32InterruptEn |= CEDI_EV_PAUSE_NZ_QU_RX;
    if (pstcInterruptList->bhresp_not_ok == true)
        u32InterruptEn |= CEDI_EV_HRESP_NOT_OK;
    if (pstcInterruptList->brx_overrun == true)
        u32InterruptEn |= CEDI_EV_RX_OVERRUN;
    if (pstcInterruptList->btx_complete == true)
        u32InterruptEn |= CEDI_EV_TX_COMPLETE;
    if (pstcInterruptList->btx_fr_corrupt == true)
        u32InterruptEn |= CEDI_EV_TX_FR_CORRUPT;
    if (pstcInterruptList->btx_retry_ex_late_coll == true)
        u32InterruptEn |= CEDI_EV_TX_RETRY_EX_LATE_COLL;
    if (pstcInterruptList->btx_underrun == true)
        u32InterruptEn |= CEDI_EV_TX_UNDERRUN;
    if (pstcInterruptList->btx_used_read == true)
        u32InterruptEn |= CEDI_EV_TX_USED_READ;
    if (pstcInterruptList->brx_used_read == true)
        u32InterruptEn |= CEDI_EV_RX_USED_READ;
    if (pstcInterruptList->brx_complete == true)
        u32InterruptEn |= CEDI_EV_RX_COMPLETE;
    if (pstcInterruptList->bman_frame == true)
        u32InterruptEn |= CEDI_EV_MAN_FRAME;  
    
    cy_ethif_cfg[u8EthIfInstance].intrEnable = u32InterruptEn;    
}

/*******************************************************************************
* Function Name: Cy_EthIF_PrepareConfiguration
****************************************************************************//**
*
* \brief prepares configuration based on the parameter passed to Cy_EthIf_Init function
* This prepared configuration which is dedicated for specific Ethernet instance would be used to initialize Ethernet MAC
*
* \param u8EthIfInstance Ethernet Instance 
* \param pstcEthIfConfig Pointer to Ethernet configuration passed from Application layer 
* 
* \Note:
*
*******************************************************************************/
static void Cy_EthIF_PrepareConfiguration (uint8_t u8EthIfInstance, cy_stc_ethif_configuration_t * pstcEthIfConfig)
{
    uint8_t u8QueueCounter = 0;
    
    /** Clear configuration table   */
    memset((void *)&cy_ethif_cfg[u8EthIfInstance], 0, sizeof(cy_ethif_cfg[u8EthIfInstance]));
    
    /** Load GEM_GXL register base address  */
    cy_ethif_cfg[u8EthIfInstance].regBase = (u8EthIfInstance == CY_ETHIF_INSTANCE_0) ? CY_ETH0_GEMGXL_ADDR_REGBASE : CY_ETH1_GEMGXL_ADDR_REGBASE;
    
    /** Prepare Queues  */
    cy_ethif_cfg[u8EthIfInstance].rxQs = CY_ETH_DEFINE_NUM_RXQS;
    cy_ethif_cfg[u8EthIfInstance].txQs = CY_ETH_DEFINE_NUM_TXQS;
    
    for (u8QueueCounter=0; u8QueueCounter<cy_ethif_cfg[u8EthIfInstance].rxQs; u8QueueCounter++) {
        cy_ethif_cfg[u8EthIfInstance].rxQLen[u8QueueCounter] = CY_ETH_DEFINE_TOTAL_BD_PER_RXQUEUE;
    }
    
    for (u8QueueCounter=0; u8QueueCounter<cy_ethif_cfg[u8EthIfInstance].txQs; u8QueueCounter++) {
        cy_ethif_cfg[u8EthIfInstance].txQLen[u8QueueCounter] = CY_ETH_DEFINE_TOTAL_BD_PER_TXQUEUE;
    }
    
    /** Prepare Network control Register    */
    cy_ethif_cfg[u8EthIfInstance].pfcMultiQuantum    = 0;                                       /* bit25    pfc_ctrl              */
    cy_ethif_cfg[u8EthIfInstance].enExtTsuPort       = 0;                                       /* bit23    ext_tsu_port_enable, Not supported by hardware  */
    cy_ethif_cfg[u8EthIfInstance].storeUdpTcpOffset  = 0;                                       /* bit22    store_udp_offset      */
    cy_ethif_cfg[u8EthIfInstance].altSgmiiEn         = 0;                                       /* bit21    alt_sgmii_mode, Not supported by hardware       */
    cy_ethif_cfg[u8EthIfInstance].enableMdio         = 0;                                       /* bit4     man_port_en, Bit is separately enabled during MDIO operation  */ 
                        
    /** Prepare Network Configuration Register    */               
    cy_ethif_cfg[u8EthIfInstance].uniDirEnable       = 0;                                       /* bit31    uni_direction_enable, Not supported by hardware    */
    cy_ethif_cfg[u8EthIfInstance].ignoreIpgRxEr      = 0;                                       /* bit30    ignore_ipg_rx_er, Not supported by hardware        */
    cy_ethif_cfg[u8EthIfInstance].enRxBadPreamble    = pstcEthIfConfig->u8enRxBadPreamble;      /* bit29    nsp_change           */
    // cy_ethif_cfg[u8EthIfInstance].ifTypeSel          = pstcEthIfConfig->ifTypeSel;              /* bit27    sgmii_mode_enable  (reserved)  */
                                                                                                /*          (see the following)  */
    // don't care                                                                               /* bit26    ignore_rx_fcs        */
    cy_ethif_cfg[u8EthIfInstance].enRxHalfDupTx      = 0;                                       /* bit25    en_half_duplex_rx, not supported by hardware    */
    cy_ethif_cfg[u8EthIfInstance].chkSumOffEn        = pstcEthIfConfig->u8chkSumOffEn;          /* bit24    receive_checksum_offload_enable */
    cy_ethif_cfg[u8EthIfInstance].disCopyPause       = pstcEthIfConfig->u8disCopyPause;         /* bit23    disable_copy_of_pause_frames */
    if(ETH_AXI_MASTER_PRESENT == 1)
    {
        cy_ethif_cfg[u8EthIfInstance].dmaBusWidth        = CEDI_DMA_BUS_WIDTH_64;                   /* bit22:21 data bus with        */
    }
    else
    {
        cy_ethif_cfg[u8EthIfInstance].dmaBusWidth        = CEDI_DMA_BUS_WIDTH_32;                   /* bit22:21 data bus with        */
    }
                                                                                                /* 00:32bit 01:64bit    */
    cy_ethif_cfg[u8EthIfInstance].mdcPclkDiv         = pstcEthIfConfig->mdcPclkDiv;             /* bit20:18 mdc_clock_division   */
                                                                                                /*          010: Divide 32       */
                                                                                                /*          011: Divide 48       */
    // don't care                                                                               /* bit17    fcs_remove           */
    cy_ethif_cfg[u8EthIfInstance].rxLenErrDisc       = pstcEthIfConfig->u8rxLenErrDisc;         /* bit16    length_field_error_frame_discard */
    cy_ethif_cfg[u8EthIfInstance].rxBufOffset        = 0;                                       /* bit15:14 receive_buffer_offset */
    // don't care                                                                               /* bit13    pause_enable         */
    // don't care                                                                               /* bit12    retry_test           */
    //cy_ethif_cfg[u8EthIfInstance].ifTypeSel        = pstcEthIfConfig->ifTypeSel               /* bit11    pcs_select (reserved)*/
                                                                                                /*          (see the following)  */
    //cy_ethif_cfg[u8EthIfInstance].ifTypeSel        = pstcEthIfConfig->ifTypeSel               /* bit10    gigabit_mode_enable  */
                                                                                                /*          (see the following)  */
    cy_ethif_cfg[u8EthIfInstance].extAddrMatch       = 0;                                       /* bit9     external_address_match_enable, not supported by hardware */
    cy_ethif_cfg[u8EthIfInstance].rx1536ByteEn       = pstcEthIfConfig->u8rx1536ByteEn;         /* bit8     receive_1536_byte_frames */
    // don't care                                                                               /* bit7     unicast_hash_enable  */
    // don't care                                                                               /* bit6     multicast_hash_enable  */
    // don't care                                                                               /* bit5     no_broadcast         */
    // don't care                                                                               /* bit4     copy_all_frames      */
    cy_ethif_cfg[u8EthIfInstance].rxJumboFrEn        = pstcEthIfConfig->u8rxJumboFrEn;          /* bit3     jumbo_frames         */
    // don't care                                                                               /* bit2     discard_non_vlan_frames */
    cy_ethif_cfg[u8EthIfInstance].fullDuplex         = 1;                                       /* bit1     full_duplex          */
    //cy_ethif_cfg[u8EthIfInstance].ifTypeSel        = pstcEthIfConfig->ifTypeSel               /* bit0     speed                */
    
    /** configuration for cy_ethif_cfg[u8EthIfInstance].ifTypeSel    */    
    if ((pstcEthIfConfig->pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_MII_10) ||
       (pstcEthIfConfig->pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_RGMII_10) ||
       (pstcEthIfConfig->pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_RMII_10))
    {
       cy_ethif_cfg[u8EthIfInstance].ifTypeSel = CEDI_IFSP_10M_MII;
    }
    else if ((pstcEthIfConfig->pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_MII_100) ||
        (pstcEthIfConfig->pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_RMII_100) ||
        (pstcEthIfConfig->pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_RGMII_100))
    {
        cy_ethif_cfg[u8EthIfInstance].ifTypeSel = CEDI_IFSP_100M_MII;
    }
    else if ((pstcEthIfConfig->pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_GMII_1000) ||
            (pstcEthIfConfig->pstcWrapperConfig->stcInterfaceSel == CY_ETHIF_CTL_RGMII_1000))
    {
        cy_ethif_cfg[u8EthIfInstance].ifTypeSel = CEDI_IFSP_1000M_GMII;
    }
    
    /*=================================================================================================*/
    /* CTL.ETH_MODE   |	Network_config[0] |  Network_config[10]   |	    PHY mode                       */
    /*                |     (speed)       | (gigabit_mode_enable) |                                    */
    /*=================================================================================================*/
    /*       2’d0	  |          0	      |          0       	  |   MII - 10Mbps                     */
    /*       2’d0	  |          1	      |          0       	  |   MII – 100Mbps                    */
    /*       2’d1	  |          0	      |          1       	  |   GMII – 1000Mbps                  */
    /*       2’d2	  |          0	      |          0       	  |   RGMII – 10Mbps (4bits/Cycle)     */
    /*       2’d2	  |          1	      |          0       	  |   RGMII – 100Mbps (4bits/Cycle)    */
    /*       2’d2	  |          0	      |          1       	  |   RGMII – 1000Mbps (8bits/Cycle)   */
    /*       2’d3	  |          0	      |          0       	  |   RMII – 10Mbps                    */
    /*       2’d3	  |          1	      |          0       	  |   RMII – 100Mbps                   */
    /*=================================================================================================*/
    
    /** Prepare DMA Config register */
    cy_ethif_cfg[u8EthIfInstance].dmaAddrBusWidth    = 0;                                       /* bit30    dma_addr_bus_width_1    */
                                                                                                /* 0:32bit 1:64bit         */
    cy_ethif_cfg[u8EthIfInstance].enTxExtBD          = CY_ETH_DEFINE_BD;                               /* bit29  tx_bd_extended_mode_en  */
    cy_ethif_cfg[u8EthIfInstance].enRxExtBD          = CY_ETH_DEFINE_BD;                               /* bit28  rx_bd_extended_mode_en  */
    cy_ethif_cfg[u8EthIfInstance].dmaCfgFlags        = pstcEthIfConfig->u8dmaCfgFlags;          /* bit26  force_max_amba_burst_tx */
                                                                                                /* bit25  force_max_amba_burst_rx */
                                                                                                /* bit24  force_discard_on_err    */
    for (u8QueueCounter=0; u8QueueCounter<cy_ethif_cfg[u8EthIfInstance].rxQs; u8QueueCounter++) {
        cy_ethif_cfg[u8EthIfInstance].rxBufLength[u8QueueCounter] = CY_ETH_SIZE_BUF_TXQ_RXQ >> 6;            /* bit23:16 rx_buf_size       */
    }
    
    cy_ethif_cfg[u8EthIfInstance].txPktBufSize       = CY_ETH_TX_PBUF_SIZE;                     /* bit10  tx_pbuf_size            */
    cy_ethif_cfg[u8EthIfInstance].rxPktBufSize       = CY_ETH_RX_PBUF_SIZE;                     /* bit9:8 rx_pbuf_size            */
    cy_ethif_cfg[u8EthIfInstance].dmaEndianism       = 0;                                       /* bit7   endian_swap_packet  */
                                                                                                /*        0: little endian mode */
                                                                                                /*        1: endian swap mode enable for packet data (CEDI_END_SWAP_DATA) */
                                                                                                /* bit6   endian_swap_management   */
                                                                                                /*        0: little endian mode    */
                                                                                                /*        1: endian swap mode enable for management descriptor (CEDI_END_SWAP_DESC) */
    cy_ethif_cfg[u8EthIfInstance].dmaDataBurstLen    = pstcEthIfConfig->dmaDataBurstLen;        /* bit4:0   amba_burst_length                                         */
                                                                                                /* 1xxxx: attempt use burst up to 16 (CEDI_DMA_DBUR_LEN_16)  */
                                                                                                /* 01xxx: attempt use burst up to  8 (CEDI_DMA_DBUR_LEN_8)   */
                                                                                                /* 001xx: attempt use burst up to  4 (CEDI_DMA_DBUR_LEN_4)   */
                                                                                                /* 0001x: always use single burst                            */
                                                                                                /* 00001: always use single burst    (CEDI_AMBD_BURST_LEN_1) */
                                                                                                /* 00000: best AXI burst up to 256 beats                     */
                                                        
    /** Prepare upper_tx_q_base_addr and upper_rx_q_base_addr register (0x4c8, 0x4D4)   */
    cy_ethif_cfg[u8EthIfInstance].upper32BuffTxQAddr = 0;                                       /* bit31:0  not used              */
    cy_ethif_cfg[u8EthIfInstance].upper32BuffRxQAddr = 0;                                       /* bit31:0  not used              */

    /** axi_max_pipeline register    */
    cy_ethif_cfg[u8EthIfInstance].aw2wMaxPipeline    = pstcEthIfConfig->u8aw2wMaxPipeline;      /* bit15:8  aw2w_max_pipeline     */
    cy_ethif_cfg[u8EthIfInstance].ar2rMaxPipeline    = pstcEthIfConfig->u8ar2rMaxPipeline;      /* bit 7:0  ar2r_max_pipeline     */
}

/*******************************************************************************
* Function Name: Cy_EthIf_PhyRegRead
****************************************************************************//**
*
* \brief Local function used by other APIs to read the PHY register
*
* \param pstcEth Ethernet instance
* \param u8RegNo Register to read
* \return read data from the register
*
* \Note: CY_ETH_PHY_ADDR must match with PHY. PHY data-sheet and hardware schematic shall be checked 
*
*******************************************************************************/
uint32_t Cy_EthIf_PhyRegRead(cy_pstc_eth_type_t pstcEth, uint8_t u8RegNo, uint8_t u8PHYAddr, uint32_t coreClkFreqInMHz)
{
    uint32_t    u32result;
    uint16_t    u16ReadData;
    uint8_t u8EthIfInstance = 255;
    
    /** check for arguments */
#if defined (tviibh8m)
    if ((pstcEth != CY_ETH0_TYPE) && (pstcEth != CY_ETH1_TYPE))
#elif defined (tviic2d6m) || defined (tviibh4m) || defined (tviic2d4m) || defined (tviic2d6mddr)
    if (pstcEth != CY_ETH0_TYPE)
#endif
    {
        return CY_ETHIF_BAD_PARAM;
    }
    
    /** Load the Ethernet instance */
    u8EthIfInstance = (pstcEth == CY_ETH0_TYPE) ? CY_ETHIF_INSTANCE_0 : CY_ETHIF_INSTANCE_1;        
    cyp_ethif_gemgxlobj->phyStartMdioRead( (void *)cyp_ethif_pd[u8EthIfInstance], CY_ETHIF_PHY_FLAG, u8PHYAddr, u8RegNo);    
    while (cyp_ethif_gemgxlobj->getMdioIdle((void *)cyp_ethif_pd[u8EthIfInstance]) != CY_ETH_MDIO_BUSY_0);

    /** additional wait */
    Cy_EthIf_WaitUsec(800, coreClkFreqInMHz);            // 500us delay

    u32result = cyp_ethif_gemgxlobj->getMdioReadData((void *)cyp_ethif_pd[u8EthIfInstance], &u16ReadData);
    if (u32result!=0) 
    {
        // debug_printf("[ETH] PHY register read not success.\r\n");
    }

    return (uint32_t)u16ReadData;
}

/*******************************************************************************
* Function Name: Cy_EthIf_PhyRegWrite
****************************************************************************//**
*
* \brief Local function used by other APIs to write the PHY register
*
* \param pstcEth Ethernet instance
* \param u8RegNo Register to write
* \param u16Data data to write
* \param coreClkFreqInMHz Input value of frequency of a core calling this function.
* \return 
*
* \Note: u8PHYAddr must match with PHY. PHY data-sheet and hardware schematic shall be checked 
*
*******************************************************************************/
cy_en_ethif_status_t Cy_EthIf_PhyRegWrite(cy_pstc_eth_type_t pstcEth, uint8_t u8RegNo, uint16_t u16Data, uint8_t u8PHYAddr, uint32_t coreClkFreqInMHz)
{
    uint8_t u8EthIfInstance = 255;
    
    /** check for arguments */
#if defined (tviibh8m)
    if ((pstcEth != CY_ETH0_TYPE) && (pstcEth != CY_ETH1_TYPE))
#elif defined (tviic2d6m) || defined (tviibh4m) || defined (tviic2d4m) || defined (tviic2d6mddr)
    if (pstcEth != CY_ETH0_TYPE)
#endif
    {
        return CY_ETHIF_BAD_PARAM;
    }
    
    /** Load the Ethernet instance */
    u8EthIfInstance = (pstcEth == CY_ETH0_TYPE) ? CY_ETHIF_INSTANCE_0 : CY_ETHIF_INSTANCE_1;    
    
    cyp_ethif_gemgxlobj->phyStartMdioWrite( (void *)cyp_ethif_pd[u8EthIfInstance], CY_ETHIF_PHY_FLAG, u8PHYAddr, u8RegNo, u16Data );    
    while (cyp_ethif_gemgxlobj->getMdioIdle((void *)cyp_ethif_pd[u8EthIfInstance]) != CY_ETH_MDIO_BUSY_0);

    /** additional wait */            
    Cy_EthIf_WaitUsec(200, coreClkFreqInMHz);       // 200usec
    return CY_ETHIF_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_EthIf_WaitUsec
****************************************************************************//**
*
* \brief Local function used by other APIs to wait specific time 
*
* \param u32micros Time in micro second
*
* \param coreClkFreqInMHz Input value of frequency of a core calling this function.
*
* \return none
*
* \Note: Function uses Systick timer of the core to create delay 
* Systick timer runs on the core frequency.
* CPU will be stuck in this function for defined time
*******************************************************************************/
void Cy_EthIf_WaitUsec (uint32_t u32micros, uint32_t coreClkFreqInMHz)
{
    uint32_t u32systickcounter = 0;
    
    cy_en_systick_clock_source_t enClockSource = CY_SYSTICK_CLOCK_SOURCE_CLK_CPU;   // 350 MHz source clock selection
    u32systickcounter = (u32micros*coreClkFreqInMHz) + 5000;
    
    Cy_SysTick_Init(enClockSource, u32systickcounter);   /** Systick is down counter    */
    
    do 
    {
        u32systickcounter = Cy_SysTick_GetValue();
    } while (u32systickcounter > 5000);
    
    Cy_SysTick_Disable(); 
}

/*******************************************************************************
* Function Name: Cy_EthIf_AssignMemory
****************************************************************************//**
*
* \brief Local function is used to initialize private data structure, tx and rx queue start address 
*
* \param u8EthIfInstance Ethernet Instance number 
*
*******************************************************************************/
static void Cy_EthIf_AssignMemory (uint8_t u8EthIfInstance)
{
    cyp_ethif_pd[u8EthIfInstance] = (CEDI_PrivateData *)cy_ethif_privatedata[u8EthIfInstance];
    cy_ethif_cfg[u8EthIfInstance].rxQAddr   = (uintptr_t)cy_ethif_rx_desc_list[u8EthIfInstance];
    cy_ethif_cfg[u8EthIfInstance].txQAddr   = (uintptr_t)cy_ethif_tx_desc_list[u8EthIfInstance];    
    cyp_ethif_statistic[u8EthIfInstance] = (CEDI_Statistics *)cy_ethif_statistic[u8EthIfInstance];
    cy_ethif_cfg[u8EthIfInstance].statsRegs = (uintptr_t)cyp_ethif_statistic[u8EthIfInstance];        
    /** get the physical address */
    cy_ethif_cfg[u8EthIfInstance].rxQPhyAddr = cy_ethif_cfg[u8EthIfInstance].rxQAddr;    
    /** get the physical address */
    cy_ethif_cfg[u8EthIfInstance].txQPhyAddr = cy_ethif_cfg[u8EthIfInstance].txQAddr;
}

/*******************************************************************************
* Function Name: Cy_EthIf_GetTimerValue
****************************************************************************//**
*
* \brief Returns the current timer value from TSU register
*
* \param pstcEth Ethernet Instance
* \param pstcRetTmrValue [out] pointer to data structure to return the values
*
*******************************************************************************/
cy_en_ethif_status_t Cy_EthIf_GetTimerValue (cy_pstc_eth_type_t pstcEth, CEDI_1588TimerVal* pstcRetTmrValue)
{
    uint8_t u8EthIfInstance = 255;
    
    /** check for arguments */
#if defined (tviibh8m)
    if ((pstcEth != CY_ETH0_TYPE) && (pstcEth != CY_ETH1_TYPE))
#elif defined (tviic2d6m) || defined (tviibh4m) || defined (tviic2d4m) || defined (tviic2d6mddr)
    if (pstcEth != CY_ETH0_TYPE)
#endif
    {
        return CY_ETHIF_BAD_PARAM;
    }
    
    if (pstcRetTmrValue == NULL)
    {
        return CY_ETHIF_BAD_PARAM;
    }
    
    /** Load the Ethernet instance */
    u8EthIfInstance = (pstcEth == CY_ETH0_TYPE) ? CY_ETHIF_INSTANCE_0 : CY_ETHIF_INSTANCE_1;
    
    cyp_ethif_gemgxlobj->get1588Timer((void *)cyp_ethif_pd[u8EthIfInstance], pstcRetTmrValue);
    
    return CY_ETHIF_SUCCESS;    
}

/*******************************************************************************
* Function Name: Cy_EthIf_SetTimerValue
****************************************************************************//**
*
* \brief Setting the current timer value in TSU register
*
* \param pstcEth Ethernet Instance
* \param pstcTmrValue pointer to data structure to configure register with
*
*******************************************************************************/
cy_en_ethif_status_t Cy_EthIf_SetTimerValue (cy_pstc_eth_type_t pstcEth, CEDI_1588TimerVal * pstcTmrValue)
{
    uint8_t u8EthIfInstance = 255;
    
    /** check for arguments */
#if defined (tviibh8m)
    if ((pstcEth != CY_ETH0_TYPE) && (pstcEth != CY_ETH1_TYPE))
#elif defined (tviic2d6m) || defined (tviibh4m) || defined (tviic2d4m) || defined (tviic2d6mddr)
    if (pstcEth != CY_ETH0_TYPE)
#endif
    {
        return CY_ETHIF_BAD_PARAM;
    }
    
    if (pstcTmrValue == NULL)
    {
        return CY_ETHIF_BAD_PARAM;
    }
    
    /** Load the Ethernet instance */
    u8EthIfInstance = (pstcEth == CY_ETH0_TYPE) ? CY_ETHIF_INSTANCE_0 : CY_ETHIF_INSTANCE_1;
    
    if (EOK != cyp_ethif_gemgxlobj->set1588Timer((void *)cyp_ethif_pd[u8EthIfInstance], pstcTmrValue))
    {
        /** Reason could be Null pointer, hardware does not support TSU or pstcTimerValue.nanosecs>0x3FFFFFFF */        
        return CY_ETHIF_BAD_PARAM;
    }
    
    return CY_ETHIF_SUCCESS;    
}

/*******************************************************************************
* Function Name: Cy_EthIf_ConfigPause
****************************************************************************//**
*
* \brief Configures the Pause Frame transmission according to IEEE 802.3X standard
*
* \param pstcEth Ethernet Instance
* \param u16PauseQuanta Time Quanta
*
*******************************************************************************/
cy_en_ethif_status_t Cy_EthIf_ConfigPause (cy_pstc_eth_type_t pstcEth, uint16_t u16PauseQuanta)
{
    uint8_t u8EthIfInstance = 255; 
    
    /** check for arguments */
#if defined (tviibh8m)
    if ((pstcEth != CY_ETH0_TYPE) && (pstcEth != CY_ETH1_TYPE))
#elif defined (tviic2d6m) || defined (tviibh4m) || defined (tviic2d4m) || defined (tviic2d6mddr)
    if (pstcEth != CY_ETH0_TYPE)
#endif
    {
        return CY_ETHIF_BAD_PARAM;
    }
    
    /** Load the Ethernet instance */
    u8EthIfInstance = (pstcEth == CY_ETH0_TYPE) ? CY_ETHIF_INSTANCE_0 : CY_ETHIF_INSTANCE_1;
    
    /** Set Tx Pause Quanta for Priority 0   */
    if (EOK != cyp_ethif_gemgxlobj->setTxPauseQuantum((void *)cyp_ethif_pd[u8EthIfInstance], u16PauseQuanta, CY_ETHIF_PAUSE_P0))
    {
        return CY_ETHIF_BAD_PARAM;
    }
    
    /** Enable Receive Pause Frames */
    cyp_ethif_gemgxlobj->setCopyPauseDisable((void *)cyp_ethif_pd[u8EthIfInstance], CY_ETH_DISABLE_0);
        
    /** Enable Pause Frames */
    cyp_ethif_gemgxlobj->setPauseEnable((void *)cyp_ethif_pd[u8EthIfInstance], CY_ETH_ENABLE_1);
    
    return CY_ETHIF_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_EthIf00_DecodeEvent
****************************************************************************//**
*
* \brief Interrupt handler for Ethernet instance ETH0
* Function calls isr function to decode the event. 
*
* \param void
*
*******************************************************************************/
void Cy_EthIf00_DecodeEvent(void)
{
    volatile uint32_t        u32result;
    
    u32result = cyp_ethif_gemgxlobj->isr((void *)cyp_ethif_pd[0]);
    //if (u32result!=0) debug_printf("NG4 (0x%08x)\r\n", result);

    return;
}

/*******************************************************************************
* Function Name: Cy_EthIf01_DecodeEvent
****************************************************************************//**
*
* \brief Interrupt handler for Ethernet instance ETH1
*
* \param void
* 
*
*******************************************************************************/
void Cy_EthIf01_DecodeEvent(void)
{
    volatile uint32_t        u32result;
    
    u32result = cyp_ethif_gemgxlobj->isr((void *)cyp_ethif_pd[1]);
    //if (u32result!=0) debug_printf("NG4 (0x%08x)\r\n", result);

    return;
}

/*******************************************************************************
* Function Name: Cy_EthIf_EventTx
****************************************************************************//**
*
* \brief Function called by cadence driver upon getting Tx Event
*
* \param pcy_privatedata    Instance specific private data
* \param u32event occurred event
* \param u8qnum Queue number 
*
*******************************************************************************/
static void Cy_EthIf_EventTx(void *pcy_privatedata, uint32_t u32event, uint8_t u8qnum)
{
    uint8_t u8EthIfInstance = 255;
    volatile uint32_t        u32result;
    CEDI_TxDescData Tx_DescData;  
    cy_pstc_eth_type_t pstcEthtmp = NULL; 
    
    /** derive the instance */
    u8EthIfInstance = (pcy_privatedata == cyp_ethif_pd[0]) ? CY_ETHIF_INSTANCE_0 : CY_ETHIF_INSTANCE_1; 
    
#if defined (tviibh8m)
    pstcEthtmp = (u8EthIfInstance == CY_ETHIF_INSTANCE_0) ? CY_ETH0_TYPE : CY_ETH1_TYPE;
#elif defined (tviibh4m) || defined (tviic2d6m) || defined (tviic2d4m) || defined (tviic2d6mddr)
    pstcEthtmp = CY_ETH0_TYPE;
#endif    
    
    if ((u32event&CEDI_EV_TX_COMPLETE) != 0) 
    {
        u32result = cyp_ethif_gemgxlobj->freeTxDesc((void *)cyp_ethif_pd[u8EthIfInstance], u8qnum, &Tx_DescData);
        
        /** application callback function     */
        if (stccallbackfunctions[u8EthIfInstance].txcompletecb != NULL)
        {
            stccallbackfunctions[u8EthIfInstance].txcompletecb(pstcEthtmp, u8qnum);
        }
        
        /** Release the buffer  */
        for (uint8_t u8tmpcounter = 0; u8tmpcounter < CY_ETH_TOTAL_TX_BUF; u8tmpcounter++)
        {
            if ((uint32_t*)Tx_DescData.bufAdd.pAddr == (uint32_t*)cy_str_txBufStatus[u8tmpcounter].cy_ethif_bufaddr.pAddr)
            {
                /** Release the buffer  */
                cy_str_txBufStatus[u8tmpcounter].enBufStatus = CY_ETHIF_BUFFER_RELEASED;
                break;
            }
        }
    }
    
    return;
}

/*******************************************************************************
* Function Name: Cy_EthIf_EventTxError
****************************************************************************//**
*
* \brief Function called by cadence driver upon getting Tx Error Event
*
* \param pcy_privatedata    Instance specific private data
* \param u32event occurred event
* \param u8qnum Queue number 
*
*******************************************************************************/
static void Cy_EthIf_EventTxError(void *pcy_privatedata, uint32_t u32event, uint8_t u8qnum)
{
    uint8_t u8EthIfInstance = 255;
    volatile uint32_t        u32result;
    CEDI_TxDescData Tx_DescData;    
    cy_pstc_eth_type_t pstcEthtmp = NULL; 
    
    /** derive the instance */
    u8EthIfInstance = (pcy_privatedata == cyp_ethif_pd[0]) ? CY_ETHIF_INSTANCE_0 : CY_ETHIF_INSTANCE_1; 
#if defined (tviibh8m)
    pstcEthtmp = (u8EthIfInstance == CY_ETHIF_INSTANCE_0) ? CY_ETH0_TYPE : CY_ETH1_TYPE;
#elif defined (tviibh4m) || defined (tviic2d6m) || defined (tviic2d4m) || defined (tviic2d6mddr)
    pstcEthtmp = CY_ETH0_TYPE;
#endif   
    
    u32result = cyp_ethif_gemgxlobj->freeTxDesc((void *)cyp_ethif_pd[u8EthIfInstance], u8qnum, &Tx_DescData);
    
    /** application callback function     */
    if (stccallbackfunctions[u8EthIfInstance].txerrorcb != NULL)
    {
        stccallbackfunctions[u8EthIfInstance].txerrorcb(pstcEthtmp, u8qnum);
    }
    
    /** Release the buffer  */
    for (uint8_t u8tmpcounter = 0; u8tmpcounter < CY_ETH_TOTAL_TX_BUF; u8tmpcounter++)
    {
        if ((uint32_t*)Tx_DescData.bufAdd.pAddr == (uint32_t*)cy_str_txBufStatus[u8tmpcounter].cy_ethif_bufaddr.pAddr)
        {
            cy_str_txBufStatus[u8tmpcounter].enBufStatus = CY_ETHIF_BUFFER_RELEASED;
            break;
        }
    }   
    
    return;
}

/*******************************************************************************
* Function Name: Cy_EthIf_EventRxFrame
****************************************************************************//**
*
* \brief Function called by cadence driver upon getting Rx Event
*
* \param pcy_privatedata    Instance specific private data
* \param u8qnum Queue number 
*
*******************************************************************************/
static void Cy_EthIf_EventRxFrame(void *pcy_privatedata, uint8_t u8qnum)
{
    uint32_t        u32Result;
    uint32_t        u32RxNum;
    // uint32_t        u32RxStatus = 0;
    CEDI_BuffAddr   TmpBufAddr;
    CEDI_RxDescData Rx_DescData;
    CEDI_RxDescStat Rx_DescStat;
    uint8_t u8EthIfInstance = 255;
    bool bReceiveBuffer = false;    /** Value must be false for Receive buffers */
    uint8_t u8BufferIndex = 255;
    bool bClearAll = false;
    cy_pstc_eth_type_t pstcEthtmp = NULL; 
    
    /** derive the instance */
    u8EthIfInstance = (pcy_privatedata == cyp_ethif_pd[0]) ? CY_ETHIF_INSTANCE_0 : CY_ETHIF_INSTANCE_1; 
#if defined (tviibh8m)
    pstcEthtmp = (u8EthIfInstance == CY_ETHIF_INSTANCE_0) ? CY_ETH0_TYPE : CY_ETH1_TYPE;
#elif defined (tviibh4m) || defined (tviic2d6m) || defined (tviic2d4m) || defined (tviic2d6mddr)
    pstcEthtmp = CY_ETH0_TYPE;
#endif   
    
    /** number of used buffers */
    u32RxNum = cyp_ethif_gemgxlobj->numRxUsed((void *)cyp_ethif_pd[u8EthIfInstance], u8qnum);

    /** read receive queue */
    while (u32RxNum!=0)
    {
        /** Get the new Buffer to replace the used one  */
        u8BufferIndex = Cy_EthIF_GetBuf(bReceiveBuffer);
        if (CY_ETHIF_NO_BUFFER_AVAILABLE == u8BufferIndex)
        {
            /** check for first released buffer */
            u8BufferIndex = Cy_EthIF_ClearReleasedBuf(bClearAll, bReceiveBuffer);
            if (CY_ETHIF_NO_BUFFER_AVAILABLE == u8BufferIndex)
            {
                return;     // No buffer available
            }
        }
        
        TmpBufAddr.vAddr = cy_str_rxBufStatus[u8BufferIndex].cy_ethif_bufaddr.vAddr;
        TmpBufAddr.pAddr = cy_str_rxBufStatus[u8BufferIndex].cy_ethif_bufaddr.pAddr;
        
        u32Result = cyp_ethif_gemgxlobj->readRxBuf((void *)cyp_ethif_pd[u8EthIfInstance],
                                          u8qnum,
                                          &TmpBufAddr,
                                          CY_ETHIF_BUFFER_CLEARED_0,
                                          &Rx_DescData);
        if (u32Result != 0)
        {
            // debug_printf("[ETH] NG4 (0x%08x)\r\n", u32Result);
        }
        else
        {
            /** change buffer status to OCCUPIED    */
            cy_str_rxBufStatus[u8BufferIndex].enBufStatus = CY_ETHIF_BUFFER_OCCUPIED;
        }
        
        switch (Rx_DescData.status)
        {
          case CEDI_RXDATA_SOF_EOF:     // 0
            /** receive start and end frame */
            cyp_ethif_gemgxlobj->getRxDescStat((void *)cyp_ethif_pd[u8EthIfInstance],
                                         Rx_DescData.rxDescStat,
                                         &Rx_DescStat);                                         
                                         
            /** application callback function     */
            if (stccallbackfunctions[u8EthIfInstance].rxframecb != NULL)
            {
                stccallbackfunctions[u8EthIfInstance].rxframecb(pstcEthtmp, (uint8_t*)TmpBufAddr.pAddr, Rx_DescStat.bufLen);
            }
            
            /** Release the buffer  */
            for (uint8_t u8tmpcounter = 0; u8tmpcounter < CY_ETH_TOTAL_RX_BUF; u8tmpcounter++)
            {
                if ((uint32_t*)TmpBufAddr.pAddr == (uint32_t*)cy_str_rxBufStatus[u8tmpcounter].cy_ethif_bufaddr.pAddr)
                {
                    cy_str_rxBufStatus[u8tmpcounter].enBufStatus = CY_ETHIF_BUFFER_RELEASED;
                    break;
                }                
            }            
            break;
          case CEDI_RXDATA_SOF_ONLY:    // 1
            /* fragment start */
            // debug_printf("[ETH] (SOF)Don't use fragment yet...\r\n");
            break; //return;
          case CEDI_RXDATA_NO_FLAG:     // 2
            /* fragment */
            // debug_printf("[ETH] (NOF)Don't use fragment yet...\r\n");
            break; //return;
          case CEDI_RXDATA_EOF_ONLY:    // 3
            /* fragment end */
            // debug_printf("[ETH] (EOF)Don't use fragment yet...\r\n");
            break;
          case CEDI_RXDATA_NODATA:      // 4
            /* normal leaving */
            // debug_printf("[ETH] NG5 RXDATA_NODATA\r\n");
            return;     /* from here it breaks while loop   */
          default:
            break;
        }
        u32RxNum--;
    }

    /* clear rx status (receive_status register) */
    // // TODO: Load the value in u32RxStatus
    //cyp_ethif_gemgxlobj->clearRxStatus((void *)cyp_ethif_pd[u8EthIfInstance], u32RxStatus);
    
    //return;
}

/*******************************************************************************
* Function Name: Cy_EthIf_EventRxError
****************************************************************************//**
*
* \brief Function called by cadence driver upon getting Rx Error Event
*
* \param pcy_privatedata    Instance specific private data
* \param u32event occurred event
* \param u8qnum Queue number 
*
*******************************************************************************/
static void Cy_EthIf_EventRxError(void *pcy_privatedata, uint32_t a_event, uint8_t a_qnum)
{
    //printf("[ETH] (Event) RxError received.\r\n");    
    return;
}

/*******************************************************************************
* Function Name: Cy_EthIf_EventPhyManComplete
****************************************************************************//**
*
* \brief 
*
* \param 
* 
*
*******************************************************************************/
static void Cy_EthIf_EventPhyManComplete(void *pcy_privatedata, uint8_t u8read, uint16_t u16ReadData)
{
    // uint32_t    u32temp;
    // uint32_t    u32addr;

    // u32temp = *((volatile uint32_t*)0xXXXX);
    // u32addr = (u32temp & 0x007C0000) >> 18;

    // debug_printf("[ETH] (Event) PhyManComplete.\r\n");
    // debug_printf("[ETH] w/r=%d, addr=0x%02x, data=0x%04x\r\n", (uint32_t)u8read, addr, (uint32_t)u16ReadData);

    return;
}

/*******************************************************************************
* Function Name: Cy_EthIf_EventhrespError
****************************************************************************//**
*
* \brief 
*
* \param 
* 
*
*******************************************************************************/
static void Cy_EthIf_EventhrespError(void *pcy_privatedata, uint8_t u8qnum)
{
    // debug_printf("[ETH] (Event) hrespError received.\r\n");
    // debug_printf("[ETH] queue num=%d\r\n", u8qnum);

    return;
}

/*******************************************************************************
* Function Name: Cy_EthIf_EventLpPageRx
****************************************************************************//**
*
* \brief 
*
* \param 
* 
*
*******************************************************************************/
static void Cy_EthIf_EventLpPageRx(void* pcy_privatedata, struct CEDI_LpPageRx* pageRx)
{
    // debug_printf("Reports PCS auto-negotiation page received");
}

/*******************************************************************************
* Function Name: Cy_EthIf_EventAn
****************************************************************************//**
*
* \brief 
*
* \param 
* 
*
*******************************************************************************/
static void Cy_EthIf_EventAn(void* pcy_privatedata, struct CEDI_NetAnStatus* netStat)
{
    // debug_printf("Auto Negotiation Event");
}

/*******************************************************************************
* Function Name: Cy_EthIf_EventLinkChange
****************************************************************************//**
*
* \brief 
*
* \param 
* 
*
*******************************************************************************/
static void Cy_EthIf_EventLinkChange(void *pcy_privatedata, uint8_t a_linkstate)
{
    // debug_printf("[ETH] (Event) linkChange received.\r\n");
    // debug_printf("[ETH] link state=%d\r\n", a_linkstate);

    return;
}
/*******************************************************************************
* Function Name: Cy_EthIf_EventTsu
****************************************************************************//**
*
* \brief 
*
* \param 
* 
*
*******************************************************************************/
static void Cy_EthIf_EventTsu (void *pcy_privatedata, uint32_t u32event)
{
    uint8_t u8EthIfInstance = 255;
    cy_pstc_eth_type_t pstcEthtmp = NULL;    
    
    /** derive the instance */
    u8EthIfInstance = (pcy_privatedata == cyp_ethif_pd[0]) ? CY_ETHIF_INSTANCE_0 : CY_ETHIF_INSTANCE_1; 
#if defined (tviibh8m)
    pstcEthtmp = (u8EthIfInstance == CY_ETHIF_INSTANCE_0) ? CY_ETH0_TYPE : CY_ETH1_TYPE;
#elif defined (tviibh4m) || defined (tviic2d6m) || defined (tviic2d4m) || defined (tviic2d6mddr)
    pstcEthtmp = CY_ETH0_TYPE;
#endif   
    
    /** Event generated if second count of the timer has incremented */
    if (u32event & CEDI_EV_TSU_SEC_INC)
    {
        /** application callback function     */
        if (stccallbackfunctions[u8EthIfInstance].tsuSecondInccb != NULL)
        {
            stccallbackfunctions[u8EthIfInstance].tsuSecondInccb(pstcEthtmp);
        }
    }

    /** Timer count matched event    */
    if (u32event & CEDI_EV_TSU_TIME_MATCH)
    {
        
    }
}
/*******************************************************************************
* Function Name: Cy_EthIf_EventPauseFrame
****************************************************************************//**
*
* \brief 
*
* \param 
* 
*
*******************************************************************************/
static void Cy_EthIf_EventPauseFrame(void *pcy_privatedata, uint32_t u32event)
{
    if (u32event & CEDI_EV_PAUSE_FRAME_TX)
    {
        // debug_printf("Pause frame transmitted");
    }
    
    if (u32event & CEDI_EV_PAUSE_NZ_QU_RX)
    {
        // debug_printf("Pause frame received");
    }
}
/*******************************************************************************
* Function Name: Cy_EthIf_EventPtp
********************************************************************************
*
* \brief 
*
* \param 
* 
*
*******************************************************************************/
static void Cy_EthIf_EventPtp (void* pcy_privatedata, uint32_t u32type, struct CEDI_1588TimerVal* time)
{
    if (u32type & CEDI_EV_PTP_TX_SYNC)
    {
        // printf("Sync frame transmitted");
    }

    if (u32type & CEDI_EV_PTP_TX_PDLY_REQ)
    {
        // printf("PTP PDelay Req frame transmitted");
    }

    if (u32type & CEDI_EV_PTP_TX_PDLY_RSP)
    {
        // printf("PTP PDelay Resp frame transmitted");
    }

    if (u32type & CEDI_EV_PTP_RX_SYNC)
    {
        // printf("Sync frame received");
    }

    if (u32type & CEDI_EV_PTP_RX_PDLY_REQ)
    {
        // printf("PTP PDelay Req frame received");
    }

    if (u32type & CEDI_EV_PTP_RX_PDLY_RSP)
    {
        // printf("PTP PDelay Resp frame received");
    }
}

/*******************************************************************************
* Function Name: Cy_EthIf_EventExternalInt
********************************************************************************
*
* \brief 
*
* \param 
* 
*
*******************************************************************************/
static void Cy_EthIf_EventExternalInt(void * pcy_privatedata)
{
   // debug_printf("External Event Occurred");
}

/*******************************************************************************
* Function Name: Cy_EthIf_EventWol
********************************************************************************
*
* \brief 
*
* \param 
* 
*
*******************************************************************************/
static void Cy_EthIf_EventWol(void * pcy_privatedata)
{
   // debug_printf("Wake On LAN Event Occurred");
}
/*******************************************************************************
* Function Name: Cy_EthIf_EventLpi
********************************************************************************
*
* \brief 
*
* \param 
* 
*
*******************************************************************************/
static void Cy_EthIf_EventLpi(void * pcy_privatedata)
{
    // debug_printf("LPI Status changed Event");
}

/*******************************************************************************
* Function Name: Cy_EthIf_InitializeBuffers
****************************************************************************//**
*
* \brief Function initializes the buffer status and clears the memory with CY_EHTIF_EMPTYVALUE value.
*
* \param none
*
*******************************************************************************/
static void Cy_EthIf_InitializeBuffers (void)
{
    uint8_t u8tmpcounter; 
    
    // Clear all TX buffers
    for (u8tmpcounter = 0; u8tmpcounter < CY_ETH_TOTAL_TX_BUF; u8tmpcounter++)
    {
        cy_str_txBufStatus[u8tmpcounter].cy_ethif_bufaddr.vAddr = (uintptr_t) &u8TxBuf[u8tmpcounter][0];
        cy_str_txBufStatus[u8tmpcounter].cy_ethif_bufaddr.pAddr = (uintptr_t) &u8TxBuf[u8tmpcounter][0];
        cy_str_txBufStatus[u8tmpcounter].enBufStatus = CY_ETHIF_BUFFER_FREE; 
        
        // Load Buffer with dummy values
        Cy_EthIf_ClearBuffer((uint32_t*)&u8TxBuf[u8tmpcounter][0]);
    }  

    // Clear all RX buffers
    for (u8tmpcounter = 0; u8tmpcounter < CY_ETH_TOTAL_RX_BUF; u8tmpcounter++)
    {
        cy_str_rxBufStatus[u8tmpcounter].cy_ethif_bufaddr.vAddr = (uintptr_t) &u8RxBuf[u8tmpcounter][0];
        cy_str_rxBufStatus[u8tmpcounter].cy_ethif_bufaddr.pAddr = (uintptr_t) &u8RxBuf[u8tmpcounter][0];
        cy_str_rxBufStatus[u8tmpcounter].enBufStatus = CY_ETHIF_BUFFER_FREE; 
        
        // Load Buffer with dummy values
        Cy_EthIf_ClearBuffer((uint32_t*)&u8RxBuf[u8tmpcounter][0]);
    } 
}

/*******************************************************************************
* Function Name: Cy_EthIf_ClearBuffer
****************************************************************************//**
*
* \brief Initializes buffer with the CY_EHTIF_EMPTYVALUE value 
*
* \param pu32Buffer start address for the buffer
* 
*******************************************************************************/
static void Cy_EthIf_ClearBuffer (uint32_t * pu32Buffer)
{
    for (uint16_t u16tmpcounter = 0; u16tmpcounter < (CY_ETH_SIZE_MAX_FRAME/4); u16tmpcounter++)
    {
        /* Load Buffer with dummy values    */
        pu32Buffer[u16tmpcounter] = CY_EHTIF_EMPTYVALUE;        
    }    
}

/*******************************************************************************
* Function Name: Cy_EthIF_GetBuf
****************************************************************************//**
*
* \brief returns the free buffer number which driver can start working with.
*
* \param bTransmitBuf To identify which pool caller wants to find free Buffer from
*
* \return u8invalid CY_ETHIF_NO_BUFFER_AVAILABLE when no buffer is free 
*         u8tmpcounter counter value loaded with the free buffer instance
*
*******************************************************************************/
static uint8_t Cy_EthIF_GetBuf (bool bTransmitBuf)
{
    uint8_t u8invalid = CY_ETHIF_NO_BUFFER_AVAILABLE;
    static uint8_t u8TxBufferPtr = 0;
    static uint8_t u8RxBufferPtr = 0;
    
    if (bTransmitBuf)
    {
        for (uint8_t u8tmpcounter = 0; u8tmpcounter < CY_ETH_TOTAL_TX_BUF; u8tmpcounter++)
        {
            if (cy_str_txBufStatus[(u8TxBufferPtr + u8tmpcounter)].enBufStatus == CY_ETHIF_BUFFER_FREE)
            {
                u8tmpcounter = u8TxBufferPtr;
                
                u8TxBufferPtr++;    
                if (u8TxBufferPtr >= CY_ETH_TOTAL_TX_BUF)
                    u8TxBufferPtr = 0;
                
                return u8tmpcounter;
            }
            
            u8TxBufferPtr++; 
            if (u8TxBufferPtr >= CY_ETH_TOTAL_TX_BUF)
                u8TxBufferPtr = 0;
        }
    }
    else
    {
        for (uint8_t u8tmpcounter = 0; u8tmpcounter < CY_ETH_TOTAL_RX_BUF; u8tmpcounter++)
        {
            if (cy_str_rxBufStatus[(u8RxBufferPtr + u8tmpcounter)].enBufStatus == CY_ETHIF_BUFFER_FREE)
            {
                u8tmpcounter = u8RxBufferPtr;
                
                u8RxBufferPtr++;    
                if (u8RxBufferPtr >= CY_ETH_TOTAL_RX_BUF)
                    u8RxBufferPtr = 0;
                
                return u8tmpcounter;
            }
            
            u8RxBufferPtr++;    
            if (u8RxBufferPtr >= CY_ETH_TOTAL_RX_BUF)
                u8RxBufferPtr = 0;
        }
    } 
    
    return u8invalid;               
}

/*******************************************************************************
* Function Name: Cy_EthIF_ClearReleasedBuf
****************************************************************************//**
*
* \brief Each buffer goes through cycle of FREE - OCCUPIED - RELEASED - FREE 
* Function looks into status of each buffer and reset them to default values if status is RELEASED
*
* \param bClearAll  True  - Free all buffers which have status "CY_ETHIF_BUFFER_RELEASED"
*                     False - Only first buffer found to be "CY_ETHIF_BUFFER_RELEASED" will be free
*        bTransmitBuf True  - Free buffer from Transmit pool
*                     False - Free buffer from Receive pool
*
* \return CY_ETHIF_BUFFER_AVAILABLE when Free all released buffers 
*         CY_ETHIF_NO_BUFFER_AVAILABLE No Buffer in a state of "CY_ETHIF_BUFFER_RELEASED"
*         u8tmpcounter in case of bClearAll to false, function will break right after locating first released buffer
*         
*******************************************************************************/
uint8_t Cy_EthIF_ClearReleasedBuf (bool bClearAll, bool bTransmitBuf)
{
    bool bBufferReleased = false;
    
    if (bTransmitBuf)
    {
        for (uint8_t u8tmpcounter = 0; u8tmpcounter < CY_ETH_TOTAL_TX_BUF; u8tmpcounter++)
        {
            if (cy_str_txBufStatus[u8tmpcounter].enBufStatus == CY_ETHIF_BUFFER_RELEASED)
            {
                Cy_EthIf_ClearBuffer((uint32_t *)cy_str_txBufStatus[u8tmpcounter].cy_ethif_bufaddr.vAddr);
                cy_str_txBufStatus[u8tmpcounter].enBufStatus = CY_ETHIF_BUFFER_FREE;
                
                bBufferReleased = true;
                if (bClearAll == false)
                {
                    return u8tmpcounter;
                }
            }
        }
    }
    else
    {
        for (uint8_t u8tmpcounter = 0; u8tmpcounter < CY_ETH_TOTAL_RX_BUF; u8tmpcounter++)
        {
            if (cy_str_rxBufStatus[u8tmpcounter].enBufStatus == CY_ETHIF_BUFFER_RELEASED)
            {
                Cy_EthIf_ClearBuffer((uint32_t *)cy_str_rxBufStatus[u8tmpcounter].cy_ethif_bufaddr.vAddr);
                cy_str_rxBufStatus[u8tmpcounter].enBufStatus = CY_ETHIF_BUFFER_FREE;
                
                bBufferReleased = true;
                if (bClearAll == false)
                {
                    return u8tmpcounter;
                }
            }
        }
    }    
    
    if (bClearAll && bBufferReleased)
        return CY_ETHIF_BUFFER_AVAILABLE;
    else
        return CY_ETHIF_NO_BUFFER_AVAILABLE;                      
}

/*******************************************************************************
* Function Name: Cy_EthIf_TransmitFrame
********************************************************************************
*
* \brief Function initiates transmission based on passed arguments
*
* \param pstcEth Ethernet Instance
*        pu8TxBuffer pointer to Transmit source buffer
*        u16Length Length of data to transmit from source buffer, Length should include source
*                  and destination buffer address. CRC bytes shall not be included in the length
*        u8QueueIndex Queue to be used to transmit the frame
*        bEndBuffer True - Last buffer of the frame to be transmitted
*                   False - Other Buffers to be provided after function call
*                           IP will not start transmitting until it gets EndBuffer True
*
* \return CY_ETHIF_SUCCESS Frame transmission started
*         CY_ETHIF_BAD_PARAM Parameter passed contains invalid values
*         CY_ETHIF_BUFFER_NOT_AVAILABLE Buffer not available to load the source data
* 
* \note
* 
*******************************************************************************/
cy_en_ethif_status_t Cy_EthIf_TransmitFrame (cy_pstc_eth_type_t pstcEth, uint8_t * pu8TxBuffer, uint16_t u16Length, uint8_t u8QueueIndex, bool bEndBuffer)
{
    uint8_t u8BufferIndex = 0;
    uint8_t u8EthIfInstance = 255;
    uint8_t * pu8LocalBuf = 0;
    bool bTransmitBuffer = true;
    bool bClearAll = false;
    uint8_t u8flags = 0;
    // uint16_t u16idx = 0;
    uint32_t u32result = 0;
    
    /** check for arguments */
#if defined (tviibh8m)
    if ((pstcEth != CY_ETH0_TYPE) && (pstcEth != CY_ETH1_TYPE))
#elif defined (tviic2d6m) || defined (tviibh4m) || defined (tviic2d4m) || defined (tviic2d6mddr)
    if (pstcEth != CY_ETH0_TYPE)
#endif
    {
        return CY_ETHIF_BAD_PARAM;
    }
    
    /** Check for arguments     */
    if ((pu8TxBuffer == NULL) || (u16Length > CY_ETH_SIZE_MAX_FRAME) || (u8QueueIndex > CY_ETH_QS3_3))
    {
        return CY_ETHIF_BAD_PARAM;
    }
    
    /** Check requested queue enabled or not    */
    if (stcQueueDisStatus[u8EthIfInstance].bTxQueueDisable[u8QueueIndex] == true)
    {
        /** Requested Queue is disabled   */
        return CY_ETHIF_BAD_PARAM;
    }
    
    /** Load the Ethernet instance */
    u8EthIfInstance = (pstcEth == CY_ETH0_TYPE) ? CY_ETHIF_INSTANCE_0 : CY_ETHIF_INSTANCE_1;
        
    /** Get available Tx Buffer from the Transmit buffer Pool   */
    u8BufferIndex = Cy_EthIF_GetBuf(bTransmitBuffer);
    if (CY_ETHIF_NO_BUFFER_AVAILABLE == u8BufferIndex)
    {
        /** check for first released buffer */
        u8BufferIndex = Cy_EthIF_ClearReleasedBuf(bClearAll, bTransmitBuffer);
        if (CY_ETHIF_NO_BUFFER_AVAILABLE == u8BufferIndex)
        {
            return CY_ETHIF_BUFFER_NOT_AVAILABLE;     // No buffer available
        }
    }
    
    /** Load the buffer address of available Buffer */
    pu8LocalBuf = (uint8_t *)cy_str_txBufStatus[u8BufferIndex].cy_ethif_bufaddr.vAddr;
    
    /** change buffer's status to OCCUPIED, Buffer will be released in case of error or after Tx complete interrupt occurs  */
    cy_str_txBufStatus[u8BufferIndex].enBufStatus = CY_ETHIF_BUFFER_OCCUPIED;
    
    /* Copy data to un-cached aligned EthIf Tx buffer */
    // for (u16idx = 0; u16idx < u16Length; u16idx++)
    // {
        // pu8LocalBuf[u16idx] = pu8TxBuffer[u16idx];
        memcpy((&pu8LocalBuf[0]), &pu8TxBuffer[0], u16Length);
    // }
    
    /** Typecast bEndBuffer to Flag type    */
    // TODO: adapt function for CEDI_TXB_NO_AUTO_CRC and CEDI_TXB_NO_AUTO_START
    if (bEndBuffer == true)
    {
        u8flags = CEDI_TXB_LAST_BUFF;
    }
    
    /** Clear transmit status register before begin to transmit */
    cyp_ethif_gemgxlobj->clearTxStatus((void *)cyp_ethif_pd[u8EthIfInstance], CY_ETHIF_TX_STATUS_CLEAR);
    
    /** Trigger Internal transmit function  */
    u32result = cyp_ethif_gemgxlobj->queueTxBuf((void *)cyp_ethif_pd[u8EthIfInstance],
									   u8QueueIndex,
									   &cy_str_txBufStatus[u8BufferIndex].cy_ethif_bufaddr,
									   u16Length,
									   u8flags);    
    if (u32result != 0)
    {
        /** error   */
        cy_str_txBufStatus[u8BufferIndex].enBufStatus = CY_ETHIF_BUFFER_RELEASED;
        return CY_ETHIF_BAD_PARAM;
    }
    
    // TODO: wait until tx done successfully?   
    
    return CY_ETHIF_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_EthIf_TxPauseFrame
****************************************************************************//**
*
* \brief Transmits IEEE 802.3X standard Pause Frame 
*
* \param pstcEth  Ethernet Instance
*        bZeroTQ  True - Zero Time Quanta 
*        bZeroTQ  False - Transmit pause frame with set time quanta
*
* \return none
* \note: If interrupt enabled, interrupt will be triggered at the end of the transmission
*         
*******************************************************************************/
cy_en_ethif_status_t Cy_EthIf_TxPauseFrame (cy_pstc_eth_type_t pstcEth, bool bZeroTQ)
{
    uint8_t u8EthIfInstance = 255;
    
    /** check for arguments */
#if defined (tviibh8m)
    if ((pstcEth != CY_ETH0_TYPE) && (pstcEth != CY_ETH1_TYPE))
#elif defined (tviic2d6m) || defined (tviibh4m) || defined (tviic2d4m) || defined (tviic2d6mddr)
    if (pstcEth != CY_ETH0_TYPE)
#endif
    {
        return CY_ETHIF_BAD_PARAM;
    }
    
    /** Load the Ethernet instance */
    u8EthIfInstance = (pstcEth == CY_ETH0_TYPE) ? CY_ETHIF_INSTANCE_0 : CY_ETHIF_INSTANCE_1;
    
    if (bZeroTQ == true)
    {
        /** trigger Pause frame with Zero Time Quanta */
        cyp_ethif_gemgxlobj->txZeroQPause((void *)cyp_ethif_pd[u8EthIfInstance]);
    }
    else
    {
        cyp_ethif_gemgxlobj->txPauseFrame((void *)cyp_ethif_pd[u8EthIfInstance]);
    }
    
    return CY_ETHIF_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_EthIf_SetNoBroadCast
****************************************************************************//**
*
* \brief 
*
* \param  
* 
*******************************************************************************/
cy_en_ethif_status_t Cy_EthIf_SetNoBroadCast(cy_pstc_eth_type_t pstcEth, bool rejectBC)
{
    uint8_t u8EthIfInstance = 255;

    /** check for arguments */
#if defined (tviibh8m)
    if ((pstcEth != CY_ETH0_TYPE) && (pstcEth != CY_ETH1_TYPE))
#elif defined (tviic2d6m) || defined (tviibh4m) || defined (tviic2d4m) || defined (tviic2d6mddr)
    if (pstcEth != CY_ETH0_TYPE)
#endif
    {
        return CY_ETHIF_BAD_PARAM;
    }

    /** Load the Ethernet instance */
    u8EthIfInstance = (pstcEth == CY_ETH0_TYPE) ? CY_ETHIF_INSTANCE_0 : CY_ETHIF_INSTANCE_1;

    cyp_ethif_gemgxlobj->setNoBroadcast((void *)cyp_ethif_pd[u8EthIfInstance],rejectBC);
    
    return CY_ETHIF_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_EthIf_SetCopyAllFrames
****************************************************************************//**
*
* \brief 
*
* \param  
* 
*******************************************************************************/
cy_en_ethif_status_t Cy_EthIf_SetCopyAllFrames(cy_pstc_eth_type_t pstcEth, bool toBeEnabled)
{
    uint8_t u8EthIfInstance = 255;

    /** check for arguments */
#if defined (tviibh8m)
    if ((pstcEth != CY_ETH0_TYPE) && (pstcEth != CY_ETH1_TYPE))
#elif defined (tviic2d6m) || defined (tviibh4m) || defined (tviic2d4m) || defined (tviic2d6mddr)
    if (pstcEth != CY_ETH0_TYPE)
#endif
    {
        return CY_ETHIF_BAD_PARAM;
    }

    /** Load the Ethernet instance */
    u8EthIfInstance = (pstcEth == CY_ETH0_TYPE) ? CY_ETHIF_INSTANCE_0 : CY_ETHIF_INSTANCE_1;

    cyp_ethif_gemgxlobj->setCopyAllFrames((void *)cyp_ethif_pd[u8EthIfInstance],toBeEnabled);
    
    return CY_ETHIF_SUCCESS;
}

/*******************************************************************************
* Function : Cy_EthIf_SetFilterAddress
****************************************************************************//**
*
*******************************************************************************/
cy_en_ethif_status_t Cy_EthIf_SetFilterAddress(cy_pstc_eth_type_t pstcEth, cy_en_eth_filter_num_t filterNo, const cy_stc_eth_filter_config_t* config)
{
    uint8_t u8EthIfInstance = 255;

    /** check for arguments */
#if defined (tviibh8m)
    if ((pstcEth != CY_ETH0_TYPE) && (pstcEth != CY_ETH1_TYPE))
#elif defined (tviic2d6m) || defined (tviibh4m) || defined (tviic2d4m) || defined (tviic2d6mddr)
    if (pstcEth != CY_ETH0_TYPE)
#endif
    {
        return CY_ETHIF_BAD_PARAM;
    }

    if(filterNo >= CY_ETH_FILTER_NUM_INV)
    {
        return CY_ETHIF_BAD_PARAM;
    }

    if(config == NULL)
    {
        return CY_ETHIF_BAD_PARAM;
    }

    /** Load the Ethernet instance */
    u8EthIfInstance = (pstcEth == CY_ETH0_TYPE) ? CY_ETHIF_INSTANCE_0 : CY_ETHIF_INSTANCE_1;

    /* add some address filters */
    cyp_ethif_gemgxlobj->setSpecificAddr((void *)cyp_ethif_pd[u8EthIfInstance],
                                        filterNo,
                                        (CEDI_MacAddress*)&config->filterAddr,
                                        config->typeFilter, 
                                        config->ignoreBytes);

    return CY_ETHIF_SUCCESS;
}


#if defined(__cplusplus)
}
#endif

/* [] END OF FILE */
