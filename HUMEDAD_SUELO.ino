/* 
 Mostrar los valores porcentuales de humedad en un display LCD, obtenidos mediante un sensor de humedad de suelo HL-69. 
 Proyecto para curso SISTEMAS EMBEBIDOS CON ARDUINO.
*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int hum0=-1;
LiquidCrystal_I2C lcd(0x27,16,2);  //Crea el objeto lcd dirección 0x27 y 16 columnas y 2 filas
void setup()
{
   Serial.begin(9600); 
   pinMode(3,INPUT); //pin entrada sensor
   pinMode(13,OUTPUT); // pin salida sensor
   lcd.init();    //Inicializa el LCD 
   lcd.backlight(); //Enciende la luz de fondo.
}
void loop()
{
 int  hum_suelo;
 
 hum_suelo=1023-analogRead(0); //Obtiene el valor de la humedad del suelo del pin A0
 hum_suelo=map(hum_suelo, 0, 1023, 0, 100); //Convierte el valor de la humedad en formato de porcentaje
 if (hum0!=hum_suelo) {
 
// Mostrar el valor de humedad en la pantalla LCD
     lcd.setCursor(0,0);
     lcd.print("HUMEDAD.:");
     lcd.print(hum_suelo);
     lcd.print("%");
 }
}
