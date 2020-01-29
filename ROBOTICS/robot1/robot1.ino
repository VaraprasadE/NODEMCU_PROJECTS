#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
int input1=D1; int input2=D2; int input3=D7; int input4=D8;
const char* ssid = "raghul";
const char* password = "gemicates";
ESP8266WebServer server;
void setup() {
  pinMode(input1,OUTPUT);
  pinMode(input3,OUTPUT);
  pinMode(input2,OUTPUT);
  pinMode(input4,OUTPUT);
  digitalWrite(input1,LOW);
 digitalWrite(input2,LOW);
 digitalWrite(input3,LOW);
 digitalWrite(input4,LOW);
  Serial.begin(115200);
  Serial.println();
  Serial.printf("Connecting to %s\n", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", []()
  {
    String content;
    content ="<!DOCTYPE HTML><html><head><title>GEMICATES</title></head><body>";
    content +="<a href=\"/front\"\"><button class='button'>FRONT</button></a> <br>";
    content +="<a href=\"/back\"\"><button class='button'>BACK</button></a><br>";
    content +="<a href=\"/Stop\"\"><button class='button'>STOP</button></a><br></body></html>";
    server.send(200, "text/html", content);
  });
server.on("/front",FRONT);
server.on("/back",BACK);
server.on("/Stop",STOP);
server.begin();

}
void loop() {
  server.handleClient();
}


void FRONT(){
 digitalWrite(input1,HIGH);
 digitalWrite(input3,HIGH);
    }
 void BACK(){
 digitalWrite(input2,HIGH);
 digitalWrite(input4,HIGH);   
    }
void STOP(){
 digitalWrite(input1,LOW);
 digitalWrite(input2,LOW);
 digitalWrite(input3,LOW);
 digitalWrite(input4,LOW);
    }
