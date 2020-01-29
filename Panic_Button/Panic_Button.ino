#include <ESP8266WiFi.h>
const char* ssid     = "Praveen";  
const char* password = "abcdefgh"; 
int button= D5;   
int Buzzer = D1;              
const char* host = "maker.ifttt.com";     //IFTTT channel address
int buttonState;
void setup() {
  pinMode(button, INPUT);
  pinMode(Buzzer,OUTPUT);
  Serial.begin(115200);
  digitalWrite(button,LOW); // By default Off state
  }
int value = 1;
void loop() {
   buttonState = digitalRead(button);
    if (buttonState == HIGH) {                     //button is pulled down to ground via 10k resistor
       if (value == 1){
         WiFi.disconnect();
        Serial.println("Button Pressed");
       WiFi.begin(ssid, password); // connecting to wifi
       while (WiFi.status() != WL_CONNECTED) {
        Serial.println("Conencting");
       delay(500);
       }
       digitalWrite(Buzzer,HIGH);  // LED turns On
       WiFiClient client;
       const int httpPort = 80;
       if (!client.connect(host, httpPort)) {
        Serial.println("Weak Network");
       return;
       }
       // We now create a URI for the request
       String url = "/trigger/save_me/with/key/j_Y443brtnPqNhBKS81U7Mqps8iS1PfRH1zci2lebr0";   //our link to trigger the event with special key and event name 
       // This will send the request to the server
       client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");  // GET request 
       value = 0;
       delay(5000);
       digitalWrite(Buzzer,LOW);  // LED turns Off
       }
    }
    else{
    value = 1;
    delay(500);
    }
}
