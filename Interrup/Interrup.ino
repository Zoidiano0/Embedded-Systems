#include <TimerOne.h>

boolean Test=false;
int i=0;

void setup() {
  attachInterrupt(digitalPinToInterrupt(2),local,LOW);
  Serial.begin(9600);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(contador);
}

void loop() {

}
void local(){
  Test=!Test;
  if(Test==true){
    Serial.println("Encendido");}
  if(Test==false){
    Serial.println("Apagado");}
  
  }

  void contador(){
    i++;
    Serial.println(i);    
    
    }
