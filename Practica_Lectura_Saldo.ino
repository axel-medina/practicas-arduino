#include <EEPROM.h>
const byte boton1 = 2;
const byte boton2 = 13;
const byte buzzerPin = 8;
unsigned long saldo;
bool boton1Val;
bool boton2Val;
uint16_t dt = 500;
uint16_t dinero = 10000;
String SALDO_UPDATE = "Saldo actualizado a: ";
String START_MESSAGE = "Sistema iniciado. Tu saldo actual es: ";
char moneda = 'G';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  saldo = EEPROM.get(0, saldo);
  /* if (saldo != 0) {           
      saldo = 0;
      EEPROM.put(0, saldo); Guarda en la memoria un valor 0 para configuración.
      } */
  Serial.print(START_MESSAGE);
  Serial.print(saldo);
  Serial.println(moneda);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (saldo == 0){ 
    activarSuma();
  }
  while( saldo == 4000000){
    activarResta();
  }
  activarSuma();
  activarResta();
}

void activarSuma() {
  boton1Val = digitalRead(boton1);
  if (boton1Val == 0) {
    saldo = saldo + dinero;
    EEPROM.put(0, saldo);
    Serial.print(SALDO_UPDATE);
    Serial.print(saldo);
    Serial.println(moneda);
    digitalWrite(buzzerPin, 1);
    delay(dt);
    digitalWrite(buzzerPin, 0);
  }
}
void activarResta() {
  boton2Val = digitalRead(boton2);
  if (boton2Val == 0) {
    saldo = saldo - dinero;
    EEPROM.put(0, saldo);
    Serial.print(SALDO_UPDATE);
    Serial.print(saldo);
    Serial.println(moneda);
    digitalWrite(buzzerPin, 1);
    delay(dt);
    digitalWrite(buzzerPin, 0);
  }
}
