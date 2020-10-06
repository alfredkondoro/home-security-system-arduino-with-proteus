#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#define pir1 A0
#define pir2 A1
#define pir3 A2
#define led1 6
#define led2 7
#define led3 8
#define buzpin 0
SoftwareSerial gsm(9, 11);
LiquidCrystal lcd(13, 12, 5, 4 , 3, 2);
String phone="+255788092978";

void setup(){
  Serial.begin(9600);
  gsm.begin(9600);
  //Output for LED
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  //Input for the pir sensors
  pinMode(pir1, INPUT);
  pinMode(pir2, INPUT);
  pinMode(pir3, INPUT);
  digitalWrite(pir1, LOW);
  digitalWrite(pir2, LOW);
  digitalWrite(pir3, LOW);

  //buzzer initialised
  digitalWrite(buzpin, LOW);
  
  //LCD print setup
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Home Security");

  // Check if you're currently connected to SIM800C 
    while(!gsm.available()){
      gsm.println("AT");
      delay(1000); 
      Serial.println("connecting....");
    }
    Serial.println("Connected..");  
    gsm.println("AT+CMGF=1");  //Set SMS Text Mode 
    delay(1000);  
    gsm.println("AT+CNMI=1,2,0,0,0");  //procedure, how to receive messages from the network
    delay(1000);
    gsm.println("AT+CMGL=\"REC UNREAD\""); // Read unread messages
    Serial.println("Ready to receive Commands..");  
}
void loop(){
 
 if(digitalRead(pir1)){
    tone(buzpin, 20);
    digitalWrite(led1, HIGH);
    lcd.setCursor(0,2);
    lcd.print("Zone 1 Detected");
    gsm.print("AT+CMGS=\"+255788092978\"\r");
    delay(1000);
    gsm.print("Zone 1 Detected");
    gsm.print((char)26);
    delay(10000);
  }
  else if(digitalRead(pir2)){
    tone(buzpin, 20);
    digitalWrite(led2, HIGH);
    lcd.setCursor(0,2);
    lcd.print("Zone 2 Detected");
    gsm.print("AT+CMGS=\"+255788092978\"\r");
    delay(1000);
    gsm.print("Zone 2 Detected");
    gsm.print((char)26);
    delay(10000);
  }
  else if(digitalRead(pir3)){
    tone(buzpin, 20);
    digitalWrite(led3, HIGH);
    lcd.setCursor(0,2);
    lcd.print("Zone 3 Detected");
    gsm.print("AT+CMGS=\"+255788092978\"\r");
    delay(1000);
    gsm.print("Zone 3 Detected");
    gsm.print((char)26);
    delay(10000);
  }
  else{
    noTone(buzpin);
    lcd.setCursor(0,2);
    lcd.print("Home is Safe");
    }
}
