// ==== Definição dos pinos da Ponte H ====

// Motor A (lado esquerdo)
#define IN1 27
#define IN2 14
#define ENA 26  // controle de velocidade (PWM)

// Motor B (lado direito)
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


