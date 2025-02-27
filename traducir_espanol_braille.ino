#include <Arduino.h>

// Mapa de Braille en formato Unicode
const char* brailleMap[26] = {
  "⠁", "⠃", "⠉", "⠙", "⠑", "⠋", "⠛", "⠓", "⠊", "⠚", 
  "⠅", "⠇", "⠍", "⠝", "⠕", "⠏", "⠟", "⠗", "⠎", "⠞", 
  "⠥", "⠧", "⠺", "⠭", "⠽", "⠵"
};

void setup() {
    Serial.begin(115200);
    Serial.println("Introduce un texto y presiona Enter:");
}

void loop() {
    if (Serial.available()) {
        String input = Serial.readStringUntil('\n'); // Leer hasta nueva línea
        input.toLowerCase(); // Convertir a minúsculas

        Serial.print("Español: ");
        Serial.println(input); // Mostrar el texto original

        Serial.print("Braille: ");
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (c >= 'a' && c <= 'z') {
                Serial.print(brailleMap[c - 'a']); // Convertir y mostrar Braille
            } else if (c == ' ') {
                Serial.print(" "); // Espacio
            } else {
                Serial.print("?"); // Caracter desconocido
            }
        }
        Serial.println();
    }
}
