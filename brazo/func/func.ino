/* fun por que es divertido mover motores wiii
 *  by daniel velez y santiquiroz
 *  version 0.0.1
*/

#include <Servo.h>

Servo motor;

boolean primera = true;
String input ;
int inputUtil; 
int pos = 0;    
void setup() {
  //iniciamos el acomunicacion serial con el controlador
  Serial.begin(9600);
  borrarSerial();
}

void loop() {
  /* 0 significa subir hombro
   *  1 significa bajar hombro
   *  2 significa abrir pinza 
   *  3 significa cerrar pinza
  */
  if (Serial.available() > 0) {
    input = Serial.readString();
    inputUtil = input.toInt();


    if (inputUtil == 0) {
      borrarSerial();
      moverHombro(0);
      borrarSerial();
    }
    else if (inputUtil == 1) {
      borrarSerial();
      moverHombro(-40);
      borrarSerial();
    }
    else if (inputUtil == 2) {
        borrarSerial();
        moverPinza(60);
        borrarSerial();
    }
    else if (inputUtil == 3) {
        borrarSerial();
        moverPinza(0);
        borrarSerial();
    }
    else {
      Serial.println("error");
    }

    borrarSerial();
  }
}

void moverHombro(int angulo){
  motor.attach(44);
  delay(20);
  motor.write(angulo);
  delay(2000);
  motor.detach();
}

void moverPinza(int angulo){
  motor.attach(47);
  delay(20);
  motor.write(angulo);
  delay(2000);
  motor.detach();
}


void borrarSerial() {
  Serial.flush();
  while (Serial.available()) {
    Serial.read();
  }
}
