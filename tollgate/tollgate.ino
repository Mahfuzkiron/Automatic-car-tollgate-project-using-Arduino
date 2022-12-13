//Object detection with LCD, LED and buzzer
//@mahfuzur rahman Kiron 
//Coding Tips BD

#include <LiquidCrystal_I2C.h>
#define trigPin 9
#define echoPin 8
#define led1 7
#define led2 6
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int duration, distance;
Servo s1;

void setup() {
  Serial.begin (9600);
  lcd.init();               // initialize the lcd
  lcd.backlight();
  pinMode(trigPin, OUTPUT); // config trigger pin to output mode
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  s1.attach(3);  
       
}

void loop() {
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance=0.017 * duration;           // calculate the distance
  lcd.print(distance);

   if (distance <= 20 || distance <= 0){
    lcd.clear();
    
    lcd.print(" Car distance: ");
    lcd.setCursor(0, 1);
    lcd.print(" in meters: ");
    lcd.print(distance);
    lcd.print("m");
    lcd.setCursor(0, 1);
    
    delay(2000);
    Serial.println("wlc to tollgate");
  }
  else {
    Serial.print("wlc to tollgate");
    Serial.println("plz keep patient");
    
  }
  
  if (distance < 6) {
  lcd.clear();
  lcd.print("Gate is open-->");
  lcd.setCursor(0, 1);
  lcd.print(" Go slowly...");
  lcd.setCursor(0, 1);
  digitalWrite(led1,HIGH);
  s1.write(0);  
  delay(3000);  
  s1.write(90); 
  lcd.setCursor(0, 1);
  delay(5000);
  lcd.clear();
  lcd.print("Gate is closed");
  lcd.setCursor(0, 1);
  lcd.print("Keep walking...");
  lcd.setCursor(0, 1);
  digitalWrite(led2,HIGH);
  delay(2000);   
  lcd.setCursor(0,1);
  Serial.println("  Gate is open");
  
}
  else {
    
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
  }

  if (distance >= 100 || distance <= 0){
    lcd.clear();
    Serial.println("WLC To Tollgate");
    lcd.print("WLC To Toll-gate");
    lcd.setCursor(0, 1);
    lcd.print("Plz Keep Patient");
    lcd.setCursor(0, 1);
    delay(2000);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    
  }

  delay(500);

}
  
