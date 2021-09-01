/***************************************************************************//**
* \file basic_tests.h
* \version 1.0
*
* Contains some basic testcase for testing the LPDDR4 functionality
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(__BASIC_TESTS_H__)
#define __BASIC_TESTS_H__

//#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>


#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

// amount off
#define LPDDR4_MAX_DATA 16



/***************************************************************************************
 *  Function Name:  Test64BitAccess
 ***************************************************************************************
 *  \brief Function to check basic 64bit write / read access  
 * 
 *  \param number_of_values  - number of values to copy to the memory.
 *          
 *  \param startaddress - address pointer holding the starting adress to copy data to. The function is 
 *         writing number_of_values times 64bit data to the memory starting at this address until address
 *         after each write the address is incremented.
 * 
 *  \param testvalue value to write to the memory
 *
 *  \return
  *  false  if error occured during write - read - compare 
 *   true   if all value could be write- read - compare ok 
 * *************************************************************************************/
bool Test64BitAccess(int number_of_values,uint64_t * startaddress,uint64_t testValue)
{
    uint64_t value = testValue;             // 64bit value to write to the LPDDR4 memory
    uint64_t * address64;                   // test read/write pointer for 64 bit access
    uint64_t readbackValue;                 // variable to read back the data from LPDDR4 after writing it to LPDDR4

    address64 = startaddress;               //set pointer startaddress
    for(int i = 0 ; i <= number_of_values; i++)
    {
        *address64 = value;                 // write data 
        readbackValue = *address64;         // read the data back
        if(readbackValue != value)
        {
           return false;
        }
        address64++;                        // increment the address before next write / read cycle
    }
    return true;
}

/***************************************************************************************
 *  Function Name:  Test32BitAccess
 ***************************************************************************************
 *  \brief Function to check basic 32bit write / read access  
 * 
 *  \param number_of_values  - number of values to copy to the memory.
 *          
 *  \param startaddress - address pointer holding the starting adress to copy data to. The function is 
 *         writing number_of_values times 32bit data to the memory starting at this address until address
 *         after each write the address is incremented.
 * 
 *  \param testvalue value to write to the memory
 *
 *  \return
  *  false  if error occured during write - read - compare 
 *   true   if all value could be write - read - compare ok 
 * *************************************************************************************/
bool Test32BitAccess(int number_of_values,uint32_t * startaddress,uint32_t testValue)
{
    uint32_t value = testValue;             // 32bit value to write to the LPDDR4 memory
    uint32_t * address32;                   // test read/write pointer for 32 bit access
    uint32_t readbackValue;                 // variable to read back the data from LPDDR4 after writing it to LPDDR4
    address32 = startaddress;               // set pointer to startaddress

    for(int i = 0 ; i <= number_of_values; i++)
    {
        *address32 = value;                 // write data
        readbackValue = *address32;         // read the data back
        if(readbackValue != value)
        {
            return false;
        }
        address32++;                        // increment the address before next write / read cycle
    }
    return true;
}



/***************************************************************************************
 *  Function Name:  Test16BitAccess
 ***************************************************************************************
 *  \brief  Function to check basic 16bit write / read access  
 * 
 *  \param  number_of_values  - number of values to copy to the memory.
 *          
 *  \param  startaddress - address pointer holding the starting adress to copy data to. The function is 
 *          writing number_of_values times 16bit data to the memory starting at this address until address
 *          after each write the address is incremented.
 * 
 *  \param  testvalue value to write to the memory
 *
 *  \return
 *          false   if error occured during write - read - compare 
 *          true    if all value could be write - read - compare ok 
 ***************************************************************************************/
bool Test16BitAccess(int number_of_values,uint16_t * startaddress,uint16_t testValue)
{
    uint16_t value = testValue;             // 16bit value to write to the LPDDR4 memory
    uint16_t * address16;                   // test read/write pointer for 16 bit access
    uint16_t readbackValue;                 // variable to read back the data from LPDDR4 after writing it to LPDDR4
    address16 = startaddress;               // set pointer startaddress

    for(int i = 0 ; i <= number_of_values; i++)
    {
        *address16 = value;                 // write data
        readbackValue = *address16;         // read the data back
        if(readbackValue != value)
        {
            return false;
        }
        address16++;                        // increment the address before next write / read cycle
    }
    return true;
}


/***************************************************************************************
 *  Function Name:  Test8BitAccess
 ***************************************************************************************
 *  \brief  Function to check basic 8bit write / read access  
 * 
 *  \param  number_of_values  - number of values to copy to the memory.
 *          
 *  \param  startaddress - address pointer holding the starting adress to copy data to. The function is 
 *          writing number_of_values times 8bit data to the memory starting at this address until address
 *          after each write the address is incremented.
 * 
 *  \param  testvalue value to write to the memory
 *
 *  \return
 *          false   if error occured during write - read - compare 
 *          true    if all value could be write - read - compare ok 
 ***************************************************************************************/
bool Test8BitAccess(int number_of_values,uint8_t * startaddress,uint8_t testValue)
{
    uint8_t value = testValue;          //  8bit value to write to the LPDDR4 memory
    uint8_t * address8;                 //  test read/write pointer for 8 bit access
    uint8_t readbackValue;              //  variable to read back the data from LPDDR4 after writing it to LPDDR4
    address8 = startaddress;            //  set pointer to startaddress

    for(int i = 0 ; i <= number_of_values; i++)
    {
        *address8 = value;              //   write data
        readbackValue = *address8;      //   read the data back
        if(readbackValue != value)
        {
            return false;
        }
        address8++;                     //   increment the address before next write / read cycle
    }
    return true;
}


#define ARRAY_SIZE(x)     (sizeof(x)/sizeof(x[0]))

void custom_memcpy(void *dest, void *src, size_t n) {
   size_t gi;
   //cast src and dest to char*
   uint32_t* src_int = (uint32_t* )src;
   uint32_t* dest_int = (uint32_t* )dest;
   for (gi=0; gi<n; gi++)
   {
      dest_int[gi] = src_int[gi]; //copy contents byte by byte
   }
}





/*
    Function to test basic LPDDR4 Memory Access it is writing data to the Memory and reading it back
    If everything was ok it returns 0
    Function stores offset of each memory cell based on the actual initilazes address mapping schemes to different memory cells 
    The memory cells selected are calculates in a nested for loop. The value which will be stored to this memory is the calculated 
    offset. After reading back the offset from this memory location we can recalculated what was initialy used to calculate the offset and 
    compare if we still have the same result.
*/
uint32_t TestBasicReadWriteAccess(const cy_stc_lpddr4_config_t *config)
{
    uint32_t ch_idx = 0;
    uint32_t bank_idx = 0;
    uint32_t row_idx = 0;
    uint32_t col_idx = 0;
    uint32_t offset = 0;
    
    uint32_t rb_ch = 0;
    uint32_t rb_bank = 0;
    uint32_t rb_row = 0;
    uint32_t rb_col_idx = 0;
    uint32_t rb_offset = 0;
    // local variable to count errors
    uint32_t error = 0;
    for(ch_idx=0;ch_idx<1;ch_idx++)
      {

        for(bank_idx=0;bank_idx<2;bank_idx++)
          {
            for(row_idx=0;row_idx<60;row_idx++)
            {
                for(col_idx=0;col_idx<512;col_idx++)
                {
                    /* Calculate a AXI Address Offset  based on ch,Bank,Row,Col information */
                    Cy_Lpddr_GetDramToAxiMapping(config, &offset,ch_idx, bank_idx, row_idx, col_idx);
                    /* write to the memory address CY_LPDDR4_BASE + offset the value of the offset */
                    *(((volatile unsigned int *)CY_LPDDR4_BASE) + offset ) = offset;
                    /* Read back the value which is stored */
                    rb_offset = *(((volatile unsigned int *)CY_LPDDR4_BASE) + offset );
                    /* Caclulate the the information ch,bak,row,col base on the offset */
                    Cy_Lpddr_GetAxiToDramMapping(config, rb_offset,&rb_ch, &rb_bank, &rb_row, &rb_col_idx);
                    /* the calculated ch, bank, row col information must be same as it 
                    was fed in at the beginning if not increment the error*/
                    if((ch_idx != rb_ch)||(bank_idx!=rb_bank)||(row_idx!=rb_row)||(col_idx!=rb_col_idx))
                    {
                      error++;
                    }
                }
            }
          }
      }
  return error;
}


/***************************************************************************************
 *  Function Name:  Copy16KDataToExternalMem
 ***************************************************************************************
 *  \brief  Function to test some basic memory functionality by copying 16KB data from 
 *          a array to ext memory. After coping the data to external memory data 
 *          will be compared if everything worked well the function return true
 * 
 *
 *  \return
 *          false   if error occured during write - read - compare 
 *          true    if all value could be write - read - compare ok 
 ***************************************************************************************/
bool Copy16KDataToExternalMem(int value)
{
    bool dataOK = false;
    // define 16kb data to be copied to ext memory
    static uint8_t testarray[1024*16];
    
    // fill the array wit 0xA5
    memset(testarray,value,sizeof(testarray));
   
    // write the DDR Memory starting at 0x80000000  with 0xff
    memset((void*)CY_LPDDR4_BASE,value,sizeof(testarray));
    
    // now copy the test array to the ext memory
    custom_memcpy((void*)CY_LPDDR4_BASE,(void*)testarray,ARRAY_SIZE(testarray));
    
    //check if the values in external memory and test array are same
    if(memcmp((void*)CY_LPDDR4_BASE,(void*)testarray,sizeof(testarray)) == 0)
    {
        dataOK = true;
    }
    else
    {
        dataOK = false;
    }
return dataOK;
}


#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* __BASIC_TESTS_H__ */

/** \} group_lpddr */

/* [] END OF FILE */
