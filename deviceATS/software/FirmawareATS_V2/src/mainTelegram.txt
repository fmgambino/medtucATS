#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <WiFiManager.h>

// Configuración Telegram
#define BOT_TOKEN "7788186330:AAGoWXnz6N1r3EfzZHbD9nSuwC5rxXAMQhc"
#define CHANNEL_CHAT_ID "-1002244708158"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

// Intervalos
const long sendDataInterval = 3600000; // Intervalo para enviar datos cada hora (3,600,000 milisegundos)
const long checkTelegramInterval = 5000; // Intervalo para revisar comandos
unsigned long previousSendMillis = 0;
unsigned long previousTelegramMillis = 0;

// Funciones que declaramos
void sendSensorData();
void checkTelegramCommands();

void setup() {
  Serial.begin(115200);

  WiFiManager wm;
  if (!wm.autoConnect("ATS_AP_WiFi", "12345678")) {
    Serial.println("Fallo al conectar, reiniciando ESP32...");
    delay(3000);
    ESP.restart();
  }
  
  Serial.println("WiFi conectado exitosamente!");
  Serial.println(WiFi.localIP());

  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT);

  randomSeed(esp_random());

  // ⛔ Limpiar todos los mensajes viejos apenas conecta
  Serial.println("Limpiando mensajes pendientes...");
  bot.getUpdates(0);  // <<< AQUI se descartan mensajes anteriores
}

void loop() {
  unsigned long currentMillis = millis();

  // Revisar comandos Telegram
  if (currentMillis - previousTelegramMillis >= checkTelegramInterval) {
    previousTelegramMillis = currentMillis;
    checkTelegramCommands(); // Revisar si hay comandos nuevos
  }

  // Enviar datos periódicamente si no se recibe un comando "DataSensores"
  if (currentMillis - previousSendMillis >= sendDataInterval) {
    previousSendMillis = currentMillis;
    sendSensorData(); // Enviar datos cada hora
  }

  delay(100);
}

void sendSensorData() {
  // Datos simulados
  float temperatura = random(200, 400) / 10.0; // Entre 20.0°C y 40.0°C
  float humedad = random(300, 900) / 10.0;      // Entre 30.0% y 90.0%
  int calidadAire = random(100, 500);           // Simular valor del MQ135
  float nafta = random(0, 100) / 10.0;          // Simular nivel de combustible
  bool generadorEncendido = random(0, 2);       // 0 o 1

  // Componer mensaje
  String estadoGenerador = generadorEncendido ? "Encendido" : "Apagado";
  String message = "📡 *Datos Sistema ATS MEDTUC (Simulados)*:\n";
  message += "🌡️ Temperatura: " + String(temperatura, 1) + " °C\n";
  message += "💧 Humedad: " + String(humedad, 1) + " %\n";
  message += "🫧 Calidad del Aire: " + String(calidadAire) + " ppm\n";
  message += "⚡ Generador: " + estadoGenerador + "\n";
  message += "⛽ Nivel Nafta: " + String(nafta, 1) + " %\n";

  if (nafta <= 30) {
    message += "\n🚨 *ALERTA:* NIVEL BAJO DE COMBUSTIBLE!";
  }

  message += "\n\n👨‍💻 Dev. for: Ing. Gambino";

  bool sent = bot.sendMessage(CHANNEL_CHAT_ID, message, "Markdown");
  
  if (sent) {
    Serial.println("✅ Mensaje enviado correctamente al canal de Telegram.");
  } else {
    Serial.println("❌ Error enviando mensaje a Telegram.");
    if (!secured_client.connected()) {
      Serial.println("🔴 Error de conexión HTTPS. Verifique el certificado y la red.");
    }
  }
}

void checkTelegramCommands() {
  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

  while (numNewMessages > 0) {
    Serial.println("Mensaje recibido!");

    for (int i = 0; i < numNewMessages; i++) {
      String text = bot.messages[i].text;
      String chat_id = bot.messages[i].chat_id;

      Serial.print("Texto recibido: ");
      Serial.println(text);

      if (text == "/DataSensores") {
        sendSensorData();
      } 
      else if (text == "/APreset") {
        bot.sendMessage(chat_id, "🔄 Reiniciando y borrando WiFi...", "");
        delay(2000);
        WiFiManager wm;
        wm.resetSettings();
        ESP.restart();
      }
      else if (text == "/start") {
        String menu = "📋 *Comandos disponibles:*\n\n";
        menu += "🛰️ `/DataSensores` - Obtener datos actuales de los sensores.\n";
        menu += "♻️ `/APreset` - Borrar configuración WiFi y reiniciar.\n";
        menu += "🏁 `/start` - Mostrar este menú.\n";

        bot.sendMessage(chat_id, menu, "Markdown");
      }
      else {
        bot.sendMessage(chat_id, "❓ Comando no reconocido. Escribe `/start` para ver opciones.", "Markdown");
      }
    }

    // 🔥 IMPORTANTE: Actualizar last_message_received al último mensaje recibido
    bot.last_message_received = bot.messages[numNewMessages-1].update_id;

    // Buscar nuevos mensajes después de procesar
    numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  }
}
