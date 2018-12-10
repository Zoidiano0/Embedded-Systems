#include <knn.h>


//---------------------/Ingreso Librerias
#include "matrices.h"
#include "test.h"
#include "train.h"
#include "reducida.h"

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

          
        }
        
        
      }
   



}





void loop() {

}
