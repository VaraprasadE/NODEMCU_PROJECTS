import RPi.GPI0 as GPIO
import time
condition=1
GPI0.setmode(GPI0.BOARD)
GPIO.setup(7, GPIO.0UT)
while condition:
	GPIO.output (7, True)
	print ("LED ON ")
	time.sleep(1)
	GPIO.output (7, False)
	print("LED OFF")
	time.sleep(1)
GPIO.cleanup()