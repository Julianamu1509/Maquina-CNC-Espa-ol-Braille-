#include <WiFi.h>  // Para ESP32 (Si usas ESP8266, cambia a <ESP8266WiFi.h>)

const char* ssid = "MURIEL";    
const char* password = "10285765";   

void setup() {
    Serial.begin(115200);
    Serial.println("\nIniciando...");

    WiFi.begin(ssid, password);
    Serial.println("Conectando a WiFi...");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\n Conectado a WiFi!");
    Serial.print(" Dirección IP: ");
    Serial.println(WiFi.localIP());
}

void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println(" Conectado a WiFi");
    } else {
        Serial.println(" Desconectado de WiFi");
    }
    delay(5000); // Se actualiza cada 5 segundos
}
