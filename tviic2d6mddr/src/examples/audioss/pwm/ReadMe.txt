This example utilize the PWM module of Audioss ip. It demonstrate the pwm wave output only.
Please check the reference image for pwm waves.

For PSVP:
Hardware Setup:
1. On PSVP 8M adapter board, PWM TX0 pins are available as
	Line1_P0 -- TP357
	Line1_N0 -- TP240
	Line2_P0 -- TP307
	Line2_N0 -- TP340
2. Please make sure all base board button jumper J102 are removed.
3. PWM audio needs external hardware, that is not available.

Software Setup:
1. Clock is configured as 8MHz (internally divided by 3).
2. Sample rate is 8MHz that gives a period of ~0.125us
3. Duty is set to 41 (period + 1), so the wave period is ~5.12us.
4. Sample data 0x0000007 will provide 0.8us (7*0.125us) on period.

Please reach out to Traveo-II SDL team for any issue. 


For Silicon:
Hardware Setup:
Just connect the earplug on J51, beep sound will come on left and right channel
Make sure jumper J54 is closed.
