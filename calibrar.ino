#include<SoftwareSerial.h>
#include <Servo.h>
#include <string.h>

#define TxD 3
#define RxD 2
#define LED_PIN1 13
#define LED_PIN2 12
#define LED_PIN3 11
#define LED_PIN4 10
#define LED_PIN5 9
#define LED_PIN6 8

SoftwareSerial bluetoothSerial(TxD, RxD);

char c;
String enable;
int counter;
Servo servo_motor1;
Servo servo_motor2; 
Servo servo_motor3; 
Servo servo_motor4; 
Servo servo_motor5; 
Servo servo_motor6; 

void setup() {
  bluetoothSerial.begin(9600);
  Serial.begin(9600);
  servo_motor1.attach(LED_PIN1);
  servo_motor2.attach(LED_PIN2);
  servo_motor3.attach(LED_PIN3);
  servo_motor4.attach(LED_PIN4);
  servo_motor5.attach(LED_PIN5);
  servo_motor6.attach(LED_PIN6);
  counter = 0;
}

void loop() {
  if (bluetoothSerial.available()) {
    c = bluetoothSerial.read();
     if ((c == '1' || c == '0') && counter < 6) {
      if (counter == 0 && c == '1') {
        servo_motor1.write(160);
      } else if (counter == 1 && c == '1') {
        servo_motor2.write(140);
      } else if (counter == 2 && c == '1') {
        servo_motor3.write(160);
      } else if (counter == 3 && c == '1') {
        servo_motor4.write(140);
      } else if (counter == 4 && c == '1') {
        servo_motor5.write(170);
      } else if (counter == 5 && c == '1') {
        servo_motor6.write(140);
      }
      Serial.println("Printei o 1");
      Serial.println(c);
      
      counter = counter + 1;

      if (counter == 6) {
        Serial.println("Cheguei a 6, estou zerando após 1 segundo.");
        delay(1000);
        disableAllLEDS();
      }
    } else if (counter > 6 || c == '9') {
      Serial.println("Printei o 2");
      Serial.println(c);
      delay(1000);
      disableAllLEDS();
    }

    Serial.print("counter");
    Serial.println(counter);
  }
}

void disableAllLEDS() {
  servo_motor1.write(130);
  servo_motor2.write(110);
  servo_motor3.write(130);
  servo_motor4.write(120);
  servo_motor5.write(140);
  servo_motor6.write(110);
  counter = 0;
}
