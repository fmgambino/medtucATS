#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <WiFiManager.h>
#include <WebServer.h>
#include <SPIFFS.h>
#include <ESPmDNS.h>

#define BOT_TOKEN "7788186330:AAGoWXnz6N1r3EfzZHbD9nSuwC5rxXAMQhc"
#define CHANNEL_CHAT_ID "-1002244708158"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
WebServer server(80);

unsigned long sendDataInterval = 3600000; // valor por defecto: 1 hora
const unsigned long checkTelegramInterval = 5000;
unsigned long previousSendMillis = 0;
unsigned long previousTelegramMillis = 0;

unsigned int rebootCount = 0;
String lastBootTime = "";

void sendSensorData();
void checkTelegramCommands();
void setupServer();
void loadIntervalFromFile();
void saveIntervalToFile(unsigned long savedValue, unsigned long currentValue);
void saveRebootInfo(); // Guardados de Reinicios ESP32
void loadRebootInfo(); // Cargar Info Reinicios ESP32
void waitForTimeSync(); // Funcion de espera NTP

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

  if (!SPIFFS.begin(true)) {
    Serial.println("❌ Error montando SPIFFS");
    return;
  }
  Serial.println("✅ SPIFFS montado correctamente");

  loadIntervalFromFile(); // cargar intervalo desde archivo

  configTime(-3 * 3600, 0, "pool.ntp.org", "time.nist.gov"); // zona horaria Argentina
  waitForTimeSync();  // <-- Agregar esto después de configTime
  delay(1000); // esperar un poco para sincronización
  loadRebootInfo(); // leer y actualizar reinicios

  if (!MDNS.begin("ats")) {
    Serial.println("❌ Error configurando mDNS");
  } else {
    Serial.println("✅ mDNS iniciado, accede a: http://ats.local");
  }

  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  randomSeed(esp_random());
  bot.getUpdates(0); // limpiar mensajes pendientes
  setupServer();
  server.begin();
  Serial.println("✅ Servidor HTTP iniciado");
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousTelegramMillis >= checkTelegramInterval) {
    previousTelegramMillis = currentMillis;
    checkTelegramCommands();
  }

  if (sendDataInterval > 0 && currentMillis - previousSendMillis >= sendDataInterval) {
    previousSendMillis = currentMillis;
    sendSensorData();
  }

  server.handleClient();
  delay(10);
}

void sendSensorData() {
  float temperatura = random(200, 400) / 10.0;
  float humedad = random(300, 900) / 10.0;
  int calidadAire = random(100, 500);
  float nafta = random(90, 800) / 10.0;
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

  if (sent) Serial.println("✅ Mensaje enviado correctamente.");
  else Serial.println("❌ Error enviando mensaje.");
}

void checkTelegramCommands() {
  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

  while (numNewMessages > 0) {
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
      else if (text.startsWith("/setInterval ")) {
        String param = text.substring(13);
        param.trim();
      
        if (param == "off") {
          saveIntervalToFile(sendDataInterval, 0); // guardar el último y poner en 0
          sendDataInterval = 0;
          bot.sendMessage(chat_id, "⏸️ Envío automático deshabilitado.", "");
        } 
        else if (param == "on") {
          File file = SPIFFS.open("/interval.txt", "r");
          if (!file) {
            bot.sendMessage(chat_id, "❌ No se encontró configuración previa.", "");
          } else {
            String line = file.readStringUntil('\n');
            file.close();
            int sep = line.indexOf('|');
            if (sep != -1) {
              unsigned long prev = line.substring(0, sep).toInt();
              if (prev >= 5000 && prev <= 86400000) {
                sendDataInterval = prev;
                saveIntervalToFile(prev, prev);
                bot.sendMessage(chat_id, "▶️ Envío automático reanudado cada " + String(prev / 1000) + " seg.", "");
              } else {
                bot.sendMessage(chat_id, "❌ Valor anterior inválido.", "");
              }
            }
          }
        }
        else {
          int nuevoIntervalo = param.toInt();
          if (nuevoIntervalo >= 5 && nuevoIntervalo <= 86400) {
            sendDataInterval = nuevoIntervalo * 1000UL;
            saveIntervalToFile(sendDataInterval, sendDataInterval);
            bot.sendMessage(chat_id, "⏱️ Intervalo actualizado a " + String(nuevoIntervalo) + " segundos.", "");
          } else {
            bot.sendMessage(chat_id, "❌ Valor inválido. Usa un número entre 60 y 86400, o 'off/on'.", "");
          }
        }
      }
      
      else if (text == "/getInterval") {
        if (sendDataInterval == 0) {
          bot.sendMessage(chat_id, "⏸️ El envío automático está *deshabilitado*.", "Markdown");
        } else {
          bot.sendMessage(chat_id, "📊 Intervalo actual de envío automático: *" + String(sendDataInterval / 1000) + "* segundos.", "Markdown");
        }
      }

      else if (text == "/status") {
        String msg = "ℹ️ *Estado del sistema:*\n\n";
        msg += (sendDataInterval == 0)
                 ? "⏸️ Envío automático: *Deshabilitado*\n"
                 : "▶️ Envío automático cada *" + String(sendDataInterval / 1000) + "* seg\n";
        msg += "♻️ Reinicios desde la última vez: *" + String(rebootCount) + "*\n";
      
        time_t now = time(nullptr);
        if (now < 1000000000) {
          msg += "🕒 *Sincronización NTP pendiente...*\n";
          msg += "⌛ Esperando servidor de fecha y hora...\n";
        } else {
          msg += "🕒 Último reinicio: `" + lastBootTime + "`\n";
        }
      
        bot.sendMessage(chat_id, msg, "Markdown");
      }        
      
      else if (text == "/start") {
        String menu = "📋 *Comandos disponibles:*\n\n";
        menu += "🛰️ `/DataSensores` - Obtener datos actuales\n";
        menu += "♻️ `/APreset` - Borrar configuración WiFi y reiniciar\n";
        menu += "⏱️ `/setInterval [segundos]` - Cambiar intervalo automático\n";
        menu += "ℹ️ `/status` - Ver estado general del sistema\n";
        menu += "🏁 `/start` - Mostrar este menú\n";
        bot.sendMessage(chat_id, menu, "Markdown");
      } 
      else {
        bot.sendMessage(chat_id, "❓ Comando no reconocido. Usa `/start`.", "Markdown");
      }
    }

    bot.last_message_received = bot.messages[numNewMessages - 1].update_id;
    numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  }
}

void loadIntervalFromFile() {
  File file = SPIFFS.open("/interval.txt", "r");
  if (!file) {
    Serial.println("⚠️ No se encontró interval.txt, usando valor por defecto.");
    sendDataInterval = 3600000;
    return;
  }

  String line = file.readStringUntil('\n');
  file.close();

  int sepIndex = line.indexOf('|');
  if (sepIndex == -1) {
    Serial.println("⚠️ Formato inválido en interval.txt");
    sendDataInterval = 3600000;
    return;
  }

  String saved = line.substring(0, sepIndex);
  String current = line.substring(sepIndex + 1);

  unsigned long savedVal = saved.toInt();
  unsigned long currentVal = current.toInt();

  sendDataInterval = currentVal;
  if (sendDataInterval == 0) {
    Serial.println("⏸️ Envío automático deshabilitado.");
  } else {
    Serial.println("✅ Intervalo activo: " + String(sendDataInterval / 1000) + " seg");
  }
}

void saveIntervalToFile(unsigned long savedValue, unsigned long currentValue) {
  File file = SPIFFS.open("/interval.txt", "w");
  if (!file) {
    Serial.println("❌ Error escribiendo interval.txt");
    return;
  }
  file.println(String(savedValue) + "|" + String(currentValue));
  file.close();
  Serial.println("💾 Intervalo guardado. Actual: " + String(currentValue / 1000));
}

// El resto de setupServer() queda igual sin cambios

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
    float nafta = random(90, 800) / 10.0;
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

void saveRebootInfo() {
  File file = SPIFFS.open("/reboots.txt", "w");
  if (!file) {
    Serial.println("❌ Error escribiendo reboots.txt");
    return;
  }

  time_t now = time(nullptr);
  struct tm* timeinfo = localtime(&now);
  char buf[64];
  strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", timeinfo);

  file.println(String(rebootCount));
  file.println(String(buf));
  file.close();

  lastBootTime = buf;
}

void loadRebootInfo() {
  File file = SPIFFS.open("/reboots.txt", "r");
  if (!file) {
    rebootCount = 1; // primera vez
    time_t now = time(nullptr);
    struct tm* timeinfo = localtime(&now);
    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", timeinfo);
    lastBootTime = buf;
    saveRebootInfo();
    return;
  }

  rebootCount = file.readStringUntil('\n').toInt();
  lastBootTime = file.readStringUntil('\n');
  file.close();

  rebootCount++;
  saveRebootInfo();  // guardamos nuevamente con el nuevo contador y fecha actual
}

void waitForTimeSync() {
  Serial.print("⏳ Esperando sincronización NTP...");
  time_t now = time(nullptr);
  int retries = 0;
  while (now < 1000000000 && retries < 20) { // menos que el año 2001
    delay(500);
    Serial.print(".");
    now = time(nullptr);
    retries++;
  }
  Serial.println();
  if (now < 1000000000) {
    Serial.println("⚠️ No se pudo sincronizar la hora.");
  } else {
    Serial.println("✅ Hora sincronizada.");
  }
}
