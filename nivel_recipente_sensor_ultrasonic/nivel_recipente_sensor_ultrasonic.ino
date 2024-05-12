#include <Ultrasonic.h> // biblioteca utilizada, pode ser encontrada no ide do arduino

#define r 9 //led vermelho
#define y 8 //led amarelo
#define g 7 //led verde


// Define pins

Ultrasonic ultrasonic(2, 3); //pino (Trig,Echo);
int distance;

void setup() {
  pinMode(r,OUTPUT);
  pinMode(y,OUTPUT);
  pinMode(g,OUTPUT);
  Serial.begin(9600);

}

void loop() {
 // Get distance in cm
   distance = ultrasonic.read();
  
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  delay(1000);
  
 /*importante ressaltar que para o projeto funcionar perfeitamente,
 voce tem que saber a distancia em cm do recipiente vazio
  , com o volume na metade e com o recipiente cheio.*/
  
  if(distance <= 5){
  digitalWrite(r,LOW);
  digitalWrite(y,LOW);
  digitalWrite(g,HIGH);
  delay(1000);
  }
  else if(distance==7){
  digitalWrite(r,LOW);
  digitalWrite(y,HIGH);
  digitalWrite(g,LOW);
  delay(1000);
  }
  else if(distance >= 8){
  
  digitalWrite(r,HIGH);
  digitalWrite(y,LOW);
  digitalWrite(g,LOW);
  delay(1000);
  }
  delay(1000);
}
