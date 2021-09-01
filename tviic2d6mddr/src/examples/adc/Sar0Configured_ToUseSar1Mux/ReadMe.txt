
This example gets analog value input from ADC[1]_15 using ADC0.

Hardware Configuration on TVII-C-2D-6M CPU Board:
If you check the analog value changing connect, analog input port with ADC POT on the CPU board.

Software Configuration:
1. Configure SAR0 as 
    CTL.SARMUX_EN=1, 
    CTL.ADC_EN=1, 
    CTL.ENABLE=1
2. Configure SAR1 as 
    CTL.SARMUX_EN=1, 
    CTL.ADC_EN=0, 
    CTL.ENABLE=1
3. Configure analog input ADC[1]_15 as 
    SAMPLE_CTL.PIN_ADDR=15,
    SAMPLE_CTL.PORT_ADDR=SARMUX1,
    SAMPLE_CTL.SAMPLE_TIME=1000,
4. Initialize logical channel with PASS0_SAR0->CH[0]  
5. Enable and trigger logical channel PASS0_SAR0->CH[0]
