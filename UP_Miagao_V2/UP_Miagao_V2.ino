

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
#include <dht.h>
#define dataPin A0 
dht DHT; 


int count1 = 35; // count upp
int count2 = 20; // count down
int CPH = 1;  // LCD 
int BTR1 = 7; // MOVE
int BTUP = 6; // value up
int BTDN = 5; // valuw down
int pos = 0; 

int Temp = 0;
int Upper= 0;
int Lower = 0;
int ULI = 0;
int LLI = 4;
int Relay = 3;

int TempI = 9;

  int val = 0;

  void setup() {
  
  lcd.begin(16,2);
  lcd.setCursor(1,0);
  lcd.print("Dried  Mangoes");
  lcd.setCursor(1,1);
  lcd.print("Temp Contoller");
  delay(2000);
  lcd.clear();
  lcd.print("[U] [L]   TEMP");
  lcd.setCursor(ULI, 1);
  lcd.print(Upper);
  lcd.setCursor(LLI, 1);
  lcd.print(Lower);
  lcd.setCursor(TempI, 1);
  lcd.print(Temp);
  lcd.setCursor(CPH, 0);
  lcd.cursor();
  lcd.blink();
  pinMode(BTR1,INPUT);
  pinMode(BTUP,INPUT);
  pinMode(BTDN,INPUT);
  pinMode(Relay,OUTPUT);
 
  
  } // void setup end

//-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o
  void loop() {
  
 lcd.setCursor(CPH, 0);
  if((digitalRead(BTR1) == HIGH) && (CPH != 1) )
  {
   CPH -=4;
    delay(500);
  }
  else if((digitalRead(BTR1) == HIGH) && (CPH != 5) )
  {
   CPH +=4;
    delay(500);
  }
  lcd.blink();
  int readData = DHT.read22(dataPin); 
  float t = DHT.temperature;
  lcd.setCursor(TempI, 1);
  lcd.print(t);
  lcd.print("*C");
  delay(10);
  
  switch (CPH){
    
    case 1:
    if ((digitalRead(BTUP) == HIGH) && (count1 != 50)){
         lcd.setCursor(ULI,1); 
      lcd.print(count1++ );
      while(digitalRead(BTUP) == HIGH) ;
      delay(200);
    }
    if ((digitalRead(BTDN) == HIGH) && (count1 != 30)){
         lcd.setCursor(ULI,1); 
      lcd.print(count1-- );
      while(digitalRead(BTDN) == HIGH) ;
      delay(200);
      
    }
 
    break;
    
    case 5:
  
    if ((digitalRead(BTUP) == HIGH) && (count2 != 31)){
         lcd.setCursor(LLI,1);
      lcd.print(count2++ );
      while(digitalRead(BTUP) == HIGH) ;
      delay(200);
    }
   if ((digitalRead(BTDN) == HIGH) && (count2 != 0)){
         lcd.setCursor(LLI,1); 
      lcd.print(count2--);
      while(digitalRead(BTDN) == HIGH) ;
      delay(200);
      
    }
    break;
   }

   
    

   //Switch end
  
  if (DHT.temperature >= count1 )
  {
    
     digitalWrite(Relay,HIGH);
      
      
    
   
 
  }
 if (DHT.temperature < count2 )
  {
   digitalWrite(Relay,LOW);

  }

\
  } //Void end
 
