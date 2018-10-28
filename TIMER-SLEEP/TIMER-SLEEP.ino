#include <TimerOne.h> // libreria de Timer1
#include <avr/sleep.h>
#include <avr/power.h>

/*
 * Interrupciones
 * Arduino uno tiene dos interrupciones
 *  INT0 -> pin 2
 *  INT1 -> pin 3
 *  configuracion 
 *  attachInterrupt(interrupcion, metodo, tipo)
 *                  digitalPinToInterrupt(interrupcion), , LOW, RISING,FALLING)
 *                  
 * TimerOne                 
 * contadores
 * configuracion 
 * -> anadir la libreria
 * -> Timer1.initialize(periodo)   -> 1 seg = 1000000
 * ->Timer1.attachInterrupt(metodo);
 * ->Timer1.start(); //
 * -> Timer1.stop(); //
 * -> Timer1.restart(); //
 * -> Timer1.resume(); //
 * 
 * MODO SLEEP
 * Ahorro de bateria
 * configurar 
 * -> librerias -> avr/sleep.h
 *                 avr/power.h
 * set_sleep_mode()= indicar el modo de funcionamiento
 *        modos-> SLEEP_MODE_IDLE, SLEEP_MODE_ADC, SLEEP_MODE_PWR_SAVE
 *                SLEEP_MODE_PWR_DOWN.
 * sleep_mode()= entrar el modo configurado
 * sleep_disable() = salir del modo sleep configurado, el programa inicia desde esa funcion
 * sleep_enable = habilitar modos sleep
 * 
 */
 int on=0; // variable de encendido del sistema
unsigned int cont=0; //varaible del contador timer1 solo positivos
int config_t1=0; // varaible para configurar timer1
int i=2;
void setup() {
   attachInterrupt(digitalPinToInterrupt(2),encendido,LOW); // configuracion de int0
   attachInterrupt(digitalPinToInterrupt(3),config_timer,LOW); // configuracion de int0
   Timer1.initialize(1000000);  // timer1 a 1 seg.
  Timer1.attachInterrupt(contador); // metodo de timer
    set_sleep_mode(SLEEP_MODE_PWR_DOWN); //configuracion sistema de ahorro de bateria
    sleep_enable(); // habilita config de sleep
   Serial.begin(9600); // habilitar cx serial
}
void loop() { 
 
 if(i==1){  // variable de modo sleep, se pone en 1 cuando entre a modo sleep
  delay(200);  // retardo para que el sistema entre a modo sleep sin problemas
    sleep_mode();  // sistema entra a modo sleep
    sleep_disable();  // sistema se levanta
    }
   if(i==0){   // despues de encender el sistema nuevamente se resetea
     void(* resetFunc) (void) = 0;  // reset de memoria ram por software
     i=2;   // cambia valor de variable de sleep para que el sistema funcione normalmente
    }
    
}

//metodo de interrupcion
void encendido(){
  on=1-on; // varaible de encendido del sistema
  if(on==1){
     Serial.println("SISTEMA ON"); // mensaje de activacion
     i=0;  // reset de sistema 
    }
  else{
     Serial.println("SISTEMA OFF"); // mensaje de activacion
     cont=0;  // reset de variable de conteo de timer1
     i=1;  // variable de ingreso a modo sleep
     }
  }
void contador(){ // subrutina de timer1
  if(on==1){
    cont++;    // varaible se incrementa de 1 en 1
    Serial.println(cont);
  }
}
void config_timer(){  // interrupcion 2
    switch(config_t1){
        case 0:
         Serial.println("T1 STOP"); 
         Timer1.stop();  // timer se detiene
         config_t1++;    // variable de confi aumenta
        break;
        case 1:
        Serial.println("T1 START");
         Timer1.start();  // timer inicia nuevamente
         config_t1=0;   // variable aumenta
        break;
      }
  }


  
