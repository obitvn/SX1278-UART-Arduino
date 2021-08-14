

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(A3, INPUT);
pinMode(A2, INPUT);
pinMode(A1, INPUT);
pinMode(A0, INPUT);
pinMode(2, INPUT);
digitalWrite(3,0);
digitalWrite(4,0);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(digitalRead(A3)==0)
 {
  while(digitalRead(A3)==0){};
  for(int i=0; i<10; i++)
  {
  Serial.println("UP");
  delay(50);
  }
 }
 if(digitalRead(A2)==0)
 {
  while(digitalRead(A2)==0){};
  for(int i=0; i<10; i++)
  {
  Serial.println("DOWN");
  delay(50);
  }
 }
 if(digitalRead(A1)==0)
 {
  while(digitalRead(A1)==0){};
  for(int i=0; i<10; i++)
  {
  Serial.println("STOP");
  delay(50);
  }
 }
 if(digitalRead(A0)==0)
 {
  while(digitalRead(A0)==0){};
  for(int i=0; i<10; i++)
  {
  Serial.println("ROLL");
  delay(50);
  }
 }
}
