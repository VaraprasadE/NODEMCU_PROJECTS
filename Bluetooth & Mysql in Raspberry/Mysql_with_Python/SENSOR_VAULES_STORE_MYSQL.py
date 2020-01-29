import mysql.connector
import time
import Adafruit_DHT   
#https://github.com/adafruit/Adafruit_Python_DHT 
from datetime import datetime

sensor=Adafruit_DHT.DHT11 
gpio=17

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="Password@123",
  database="mysql"
)
while 1:
	humidity, temperature = Adafruit_DHT.read_retry(sensor, gpio)
	mycursor = mydb.cursor()
	sql = """INSERT INTO climate (date_time, temp, humi) VALUES (%s, %s, %s)"""
	current_Date = datetime.now()
	#formatted_date = current_Date.strftime('%Y-%m-%d %H:%M:%S')
	val = (current_Date, temperature, humidity)
	mycursor.execute(sql, val)
	mydb.commit()
	print(mycursor.rowcount, "Record inserted to Database.")
	time.sleep(30)
