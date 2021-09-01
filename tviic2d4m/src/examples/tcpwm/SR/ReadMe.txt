* CYTVII-C-2D-4M-216-CPU Board setting
  - Short the following pins on the CPU board:
  	P9_17 and P9_18
  - Check the following pins on the CPU Board:
	GPIO_TO_BE_COPY 	--> P9_17
	TCPWM0_LINE21 		--> J119_2
  
* Copy main_cm0plus.c or main_cm7_0.c into your workspace and re-build.
  Both file behave same. Only one of those can be used at once.

* Please see pin outputs PWM output should be delayed by the 8us with
  respect to the applied GPIO input.
