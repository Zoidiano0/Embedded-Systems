#include <knn.h>
#include "train.h"
#include "test.h"
///valor de juzgamiento
float minim =0.2;
float maxim =0.8;
float maxtype1=0;
float promedios1[4],promedios2[4],promedios3[4];
float result;
float type1[40][5];
float type2[40][5];
float type3[40][5];
int aciertos=0;
int fallos=0;
float distancias1[40];
void setup() {
 Serial.begin(9600);
    for(int i=0;i<=29;i++){
    result=knn(5,5,3,3,prueba[i]);
    //Serial.println(result);
    Serial.println(i);
    if(result==prueba[i][4]){
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

//----------------------------------------------------------------------------------------------------

float maximos1[4],maximos2[4],maximos3[4];
   
   float maximum = datos[0][0];
   float maximum2 = datos[0][1];
   float maximum3 = datos[0][2];
   float maximum4 = datos[0][3];
   
 //Valores para la primera matriz primer tipo 

 
  for (int c = 1; c < 40; c++)
  {
    //Valor 1
    if (datos[c][0]> maximum)
    {
       maximos1[0]  = datos[c][0];      
    }
    //Valor 2
     if (datos[c][1]> maximum2)
    {
       maximos1[1]  = datos[c][1];      
    }
    //Valor 3
        if (datos[c][2]> maximum3)
    {
       maximos1[2]  = datos[c][2];      
    }
    //Valor 4
     if (datos[c][3]> maximum4)
    {
       maximos1[3]  = datos[c][3];      
    }
  }
//max valores
int valorin =sqrt(pow((datos[0][0]-promedios1[0]),2)+
             pow((datos[0][1]-promedios1[1]),2)+
             pow((datos[0][2]-promedios1[2]),2)+
             pow((datos[0][3]-promedios1[3]),2));
             
for (int c = 1; c < 40; c++)
  {
    //Valor 1
    if (sqrt(pow((datos[0][0]-promedios1[0]),2)+
             pow((datos[0][1]-promedios1[1]),2)+
             pow((datos[0][2]-promedios1[2]),2)+
             pow((datos[0][3]-promedios1[3]),2))> valorin)
    {
        maxtype1=sqrt(pow((datos[0][0]-promedios1[0]),2)+
             pow((datos[0][1]-promedios1[1]),2)+
             pow((datos[0][2]-promedios1[2]),2)+
             pow((datos[0][3]-promedios1[3]),2));
    }
    //Valor 2
   
  }
 
 //Valores para la primera matriz primer tipo 

 float maximum5 = datos[39][0];
   float maximum6 = datos[39][1];
   float maximum7 = datos[39][2];
   float maximum8 = datos[39][3];
 

 
  for (int c = 40; c < 80; c++)
  {
    //Valor 1
    if (datos[c][0]> maximum5)
    {
       maximos2[0]  = datos[c][0];      
    }
    //Valor 2
     if (datos[c][1]> maximum6)
    {
       maximos2[1]  = datos[c][1];      
    }
    //Valor 3
        if (datos[c][2]> maximum7)
    {
       maximos2[2]  = datos[c][2];      
    }
    //Valor 4
     if (datos[c][3]> maximum8)
    {
       maximos2[3]  = datos[c][3];      
    }
  }

 //Valores para la primera matriz primer tipo 

 float maximum9 = datos[79][0];
   float maximum10 = datos[79][1];
   float maximum11 = datos[79][2];
   float maximum12 = datos[79][3];
 

 
  for (int c = 80; c < 120; c++)
  {
    //Valor 1
    if (datos[c][0]> maximum9)
    {
       maximos3[0]  = datos[c][0];      
    }
    //Valor 2
     if (datos[c][1]> maximum10)
    {
       maximos3[1]  = datos[c][1];      
    }
    //Valor 3
        if (datos[c][2]> maximum11)
    {
       maximos3[2]  = datos[c][2];      
    }
    //Valor 4
     if (datos[c][3]> maximum12)
    {
       maximos3[3]  = datos[c][3];      
    }
  }
//-----------Promedios


float valores1=0;
float valores2=0;
float valores3=0;
float valores4=0;
for(int c=0;c<40;c++){


valores1 = valores1+datos[c][0];
valores2 = valores2+datos[c][1];
valores3 = valores3+datos[c][2];
valores4 = valores4+datos[c][3];

promedios1[0]=valores1/40;
promedios1[1]=valores2/40;
promedios1[2]=valores3/40;
promedios1[3]=valores4/40;

/*
valores9 = datos[c][0];
valores10 = datos[c][0];
valores11 = datos[c][0];
valores12 = datos[c][0];*/
  
}


for(int c=39;c<80;c++){
  
float valores5=0;
float valores6=0;
float valores7=0;
float valores8=0;

valores5 = valores5+datos[c][0];
valores6 = valores6+datos[c][1];
valores7 = valores7+datos[c][2];
valores8 = valores8+datos[c][3];


promedios2[0]=valores5/c;
promedios2[1]=valores6/c;
promedios2[2]=valores7/c;
promedios2[3]=valores8/c;


  
}

for(int c=79;c<120;c++){
float valores9=0;
float valores10=0;
float valores11=0;
float valores12=0;

valores9 = valores9+datos[c][0];
valores10 = valores10+datos[c][1];
valores11= valores11+datos[c][2];
valores12 = valores12+datos[c][3];

promedios3[0]=valores9/c;
promedios3[1]=valores10/c;
promedios3[2]=valores11/c;
promedios3[3]=valores12/c;

  
}
//////Obtencion de valores netre los rangos propuestos

int posiciones=0;
for(int c =0;c<40;c++){
float    distancia=sqrt(pow((datos[c][0]-promedios1[0]),2)+
             pow((datos[c][1]-promedios1[1]),2)+
             pow((datos[c][2]-promedios1[2]),2)+
             pow((datos[c][3]-promedios1[3]),2));
             Serial.println(distancia);
             if((distancia/maximos1[0])>=minim &&(distancia/maximos1[0])<=maxim){
             distancias1[c]=distancia;
              for(int m=0;m<5;m++){
                type1[posiciones][m]=datos[posiciones][m];
              }
              posiciones++;
             }

}
//obtener maximo

float maximo=distancias1[0];

for(int c=1;c<40;c++){
  if(distancias1[c]>maximo){
    maximo=distancias1[c];
  }
}
int contador=0;
for(int g=0;g<40;g++){
  if((distancias1[g]/maximo)>minim &&(distancias1[g]/maximo)<maxim){
    type1[contador][0]=datos[g][0];
    type1[contador][1]=datos[g][1];
    type1[contador][2]=datos[g][2];
    type1[contador][3]=datos[g][3];
    type1[contador][4]=datos[g][4];
    contador++;
  }
}





for(int g=0;g<=posiciones;g++){
    for(int r=0;r<5;r++){

      Serial.print(type1[g][r]);
      Serial.print(" ");
    }
    Serial.println(" ");
}










}



void loop() {
  

}
