// foi utilizando esse tutorial que consegui fazer o interruptor funcionar e percebi que bastava trocar os pinos: https://arduinomodules.info/ky-027-magic-light-cup-module/

const int mercurioPin = 8; //pino de saída do módulo de mercúrio
const int ledPin = 9; //pino do LED indicador

void setup() {
  pinMode(mercurioPin,INPUT); //configura o pino de módulo como entrada
  pinMode(ledPin, OUTPUT); //configura o pino do LED como saída
}

void loop() {
  int estado = digitalRead(mercurioPin); //lê o estado do módulo

  if (estado == LOW) { //se o interruptor estiver inclinado (ativa em LOW)
    digitalWrite(ledPin,HIGH); //acende o led
  } else {
    digitalWrite(ledPin,LOW); //apaga o led
  }

  delay(100); //pequeno atraso para estabilidade
}
