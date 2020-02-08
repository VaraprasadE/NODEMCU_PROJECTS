import mysql.connector
import paho.mqtt.publish as publish
from bluepy import btle
import time
from datetime import datetime
mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="Admin@123",
  database="mysql"
)
class MyDelegate(btle.DefaultDelegate):
    def __init__(self,params):
        btle.DefaultDelegate.__init__(self)

    def handleNotification(self,cHandle,data):
#        print("handling notification...")
        print(data.decode("utf-8"))
        Temper = data.decode("utf-8")
        current_Date = datetime.now()
        temperature = Temper[0:6]
        humidity = Temper[6:11]
        mycursor = mydb.cursor()
        sql = """INSERT INTO health(date_time, temp, humi) VALUES (%s, %s, %s)"""
        val = (current_Date, temperature, humidity)
        mycursor.execute(sql, val)
        mydb.commit()
        time.sleep(0.5)
		publish.single("Gemicates/SIET/phd", Temper, hostname="test.mosquitto.org")
p = btle.Peripheral('00:13:AA:00:64:48')
p.setDelegate(MyDelegate(0))

while True:
    if p.waitForNotifications(1.0):
        continue
 #  print("waiting...")