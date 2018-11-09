#include <ArduinoSort.h>

#include"test.h"
#include"train.h"
int col=0;
int row=0;
float distancia;
float distancia_menor=1000;

//Valor de Prueba a determinar
int valt=80;
byte valores[120];
int tipos[3];
int tcont=0;
int contt1=0;
int contt2=0;
int contt3=0;

int runtime=0;
void setup() {
  
  Serial.begin(115200);

//  for(;row<120;row++){
//    for(;col<5;col++){
//      Serial.print(matriz[row][col]);
//      Serial.print(',');
//      
//      }
//      col=0;
//      Serial.println(' ');
//    }

 }












void loop() {
while(runtime==0){
for(;row<120;row++){
   
      distancia=sqrt( pow((matriz[row][0]-prueba[valt][0]),2)+pow((matriz[row][1]-prueba[valt][1]),2)+ pow((matriz[row][2]-prueba[valt][2]),2)+pow((matriz[row][3]-prueba[valt][3]),2)+pow((matriz[row][4]-prueba[valt][4]),2));
          
          

valores[row]=distancia;

         
        
        
        Serial.println("");
        Serial.print("int: ");
        Serial.print(distancia);
         Serial.print("byte: ");
        Serial.print( valores[row]);

   
      }

   for(;col<120;col++){
 
      
  
  Serial.println(valores[col]);
}
     
  /*printArray(valores, sizeof(valores));
 isort(valores, sizeof(valores));
 printArray(valores, sizeof(valores));*/
       
runtime=1;
  }
}





void tipo(){
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
