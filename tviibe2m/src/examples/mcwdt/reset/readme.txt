This example works only when debugger does NOT connect to MCU.
When the contents of the infinite loop at bottom of main function are commented out, this example should work as below.

main_cm0plus.c
At first this program turns a LED off.
After 2 seconds, MCWDT0 reset will occur. At the top of main code, if MCWDT0 reset is detected, CPU is going to blink the LED2.
Duration of LED off should be 2 seconds.


main_cm4.c
At first this program turns a LED off.
After 1 seconds, MCWDT1 reset will occur. At the top of main code, if MCWDT1 reset is detected, CPU is going to blink the LED8.
Duration of LED off should be 1 seconds.

