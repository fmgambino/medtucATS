#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <WiFiManager.h>  // Librería WiFiManager

// Configuración Telegram
#define BOT_TOKEN "7458261818:AAG2F9ZODOJ6uNzfvP4Eysu6r4-d_PZO0QE"
#define CHANNEL_CHAT_ID "-1002244708158"  // Reemplaza con el chat_id del canal

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

// Intervalo de envío (10 segundos)
const long interval = 10000;
unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);

  // Usar WiFiManager para gestionar la conexión WiFi
  WiFiManager wm;
  
  // Intentar conectar automáticamente
  if (!wm.autoConnect("ATS_AP", "12345678")) {
    Serial.println("Fallo al conectar, reiniciando ESP32...");
    delay(3000);
    ESP.restart();
  }
  
  Serial.println("WiFi conectado exitosamente!");
  Serial.println(WiFi.localIP());

  // Configurar cliente seguro para Telegram
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT);

  // Inicializar generador de números aleatorios
  randomSeed(analogRead(0));
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Generar datos aleatorios
    float temperatura = random(200, 400) / 10.0; // Entre 20.0°C y 40.0°C
    float humedad = random(300, 900) / 10.0;      // Entre 30.0% y 90.0%
    int calidadAire = random(100, 500);           // Simular valor del MQ135
    bool generadorEncendido = random(0, 2);       // 0 o 1

    // Componer mensaje
    String estadoGenerador = generadorEncendido ? "Encendido" : "Apagado";
    String message = "Datos Sistema ATS MEDTUC (Simulados):\n";
    message += "Temperatura: " + String(temperatura, 1) + " °C\n";
    message += "Humedad: " + String(humedad, 1) + " %\n";
    message += "Calidad del Aire (MQ135): " + String(calidadAire) + " ppm\n";
    message += "Generador: " + estadoGenerador + "\n";
    message += "\nDev. for: Ing. Gambino";

    // Enviar mensaje a Telegram
    bot.sendMessage(CHANNEL_CHAT_ID, message, "");

    // Imprimir en el monitor serial
    Serial.println("Mensaje enviado al canal de Telegram:");
    Serial.println(message);
  }

  delay(100); // Pequeña pausa
}
