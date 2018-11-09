#include"train.h"
#include"test.h"


int col=0;
int row=0;
float distancia;
float dist_menor=1000;
int tcont=0;

int contt1=0;
int contt2=0;
int contt3=0;
int tval=15;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {

  for(;row<120;row++){ // contador de filas (for lento)
       distancia= sqrt( pow((matriz[row][0]-prueba[tval][0]),2)+
                        pow((matriz[row][1]-prueba[tval][1]),2)+
                        pow((matriz[row][2]-prueba[tval][2]),2)+
                        pow((matriz[row][3]-prueba[tval][3]),2));
      if(distancia<dist_menor){ 
       dist_menor=distancia;   
       Serial.println(dist_menor);
       tcont=matriz[row][4];
       Serial.println(tcont);
       
         switch(tcont){
          case 1:
                 Serial.println("Setosa");
                 contt1++;
                 break;
          case 2:
                  Serial.println("Versicolor");
                  contt2++;
                 break;
          case 3:
                Serial.println("Virginica");
                contt3++;
                 break;
        
        }
       
     }             
      
  }

/*
 * Lectura de datos
  for(;row<120;row++){ // contador de filas (for lento)
    for(;col<5;col++){ // contador de col (for rapido)
      Serial.print(matriz[row][col]);  // imprime dato de matriz
      Serial.print(',');            // separador de dato
      delay(25);
      }
      col=0;        // reinicio de columna
      Serial.println(' ');   // caracter en blanco de avance de linea
  }
  */    
}
