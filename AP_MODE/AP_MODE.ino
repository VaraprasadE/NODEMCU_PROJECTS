#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server;
WiFiClient espClient;
PubSubClient client(espClient);

IPAddress staticIP(192,168,1,22);
IPAddress gateway(192,168,1,9);
IPAddress subnet(255,255,255,0);

int frontside = D1;   
int leftside = D2;
int rightside = D3;
int backside = D4;
  
void setup()
{
  pinMode(frontside,OUTPUT);
  pinMode(leftside,OUTPUT);
  pinMode(rightside,OUTPUT);
  pinMode(backside,OUTPUT);
  Serial.begin(115200);
  Serial.println();
 
  Serial.print("Setting Hotspot on NodeMCU... ");
  WiFi.softAPConfig(staticIP, gateway, subnet);
  
  boolean result = WiFi.softAP("SIH-2019", "123456789");
  if(result == true)
  {
    Serial.println("Ready");
  }
  else
  {
    Serial.println("Failed!");
  }
  Serial.println(WiFi.softAPIP());
      server.on("/",[](){
        String content;
        content ="<!DOCTYPE html>";
content +="<html><head><meta charset='utf-8'/><meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'/>";
content +="<title>GEMICATES</title><style>";
content +=".button{height:50px;background:#e8491d;border:0;padding-left: 40px;padding-right:40px;color:#ffffff;font-weight:bold;margin:15px;}";
content +=".button:hover {box-shadow: 0 12px 16px 0 rgba(0,0,0,0.24), 0 17px 50px 0 rgba(0,0,0,0.19);}";
content +="</style></head><body><center><h1>WOW SMART INDIA HACKTHON 2019</h1></br></br>";
content +="<a href=\"/front\"\"><button class='button'> Forward </button></a></br></br></br>";
content +="<a href=\"/left\"\"><button class='button'> LEFT</button></a>";
content +="<a href=\"/right\"\"><button class='button'> Right</button></a></br></br></br>";
content +="<a href=\"/back\"\"><button class='button'> Backward </button></a>";
content +="</center></body></html>";
        server.send(200, "text/html", content);});
      server.on("/right",right);
      server.on("/left",left);
      server.on("/front",forward);
      server.on("/back",backward);
      server.begin();
}

void loop()
{
  server.handleClient();
}

void right()
{
  digitalWrite(rightside,!digitalRead(rightside));
  // Write the code regading to the Right Direction this PINS connected to MEGA BOARD
  server.send(204,"");
}

void left()
{
  digitalWrite(leftside,!digitalRead(leftside));
  // Write the code regading to the left Direction this PINS connected to MEGA BOARD
  server.send(204,"");
}
void forward()
{
  digitalWrite(frontside,!digitalRead(frontside));
  // Write the code regading to the front Direction this PINS connected to MEGA BOARD
  server.send(204,"");
}
void backward()
{
  digitalWrite(backside,!digitalRead(backside));
  // Write the code regading to the back Direction or this PINS connected to MEGA BOARD
  server.send(204,"");
}
