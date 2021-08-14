
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7,6);

void setup() {
  // put your setup code here, to run once:
  pinMode(A5, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(3,0);
  digitalWrite(4,0);
  pinMode(2, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("LORA RECEVICE");
}


char Lora[50];
char index, off, roll, up, down,latch;
int duty=100;
uint32_t time_now, time_late;
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    time_late = millis();
    char inChar = (char)Serial.read();
    if (index < 40)
      {
        Lora[index++] = inChar;
      }
    else 
      {
        for(int i=0; i<50;i++)
        {
          Lora[i]=0;
        }
        index=0;
      }
    if (inChar == '\n')
      {
        if (strstr(Lora, "UP") != 0)
          {
             lcd.setCursor(0, 1);
             lcd.print("UP  ");
             up=1;
          }
        else if (strstr(Lora, "DOWN") != 0)
          {
             lcd.setCursor(0, 1);
             lcd.print("DOWN");
             down=1;
          }
        else if (strstr(Lora, "STOP") != 0)
          {
             lcd.setCursor(0, 1);
             lcd.print("STOP");
             off=1;
          }
        else if (strstr(Lora, "ROLL") != 0)
          {
             lcd.setCursor(0, 1);
             lcd.print("ROLL");
             roll=1;
          }
        index=0;
        for(int i=0; i<50;i++)
        {
          Lora[i]=0;
        }
      }
  }

  if(millis()-time_late>100)
  {
    if(roll==1) 
    {
      latch=~latch;
      if(latch)
      {
        digitalWrite(5,1);
        digitalWrite(4,0);
        lcd.setCursor(5, 1);
        lcd.print("+");
      }
      else
      {
        digitalWrite(4,1);
        digitalWrite(5,0);
        lcd.setCursor(5, 1);
        lcd.print("-");
      }
      roll=0;
    }
    if (up==1) 
    {
      duty=duty+5;
      if(duty>255) duty=0;
      lcd.setCursor(8, 1);
  lcd.print("DUTY:");
  lcd.setCursor(13, 1);
  lcd.print("   ");
  lcd.setCursor(13, 1);
  lcd.print(duty);
      up=0;
    }
    if(down==1)
    {
      duty=duty-5;
      if(duty<0) duty=255;
      lcd.setCursor(8, 1);
  lcd.print("DUTY:");
  lcd.setCursor(13, 1);
  lcd.print("   ");
  lcd.setCursor(13, 1);
  lcd.print(duty);
      down=0;
    }
    if(off==1)
    {
      duty=0;
      lcd.setCursor(8, 1);
      lcd.print("DUTY:");
      lcd.setCursor(13, 1);
      lcd.print("   ");
      lcd.setCursor(13, 1);
      lcd.print(duty);
      off=0;
    }
  }

  analogWrite(3,duty);
  
  }
