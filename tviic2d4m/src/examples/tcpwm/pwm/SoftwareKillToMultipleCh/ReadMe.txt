* CYTVII-C-2D-4M-216-CPU Board setting
  - Check the following pins on the CPU Board:
    TCPWM0_GRP0_CNT23	--> R651_1
	TCPWM0_GRP0_CNT24	--> J107_2
	TCPWM0_GRP0_CNT25	--> J108_2
	TCPWM0_GRP0_CNT26	--> J109_2
	TCPWM0_GRP0_CNT27	--> J110_2
	TCPWM0_GRP0_CNT28	--> J95_2
	TCPWM0_GRP1_CNT0 	--> J55_1
	TCPWM0_GRP1_CNT1 	--> J55_9
	TCPWM0_GRP2_CNT16	--> J55_3
	TCPWM0_GRP2_CNT17	--> J55_11
  
* Copy main_cm0plus.c or main_cm7_0.c into your workspace and re-build.
  Both file behave same. Only one of those can be used at once.

* Example will trigger multiple PWM channel, after 2 seconds all the PWM channel
  will be killed by Trigger MUX.

