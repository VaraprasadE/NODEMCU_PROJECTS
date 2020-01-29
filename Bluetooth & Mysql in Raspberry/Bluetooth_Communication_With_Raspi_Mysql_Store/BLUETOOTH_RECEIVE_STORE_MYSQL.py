import serial
import mysql.connector
import time
from datetime import datetime
port = serial.Serial("/dev/rfcomm1", baudrate=9600)
mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="Password@123",
  database="mysql"
)
while 1:
    rcv = port.readline()
    print(rcv)
    current_Date = datetime.now()
    temperature = rcv[0:6]
    humidity = rcv[6:11]
    mycursor = mydb.cursor()
    sql = """INSERT INTO climate (date_time, temp, humi) VALUES (%s, %s, %s)"""
    #formatted_date = current_Date.strftime('%Y-%m-%d %H:%M:%S')
    val = (current_Date, temperature, humidity)
    mycursor.execute(sql, val)
    mydb.commit()
    print(mycursor.rowcount, "Record inserted to Database.")
    time.sleep(1)