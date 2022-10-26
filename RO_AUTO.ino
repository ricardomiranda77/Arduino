int SensorBaixo ;
int SensorAlto ;
int SensorBaixoPorta = A1;
int SensorAltoPorta = A2;
int tempo = 0;

int Bomba = 2;
int Selenoide = 3;
int Buzzer = 4;

bool Agua = false;
bool RoFlush = true;
bool erro = false;


void setup() {
  pinMode(Bomba, OUTPUT);
  pinMode(Selenoide, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  pinMode(SensorBaixoPorta, INPUT_PULLUP);
  pinMode(SensorAltoPorta, INPUT_PULLUP);

  digitalWrite(Selenoide, HIGH);
  digitalWrite(Bomba, HIGH); 
  digitalWrite(Buzzer, HIGH);
}

void loop() {

 SensorBaixo = digitalRead(SensorBaixoPorta);
 SensorAlto = digitalRead(SensorAltoPorta);
 delay(500);

if (SensorBaixo == 1 and SensorAlto == 1 ) {
   Agua = true;
    }
else {
  digitalWrite(Bomba, HIGH); // Desliga Bomba    
  tempo = 0;
}
    

if (SensorAlto == 0) {
    Agua = false;
    RoFlush = true;
}
while (Agua == true) {
   digitalWrite(Bomba, LOW); // liga bomba 
   while (RoFlush == true) {
      digitalWrite(Selenoide, LOW); // liga Flush
      delay(50000);
      digitalWrite(Selenoide, HIGH); // desliga flush
      RoFlush = false;
   }
   
    
   SensorAlto = digitalRead(A2);
   tempo = tempo + 1;
   delay(1000);
   if (tempo >= 3600000 ) {
    cancela();
   }
   if (SensorAlto == 0) {
        Agua = false;
   }
   
   
      
      }
      
 
} // end loop

void cancela() {
  erro = true;
  while( erro == true) {
    
    digitalWrite(Selenoide, HIGH);
    digitalWrite(Bomba,  HIGH);
    digitalWrite(Buzzer, LOW);
    delay(500);
    digitalWrite(Buzzer, HIGH);
    delay(500);
  }
  
}
