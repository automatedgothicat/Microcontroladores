#include <LiquidCrystal_I2C.h>

const int botaoProximo = 2;
const int botaoAnterior = 3;
const int botaoContinuar = 4;
const int pinoBuzzer = 5;
const int pinoDisplay = 6;
int equipes[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int pessoasvotaram = 0;
int i = 0;
int lastButtonProxState = HIGH;
int lastButtonAntState = HIGH;
int lastButtonContState = HIGH;
bool precisaAtualizar = true;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  pinMode(botaoProximo,INPUT_PULLUP);
  pinMode(botaoAnterior,INPUT_PULLUP);
  pinMode(botaoContinuar,INPUT_PULLUP);
  pinMode(pinoBuzzer,OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);//Posiciona o cursor na coluna 0, linha 0 (primeira linha)
  lcd.print("Escolha seu voto");//Escreve o texto desejado
  // put your main code here, to run repeatedly:
  delay(1000);
  lcd.clear();
}

void loop() {
  bool buttonProxState = digitalRead(botaoProximo);
  bool buttonAntState = digitalRead(botaoAnterior);
  bool buttonContState = digitalRead(botaoContinuar);

  if(lastButtonProxState == HIGH && buttonProxState == LOW){
    i++;
    if (i >= 8){
      i = 0;
    }

    lcd.clear();
    delay(50);
  }

  lastButtonProxState = buttonProxState;

  if(lastButtonAntState == HIGH && buttonAntState == LOW){
    i--;
    if (i <= 0 ){
      i = 7;
    }

    lcd.clear();
    delay(50);
  }

  lastButtonAntState = buttonAntState;

 if (lastButtonContState == HIGH && buttonContState == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Confirmar Equipe ");
    lcd.print(i + 1);
    lcd.setCursor(0, 1);
    lcd.print("Sim (OK) / Nao");

    delay(500);

    while (true) {
      if (digitalRead(botaoContinuar) == LOW) {
        lcd.clear();
        lcd.print("Voto Gravado!");
        digitalWrite(pinoBuzzer, HIGH);
        equipes[i]++;
        delay(200);
        digitalWrite(pinoBuzzer, LOW);
        delay(1500);
        break;
      }
      if (digitalRead(botaoProximo) == LOW || digitalRead(botaoAnterior) == LOW) {
        lcd.clear();
        lcd.print("Cancelado");
        delay(1000);
       
        break;
      }
    }
    if (pessoasvotaram >= 8){
          for (int j = 0; j < 8; j++) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("RESULTADO FINAL");
            lcd.setCursor(0, 1);
            lcd.print("Equipe " + String(j + 1) + ": " + String(equipes[j]) + " vts");
            delay(2500);
          }
        } else{
          pessoasvotaram++;
        }
    precisaAtualizar = true;
  }
  lastButtonContState = buttonContState;

  lcd.setCursor(0,0);
  lcd.print("Vote AGORA!:");
  lcd.setCursor(0,1);
  lcd.print("Equipe "+ String(i+1));
  delay(50);
}
