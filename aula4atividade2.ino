const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int buttonPin = 2;
int buttonState = HIGH;
int colorIndex = 0;


void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}


void loop(){
  buttonState = digitalRead(buttonPin);


  if(buttonState == LOW){
    colorIndex++;
    if (colorIndex > 6) {
      colorIndex = 0;
    }
    delay(500);
  }
  // Define a cor de acordo com o índice atual
  switch (colorIndex) {
    case 0: // Vermelho
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      delay(1000);
      break;


    case 1: // Verde
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);
      delay(1000);
      break;


    case 2: // Azul
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);
      delay(1000);
      break;


    case 3: // Amarelo (vermelho + verde)
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);
      delay(1000);
      break;


    case 4: // Ciano (verde + azul)
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, HIGH);
      delay(1000);
      break;


    case 5: // Magenta (vermelho + azul)
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);
      delay(1000);
      break;


    case 6: // Branco (todas as cores)
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, HIGH);
      delay(1000);
      break;
  }
}
