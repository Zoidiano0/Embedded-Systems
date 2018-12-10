#include"train.h"
#include"test.h"
#include <stdio.h>  
int respuestas[100];
int posiciones[100];
int col=0;
int row=0;
float distancia;
float dist_menor=1000;
int tcont=0;

int contres=0;

int kn=3;

int contt1=0;
int contt2=0;
int contt3=0;
int tval=15;
int runtime=0;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  while(runtime==0){

 knm(5);

runtime=1;
  }
}


void knm(int k){

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

       
       respuestas[contres]=distancia;
       posiciones[contres]=matriz[row][4];
        contres++;

        
Serial.println("Valoes guardado");
Serial.println(contres);

  
       
     }  

         
      
  }




    for(int h=(contres-1);h>=(contres-k);h--){
  Serial.println("Valoes de h");
      Serial.println(h);
       Serial.println(respuestas[h]);
        Serial.println(posiciones[h]);
        
         switch(posiciones[h]){
          
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
