import paho.mqtt.publish as publish
import RPi.GPIO as GPIO
import paho.mqtt.client as mqtt
GPIO.setmode(GPIO.BOARD)
GPIO.setup(5,GPIO.OUT)
def on_connect(client, userdata, flags, rc):
	print("Connecting to"+str(rc))
	client.subscribe("LED/CONTROL")
def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))

    if msg.payload == "Hello":
        print("Received message #1, do something")
        GPI0.output (5,True)
		publish.single ( "LED/STATUS", "Led in ON state",hostname="test.mosquitto.org")


    if msg.payload == "World!":
        print("Received message #2, do something else")
        GPIO.output (5, False)
		publish.single( "LED/STATUS", "Led in OFF state",hostname="test.mosquitto.org")
		
client=mqtt.Client()
client.on_connect=on_connect
client.on_message=on_message
client.connect("test.mosquitto.org",1883,60)
client.loop_forever()