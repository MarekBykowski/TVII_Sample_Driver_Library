LPDDR4 driver for usage with PSVP BItfile released with PAND#61


Additional Memory settings:
    cy_dram_config.h 
    the user must select the right memory density and 
    data rate of the device in use. This is needed as some timing parameters 
    are depending on these memory density/data rate.

        /* select the right DRAM Density here */
        #define CHANNEL_DENSITY         DENSITY_PER_CHANNEL_4GB

        /* select the right data rate which shall be used here */
        #define DATA_RATE               DATA_RATE_1600
    These macros are place in a seperate file so the user doesn´t need to touch 
    cy_lpddr4.h or cy_lpddr4.c


    
Configuration File:
----------------------------
    
    The lpddr4_*.h files contains a structure needed to init the LPDDR4 Controller.
    Which file to use can be set with #define USED_INIT_DATA ....

            /******************************************************************************/
            /*                              USED INIT DATA Definintion                    */
            /******************************************************************************/
            #define USE_CYPRESS_CFG3        3     //lpddr4_cfg3.h  refer lpddr4 config file content.xlsx
            #define USE_CYPRESS_CFG3_ECC    5     //same as lpddr4_cfg3.h with ECC enabled
            #define USE_CYPRESS_CFG7        7    //lpddr4_cfg7.h refer lpddr4 config file content.xlsx
            #define USE_CYPRESS_CFG8        8    //lpddr4_cfg8.h refer lpddr4 config file content.xlsx

            /* select the configuration to use for LPDDR Controlller initialization */
            #define USED_INIT_DATA      USE_CYPRESS_CFG8


    -lpddr4_cfg3.h configuration data for IOP Testing.Refer lpddr4 config file content.xlsx
    -lpddr4_cfg3_ecc.h same as with ECC enabled 
    -lpddr4_cfg7.h configuration data for IOP Testing.Refer lpddr4 config file content.xlsx
    -lpddr4_cfg8.h configuration data for IOP Testing.Refer lpddr4 config file content.xlsx





Header File Version:
---------------------
As at the moment the header for the latest IP release are not yet available 
some bitfields of the IP registers must be set without bitfields.
This is done using ApplyMissingHeaderFileChanges(cy_stc_lpddr4_config_t * config). 
As soon as newer header file is available this function isn´t needed anymore.
 The function checks the header file version the user must set. If header version is >DOTP26 
 no manual update is needed. Current Version is DOTP26
    
    #define HEADER_FILE_RELEASE DOTP26



Initialization:
----------------------

User can select how to Init the controller by setting the INIT_TYPE

    - when set to INIT_WITH_TRAINING the controller will be initialized running
      all necessary trainings, CBT, WRLVL,RDLVL,GateTarining.....

    - when set to INIT_WITHOUT_TRAINING the controller is initialize by reloading
      valid data from PTSRxx registers. Once the controller was successfully trained
      the user might store the data in some nonvolatile memory as it can be used 
      druring next initialization for reloading valid data back to the controller
      and re-init without the need of training. Save also time when simulating the 
      code. The content of the PTSR Registers in the lpddr_*.h config files are 
      values from a successfull training on  FCV. When using real silicon we need
      run a ral training and note down the trained values from the PTSRxx registers 
      and include them in the lpddr_*.h config to reload valid data to the controller.












