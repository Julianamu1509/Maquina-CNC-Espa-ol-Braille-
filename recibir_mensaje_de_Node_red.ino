#include <WiFi.h>
#include <WebServer.h> // Librería para servidor HTTP en ESP32

const char* ssid = "MURIEL"; 
const char* password = "10285765";
WebServer server(80); // Servidor HTTP en el puerto 80

void handlePost() {
    if (server.hasArg("plain")) { // Si hay datos en la solicitud POST
        String mensaje = server.arg("plain"); // Obtener el mensaje enviado
        Serial.println("Mensaje recibido: " + mensaje); // Mostrar en Monitor Serie
        server.send(200, "text/plain", "Mensaje recibido en ESP32");
    } else {
        server.send(400, "text/plain", "No se recibió mensaje");
    }
}

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConectado a WiFi!");
    server.on("/datos", HTTP_POST, handlePost); // Ruta para recibir datos desde Node-RED
    server.begin();
}

void loop() {
    server.handleClient();
}
