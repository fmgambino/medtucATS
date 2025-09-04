#include <Arduino.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif

#include <WiFiManager.h>
#include <Separador.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>

#include <SPI.h>
#include <Wire.h>             // libreria para bus I2C
#include <Adafruit_GFX.h>     // libreria para pantallas graficas
#include <Adafruit_SSD1306.h> // libreria para controlador SSD1306
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3c // inicializa con I2C en la direccion 0x3C
#define ANCHO 128        // reemplaza ocurrencia de ANCHO por 128
#define ALTO 64          // reemplaza ocurrencia de ALTO por 64

//#define OLED_RESET 4      // necesario por la libreria pero no usado
// Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);  // crea objeto OLED SSD1306
#define OLED_RESET -1                                                     // necesario por la libreria pero no usado
Adafruit_SH1106G oled = Adafruit_SH1106G(ANCHO, ALTO, &Wire, OLED_RESET); // crea objeto OLED SH1106

#define LOGO16_GLCD_HEIGHT 32
#define LOGO16_GLCD_WIDTH 32

const unsigned char PROGMEM logo_hydrocrop[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x81, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x01, 0xC0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x01, 0xE0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x0F, 0xF0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x0F, 0xF0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x1F, 0xF0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x3F, 0xE0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x3F, 0xC0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x3F, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x3F, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x0C, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x8F, 0xC0, 0xFC, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x8F, 0xF3, 0xFC, 0x60, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x8F, 0xFF, 0xFC, 0x60, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x8F, 0xFF, 0xFC, 0x60, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x87, 0xFF, 0xF8, 0x60, 0x00, 0x0D, 0xC0, 0xF1, 0xF0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x87, 0xFF, 0xF8, 0x60, 0x00, 0x0F, 0xE1, 0xF9, 0xF0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x81, 0xFF, 0xE0, 0x60, 0x00, 0x0E, 0x73, 0x0D, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x0C, 0x00, 0x60, 0x00, 0x0C, 0x33, 0x0D, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x0C, 0x00, 0x60, 0x00, 0x0C, 0x33, 0xFD, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x0C, 0x00, 0x60, 0x00, 0x0C, 0x33, 0xFD, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xBF, 0xFF, 0xFF, 0x60, 0x00, 0x0C, 0x33, 0x01, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xBF, 0xFF, 0xFF, 0x60, 0x00, 0x0C, 0x33, 0x89, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xDF, 0xFF, 0xFF, 0x60, 0x00, 0xCC, 0x31, 0xF9, 0xF0, 0x00,
    0x00, 0x70, 0x00, 0x00, 0x00, 0x38, 0xE0, 0x00, 0x01, 0xC0, 0x00, 0xCC, 0x30, 0xF0, 0xF0, 0x00,
    0x00, 0x70, 0x00, 0x00, 0x00, 0x38, 0x7F, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x70, 0x00, 0x00, 0x00, 0x38, 0x3F, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x70, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x70, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x70, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x73, 0x83, 0x03, 0x87, 0x38, 0xC7, 0x07, 0xC0, 0x3E, 0x18, 0xE0, 0xF8, 0x1D, 0xE0, 0x00,
    0x00, 0x77, 0xE7, 0x03, 0x9F, 0xB8, 0xEF, 0x0F, 0xE0, 0xFF, 0x1D, 0xE1, 0xFC, 0x1F, 0xF8, 0x00,
    0x00, 0x7F, 0xE3, 0x83, 0x9F, 0xF8, 0xFF, 0x1F, 0xF0, 0xFF, 0x1F, 0xE3, 0xFE, 0x1F, 0xF8, 0x00,
    0x00, 0x78, 0xF3, 0x87, 0x3C, 0x78, 0xF8, 0x3C, 0x79, 0xE0, 0x1F, 0x07, 0x8F, 0x1E, 0x3C, 0x00,
    0x00, 0x70, 0x71, 0xC7, 0x38, 0x38, 0xF0, 0x38, 0x39, 0xC0, 0x1E, 0x07, 0x07, 0x1C, 0x1C, 0x00,
    0x00, 0x70, 0x71, 0xC7, 0x38, 0x38, 0xE0, 0x38, 0x39, 0xC0, 0x1C, 0x07, 0x07, 0x1C, 0x1C, 0x00,
    0x00, 0x70, 0x70, 0xCE, 0x38, 0x38, 0xE0, 0x38, 0x39, 0xC0, 0x1C, 0x07, 0x07, 0x1C, 0x1C, 0x00,
    0x00, 0x70, 0x70, 0xEE, 0x38, 0x38, 0xE0, 0x38, 0x39, 0xC0, 0x1C, 0x07, 0x07, 0x1C, 0x1C, 0x00,
    0x00, 0x70, 0x70, 0xEC, 0x38, 0x38, 0xE0, 0x38, 0x39, 0xC0, 0x1C, 0x07, 0x07, 0x1C, 0x1C, 0x00,
    0x00, 0x70, 0x70, 0x7C, 0x3C, 0x78, 0xE0, 0x3C, 0x79, 0xE0, 0x1C, 0x07, 0x8F, 0x1E, 0x3C, 0x00,
    0x00, 0x70, 0x70, 0x7C, 0x1F, 0xF8, 0xE0, 0x1F, 0xF0, 0xFF, 0x1C, 0x03, 0xFE, 0x1F, 0xF8, 0x00,
    0x00, 0x70, 0x70, 0x38, 0x0F, 0xF8, 0xE0, 0x0F, 0xE0, 0xFF, 0x1C, 0x01, 0xFC, 0x1D, 0xF0, 0x00,
    0x00, 0x70, 0x70, 0x38, 0x07, 0x38, 0xE0, 0x07, 0xC0, 0x3E, 0x1C, 0x00, 0xF8, 0x1C, 0xE0, 0x00,
    0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x70, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xF0, 0x0C, 0x18, 0x60, 0x00, 0x00, 0x00, 0xD8, 0xC0, 0x00, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x07, 0xE0, 0x0C, 0x00, 0x60, 0x00, 0x00, 0x00, 0xD8, 0x00, 0x00, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x07, 0xC0, 0x0F, 0x9B, 0xE7, 0xFC, 0x07, 0x6C, 0xFE, 0xF3, 0x7C, 0x7C, 0x00, 0x00,
    0x00, 0x00, 0x03, 0x80, 0x0C, 0xDE, 0x66, 0xC6, 0x18, 0x6C, 0xD8, 0xD2, 0xC6, 0xDC, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0C, 0xDE, 0x66, 0xC6, 0x18, 0x6C, 0xD8, 0xDE, 0xC6, 0xE0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0C, 0xDE, 0x66, 0xC6, 0xD8, 0x6C, 0xD8, 0xDE, 0xC6, 0x70, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0C, 0xDE, 0x66, 0xC6, 0x18, 0x6C, 0xD8, 0xCC, 0xC6, 0x30, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0C, 0xDB, 0xE6, 0x7C, 0x07, 0x38, 0xCE, 0xCC, 0x7D, 0xE0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

//*********************************
//*********** CONFIG **************
//*********************************

// ENTRADAS

#define WIFI_PIN 23

const int sCap1   = 25; //SENSOR DE NIVEL MELASA CAPACITIVO 01
const int sCap2   = 26; //SENSOR DE NIVEL MELASA CAPACITIVO 02
const int sCap3   = 27; //SENSOR DE NIVEL MELASA CAPACITIVO 03
const int sOptico = 34; //SENSOR DE NIVEL ESPUMA OPTICO
const int sTemp   = 35; //SENSOR DE TEMPERATURA MELADA

const int sAmp1 = 32; // Entrada 4-20 mA
const int sAmp2 = 33; // Entrada 4-20 mA

// SALIDAS

#define bomba   13 //BOMBA ANTIDERRAME / relay1
#define relay2   9
#define mosfet1 10
#define mosfet2 12


//INICIALIZACION
int estadoCap1 = 0; //NIVEL ALTO
int estadoCap2 = 0; //NIVEL MEDIO
int estadoCap3 = 0; //NIVEL BAJO

// NIVEL DE AGUA CONFIG
char *estado;


//************************************
//***** HOSTING + BROKER MQTT ********
//************************************
// estos datos deben estar configurador también en las constantes de tu panel
//  NO USES ESTOS DATOS PON LOS TUYOS!!!!
const String serial_number = "797179";
const String insert_password = "285289";
const String get_data_password = "420285";
const char *server = "medtucats.info";

// MQTT
const char *mqtt_server = "broker.emqx.io";
const int mqtt_port = 8883;

// no completar, el dispositivo se encargará de averiguar qué usuario y qué contraseña mqtt debe usar.
char mqtt_user[20] = "";
char mqtt_pass[20] = "";

const int expected_topic_length = 26;

WiFiManager wifiManager;
WiFiClientSecure client;
PubSubClient mqttclient(client);
WiFiClientSecure client2;

Separador s;


//************************************
//***** DECLARACION FUNCIONES ********
//************************************

bool get_topic(int length);
void callback(char *topic, byte *payload, unsigned int length);
void reconnect();
void ReStartESP();
void send_mqtt_data();
void send_to_database();
void myOled();
void oledWiFi();
void oledWiFiConect();
void push(String titulo, String mensaje);

void Cap1(); // entrada Nivel Bajo
void Cap2(); // entrada Nivel Medio
void Cap3(); // entrada Nivel Alto

void Optico(); // entrada Nivel Espuma
void Temp();   // Temperatura MElasa
 
void Amp1(); // entrada 4-20ma
void Amp2(); // entrada 4-20ma

// funciones de salidas
void fbomba();
void Rele2();

void MosFet1();
void MosFet2();

// Funcion de Hard Reset

void fHardReset();


//*************************************
//********      GLOBALS         *******
//*************************************
bool topic_obteined = false;
char device_topic_subscribe[40];
char device_topic_publish[40];
char msg[60];
long milliseconds = 0;

byte sw1 = 0;      // BOMBA DE AGUA - Variable Global de Inicializacion

int temp;
int nivCap;
int varConversor1;
int varConversor2;

int count = 300000; // Tiempo del HARD-RESET
int i=0;

// VARIABLS ESTADOS EN PHP

int eHO2;
int nivOptico;

void setup()
{
  Serial.begin(115200); // inicializa comunicacion serie a 1155200 bps
  Wire.begin();                  // inicializa bus I2C
  oled.begin(i2c_Address, true); // inicializa pantalla con direccion 0x3C

  // oled.stopscroll();
  oled.clearDisplay();
  oled.drawBitmap(0, 0, logo_hydrocrop, 128, 64, WHITE); //LOGO EN LCD
  oled.display();
  delay(200);

   myOled(); // PANTALLA MENU PRINCIPAL

  Serial.println("inicio");

  pinMode(sCap1, INPUT);
  pinMode(sCap2, INPUT);
  pinMode(sCap3, INPUT);
  pinMode(nivOptico,INPUT);

  pinMode(bomba, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(mosfet1, OUTPUT);
  pinMode(mosfet2, OUTPUT);

  digitalWrite(bomba, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(mosfet1, LOW);
  digitalWrite(mosfet2, LOW);

  Serial.begin(115200);

  pinMode(WIFI_PIN, INPUT_PULLUP);

  wifiManager.autoConnect("yakubox Admin");
  oledWiFiConect();
  Serial.println("Conexión a WiFi exitosa!");

  // client2.setCACert(web_cert);

  while (!topic_obteined)
  {
    topic_obteined = get_topic(expected_topic_length);
    delay(100);
  }

  // set mqtt cert
  // client.setCACert(mqtt_cert);
  mqttclient.setServer(mqtt_server, mqtt_port);
  mqttclient.setCallback(callback);

  oledWiFi();
}

void loop()
{
  // Wait a few seconds between measurements.
  //delay(200);
  i++;
  Serial.println("CAPTURA DE DATOS");

  Cap1();
  Cap2();
  Cap3();

  Optico();
  Temp();

  Amp1();
  Amp2();
  
  fbomba();
  fHardReset();

  if (!client.connected())
  {
    reconnect();
  }
 // si el pulsador wifi esta en low, activamos el acces point de configuración
  if (digitalRead(WIFI_PIN) == HIGH)


  // si estamos conectados a mqtt enviamos mensajes
  if (millis() - milliseconds > 500)
  {
    milliseconds = millis();

    if (mqttclient.connected())
    {
      // set mqtt cert

      String to_send = String(nivCap) + "," + String(temp) + "," + String(nivOptico) + "," + String(sw1) + "," + String(eHO2);
      to_send.toCharArray(msg, 60);
      mqttclient.publish(device_topic_publish, msg);

      // Serial.print("ENVIO DE CADENA A PHP...");

      delay(10);

      //send_to_database();

      /*
        if (ph >=0 || ph <=20){
          send_to_database();
        } */
    }
  }

  mqttclient.loop();

  myOled();        // Se llama a la Funcion de Config Pantalla Oled 0,96"

}

//************************************
//*********** FUNCIONES **************
//************************************

void callback(char *topic, byte *payload, unsigned int length)
{
  String incoming = "";
  Serial.print("Mensaje recibido desde tópico -> ");
  Serial.print(topic);
  Serial.println("");
  for (int i = 0; i < length; i++)
  {
    incoming += (char)payload[i];
  }
  incoming.trim();
  Serial.println("Mensaje -> " + incoming);

  String str_topic = String(topic);
  String command = s.separa(str_topic, '/', 3);
  Serial.println(command);

  // LECTURA  BOMBA DE AGUA DESDE PHP

  if (command == "sw1")
  {
    Serial.println("Sw1 pasa a estado " + incoming);
    sw1 = incoming.toInt();
    Serial.print("Estado Bomba: ");
    Serial.println(sw1);
    fbomba();
  }  
}

void reconnect()
{

  while (!mqttclient.connected())
  {
    Serial.print("Intentando conexión MQTT SSL");
    // we create client id
    String clientId = "esp32_fmg_";
    clientId += String(random(0xffff), HEX);
    // Trying SSL MQTT connection
    if (mqttclient.connect(clientId.c_str(), mqtt_user, mqtt_pass))
    {
      Serial.println("Connected!");
      // We subscribe to topic

      mqttclient.subscribe(device_topic_subscribe);
    }
    else
    {
      Serial.print("falló :( con error -> ");
      Serial.print(mqttclient.state());
      Serial.println(" Intentamos de nuevo en 5 segundos");

      delay(100);
      ReStartESP();
    }
  }
}

// función para obtener el tópico perteneciente a este dispositivo
bool get_topic(int length)
{

  Serial.println("\nIniciando conexión segura para obtener tópico raíz...");

  if (!client2.connect(server, 443))
  {
    Serial.println("Error... Falló conexión!");
  }
  else
  {
    Serial.println("Conectados a servidor para obtener tópico - ok");
    // Make a HTTP request:
    String data = "gdp=" + get_data_password + "&sn=" + serial_number + "\r\n";
    client2.print(String("POST ") + "/app/getdata/gettopics" + " HTTP/1.1\r\n" +
                  "Host: " + server + "\r\n" +
                  "Content-Type: application/x-www-form-urlencoded" + "\r\n" +
                  "Content-Length: " + String(data.length()) + "\r\n\r\n" +
                  data +
                  "Connection: close\r\n\r\n");

    Serial.println("Solicitud enviada - ok");

    while (client2.connected())
    {
      String line = client2.readStringUntil('\n');
      if (line == "\r")
      {
        Serial.println("Headers recibidos - ok");
        break;
      }
    }

    String line;
    while (client2.available())
    {
      line += client2.readStringUntil('\n');
    }
    Serial.println(line);
    String temporal_topic = s.separa(line, '#', 1);
    String temporal_user = s.separa(line, '#', 2);
    String temporal_password = s.separa(line, '#', 3);

    Serial.println("El tópico es: " + temporal_topic);
    Serial.println("El user MQTT es: " + temporal_user);
    Serial.println("La pass MQTT es: " + temporal_password);
    Serial.println("La cuenta del tópico obtenido es: " + String(temporal_topic.length()));

    if (temporal_topic.length() == length)
    {
      Serial.println("El largo del tópico es el esperado: " + String(temporal_topic.length()));

      String temporal_topic_subscribe = temporal_topic + "/actions/#";
      temporal_topic_subscribe.toCharArray(device_topic_subscribe, 40);
      Serial.println(device_topic_subscribe);
      String temporal_topic_publish = temporal_topic + "/data";
      temporal_topic_publish.toCharArray(device_topic_publish, 40);
      temporal_user.toCharArray(mqtt_user, 20);
      temporal_password.toCharArray(mqtt_pass, 20);

      client2.stop();
      return true;
    }
    else
    {
      client2.stop();
      return false;
    }
  }
}

void send_to_database()
{

  Serial.println("\nIniciando conexión segura para enviar a base de datos...");

  if (!client2.connect(server, 443))
  {
    Serial.println("Falló conexión!");
  }
  else
  {
    Serial.println("Conectados a servidor para insertar en db - ok");
    // Haciendo solitud por HTTP a DB
    String data = "idp=" + insert_password + "&sn=" + serial_number + "&nivCap=" + String(nivCap) + "&temp=" + String(temp) + "\r\n";
    client2.print(String("POST ") + "/app/insertdata/insert" + " HTTP/1.1\r\n" +
                  "Host: " + server + "\r\n" +
                  "Content-Type: application/x-www-form-urlencoded" + "\r\n" +
                  "Content-Length: " + String(data.length()) + "\r\n\r\n" +
                  data +
                  "Connection: close\r\n\r\n");

    Serial.println("Solicitud enviada - ok");

    while (client2.connected())
    {
      String line = client2.readStringUntil('\n');
      if (line == "\r")
      {
        Serial.println("Headers recibidos - ok");
        break;
      }
    }

    String line;
    while (client2.available())
    {
      line += client2.readStringUntil('\n');
    }
    Serial.println(line);
    client2.stop();
  }
}

// SENSOR OPTICO 1 - NIVEL BAJO
void Cap1()
{  
  estadoCap1 = digitalRead(sCap1);
  if (estadoCap1 == HIGH)
  { //aqui poner codigo para mandar dato si se detecto objeto
    Serial.println("cap 1 activado ");
    nivCap = 25;
  }
  else {
    //aqui poner codigo para mandar dato si NO se detecto objeto
    Serial.println("cap 1 Apagado ");
    nivCap = 0;
  }
}

void Cap2()
{  
  estadoCap1 = digitalRead(sCap1);
  if (estadoCap1 == HIGH)
  { //aqui poner codigo para mandar dato si se detecto objeto
    Serial.println("cap 1 activado ");
    nivCap = 25;
  }
  else {
    //aqui poner codigo para mandar dato si NO se detecto objeto
    Serial.println("cap 1 Apagado ");
    nivCap = 0;
  }  
}

void Cap3()
{
  estadoCap3 = digitalRead(sCap3);
  if (estadoCap3 == HIGH)
  {
    //aqui poner codigo para mandar dato si se detecto objeto
    Serial.println("cap 3 activado ");
    nivCap = 75;
  }
  else {
    //aqui poner codigo para mandar dato si NO se detecto objeto
    Serial.println("cap 3 Apagado ");
    nivCap = 50;
  }
}

void Optico()
{
  Serial.print("Valor Sensor Optico     : ");
  Serial.println(analogRead(sOptico));

  nivOptico = (analogRead(sOptico));

  if(nivOptico < 1000)
  {
    digitalWrite(bomba, HIGH); // ACTIVA BOMBA
    sw1 = 1;
    eHO2 = 1;
    nivCap = 100;
    Serial.print("BOMBA ACTIVA");
    //delay(250);
  }

  if (nivOptico > 1000 || sw1 ==0 )
  {
    digitalWrite(bomba, LOW); // APAGA BOMBA
    sw1 = 0;
    eHO2 = 0;
    Serial.println("BOMBA APAGADA");
    //delay(250);    
  }
  
  
}

void Temp()
{
  int sum = 0;
  for (int i = 0; i < 100; i++) {
    sum = sum + analogRead(sTemp); // Almacenos la lectura analogica
  }
  int promedio = sum / 100;
  int y = promedio;
  int x = (1000 * ( y ) / 9107.0) + 6.5;
  temp = x; // Variable de temperatura que se va a mostrar
  Serial.print("TEMP= ");
  Serial.println(temp); 
  // delay(10);
}

void Amp1()
{
  int conversor1 = analogRead(sAmp1);
  varConversor1 = map(conversor1, 0, 4095, 0, 5);
  Serial.print("Conversor1  = ");
  Serial.println(varConversor1);
}

void Amp2()
{
}

// PANTALLA OLED

void myOled()
{
  
  oled.clearDisplay();
  oled.setTextSize(1);                             // Normal 1:1 pixel scale
  oled.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw white text
  oled.setCursor(15, 5);                           // Columna, Fila
  oled.println(F("MENU PRINCIPAL"));

  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(1, 20);
  oled.print(F("TEMP LIQ: "));
  oled.print(temp);
  oled.println(F("C"));
  delay(5);

  if (digitalRead(nivCap) == 0)
  {

    oled.setTextColor(SSD1306_WHITE); // Draw white text
    oled.setCursor(1, 50);
    oled.print(F("NIVEL: VACIO    "));

    //delay(250);
  }
  
  switch (nivCap)
  {
  case 0:
    /* code */
    oled.setTextColor(SSD1306_WHITE); // Draw white text
    oled.setCursor(1, 50);
    oled.print(F("NIVEL: VACIO    "));

    //delay(250);
    break;
  
    case 1:
    /* code */
    oled.setTextColor(SSD1306_WHITE); // Draw white text
    oled.setCursor(1, 50);
    oled.print(F("NIVEL: BAJO    "));

    //delay(250);
    break;

    case 2:
    /* code */
    oled.setTextColor(SSD1306_WHITE); // Draw white text
    oled.setCursor(1, 50);
    oled.print(F("NIVEL: MEDIO    "));

    //delay(250);
    break;

    case 3:
    /* code */
    oled.setTextColor(SSD1306_WHITE); // Draw white text
    oled.setCursor(1, 50);
    oled.print(F("NIVEL: ALTO    "));

    //delay(250);
    break;
  
  }

  /*
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(1,50);
  oled.println(F("by ZENTENO-GAMBINO"));
  delay(50);
*/
  oled.display();
}

// OLED CONECTANDO AL WI FI

void oledWiFiConect()
{

  // oled.stopscroll();
  oled.clearDisplay();
  oled.setTextSize(2);              // Normal 1:1 pixel scale
  oled.setTextColor(SSD1306_WHITE); // Draw white text
  oled.setCursor(0, 10);            // Columna, Fila
  oled.println(F("Conectando"));
  oled.setCursor(0, 30);
  oled.println(F("a Wi-Fi..."));
  oled.display();
  delay(5);
}

// OLED WI FI CONEXION EXITOSA

void oledWiFi()
{

  // oled.stopscroll();
  oled.clearDisplay();
  oled.setTextSize(2);              // Normal 1:1 pixel scale
  oled.setTextColor(SSD1306_WHITE); // Draw white text
  oled.setCursor(15, 10);           // Columna, Fila
  oled.println(F("Conexion"));
  oled.setCursor(15, 30);
  oled.println(F("MQTT"));

  oled.setCursor(15, 50);
  oled.println(F("EXITOSA"));

  oled.display();
  delay(100);
  oled.clearDisplay();
}

// FUNCION DE RESET
void ReStartESP()
{

  delay(100);
  ESP.restart(); // PARA ESP32
}

// FUNCION ANTI DERRAME BOMBA H2O

void fbomba()
{

  if (sw1 == 1 )
  {
      digitalWrite(bomba, HIGH); // ACTIVA BOMBA
      sw1 = 1;
      eHO2 = 1;
      Serial.print("BOMBA ACTIVA");
     // delay(250);

  }
  if (sw1 == 0)
  {
    digitalWrite(bomba, LOW);
    sw1 = 0;
    eHO2 = 0;
    Serial.println("BOMBA APAGADITA");
  }

}

//FUNCION PARA RESETEO DE PLACA - HARDRESET

void fHardReset(){
   Serial.print("RESETEO EN: ");
   Serial.println(i);

 if (i == count)
 {
   delay(300);
   ESP.restart(); // PARA ESP32
   Serial.print("HARD-RESET ACTIVADO: ");
   i=0;
 }

}