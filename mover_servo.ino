
#include <ESP32Servo.h>

Servo miServo;  // Crear objeto Servo
const int pinServo = 13;  // Cambia este pin según tu conexión

void setup() {
    miServo.attach(pinServo);  // Asignar el pin al servo
}

void loop() {
    // Mover de 0° a 180°
    for (int angulo = 0; angulo <= 180; angulo += 1) {
        miServo.write(angulo);
        delay(50);
    }

}

