#include <ESP32Servo.h>

Servo servoMotor;
const int servoPin = 25;

void moverServo(int angulo) {
  angulo = constrain(angulo, 0, 180);
  servoMotor.write(angulo);
  delay(500);
}

void setup() {
  servoMotor.attach(servoPin);  // liga o servo ao pino
}

//Função para abrir a porta
void abrirPorta() {
  moverServo(50);   // posição aberta
}

//Função para fechar a porta
void fecharPorta() {
  moverServo(160);  // posição fechada
}

