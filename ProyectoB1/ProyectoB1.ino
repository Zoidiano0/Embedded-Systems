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


// valores
float extra=0.1;
int result=0;
int aciertos=0;
int fallos=0;
int cont_ef1=0;

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
int cont_pos=0;
//-----------efectividad

int exactitud[10];

//union para an'alisis

float matrixu[80]={};

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

     // Serial.println(sumatoria);

    }
    pr_nor1[r] = (sumatoria / 40);
   // Serial.println("Promedio");
   // Serial.println(pr_nor1[r]);
    sumatoria = 0;
    //   delay(500);

  }



//------------------Promedios Tipo 2


for (int r = 0; r < 4; r++) {
    for (int a = 40; a < 80; a++) {

      sumatoria += base[a][r];

    //  Serial.println(sumatoria);

    }
    pr_nor2[r] = (sumatoria / 40);
 //   Serial.println("Promedio");
//Serial.println(pr_nor2[r]);
    sumatoria = 0;
    //   delay(500);

  }


//------------------Promedios Tipo 3


for (int r = 0; r < 4; r++) {
    for (int a = 80; a < 120; a++) {

      sumatoria += base[a][r];

    //  Serial.println(sumatoria);

    }
    pr_nor3[r] = (sumatoria / 40);
    Serial.println("Promedio  3");
Serial.println(pr_nor3[r]);
    sumatoria = 0;
    //   delay(500);

  }






  

//---valores primeros datos label 1


//---------obtencion de distancias tipo 1 -




  for (int d = 0; d < 40; d++) {


    distancia = sqrt(pow(base[d][0] - pr_nor1[0], 2) +
                     pow(base[d][1] - pr_nor1[1], 2) +
                     pow(base[d][2] - pr_nor1[2], 2) +
                     pow(base[d][3] - pr_nor1[3], 2));
  //  Serial.println(distancia);
    // delay(200);
    distancias1[d] = distancia;
  }


  //   maximo 1

  max1 = distancias1[0];

  for (int o = 1; o < 40; o++) {

    if (max1 < distancias1[o]) {

      max1 = distancias1[o];
     // Serial.print(max1);
    }

  }

//---------obtencion de distancias tipo 2


  for (int d = 40; d < 80; d++) {


    distancia = sqrt(pow(base[d][0] - pr_nor2[0], 2) +
                     pow(base[d][1] - pr_nor2[1], 2) +
                     pow(base[d][2] - pr_nor2[2], 2) +
                     pow(base[d][3] - pr_nor2[3], 2));
   // Serial.println(distancia);
    // delay(200);
    distancias2[d-40] = distancia;
  }


  //   maximo 1

  max2 = distancias2[0];

  for (int o = 1; o < 40; o++) {

    if (max2 < distancias2[o]) {

      max2 = distancias2[o];
    //  Serial.print(max2);
    }

  }


//---------obtencion de distancias tipo 3


  for (int d = 80; d < 120; d++) {


    distancia = sqrt(pow(base[d][0] - pr_nor3[0], 2) +
                     pow(base[d][1] - pr_nor3[1], 2) +
                     pow(base[d][2] - pr_nor3[2], 2) +
                     pow(base[d][3] - pr_nor3[3], 2));
   // Serial.println(distancia);
    // delay(200);
    distancias3[d-80] = distancia;
  }


  //   maximo 1

  max3 = distancias3[0];

  for (int o = 1; o < 40; o++) {

    if (max3 < distancias3[o]) {

      max3 = distancias3[o];
    //  Serial.print(max2);
    }

  }











  //---------------vector normalizadas tipo 1


  for (int n = 0; n < 40; n++) {

    normal1[n] = (distancias1[n] / max1);
   // Serial.println(normal1[n]);

  }



//---------------vector normalizadas tipo 2


  for (int n = 0; n < 40; n++) {

    normal2[n] = (distancias2[n] / max2);
    //Serial.println(normal2[n]);

  }


//---------------vector normalizadas tipo 3

Serial.println(" imPRIMIENDO NORMAL 3");
  for (int n = 0; n < 40; n++) {

    normal3[n] = (distancias3[n] / max3);
    Serial.println(normal3[n]);

  }
Serial.println("FIN imPRIMIENDO NORMAL 3");




//-------------union de normales



for(int r=0;r<40;r++){

        matrixu[r]=normal1[r];
          
   /*
      
   
Serial.println(' ');
Serial.print(" Valor Posicicion  " );
Serial.print(r);
Serial.print(" =  " );
Serial.print(matrixu[r]);

  */
}


for(int r=40;r<80;r++){

        
        matrixu[r]=normal2[r-40];
          
  /*      
   
Serial.println(' ');
Serial.print(" Valor Posicicion  " );
Serial.print(r);
Serial.print(" =  " );
Serial.print(matrixu[r]);
*/
  
}


for(int r=80;r<120;r++){

        
        matrixu[r]=normal3[r-80];
          
        
      
   /*
Serial.println(' ');
Serial.print(" Valor Posicicion  " );
Serial.print(r);
Serial.print(" =  " );
Serial.print(matrixu[r]);
*/
  
}








//Serial.println("imPRIMIENDO NORMAL COMPLETA");

for(int a=0;a<120;a++){
/*Serial.print("  " );
  Serial.println(matrixu[a]);
  Serial.print("  Valor de matriz#  " );
  Serial.print(a);*/
}

  //-------------------dona con valores 
//Serial.println("FIN imPRIMIENDO NORMAL COMPLETA");

  
Serial.println("Dona Valores" );

      for(float fd=0.0;fd<1;fd+=0.1){

        for(int pos=0;pos<119;pos++){
                   
         if(matrixu[pos]>(fd) && matrixu[pos]<=(fd+extra)){
            matriz[cont_pos][0]=base[pos][0];
            matriz[cont_pos][1]=base[pos][1];
            matriz[cont_pos][2]=base[pos][2];
            matriz[cont_pos][3]=base[pos][3];
            matriz[cont_pos][4]=base[pos][4];
            cont_pos++;
            size1++;
            
            Serial.println(size1);
            //delay(500);

          }
          
        }

        for(int r=0;r<=(size1-1);r++){

            for(int e=0;e<5;e++){

              Serial.print(matriz[r][e]);
              Serial.print(" ");
            }
          Serial.println(" ");
        }

        
        exactitud[cont_ef1]=efectividad();
        size1=0;
        fallos=0;
        aciertos=0;
       float matriz[120][5]={};
        //Serial.println(exactitud[cont_ef1]);
        cont_ef1++;
        cont_pos=0;
      }
   
  for(int p=0;p<10;p++){
    Serial.println(exactitud[p]);
  }




// Busqueda de mayor eficiencia


int efcont=0;

for(int r=0;r<10;r++){

    

  
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
          c=0;
          f=0;
          return clase;
          
        
}


int efectividad(){
       
      for(int i=0;i<=29;i++){
            result=knn(119,5,3,3,test[i]);
             //Serial.println(result);
             Serial.println(i);
               if(result==test[i][4]){
                aciertos++;Serial.println("OK");}else{fallos++;Serial.println("Fail");}
            }
        Serial.println("Porcentage Aciertos:");
      Serial.println((aciertos*100)/30);
        Serial.println("Porcentage Fallas:");
    Serial.println((fallos*100)/30);
Serial.println("Aciertos:");
Serial.println(aciertos);
Serial.println("Fallas:");
Serial.println(fallos);
Serial.println(" Fin de prueba" );
Serial.println(" Contando componentes de matriz en el intervalo");
  return (aciertos*100)/30;
}
