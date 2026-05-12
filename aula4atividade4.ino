// Definição dos pinos do LED RGB
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;


// Definição do pino do botão
const int buttonPin = 2;
const int button2Pin = 3;


// Variável para armazenar o estado atual do botão
int buttonState = HIGH;
int lastButtonState = HIGH;
int button2State = HIGH;
int lastButton2State = HIGH;


// Variável para controlar a cor atual
int colorIndex = 0;


void setup() {
  // Configura os pinos do LED como saída
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);


  // Configura o botão com resistor interno (INPUT_PULLUP)
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
}


void loop() {
  // Lê o estado atual do botão
  buttonState = digitalRead(buttonPin);
  button2State = digitalRead(button2Pin);


  // Verifica se o botão foi pressionado (transição de HIGH para LOW)
  if (lastButtonState == HIGH && buttonState == LOW) {
   
    // Avança para a próxima cor
    colorIndex++;


    // Se passar da última cor, volta para o início
    if (colorIndex > 6) {
      colorIndex = 0;
    }


    // Pequeno delay para evitar efeito de bouncing (debounce simples)
    delay(200);
  }
  if (lastButton2State == HIGH && button2State == LOW) {
   
    // Avança para a próxima cor
    colorIndex--;


    // Se passar da última cor, volta para o início
    if (colorIndex < 0) {
      colorIndex = 6;
    }


    // Pequeno delay para evitar efeito de bouncing (debounce simples)
    delay(200);
  }


  // Atualiza o estado anterior do botão
  lastButtonState = buttonState;
  //int j = 255;
  for (int i = 0; i <= 255; i += 5){
    // -= 5;
    // Define a cor de acordo com o índice atual
    switch (colorIndex) {


      case 0: // Vermelho
        analogWrite(redPin,i);
        analogWrite(greenPin,0);
        analogWrite(bluePin,0);
        delay(50);
        break;


      case 1: // Verde
        digitalWrite(redPin, 0);
        digitalWrite(greenPin, i);
        digitalWrite(bluePin, 0);
        delay(50);
        break;


      case 2: // Azul
        digitalWrite(redPin, 0);
        digitalWrite(greenPin, 0);
        digitalWrite(bluePin, i);
        delay(50);
        break;


      case 3: // Amarelo (vermelho + verde)
        digitalWrite(redPin, i);
        digitalWrite(greenPin, i);
        digitalWrite(bluePin, 0);
        delay(50);
        break;


      case 4: // Ciano (verde + azul)
        digitalWrite(redPin, 0);
        digitalWrite(greenPin, i);
        digitalWrite(bluePin, i);
        delay(50);
        break;


      case 5: // Magenta (vermelho + azul)
        digitalWrite(redPin, i);
        digitalWrite(greenPin, 0);
        digitalWrite(bluePin, i);
        delay(50);
        break;


      case 6: // Branco (todas as cores)
        digitalWrite(redPin, i);
        digitalWrite(greenPin, i);
        digitalWrite(bluePin, i);
        delay(50);
        break;
    }
  }
}
