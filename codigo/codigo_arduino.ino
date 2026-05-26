#include <LiquidCrystal.h>

// ===== LCD =====
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

// ===== SENSORES =====
int temperaturaPin = A0;
int luzPin = A1;
int vibracaoPin = 2;

// ===== LEDS =====
int verde = 8;
int amarelo = 9;
int vermelho = 10;

void setup() {

  // Vibração
  pinMode(vibracaoPin, INPUT);

  // LEDs
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);

  // LCD
  lcd.begin(16,2);

  // Monitor Serial
  Serial.begin(9600);
}

void loop() {

  // ===== TEMPERATURA =====

  int valorTemp = analogRead(temperaturaPin);

  float voltagem = valorTemp * 5.0 / 1023.0;

  float temperatura = (voltagem - 0.5) * 100;

  // ===== LUZ =====

  int luz = analogRead(luzPin);

  // ===== VIBRAÇÃO =====

  int vibracao = digitalRead(vibracaoPin);

  // ===== LCD =====

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(temperatura);

  lcd.setCursor(0,1);
  lcd.print("Luz:");
  lcd.print(luz);

  // ===== LEDS TEMPERATURA =====

  // MUITO FRIO
  if (temperatura < 10) {

    digitalWrite(verde, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, HIGH);

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("TEMP BAIXA");

  }

  // NORMAL
  else if (temperatura < 30) {

    digitalWrite(verde, HIGH);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, LOW);

  }

  // ALERTA
  else if (temperatura < 40) {

    digitalWrite(verde, LOW);
    digitalWrite(amarelo, HIGH);
    digitalWrite(vermelho, LOW);

  }

  // CRÍTICO
  else {

    digitalWrite(verde, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, HIGH);

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("ALERTA TEMP");

  }

  // ===== VIBRAÇÃO =====

  if (vibracao == HIGH) {

    digitalWrite(vermelho, HIGH);

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("VIBRACAO!");

  }

  // ===== SERIAL =====

  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  Serial.print("Luminosidade: ");
  Serial.println(luz);

  Serial.print("Vibracao: ");
  Serial.println(vibracao);

  delay(1000);
}
