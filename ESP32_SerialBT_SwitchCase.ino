#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define LED 2

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(LED,OUTPUT);
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
//    Serial.write(SerialBT.read());
    char command = SerialBT.read();
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
  } // end of SerialBT
  delay(20);
} // end of void loop
