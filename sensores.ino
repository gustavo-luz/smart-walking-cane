#include <Ultrasonic.h>



//Define os pinos para o trigger e echo
//TRIGGER PODE SER O MESMO PRA TODOS
#define pino_trigger 8
#define pino_echo 10
#define pino_triggersegundo 8
#define pino_echosegundo 11
#define pino_triggerterceiro 8
#define pino_echoterceiro 12
#define pino_buzzer 6
#define DEBUG 0 //debug 1 pra usar o monitor serial do pc


 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
Ultrasonic ultrasonic2(pino_triggersegundo, pino_echosegundo);            
Ultrasonic ultrasonic3(pino_triggerterceiro, pino_echoterceiro); 


void setup()
{
  #if(DEBUG)
    Serial.begin(9600);
    while(!Serial);
    Serial.println("Lendo dados do sensor...");
  #endif
  //Trigger como OUTPUT
  pinMode(pino_trigger, OUTPUT);
  pinMode(pino_triggersegundo, OUTPUT);
  pinMode(pino_triggerterceiro, OUTPUT);
  //Echo como INPUT
  pinMode(pino_echo, INPUT);
  pinMode(pino_echosegundo, INPUT);
  pinMode(pino_echoterceiro, INPUT);
  //Buzzer como OUTPUT
  pinMode(pino_buzzer, OUTPUT);
  digitalWrite(pino_buzzer, LOW);
  delay(1000);
  digitalWrite(pino_buzzer, HIGH);
  delay(1000);
}
 
void loop()
{
  //Le as informacoes do sensor, em cm 
  long cmMsec = ultrasonic.read(CM);
  long cmMsec2 = ultrasonic2.read(CM);
  long cmMsec3 = ultrasonic3.read(CM);

  #if(DEBUG)
  //Exibe informacoes no serial monitor
    Serial.print("Distancia em cm: ");
    Serial.println(cmMsec);
    Serial.print("Distancia 2 em cm: ");
    Serial.println(cmMsec2);
    Serial.print("Distancia 3 em cm: ");
    Serial.println(cmMsec3);
    delay(100);
  #endif

  
  if(cmMsec > 10 && cmMsec <= 35){// SE A DIST NCIA ENTRE O OBJETO E O SENSOR ULTRASONICO FOR MENOR QUE 30CM, FAZ
    #if(DEBUG)
      Serial.println("objeto 1 detectado");
    #endif
    //tone(buzzPin, frequency);
    //delay(timeOn);
    //tone(D6, 4000);
    tone(pino_buzzer,1000,500);
    //digitalWrite(pino_buzzer, LOW);   
  }
//tone(pino_buzzer,500);//ACIONA O BUZZER 
  else if (cmMsec2 > 25 && cmMsec2 <=100){
    #if(DEBUG)
      Serial.println("objeto 2 detectado");
    #endif
    tone(pino_buzzer,50,500);

  }
  else if (cmMsec3 > 0 && cmMsec3 <0){
    
    #if(DEBUG)
      Serial.println("objeto 3 detectado");
    #endif
    //tone(pino_buzzer,1000,500);

  }
  else{
    #if(DEBUG)
      Serial.println(cmMsec);
      Serial.println("nao entrou");
    #endif
 
    digitalWrite(pino_buzzer, HIGH); 
  }
  delay(100);
}
 
