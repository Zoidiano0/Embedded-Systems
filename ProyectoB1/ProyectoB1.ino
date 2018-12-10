#include<math.h>//libreria pow

//---------------------/Ingreso Librerias
#include "matrices.h"
#include "test.h"
#include "train.h"
#include "reducida.h"
#include "temp.h"

//-------------------Variables



//-----delimitaci'on tipo 1
int type1min = 0;
int type1max = 40;
//-----delimitaci'on tipo 2
int type2min = 41;
int type2max = 80;
//-----delimitaci'on tipo 3
int type3min = 81;
int type3max = 120;

float sumatoria = 0.0;
float promedio = 0;

float distancia = 0;

float max1 = 0;
float max2 = 0;
float max3 = 0;


float normal1[40];
float normal2[40];
float normal3[40];

//------------ DONA




//----------------------Fin Variables
//----------------------Matrices aux

float pr_nor1[5];
float pr_nor2[5];
float pr_nor3[5];


float distancias1[40];
float distancias2[40];
float distancias3[40];

//---_______DONA

float donas1[40][3];




//-----------------------Fin Matrices Aux





void setup() {
  // -----------------Inicializo Serial
  Serial.begin(9600);
  //-------------test


  //--------------------------------- obtencion de valores promedio

  //------------------promedios tipo 1



  for (int r = 0; r < 4; r++) {
    for (int a = 0; a < 40; a++) {

      sumatoria += base[a][r];

      Serial.println(sumatoria);

    }
    pr_nor1[r] = (sumatoria / 40);
    Serial.println("Promedio");
    Serial.println(pr_nor1[r]);
    sumatoria = 0;
    //   delay(500);

  }

//---valores primeros datos label 1


//---------obtencion de distancias




  for (int d = 0; d < 40; d++) {


    distancia = sqrt(pow(base[d][0] - pr_nor1[0], 2) +
                     pow(base[d][1] - pr_nor1[1], 2) +
                     pow(base[d][2] - pr_nor1[2], 2) +
                     pow(base[d][3] - pr_nor1[3], 2));
    Serial.println(distancia);
    // delay(200);
    distancias1[d] = distancia;
  }


  //   maximo 1

  max1 = distancias1[0];

  for (int o = 1; o < 40; o++) {

    if (max1 < distancias1[o]) {

      max1 = distancias1[o];
      Serial.print(max1);
    }

  }


  //---------------vector normalizadas


  for (int n = 0; n < 40; n++) {

    normal1[n] = (distancias1[n] / max1);
    Serial.println(normal1[n]);

  }

  //-------------------dona con valores 
Serial.println("Dona Valores" );

      for(float f=0.0;f<1;f+=0.1){

        for(int pos=0;pos<40;pos++){

          if(normal1[pos]>=f && normal1[pos]<=(f+.1)){
            matriz[pos][0]=base[pos][0];
            matriz[pos][1]=base[pos][1];
            matriz[pos][2]=base[pos][2];
            matriz[pos][3]=base[pos][3];
            matriz[pos][4]=base[pos][4];
            
            size1++;

            for(int s=0;s<5;s++){

              Serial.println( matriz[pos][s]);
            }
          }
        }
        
        
      }
   



}





void loop() {

}


float knn(int fila, int col, int k, int label, float datos[]){//parametros de entrada , datos=nueva infromación
  int c=0;// movernos en columnas
  int f=0;//movernos en fila
  
  float k_vecinos_dist[k];//vector de almacenamiento de k distancias menores
  float etiquetas[2][label];// matriz y conteo de etiquetas
  float dist=0; //variable que almacena cada distancia.
  float dist_total=0;// caribel para almacenamiento distancai
  //lenar vector k_vecinos_dist con valores altos
  float eti_menor[k];//vector de eqtiquetas de distancia menor
  int k_cont=0;//contador de k
  int i=0;//contador
  float clase; //return etiqueta
  float comparacion;// comparar k-vecino mayor
  for (;c<k;c++)
  {
    k_vecinos_dist[c]=2000.0+c; // valores altos y ordenados
  }
  c=0;//reiniciar variable
  //llenado de las k distancias menores
  for(;c<label; c++){
    etiquetas [0][c]=c+1;//lleno con valores d eetiqueta
    etiquetas [1][c]=0;//lleno con el conteo de etiquetas
    }
    c=0;// reinicio de variabel
    // distancia mas corta del nuevo punto hacia la amtriz
    for(;f<fila;f++)
    {
      for(;c<col-1;c++){
        dist=dist+pow(matriz[f][c]-datos[c],2);//distancia entre dos puntos 
        }
        dist_total=sqrt(dist);//raíz total de la formula
        //Serial.print(dist_total);
        for(;k_cont<k;k_cont++){// determinar las k distancias enores y ordenarlas
          if(dist_total<k_vecinos_dist[k_cont]){
            k_vecinos_dist[k_cont]=dist_total;// asignar nuevo valor a vetor de dsitancias
            eti_menor[k_cont]=matriz[f][col-1];//col=5,4 //ya se ordenos el vector
            }
          }
          k_cont=0;
          dist=0;
          dist_total=0;
          c=0;
      }//for fila
      
      // comparar cada una de las posiciones d ela matriz y comparar
      
      //seleccion del k vecino
      for(;c<label;c++){
        for(;k_cont<k;k_cont++){// recorro cad posicion de eti_menor y comparo con etiquetas y cuento si son iguales
          if(etiquetas[0][c]==eti_menor[k_cont]){
            i++;
            etiquetas[1][c]=i;
            }
          }
          k_cont=0;
          i=0;
        }
        //c=0;
        c=1;//para que en comparacion
        comparacion=etiquetas[1][0];
        clase=etiquetas[0][0];
        for(;c<label;c++){
          if(etiquetas[1][c]>comparacion){//omparacion entre valores de suma de etiqueta
         clase=etiquetas[0][c];//ponga neuva clase 
         comparacion=etiquetas[1][c];
         
         }
          }
          comparacion=0;
          c=1;
          return clase;
        
}
