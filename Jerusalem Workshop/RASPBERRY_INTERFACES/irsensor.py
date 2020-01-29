import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(14, GPIO.IN)
GPIO.setup (3,GPIO.OUT)
count=0
while 1:
	if (GPIO.input(14)=False) :
		GPIO.output(3,True)
		count=count+1
		print("the count is:",count)
		print("object Detected")
	else:
		GPIO.output (3,False)
		print("No object Detected")
		time.sleep(1)
GPIO.cleanup ()