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
int ultimaCadera;
int ultimaHombro;
int ultimaCodo;
int ultimaMuneca;
int ultimaPinza; 
   
int ang;
int aceleracionCadera = 20;
int aceleracionHombro = 20;
int aceleracionCodo = 20;
int aceleracionMuneca = 20;
int aceleracionPinza = 20;

void setup() {
  //iniciamos el acomunicacion serial con el controlador
  Serial.begin(9600);
  borrarSerial();
  reiniciarPosiciones();
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
    Serial.println(inputUtil);
    delay(20);
    borrarSerial();

    if (inputUtil == int(1)) {
      ang = ultimaCadera - aceleracionCadera;
      moverCadera(ang);
    }
    if (inputUtil == (2)) {
      ang = ultimaCadera + aceleracionCadera;
      moverCadera(ang);
    }
    if (inputUtil == (3)) {
      ang = ultimaHombro - aceleracionHombro;
      moverHombro(ang);
    }
    if (inputUtil == (4)) {
      ang = ultimaHombro + aceleracionHombro;
      moverHombro(ang);
    }
    if (inputUtil == (5)) {
      ang = ultimaCodo - aceleracionCodo;
      moverCodo(ang);
    }
    if (inputUtil == (6)) {
      ang = ultimaCodo + aceleracionCodo;
      moverCodo(ang);
    }
    if (inputUtil == (7)) {
      ang = ultimaMuneca - aceleracionMuneca;
      moverMuneca(ang);
    }
    if (inputUtil == (8)) {
      ang = ultimaMuneca + aceleracionMuneca;
      moverMuneca(ang);
    }
    if (inputUtil == (9)) {
      ang = ultimaPinza + aceleracionPinza;
      moverPinza(ang);
    }
    if (inputUtil == int(0)) {
      ang = ultimaPinza - aceleracionPinza;
      moverPinza(ang);
    }
    if (inputUtil == int(10)) {
      moverPinza(0);
    }
  }
}

void moverCadera(int angulo){
  motor.attach(44);
  delay(20);
  motor.write(angulo);
  delay(2000);
  ultimaPinza = angulo;
  motor.detach();
}

void moverHombro(int angulo){
  motor.attach(45);
  delay(20);
  motor.write(angulo);
  delay(2000);
  ultimaHombro = angulo;
  motor.detach();
}

void moverCodo(int angulo){
  motor.attach(46);
  delay(20);
  motor.write(angulo);
  delay(2000);
  ultimaCodo = angulo;
  motor.detach();
}

void moverMuneca(int angulo){
  motor.attach(47);
  delay(20);
  motor.write(angulo);
  delay(2000);
  ultimaMuneca = angulo;
  motor.detach();
}

void moverPinza(int angulo){
  motor.attach(48);
  delay(20);
  motor.write(angulo);
  delay(2000);
  ultimaPinza = angulo;
  motor.detach();
}


void reiniciarPosiciones(){
  ultimaCadera = 90;
  ultimaHombro = 0;
  ultimaCodo = 0;
  ultimaMuneca = 0;
  ultimaPinza = 0; 
  //moverCadera(ultimaCadera);
  //moverHombro(ultimaHombro);
  moverCodo(ultimaCodo);
  //moverMuneca(ultimaMuneca);
  moverPinza(ultimaPinza);
  
}

void borrarSerial() {
  Serial.flush();
  while (Serial.available()) {
    Serial.read();
  }
}
