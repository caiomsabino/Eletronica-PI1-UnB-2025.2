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