int WATER = 8;
int PUMP = 6;
void setup() {
  pinMode(PUMP,OUTPUT);
  pinMode(WATER,INPUT);
  Serial.begin(9600);
}

void loop() {
  int waterlevel = digitalRead(WATER);
  Serial.println(waterlevel);
  delay(10);
  if(waterlevel==0){
    digitalWrite(PUMP,LOW);
    }
    else if(waterlevel==1){
      digitalWrite(PUMP,HIGH);
      }
      else{
        digitalWrite(PUMP,LOW);
        }
}
