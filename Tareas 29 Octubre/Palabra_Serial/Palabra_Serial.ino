//Librerias
#include <LiquidCrystal.h> 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);


void setup() {

  //Serial
  Serial.begin(9600);

  //LCD
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("Palabra 8 Char");
  
}

void loop() {
      
        String string = Serial.readStringUntil(':');//Lee entrada serial hasta caracter especificado
        if(string != ""){
            //here you could check the servo number
            String pos = Serial.readStringUntil('&');
            int int_pos=pos.toInt();
            Serial.println("Pos");
            Serial.println(int_pos);
            Serial.println(string);
             Serial.println(string.length());
             lcd.clear();
             char vector[string.length()] {};   // crea vector del tamanio de palabra recoletada
            for(int i=0; i<=(string.length()-1); i++) {
             vector[i]=string.charAt(i);              // asigna las letras de la palabara dentro del vector
             
                Serial.println(vector[i]);
        }

         for(int i=0; i<=(string.length()-1); i++) {
             vector[i]=string.charAt(i);
             lcd.setCursor(i,0);                              // imprime letras de vectro en lcd en orden ascendente
              lcd.print(vector[i]);
              delay(200);              
        }


           for(int i=(string.length()-1); i>=0; i--) {
                                                                     // Borra letras de vectro en lcd en orden ascendente
             lcd.setCursor(i,0);
              lcd.print(" ");
              delay(200);              
        }



        for(int i=(string.length()-1); i>=0; i--) {
             vector[i]=string.charAt(i);
             lcd.setCursor(i,0);                               // imprime letras de vectro en lcd en orden decendente
              lcd.print(vector[i]);
              delay(200);              
        }
        
    }


 
  
}
