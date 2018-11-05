// Variables
const int Fnum=10;
const int Cnum=4;
int MainM[Fnum][Cnum];
int filaV[Cnum];
int ColV[Fnum];
#include <stdio.h>


void setup() {

  Serial.begin(9600);
  Serial.println("Matriz principal Generada Rand");
  Serial.println("");
  for (int x = 0; x < Fnum; x++) {
    for (int y = 0; y < Cnum; y++) { 
      MainM[x][y] = random(12, 99); 
      Serial.print(" ");
      Serial.print(MainM[x][y]);
    }
    Serial.println("");
  }

}

void loop() {
Fila_Max(5);
Fila_Min(5);
Fila_PromF(5);
Fila_PromC(1);
Matrix_max();
Matrix_min();    

}

void Fila_Max(int fila){
      Serial.println("lyendo Valores de Fila");
        for(int t=0;t<Cnum;t++){
          filaV[t] =  MainM[fila][t];
          
          Serial.print(filaV[t]);
          Serial.print(" ");
        }
         Serial.println("");
Serial.println("Valor MAX");
        int vmax= filaV[0];
      for(int s=1;s<Cnum;s++){
      if(filaV[s]>vmax){
        vmax=filaV[s];
      }
      }
Serial.println(vmax);
      

  
}



void Fila_Min(int fila){
      Serial.println("lyendo Valores de Fila");
        for(int t=0;t<Cnum;t++){
          filaV[t] =  MainM[fila][t];
          
          Serial.print(filaV[t]);
          Serial.print(" ");
        }
         Serial.println("");
Serial.println("Valor Min");
        int vmin= filaV[0];
      for(int s=1;s<Cnum;s++){
      if(filaV[s]<vmin){
        vmin=filaV[s];
      }
      }
Serial.println(vmin);
      

  
}




void Fila_PromF(int fila){
      Serial.println("elyendo Valores de Fila");
        for(int t=0;t<Cnum;t++){
          filaV[t] =  MainM[fila][t];
          
          Serial.print(filaV[t]);
          Serial.print(" ");
        }
         Serial.println("");
Serial.println("Valor Promedio");
        int sum=0;  
      for(int s=0;s<Cnum;s++){
      sum= sum+filaV[s];
      }

     int resultado=sum/Cnum;
 Serial.println(resultado);    

  
}



void Fila_PromC(int columna){
      Serial.println("leyendo Valores de Columna");
        for(int t=0;t<Fnum;t++){
          ColV[t] =  MainM[t][columna];
          
          Serial.print(ColV[t]);
          Serial.print(" ");
        }
         Serial.println("");
Serial.println("Valor Promedio");
        int sum=0;  
      for(int s=0;s<Fnum;s++){
      sum= sum+ColV[s];
      }

     int resultado=sum/Fnum;
 Serial.println(resultado);    

  
}





void Matrix_max(){
  
      Serial.println("Numero mas alto toda la matriz");
  int vmax= MainM[0][0];
        for(int r=0;r<Fnum;r++){
        for(int t=0;t<Cnum;t++){
          
          filaV[t] =  MainM[r][t];
          
          if(MainM[r][t]>vmax){
        
         vmax=MainM[r][t];
        
      }
          
        }
        }
         Serial.println("");
         
      Serial.println("Valor MAX");

   
      
Serial.println(vmax);
      
}


void Matrix_min(){
  
      Serial.println("Numero mas Bajo toda la matriz");
  int vmax= MainM[0][0];
        for(int r=0;r<Fnum;r++){
        for(int t=0;t<Cnum;t++){
          
          filaV[t] =  MainM[r][t];
          
          if(MainM[r][t]<vmax){
        
         vmax=MainM[r][t];
        
      }
          
        }
        }
         Serial.println("");
         
      Serial.println("Valor min");

   
      
Serial.println(vmax);
      
}
  
