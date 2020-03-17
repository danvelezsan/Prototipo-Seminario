#include <Servo.h>
Servo motor2;

void setup() {
 
}

void loop() {
  motor2.attach(48);
  motor2.write(0);
  delay(2000);
  motor2.write(90);
  delay(2000);
}
