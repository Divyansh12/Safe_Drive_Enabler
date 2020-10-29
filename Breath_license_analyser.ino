
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
 
#define SS_PIN 10
#define RST_PIN 9
#define LED_G 5 //define green LED pin
#define LED_B 8 //define Blue LED pin
#define LED_R 4 //define red LED
#define BUZZER 2 //buzzer pin
int sensorPin = A0;
int value;


MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myServo; //define servo name
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  myServo.attach(3); //servo pin
  myServo.write(0); //servo start position
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  Serial.println("Put your card to the reader...");
  Serial.println();

}


void added_setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  myServo.attach(3); //servo pin
  myServo.write(0); //servo start position
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  Serial.println("Put your card to the reader...");
  Serial.println();

}

void check_loop() 
{
  // Read the value from Gas sensor
  int Value = analogRead(sensorPin);
  value = analogRead(A0);
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "F1 BA F1 2D") 
  {
    digitalWrite(LED_B, HIGH);
    delay(2000);
    Serial.println("Analyse your Breath !!");
    delay(5000);
    if(value-50 < 400) 
    {
      Serial.println("Authorized access!!");
      Serial.println();
      delay(500);
      digitalWrite(LED_G, HIGH);
      digitalWrite(LED_B, LOW);
      tone(BUZZER, 500);
      delay(300);
      noTone(BUZZER);
      myServo.write(180);
      delay(5000);
      myServo.write(0);
      digitalWrite(LED_G, LOW);
    }
    else   {
    Serial.println(" Access denied");
    digitalWrite(LED_R, HIGH);
     digitalWrite(LED_B, LOW);
    tone(BUZZER, 300);
    delay(1000);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
  }
  }
 
 else   {
    Serial.println(" Access denied");
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 300);
    delay(1000);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
  }
} 

void loop() 
{
  // Read the value from Gas sensor
  int Value = analogRead(sensorPin);
  value = analogRead(A0);
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "F1 BA F1 2D") 
  {
    digitalWrite(LED_B, HIGH);
    delay(2000);
    Serial.println("Analyse your Breath !!");
    delay(5000);
    if(value-50 < 400) 
    {
      Serial.println("Authorized access!!");
      Serial.println();
      delay(500);
      digitalWrite(LED_G, HIGH);
      digitalWrite(LED_B, LOW);
      tone(BUZZER, 500);
      delay(300);
      noTone(BUZZER);
      myServo.write(180);
      delay(5000);
      myServo.write(0);
      digitalWrite(LED_G, LOW);
    }
    else   {
    Serial.println(" Access denied");
    digitalWrite(LED_R, HIGH);
     digitalWrite(LED_B, LOW);
    tone(BUZZER, 300);
    delay(1000);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
  }
  }
 
 else   {
    Serial.println(" Access denied");
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 300);
    delay(1000);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
  }
} 
