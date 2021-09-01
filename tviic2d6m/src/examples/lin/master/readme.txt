* Board setting
  - Short J22_1 with R81_1 on the board. 
  - Connect LIN1 connector (P2 second one) on the CPU board.
    and CANoe or other analyzer if available.
    
Please note that LIN0 lines are multiplexed with the SWD_CLK, so it should not be 
used while debugging. 

* Copy main_cm0plus.c or main_cm7_0.c into your workspace and re-build.
  Both file behave same. Only one of those can be used at once.

* If you have CANoe.LIN, you can use LinConfig_ForMasterTest.cfg for it.
  It's configured as a slave node. It's configured simple test for this example.
  Just run and monitor using trase, statistics window.

