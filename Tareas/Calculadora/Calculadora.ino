/* ----------------------------------------------------------- */
/* ---ARDUINO - CALCULADORA BÁSICA---------------------------- */
/* ---INCLUYE: DISPLAY LCD 16X2 + TECLADO MATRICIAL 8X8------- */
/* ----------------------------------------------------------- */
#include <LiquidCrystal.h>
#include <Keypad.h>
/* ----------------------------------------------------------- */
/* --- Definición de variables ------------------------------- */
/* ----------------------------------------------------------- */
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
const byte COLUMNAS = 4;
const byte FILAS = 4;
char teclas [FILAS] [COLUMNAS] = {{'1', '4', '7', 'X'},{'2', '5', '8', '0'},{'3', '6', '9', '='},{'+', '-', '*', '/'}};
byte filasPines[FILAS] = {3, 2, 1, 0}; //Define lineas
byte columnasPines[COLUMNAS] = {7 ,6 ,5 ,4}; //Define columnas
Keypad miTeclado = Keypad( makeKeymap(teclas), filasPines, columnasPines, FILAS, COLUMNAS );
boolean valorActual = false;
boolean siguiente = false;
boolean final = false;
String numero1, numero2, numero3;
int calculoTotal;
int movimiento;
char operacion;
float r1,r2,r3,r4;
float decimal;
int contador=0;
/* ----------------------------------------------------------------------------------- */
/* --- Cada vez que se reinicie Ardino, se ejecuta se ejecuta la función setup() ----- */
/* ----------------------------------------------------------------------------------- */
void setup(){
             lcd.begin(16,2);
             lcd.setCursor(3,0);
             lcd.print("CALCULADORA");
             lcd.setCursor(1,1);
             lcd.print("OP. ARITMETICAS");
             delay(2500);
             lcd.clear();
             lcd.setCursor(3,0);
             lcd.print("SUMA, RESTA");
             lcd.setCursor(1,1);
             lcd.print("MULT Y DIVISION");
             delay(2500);
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print(">");
}
/* --- Estructura del bluce del programa -------------------------------------------- */
void loop()
{
 char tecla = miTeclado.getKey();
 int longitudDelNumero; 

 // Verifico que se presionó una teclada determinada.
 if (tecla != NO_KEY && (tecla=='1'||tecla=='2'||tecla=='3'||tecla=='4'||tecla=='5'||tecla=='6'||tecla=='7'||tecla=='8'||tecla=='9'||tecla=='0'))
 {
   // Inicialización de las variables
   if (contador == 1){
                     lcd.clear();
                     valorActual = false;
                     final = false;
                     numero1 = "";
                     numero2 = "";
                     calculoTotal = 0;
                     operacion = ' ';
                     lcd.setCursor(0,0);
                     lcd.print(">");
                     contador=0;                  
                   }
   if (valorActual != true){
                           numero1 = numero1 + tecla;
                           longitudDelNumero = numero1.length();
                           movimiento = longitudDelNumero;
                           lcd.setCursor(1, 0);
                           lcd.print(numero1);
                          } else {
                                  numero2 = numero2 + tecla;
                                  longitudDelNumero = numero2.length();
                                  lcd.setCursor(movimiento+2, 0);
                                  lcd.print(numero2);
                                  final = true;
                                 }
  } else if ((tecla == '+' || tecla == '-' || tecla == '*' || tecla == '/') && valorActual == false && tecla != NO_KEY)
{
 if (valorActual == false){
                          valorActual = true;
                          operacion = tecla;
                          lcd.setCursor(movimiento+1,0);
                          lcd.print(operacion);
                         }
 } else if (final == true && tecla != NO_KEY && tecla == '=')
 {
   // Dependiendo de la opción que se selecciono, resuelve las distintas operaciones 
   switch (operacion) {
    case '+':
      //Resuelve la operacion suma
      calculoTotal = numero1.toInt() + numero2.toInt();
      break;
    case '-':
      //Resuelve la operacion resta
      calculoTotal = numero1.toInt() - numero2.toInt();
      break;
    case '*':
      //Resuelve la operacion multiplicacion
      calculoTotal = numero1.toInt() * numero2.toInt();
      break;
    case '/':
      //Se resolverá la operacion division
      if(numero2.toInt()==0){
                             calculoTotal = 'E'; // Error al dividor por 0 (cero)
                            }else
                                 {
                                  calculoTotal = (numero1.toInt()) / (numero2.toInt());
                                  r1=numero1.toInt();// Asignacion en r1 = calculo de los nros decimales
                                  r2=numero2.toInt();// Asignacion en r2 = calculo de los nros decimales
                                  decimal= r1/r2;// Asignacion en decimal para la dision entre r1/r2 = numero decimal
                                 }
      break;
    default: 
      // si nada más coincide, elija esta opción
    break;
  }
 numero3=String(calculoTotal);
 lcd.clear();
 lcd.setCursor(15,0);
 lcd.autoscroll();
 if(calculoTotal=='E'){
                       lcd.print(" Err.de Sintaxis");
                      } else if(numero3.length()>4){
                                                    lcd.print("*Sin Memoria*");
                                                   }else{
                                                         if (operacion == '/') {lcd.print(decimal,2);} 
                                                            else {lcd.print(calculoTotal);}; 
                                                         contador=1;
                                                        }
lcd.noAutoscroll();
} else if (tecla == 'X' && tecla != NO_KEY){
                                       lcd.clear();
                                       valorActual = false;
                                       final = false;
                                       numero1 = "";
                                       numero2 = "";
                                       calculoTotal = 0;
                                       operacion = ' ';
                                       lcd.setCursor(0,0);
                                       lcd.print(">");
                                      }
}
/* ----------------------------------------------------------- */
