const int pinoBuzzer = 7;
const int mercurioPin = 8; //pino de saída do módulo de mercúrio
const int ledPin = 9; //pino do LED indicador

void setup() {
  pinMode(mercurioPin,INPUT); //configura o pino de módulo como entrada
  pinMode(ledPin, OUTPUT); //configura o pino do LED como
  pinMode(pinoBuzzer, OUTPUT); // Configura o pino do buzzer como saída
}

void loop() {
  int estado = digitalRead(mercurioPin); //lê o estado do módulo

  if (estado == LOW) { //se o interruptor estiver inclinado (ativa em LOW)
    digitalWrite(ledPin,HIGH); //acende o led
    digitalWrite(pinoBuzzer,HIGH); // Desliga o buzzer
    delay(1000); // Espera 1 segundo (1000 milissegundos)
  } else {
    digitalWrite(ledPin,LOW); //apaga o led
    digitalWrite(pinoBuzzer,LOW); // Desliga o buzzer
    delay(1000); // Espera 1 segundo (1000 milissegundos)
  }
}
