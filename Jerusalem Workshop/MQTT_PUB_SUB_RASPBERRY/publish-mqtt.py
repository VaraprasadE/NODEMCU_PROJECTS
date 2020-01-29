import paho.mqtt.publish as publish
publish.single("Gemicates", "Hello", hostname="test.mosquitto.org")
print("Published")
