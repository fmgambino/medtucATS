#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <WiFiManager.h>
#include <WebServer.h>
#include <SPIFFS.h>
#include <ESPmDNS.h>

// Configuración Telegram
#define BOT_TOKEN "7788186330:AAGoWXnz6N1r3EfzZHbD9nSuwC5rxXAMQhc"
#define CHANNEL_CHAT_ID "-1002244708158"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
WebServer server(80);

// Intervalos
const long sendDataInterval = 3600000; // Enviar datos cada hora
const long checkTelegramInterval = 5000; // Revisar comandos Telegram
unsigned long previousSendMillis = 0;
unsigned long previousTelegramMillis = 0;

// Funciones
void sendSensorData();
void checkTelegramCommands();
void setupServer();

void setup() {
  Serial.begin(115200);

  // WiFiManager para autoconexión
  WiFiManager wm;
  if (!wm.autoConnect("ATS_AP_WiFi", "12345678")) {
    Serial.println("Fallo al conectar, reiniciando ESP32...");
    delay(3000);
    ESP.restart();
  }

  Serial.println("WiFi conectado exitosamente!");
  Serial.println(WiFi.localIP());

  // Inicializar SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("❌ Error montando SPIFFS");
    return;
  }
  Serial.println("✅ SPIFFS montado correctamente");

  // Inicializar mDNS
  if (!MDNS.begin("ats")) {
    Serial.println("❌ Error configurando mDNS");
  } else {
    Serial.println("✅ mDNS iniciado, accede a: http://ats.local");
  }

  // Configurar HTTPS para Telegram
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT);

  randomSeed(esp_random());

  // Limpiar mensajes antiguos de Telegram
  Serial.println("Limpiando mensajes pendientes...");
  bot.getUpdates(0);

  // Iniciar servidor web
  setupServer();
  server.begin();
  Serial.println("✅ Servidor HTTP iniciado");
}

void loop() {
  unsigned long currentMillis = millis();

  // Revisar comandos Telegram
  if (currentMillis - previousTelegramMillis >= checkTelegramInterval) {
    previousTelegramMillis = currentMillis;
    checkTelegramCommands();
  }

  // Enviar datos periódicamente
  if (currentMillis - previousSendMillis >= sendDataInterval) {
    previousSendMillis = currentMillis;
    sendSensorData();
  }

  server.handleClient(); // Atender peticiones HTTP

  delay(10);
}

void sendSensorData() {
  float temperatura = random(200, 400) / 10.0;
  float humedad = random(300, 900) / 10.0;
  int calidadAire = random(100, 500);
  float nafta = random(0, 100) / 10.0;
  bool generadorEncendido = random(0, 2);

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

    bot.last_message_received = bot.messages[numNewMessages-1].update_id;
    numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  }
}

void setupServer() {
  // Página principal
  server.on("/", HTTP_GET, []() {
    File file = SPIFFS.open("/index.html", "r");
    if (!file) {
      server.send(500, "text/plain", "Error abriendo index.html");
      return;
    }
    server.streamFile(file, "text/html");
    file.close();
  });

  // Página de login
  server.on("/login", HTTP_GET, []() {
    File file = SPIFFS.open("/login.html", "r");
    if (!file) {
      server.send(500, "text/plain", "Error abriendo login.html");
      return;
    }
    server.streamFile(file, "text/html");
    file.close();
  });

  // Archivos CSS
  server.on("/styles.css", HTTP_GET, []() {
    File file = SPIFFS.open("/styles.css", "r");
    if (!file) {
      server.send(404, "text/plain", "No encontrado styles.css");
      return;
    }
    server.streamFile(file, "text/css");
    file.close();
  });

  // Archivos JS
  server.on("/script.js", HTTP_GET, []() {
    File file = SPIFFS.open("/script.js", "r");
    if (!file) {
      server.send(404, "text/plain", "No encontrado script.js");
      return;
    }
    server.streamFile(file, "application/javascript");
    file.close();
  });

  // Logo para modo claro
  server.on("/logo_light.png", HTTP_GET, []() {
    File file = SPIFFS.open("/logo_light.png", "r");
    if (!file) {
      server.send(404, "text/plain", "No encontrado logo_light.png");
      return;
    }
    server.streamFile(file, "image/png");
    file.close();
  });

  // Logo para modo oscuro
  server.on("/logo_dark.png", HTTP_GET, []() {
    File file = SPIFFS.open("/logo_dark.png", "r");
    if (!file) {
      server.send(404, "text/plain", "No encontrado logo_dark.png");
      return;
    }
    server.streamFile(file, "image/png");
    file.close();
  });

  // ⚡ API para obtener datos en tiempo real
  server.on("/data", HTTP_GET, []() {
    // Simulamos datos como en tu función sendSensorData()
    float temperatura = random(200, 400) / 10.0;
    float humedad = random(300, 900) / 10.0;
    int calidadAire = random(100, 500);
    float nafta = random(0, 100) / 10.0;
    bool generadorEncendido = random(0, 2);

    String json = "{";
    json += "\"temperatura\":" + String(temperatura, 1) + ",";
    json += "\"humedad\":" + String(humedad, 1) + ",";
    json += "\"calidadAire\":" + String(calidadAire) + ",";
    json += "\"nafta\":" + String(nafta, 1) + ",";
    json += "\"generador\":" + String(generadorEncendido ? "true" : "false");
    json += "}";

    server.send(200, "application/json", json);
  });

  // 404 Not Found
  server.onNotFound([]() {
    server.send(404, "text/plain", "Página no encontrada");
  });
}
