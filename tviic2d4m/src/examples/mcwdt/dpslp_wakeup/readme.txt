This example requires that all main_cm?????.c files are used, so that the MCU will enter DeepSleep mode
(also disconnect the debugger to really enter DeepSleep mode)

CM0+ will just go to sleep mode with sleepdeep bits set. 

CM7_0 will periodically wake-up from DeepSleep based on events from all 3 subcounters of MCWDT1 and toggles LED1,2,3 respectively

Please check EXT_CLK port defined in CM0+ main code to ensure the MCU is really going to DeepSleep.

