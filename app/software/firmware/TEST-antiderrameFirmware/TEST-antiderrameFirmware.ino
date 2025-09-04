

// ENTRADAS

int bWiFi = 23;

int sCap1   = 25;
int sCap2   = 26;
int sCap3   = 27;
int sOptico = 34;
int sTemp   = 35;

int sAmp1 = 32; // Entrada 4-20 mA
int sAmp2 = 33; // Entrada 4-20 mA

// SALIDAS

int relay1  = 13;
int relay2  = 9;
int mosfet1 = 10;
int mosfet2 = 12;


int estadoCap1 = 0;
int estadoCap2 = 0;
int estadoCap3 = 0;

// VARIABLES GLOBALES

int nivCap = 0;    // indica el nivel segun se activan los capasitores , 0: ninguno activo , 1: cap1 activo , 2: cap2 activo, 3: cap3 activo
int nivOptico = 0; // indica si se detecto un objeto 0: si no se detecto objeto, 1: si se detecto objeto
float temp = 0;    // indica el valor de la temperatura final
float varConversor1 = 0; // indica valor en tension del conversor 1 de 4-20 mA
float varConversor2 = 0; // indica valor en tension del conversor 2 de 4-20 mA

//************************************
//***** DECLARACION FUNCIONES ********
//************************************

void Cap1();
void Cap2();
void Cap3();

void Optico();
void Temp();

void Amp1(); // entrada 4-20ma
void Amp2(); // entrada 4-20ma

// funciones de salidas
void Rele1();
void Rele2();

void MosFet1();
void MosFet2();


void setup()
{
  Serial.begin(115200); // inicializa comunicacion serie a 9600 bps
  Serial.println("inicio");

  pinMode(sCap1, INPUT);
  pinMode(sCap2, INPUT);
  pinMode(sCap3, INPUT);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(mosfet1, OUTPUT);
  pinMode(mosfet2, OUTPUT);

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(mosfet1, LOW);
  digitalWrite(mosfet2, LOW);
}

void loop()
{
  // Wait a few seconds between measurements.
  delay(2000);

  Serial.println("LECTURAS ENTRADAS ");

  Cap1();
  Cap2();
  Cap3();

  Optico();
  Temp();

  Amp1();
  Amp2();

}

// SENSOR OPTICO 1 - NIVEL BAJO
void Cap1()
{
  estadoCap1 = digitalRead(sCap1);
  if (estadoCap1 == HIGH)
  { //aqui poner codigo para mandar dato si se detecto objeto
    Serial.println("cap 1 activado ");
    nivCap = 1;
  }
  else {
    //aqui poner codigo para mandar dato si NO se detecto objeto
    Serial.println("cap 1 Apagado ");
    nivCap = 0;
  }
}

void Cap2()
{
  estadoCap2 = digitalRead(sCap2);
  if (estadoCap2 == HIGH)
  { //aqui poner codigo para mandar dato si se detecto objeto
    Serial.println("cap 2 activado ");
    nivCap = 2;
  }
  else {
    //aqui poner codigo para mandar dato si NO se detecto objeto
    Serial.println("cap 2 Apagado ");
    nivCap = 1;
  }
}

void Cap3()
{
  estadoCap3 = digitalRead(sCap3);
  if (estadoCap3 == HIGH)
  {
    //aqui poner codigo para mandar dato si se detecto objeto
    Serial.println("cap 3 activado ");
    nivCap = 3;
  }
  else {
    //aqui poner codigo para mandar dato si NO se detecto objeto
    Serial.println("cap 3 Apagado ");
    nivCap = 2;
  }
}

void Optico()
{
  int ValOptico = analogRead(sOptico);
  Serial.print("Valor Sensor Optico     : "  );
  Serial.println(ValOptico);
  if (ValOptico < 1000 ) {
    //aqui poner codigo para mandar dato si se detecto objeto
    Serial.println("se detecto objeto");
    nivOptico = 1;
  }
  else {
    //aqui poner codigo para mandar dato si NO se detecto objeto
    Serial.println("Ningun objeto detectado");
    nivOptico = 0;
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
  float x = (1000 * ( y ) / 9107.0) + 6.5;
  temp = x; // Variable de temperatura que se va a mostrar
  Serial.print("temperatura= ");
  Serial.println(temp);  
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
  int conversor2 = analogRead(sAmp1);
  varConversor2 = map(conversor2, 0, 4095, 0, 5);
  Serial.print("Conversor2  = ");
  Serial.println(varConversor2);
}
