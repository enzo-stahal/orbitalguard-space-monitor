#include <LiquidCrystal.h>

// LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

// Sensores
int temperaturaPin = A0;
int luzPin = A1;
int vibracaoPin = 2;

// LEDs
int verde = 8;
int amarelo = 9;
int vermelho = 10;

void setup() {

  pinMode(vibracaoPin, INPUT);

  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);

  lcd.begin(16,2);

  Serial.begin(9600);
}

void loop() {

  // ===== TEMPERATURA =====

  int valorTemp = analogRead(temperaturaPin);

  float voltagem = valorTemp * 5.0 / 1023.0;

  float temperatura = (voltagem - 0.5) * 100;

  // ===== LUZ =====

  int luz = analogRead(luzPin);

  // ===== VIBRACAO =====

  int vibracao = digitalRead(vibracaoPin);

  // ===== LCD =====

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(temperatura);

  lcd.setCursor(0,1);
  lcd.print("Luz:");
  lcd.print(luz);

  // ===== LEDS =====

  if (temperatura < 30) {

    digitalWrite(verde, HIGH);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, LOW);

  }

  else if (temperatura < 40) {

    digitalWrite(verde, LOW);
    digitalWrite(amarelo, HIGH);
    digitalWrite(vermelho, LOW);

  }

  else {

    digitalWrite(verde, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, HIGH);

  }

  // ===== VIBRACAO =====

  if (vibracao == HIGH) {

    digitalWrite(vermelho, HIGH);

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("VIBRACAO!");

  }

  delay(1000);
}
