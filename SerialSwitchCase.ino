#define LED 2

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
  pinMode(LED,OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    switch(command){
      case 'u':
      Serial.println("Up");
      break;

      case 'd':
      Serial.println("Down");
      break;

      case 'l':
      Serial.println("Left");
      break;

      case 'r':
      Serial.println("Right");
      break;

      case 'z':
      Serial.println("LED ON");
      digitalWrite(LED,HIGH);
      break;

      case 'y':
      Serial.println("LED OFF");
      digitalWrite(LED,LOW);
      break;
    } // end of switch
  } // end of Serial
  delay(20);
} // end of void loop
