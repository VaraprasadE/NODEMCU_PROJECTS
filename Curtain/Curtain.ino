int up = D1;
int down = D2;
int halt = D3;
int M1=D5;
int M2=D6;
void setup() {
  pinMode(up,INPUT);
  pinMode(down,INPUT);
  pinMode(halt,INPUT);
  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  digitalWrite(up,HIGH);
  digitalWrite(down,HIGH);  
  digitalWrite(halt,HIGH);
  Serial.begin(9600);
}

void loop() {
  // For Opening
  if(digitalRead(up)==LOW){
   int t = 0;
   while(t<5){     
   // For Stop
        if(digitalRead(halt)==LOW){
            digitalWrite(M1,LOW);
            digitalWrite(M2,LOW);
            return;
        }
        digitalWrite(M1,LOW);
        digitalWrite(M2,HIGH);
        delay(1000);
        t++;
       }
    }
  else{
    digitalWrite(M1,LOW);
    digitalWrite(M2,LOW);
  }
// For Closing
  if(digitalRead(down)==LOW){
   int t1 = 0;
   while(t1<5){     
   // For Stop
        if(digitalRead(halt)==LOW){
            digitalWrite(M1,LOW);
            digitalWrite(M2,LOW);
            return;
        }
        digitalWrite(M1,HIGH);
        digitalWrite(M2,LOW);
        delay(1000);
        t1++;
       }
    }
  else{
    digitalWrite(M1,LOW);
    digitalWrite(M2,LOW);
  }
}
