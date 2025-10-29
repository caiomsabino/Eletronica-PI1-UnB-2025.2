#include <ESP32Servo.h>

// ==== Definições ====
Servo servoMotor;        // Cria o objeto servo
const int servoPin = 25;  // Pino de controle do servo

// ==== Configuração inicial ====
void setup() {
  Serial.begin(115200);
  servoMotor.attach(servoPin);  // Liga o servo ao pino definido
}

// ==== Função para mover o servo ====
void moverServo(int angulo) {
  // Limita o ângulo entre 0 e 180 graus
  angulo = constrain(angulo, 0, 180);

  servoMotor.write(angulo);  // Envia o sinal para o servo
  delay(500);  // Espera o servo chegar na posição
}



