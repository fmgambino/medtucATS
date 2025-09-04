int relay1 = 13;
int relay2 = 9;
int mosfet1 = 10;
int mosfet2 = 12;

int stemp = 35;

void setup() {
  // salidas
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(mosfet1, OUTPUT);
  pinMode(mosfet2, OUTPUT);
  // entradas
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(relay1,LOW);    
    digitalWrite(relay2,LOW);   
    digitalWrite(mosfet1,LOW);    
    digitalWrite(mosfet2,LOW);    
    

    Serial.println(analogRead(stemp));
    
    
   
}
