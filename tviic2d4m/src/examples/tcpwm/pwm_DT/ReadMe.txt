* CYTVII-C-2D-4M-216-CPU Board setting
  - Check the following pins on the CPU Board:
	TCPWM0_LINE256 		--> J55_1
	TCPWM0_LINE256_COMP	--> J55_3
  
* Copy main_cm0plus.c or main_cm7_0.c into your workspace and re-build.
  Both file behave same. Only one of those can be used at once.

* Please see pin outputs the 200Hz with right side dead time 250 [us] 
  and left side dead time 500 [us].

