//Light control device by the brain with OpenBCI / Processing

// définition des broches utilisées
#define  RELAIS_PIN   2
#define     LED_PIN  13

volatile char inChar;
boolean LIGHT = false;

void setup() {
  // initialize serial:
  Serial.begin(115200);
  
  pinMode(RELAIS_PIN, OUTPUT);
  pinMode(   LED_PIN, OUTPUT);

  // print help
  Serial.println("LIGHTController: starting...");
  Serial.println("Commands Include: ");
  Serial.println("    'P' = ON the light");
  Serial.println("    '0' = OFF the light");
}

void loop() {
  
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = Serial.read();
    Serial.print("Received ");
    Serial.println(inChar);

    if( inChar == 'P' ){
      if( LIGHT == false ){
        LightON();
        delay(2000);
      } else {
        LightOFF();
      }
    } else if( inChar == '0' ) {
      LightOFF();
    }
  }
}

void LightON(){
  //ETAT ON
   digitalWrite(RELAIS_PIN,LOW);
   //Serial.print('LIGHT IS ON');
   digitalWrite(LED_PIN,HIGH);
   LIGHT = true;
}

void LightOFF(){
  //ETAT OFF
   digitalWrite(RELAIS_PIN,HIGH);
   //Serial.print('LIGHT IS OFF');
   digitalWrite(LED_PIN,LOW);
   LIGHT = false;
}
