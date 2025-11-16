// Constants
const int dotDelay = 200;
const int ledPin = 13;

char* letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

char* numbers[] = {
  "-----", ".----", "..---", "...--", "....-",
  ".....", "-....", "--...", "---..", "----."
};

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char ch;
  if(Serial.available() > 0){
    ch = Serial.read(); // Reading the serial port input from the user
    if(ch >= 'a' && ch <= 'z'){
      flashSequence(letters[ch - 'a']);
    }
    else if(ch >= 'A' && ch <= 'Z'){
      flashSequence(letters[ch - 'A']);
    }
    else if(ch >= '0' && ch <= '9'){
      flashSequence(letters[ch - '0']);
    }
    else if(ch == ' '){
      delay(dotDelay * 4);
    }
  }
}

/**
  Flash sequence function.
  It reads each character from the string until
  the end of line character (\0)
*/
void flashSequence(char* sequence){
  int i = 0;
  
  while(sequence[i] != '\0'){
    flashDotOrDash(sequence[i]);
    i++;
  }

  delay(dotDelay * 3);
}

/**
  Flash function depending on if it is a dot or a dash
*/
void flashDotOrDash(char dotOrDash){
  digitalWrite(ledPin, HIGH);

  if(dotOrDash == '.'){
    delay(dotDelay);
  }
  else{
    delay(dotDelay * 3);
  }

  digitalWrite(ledPin, LOW);
}
