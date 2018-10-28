//Librerias
#include <LiquidCrystal.h> // Librería para el control del LCD
#include <Keypad.h> // Librería para el control del keypad

//Variables

boolean inicio = false; 
boolean final = false; // variables de control

String num1, num2;
int ans;
char op;

//Variables definiciones LCD
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // varible LCD y pines
//COnf Teclado
const byte filas = 4; 
const byte columnas = 4; 

//COnfiguracion de Pines teclado
byte filaPines[filas]={0,1,2,3}; //configuración de filas
byte columnaPines[columnas]={4,5,6,7}; // configuración de columnas

// Disposicion de teclado

char teclado [filas][columnas]={
                      {'1','2','3','-'},
                      {'4','5','6','x'},
                      {'7','8','9','/'},
                      {'*','0','=','+'}}; 


// Creacion Objeto Teclado
Keypad calcu = Keypad (makeKeymap(teclado),filaPines, columnaPines, filas, columnas);


void setup()
{
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("Calculadora");
  lcd.clear();
}

void loop()
{
  char key = calcu.getKey();// Obtiene dato de teclado
  // Verifica el tipo de dato
  if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
    if(inicio == false)
      {num1 = num1 + key;
      int numLength = num1.length();
      lcd.setCursor(15-numLength,0);
      lcd.print(num1); 
  }
     else                                         // Verifica teclas seleccionasdas
     {num2 = num2 + key;
      int numLength = num2.length();
      lcd.setCursor(15-numLength,1);
      lcd.print(num2);
      final = true;
  }
}
if (inicio == false && key != NO_KEY && (key == '+' || key == '-' || key == 'x' || key == '/')) 
{inicio = true;
 op = key;
 lcd.setCursor(15,0);
 lcd.print (op); 

}
if (final == true && key !=NO_KEY && key == '=') 
{
    if (op == '+')
    {ans= num1.toInt() + num2.toInt();}
    if (op == '-')
    {ans= num1.toInt() - num2.toInt();}
    if (op == 'x')
    {ans= num1.toInt() * num2.toInt();}                     // Verifica operacion a realizar 
    if (op == '/')
    {ans= num1.toInt() / num2.toInt();}
    
    lcd.clear();
    lcd.setCursor(15,0);
    lcd.autoscroll();
    lcd.print(ans);
    lcd.noAutoscroll();    
}
if(key !=NO_KEY && key == '*')
{
  lcd.clear();
  inicio = false;                           //Reinicio De Sistema
  final = false;
  num1 = "";
  num2 = "";
  ans = 0;
  op = ' ';
}
}
