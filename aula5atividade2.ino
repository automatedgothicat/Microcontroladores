// Definindo o pino do buzzer
const int pinoBuzzer = 9; // Pino digital onde o buzzer está conectado
void setup() {
  pinMode(pinoBuzzer, OUTPUT); // Configura o pino do buzzer como saída
}

void loop() {
  digitalWrite(pinoBuzzer, HIGH); // Liga o buzzer
  delay(1000); // Espera 1 segundo (1000 milissegundos)

  digitalWrite(pinoBuzzer, LOW); // Desliga o buzzer
  delay(1000); // Espera 1 segundo (1000 milissegundos)
}
