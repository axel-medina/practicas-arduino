#include <EEPROM.h>

#define verde2 2
#define verde1 3
#define azul 4
#define amarillo 5
#define rojo 6

int direccion = 0;  //Dirección de la memoria EEPROM (0 a 1023).
byte proceso;   //Un valor que irá cambiando cada cierto tiempo.

void setup() {
  pinMode(verde2, OUTPUT);
  pinMode(verde1, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(rojo, OUTPUT);
  proceso = EEPROM.read(direccion);  //Lee el último estado de "proceso" solo al iniciar el programa.
  if (proceso > 4) proceso = 0;  //Si la EEPROM no ha sido utilizada o contiene valores superiores a 4, asigna un valor 0 para ejecutar el programa.
}

void loop() {
  switch (proceso) {
    case 0:
      digitalWrite(verde2, 1);
      digitalWrite(verde1, 0);
      digitalWrite(azul, 0);
      digitalWrite(amarillo, 0);
      digitalWrite(rojo, 0);
      EEPROM.update(direccion, proceso); //Guarda el estado actual de "proceso".
      break;

    case 1:
      digitalWrite(verde2, 0);
      digitalWrite(verde1, 1);
      digitalWrite(azul, 0);
      digitalWrite(amarillo, 0);
      digitalWrite(rojo, 0);
      EEPROM.update(direccion, proceso);
      break;

    case 2:
      digitalWrite(verde2, 0);
      digitalWrite(verde1, 0);
      digitalWrite(azul, 1);
      digitalWrite(amarillo, 0);
      digitalWrite(rojo, 0);
      EEPROM.update(direccion, proceso);
      break;

    case 3:
      digitalWrite(verde2, 0);
      digitalWrite(verde1, 0);
      digitalWrite(azul, 0);
      digitalWrite(amarillo, 1);
      digitalWrite(rojo, 0);
      EEPROM.update(direccion, proceso);
      break;

    case 4:
      digitalWrite(verde2, 0);
      digitalWrite(verde1, 0);
      digitalWrite(azul, 0);
      digitalWrite(amarillo, 0);
      digitalWrite(rojo, 1);
      EEPROM.update(direccion, proceso);
      break;
  }
  proceso++;  //Al detectar uno de los casos de arriba, ejecuta el resto del loop, sumando 1 a cada vuelta.
  if (proceso > 4) proceso = 0;  //Si se pasa de 4, vuelve a reiniciar "proceso".
  delay(2000);  //Delay necesario para no desgastar la memoria muy rápido.
}
