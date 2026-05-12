#include <RTClib.h>

int vermelho = 10;
int amarelo = 9;
int verde = 8;
int botao = 12;
// nomeia as saídas de acordo com as cores
 
void setup() {
  Serial.begin(9600);
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  } // inicia serial e procura módulo rtc


  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  } //seta o tempo


  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(botao, OUTPUT);


  digitalWrite(verde,HIGH); //inicia verde ligado
  digitalWrite(vermelho,LOW); //inicia vermelho desligado
  digitalWrite(amarelo,LOW); //inicia amarelo desligado
}
// define o pin de saída pelas variáveis


void loop() {
  DateTime now = rtc.now(); //recebe o tempo atual
  if (digitalRead(botao) == HIGH) {
    // esperamos um pouco antes de começar a lógica
    delay(2000);
    semaforo();
  }
  delay(1000); //força o loop a atualizar a cada segundo
}


void semaforo() {


digitalWrite(verde,LOW); //desliga verde
digitalWrite(amarelo,high); //liga amarelo


if(now.hour >= 11){
  if(now.hour <= 13){
    delay(5000);
  }
} else{
  delay(2000); //espera 2 segundos
}


digitalWrite(amarelo,LOW); //desliga amarelo
digitalWrite(vermelho,HIGH); //liga vermelho


if(now.hour >= 11){
  if(now.hour <= 13){
    delay(8000);
  }
} else{
  delay(5000); //espera 5 segundos
}


digitalWrite(vermelho,LOW); //desliga o vermelho
digitalWrite(verde,HIGH); //liga verde


if(now.hour >= 11){
  if(now.hour <= 13){
    delay(8000);
  }
} else{
  delay(5000); //espera 5 segundos
}


}
