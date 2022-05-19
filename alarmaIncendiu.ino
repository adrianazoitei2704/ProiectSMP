

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal lcd(12, 11, 9,8,7,6);
int fire = 5;
int smoke = A0;
int buzzer = 13;
int verde = 4;
int galben = 3;
int rosu = 2;
void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(smoke,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(galben,OUTPUT);
  pinMode(rosu,OUTPUT);
  pinMode(fire,INPUT);
  lcd.print("Senzor gaz");
  delay(2000);
  lcd.clear();
  noTone(buzzer);
}
bool getValueGaz(){
  int sensorValue = analogRead(smoke);
  Serial.println(sensorValue);
  if(sensorValue > 45)
  {
    return true;
  }
  return false;
}
bool getValueFoc(){
  int sensorValue = digitalRead(fire);
  Serial.println(sensorValue);
  if(sensorValue > 0)
  {
    return true;
  }
  return false;
}
void alarma()
{
  lcd.clear();
  lcd.print("INCENDIU!!");
  tone(buzzer,200);
  delay(1000);
  noTone(buzzer);
  
}
void loop() {
  bool fum = getValueGaz();
  bool foc = getValueFoc();
  bool incendiu = foc && fum;
  if(!foc && !fum)
  {
    digitalWrite(galben,LOW);
    digitalWrite(rosu,LOW);
    digitalWrite(verde,HIGH);
  }
  if(!incendiu){
    lcd.setCursor(0,0);
    lcd.print("Valoare senzori:");
    lcd.setCursor(0,1);
    lcd.print("Fum:");
    lcd.setCursor(4,1);
    if(fum)
    {
      digitalWrite(rosu,LOW);
      digitalWrite(verde,LOW);
      digitalWrite(galben,HIGH);
      lcd.print("DA");
    }
    else{
      lcd.print("NU");
    }
    lcd.setCursor(8,1);
    lcd.print("Foc:");
    lcd.setCursor(12,1);
     if(foc)
    {
      digitalWrite(rosu,LOW);
      digitalWrite(verde,LOW);
      digitalWrite(galben,HIGH);
      lcd.print("DA");
    }
    else{
      lcd.print("NU");
    }
  }
  else{
    digitalWrite(rosu,HIGH);
    digitalWrite(verde,LOW);
    digitalWrite(galben,LOW);
    alarma();
  }
  delay(50);

  
}
