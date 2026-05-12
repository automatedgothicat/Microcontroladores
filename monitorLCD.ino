#include <LiquidCrystal_I2C.h>


// Inicializa o display no endereço 0x27 (padrão) com 16 colunas e 2 linhas
LiquidCrystal_I2C lcd(0x27, 16, 2);


#define sensorPin A0 // Define que o Pino de sinal do sensor deve ser conectado a entrada analógica A0
int LeituraSensor;   // Variável que irá armazenar os valores de leitura do sensor
int Pulso = 550;     // Valor analógico limiar para ser considerado um Pulso


void setup() {
  Serial.begin(9600);      // Inicia a comunicação serial a 9600 bps


  // Inicialização e configuração do Display LCD
  lcd.init();
  lcd.clear();
  lcd.backlight();
 
  // Exibe uma mensagem estática na primeira linha
  lcd.setCursor(0, 0);
  lcd.print("Monitor Cardiaco");
}


void loop() {
  LeituraSensor = analogRead(sensorPin); // Realiza a leitura analógica do sensor
  Serial.println(LeituraSensor);         // Mostra os valores no monitor serial
 
  // Verifica se o valor lido ultrapassa o limiar.
  // Nota: Mantive > 10 conforme seu código, mas caso haja muito ruído,
  // experimente trocar por (LeituraSensor > Pulso) usando o limiar de 550.
  if (LeituraSensor > 671) {
   
    // Mostra o sinal visual no LCD
    lcd.setCursor(0, 1);
    lcd.print("bpm: " + String(LeituraSensor/10) + " ");
    delay(500);
  } else {
    //lcd.print(" else ");
   
    // Apaga a mensagem de pulso substituindo por espaços em branco
    // (Isso evita o uso do lcd.clear() no loop, que faz a tela "piscar")
    lcd.setCursor(0, 1);
    lcd.print(":D       ");
  }
 
  delay(10); // Tempo de espera entre as leituras
}
