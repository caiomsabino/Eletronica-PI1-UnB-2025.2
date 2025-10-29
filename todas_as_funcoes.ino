#include <ESP32Servo.h>

// ==== Definição dos pinos da Ponte H ====
// Motor A 
#define IN1 27
#define IN2 14
#define ENA 26  // controle de velocidade (PWM)

// Motor B 
#define IN3 23
#define IN4 22
#define ENB 21  // controle de velocidade (PWM)


// ==== Configuração inicial ====
void setup() {
  // Define todos os pinos como saída
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}


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


// ==== Função para o carrinho andar para frente ====
void andarFrente(int velocidade) {
  // Garante que a velocidade fique dentro do limite do PWM (0 a 255, potencia media)
  velocidade = constrain(velocidade, 0, 255);

  // Motor A gira para frente
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velocidade);

  // Motor B gira para frente
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velocidade);
}

// ==== Função para o carrinho andar para trás ====
void andarTras(int velocidade) {
  // Garante que a velocidade fique dentro do limite do PWM (0 a 255, potencia media)
  velocidade = constrain(velocidade, 0, 255);

  // Motor A gira para trás
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, velocidade);

  // Motor B gira para trás
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, velocidade);
}

// ==== Função para o carrinho virar para a direita ====
void virarDireita(int velocidade) {
  // Garante que a velocidade fique dentro do limite do PWM
  velocidade = constrain(velocidade, 0, 255);

  // Motor esquerdo gira para frente
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velocidade);

  // Motor direito parado
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

// ==== Função para o carrinho virar para a esquerda ====
void virarEsquerda(int velocidade) {
  // Garante que a velocidade fique dentro do limite do PWM
  velocidade = constrain(velocidade, 0, 255);

  // Motor direito gira para frente
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velocidade);

  // Motor esquerdo parado
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
}
