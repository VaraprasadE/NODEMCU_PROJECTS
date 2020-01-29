import serial
import time
port = serial.Serial("/dev/rfcomm2", baudrate=9600)
while True:
	print "DIGITAL LOGIC -- > SENDING..."
	port.write(str(3))
	rcv = port.readline()
	if rcv:
	   print(rcv)
	time.sleep( 3 )
