#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <SparkFun_ADXL345.h> 
 
ADXL345 adxl = ADXL345();

File logFile;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

int x1 = 0;
int y1 = 0;
int z1 = 0;
int aux = 0;
int aux2 = 0;
int aux3 = 0;
int aux4 = 0;
int reseteo = 2000;

void setup() 
{
   Serial.begin(2400);
   pinMode(5, INPUT);
   pinMode(6, INPUT);
   pinMode(7, INPUT);
   pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(11, OUTPUT);
   adxl.powerOn();            
   adxl.setRangeSetting(8);       //Definir el rango, valores 2, 4, 8 o 16
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
}
 
void loop() 
{
   //leer los valores e imprimirlos
   int x, y, z;
   adxl.readAccel(&x, &y, &z);
   buttonState1 = digitalRead(5);
   Serial.println(buttonState1);
   aux4 = digitalRead(11);
   if (aux4 == 1) {
    aux2 = digitalRead(9);
     aux3 = digitalRead(10);
    buttonState1 = digitalRead(5);
    buttonState2 = digitalRead(6);
    buttonState3 = digitalRead(7);
    if (buttonState1 == 0){
      if (buttonState3 == 1){
        delay(3000);
        digitalWrite(9, LOW);
      }
    }
    if (aux2 == 0){
      if (buttonState1 == 0){
      if (buttonState2 == 1){
        delay(3000);
        digitalWrite(10, LOW);
      }
    }
    }
    if (aux3 == 0){
      if (buttonState2 == 1){
      if (buttonState3 == 1){
        delay(3000);
        digitalWrite(11, LOW);
      }
    }
    }
   }

   delay(50);
   
}
