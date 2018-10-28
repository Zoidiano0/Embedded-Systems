//Librerias
#include <LiquidCrystal.h> 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup() {
  Serial.begin(9600);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("Palabra 8 Char");
  
}

void loop() {
      
        String string = Serial.readStringUntil(':');
        if(string != ""){
            //here you could check the servo number
            String pos = Serial.readStringUntil('&');
            int int_pos=pos.toInt();
            Serial.println("Pos");
            Serial.println(int_pos);
            Serial.println(string);
             Serial.println(string.length());
             lcd.clear();
             char vector[string.length()] {};
            for(int i=0; i<=(string.length()-1); i++) {
             vector[i]=string.charAt(i);
                Serial.println(vector[i]);
        }

         for(int i=0; i<=(string.length()-1); i++) {
             vector[i]=string.charAt(i);
             lcd.setCursor(i,0);
              lcd.print(vector[i]);
              delay(200);              
        }


           for(int i=(string.length()-1); i>=0; i--) {
             
             lcd.setCursor(i,0);
              lcd.print(" ");
              delay(200);              
        }



        for(int i=(string.length()-1); i>=0; i--) {
             vector[i]=string.charAt(i);
             lcd.setCursor(i,0);
              lcd.print(vector[i]);
              delay(200);              
        }
        
    }


 
  
}
