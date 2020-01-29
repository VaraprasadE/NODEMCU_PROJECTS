#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "soil-ph-detection.firebaseio.com"
#define FIREBASE_AUTH "OfObvP5ZgwaQWvI7m6jt5wbHm8zAjeiU0OqbPS1Z"
int phsensor = A0;
float phvalue;
void setup()
{
  pinMode(phsensor,INPUT);
  Serial.begin(9600);
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  //Serial.println();

   WiFi.begin("gowtham", "gowthamraj");
  //Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
   // Serial.print(".");
  }
  //Serial.println();
  //Serial.print("Connected, IP address: ");
  //Serial.println(WiFi.localIP());
}

void loop()
{
          for(int i=1; i<=10; i++) {
        String phdata = Serial.readStringUntil(':');
        Serial.println(phdata);
        if(phdata != ""){
            String ph = Serial.readStringUntil('$');
            Serial.println(ph);
            float phvalue=ph.toFloat();
            Serial.println();
            Serial.println("PH Value");
            Serial.println(phvalue);
            delay(1000);
            if(phvalue>14){
              phvalue=14;
              }
              else{
                phvalue=phvalue;
                }
            Firebase.setFloat ("Measured_PH",phvalue);
        }
    }
}
