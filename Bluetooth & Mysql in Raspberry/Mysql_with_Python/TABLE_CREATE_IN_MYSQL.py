import mysql.connector
mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="Password@123",
  database="mysql"
)
mycursor = mydb.cursor()

mycursor.execute("CREATE TABLE climate (s_no INT AUTO_INCREMENT PRIMARY KEY, date_time VARCHAR(45), temp VARCHAR(45), humi VARCHAR(45))")

