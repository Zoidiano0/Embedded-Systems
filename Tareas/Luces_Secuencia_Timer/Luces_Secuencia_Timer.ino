//Libreriras 
#include <TimerOne.h> // libreria de Timer1
#include <avr/sleep.h>
#include <avr/power.h>
#include <LiquidCrystal.h>
//Variables

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// Estado Sistema
boolean StadoS=false;
//Contador de T Sistema
int cont=0;
int t1=0;
int t2=0;
int t3=0;
// Contador luz1
int luz1=0;
// Contador luz2
int luz2=0;
// Contador luz3
int luz3=0;



void setup() {
  //Inicializa Serial
   Serial.begin(9600);
  //Interrupt On/Off
  attachInterrupt(digitalPinToInterrupt(2),runtime,LOW); 
  //Timer1 Config 1S
   Timer1.initialize(1000000); 
   //Metodo
   Timer1.attachInterrupt(contador);
   //Asignacione Pines Digitales
   pinMode(7,OUTPUT);
   pinMode(6,OUTPUT);
   pinMode(5,OUTPUT);

   //LCD start
   lcd.begin(20, 4);
   lcd.setCursor(0,0);
   lcd.print("Tiempo:");
   lcd.setCursor(0,1);
   lcd.print("T Luz #1:");
   lcd.setCursor(0,2);
   lcd.print("T Luz #2:");
   lcd.setCursor(0,3);
   lcd.print("T Luz #3:");
   
}


void loop() {

      if(cont==10){
        digitalWrite(7,HIGH);
        t1=cont;
      }
      if((cont-t1)==10){
         digitalWrite(7,LOW);
      }

      if(cont==25){
        digitalWrite(6,HIGH);
        t2=cont;
      }
      if((cont-t2)==15){
         digitalWrite(6,LOW);
      }


      if(cont==10){
        digitalWrite(5,HIGH);
        t3=cont;
      }
      if((cont-t3)==5){
         digitalWrite(5,LOW);
      }

   lcd.setCursor(11,1);
   lcd.print((cont-t1));
   lcd.setCursor(11,2);
   lcd.print((cont-t2));
   lcd.setCursor(11,3);
   lcd.print((cont-t3));

}




//Secuencia On/Off
void runtime(){
  StadoS=!StadoS; // varaible de encendido del sistema
  if(StadoS==true){
     Serial.println("SISTEMA ON");
    }
  else{
     Serial.println("SISTEMA OFF");
     cont=0;  
     luz1=0;
     luz2=0;
     luz3=0;

     }
  }

  void contador(){ // subrutina de timer1
  if(StadoS==true){
    cont++;    // varaible se incrementa de 1 en 1
    lcd.setCursor(8,0);
    lcd.print(cont);
    Serial.println(cont);
  }
}
