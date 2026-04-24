#include <LiquidCrystal.h>

// LCD Pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Pin Definitions
const int tempPin = A0;
const int lightPin = A1;
const int alertLedPin = 13;
const int roomLedPin = 12;
const int buzzerPin = 8;

// Thresholds
const float tempThreshold = 30.0;
const int lightThreshold = 800;

void setup() {
  pinMode(alertLedPin, OUTPUT);
  pinMode(roomLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.print("Smart Room Active");
  delay(2000);
  lcd.clear();
  
  Serial.begin(9600);
}

void loop() {
  // --- Sensor Readings ---
  int tempReading = analogRead(tempPin);
  float voltage = tempReading * (5.0 / 1023.0);
  float tempC = (voltage - 0.5) * 100;
  int lightLevel = analogRead(lightPin);

  // --- Temperature & Buzzer Logic ---
  if (tempC > tempThreshold) {
    digitalWrite(alertLedPin, HIGH);
    // Play a 1000Hz tone on pin 8
    tone(buzzerPin, 1000); 
  } else {
    digitalWrite(alertLedPin, LOW);
    // Stop the sound
    noTone(buzzerPin); 
  }

  // --- Light Logic ---
  if (lightLevel < lightThreshold) {
    digitalWrite(roomLedPin, HIGH);
  } else {
    digitalWrite(roomLedPin, LOW);
  }

  // --- LCD Update ---
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC, 1);
  lcd.print("C  ");

  lcd.setCursor(0, 1);
  if (tempC > tempThreshold) {
    lcd.print("ALARM! ");
  } else {
    lcd.print("Status:OK ");
  }
  
  lcd.print("L:");
  lcd.print(lightLevel);
  lcd.print(" ");

  delay(800); 
}
