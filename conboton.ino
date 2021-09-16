#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <SparkFun_ADXL345.h> 

File logFile;

const int pulsadorPin = 2;
const int ledPin = 3;
int valorPulsador = 0;

ADXL345 adxl = ADXL345();

void setup() 
{
   Serial.begin(2400);
   Serial.print(F("Iniciando SD ..."));
   if (!SD.begin(10))
   {
     Serial.println(F("Error al iniciar"));
     return;
   }
   Serial.println(F("Iniciado correctamente"));             
   Serial.println("Iniciar");
   Serial.println();
   
   pinMode(pulsadorPin, INPUT);
   pinMode(ledPin, OUTPUT);
 
   adxl.powerOn();            
   adxl.setRangeSetting(8);       //Definir el rango, valores 2, 4, 8 o 16

}
 
void loop() 
{
   valorPulsador = digitalRead(pulsadorPin);
   
   //leer los valores e imprimirlos
   int x, y, z;
   adxl.readAccel(&x, &y, &z); 
    
   Serial.print(x);
   Serial.print(", ");
   Serial.print(y);
   Serial.print(", ");
   Serial.println(z);
  
   if (valorPulsador == HIGH) {
    delay(2000);
      do {
        valorPulsador = digitalRead(pulsadorPin);
        digitalWrite(ledPin, HIGH);
        logFile = SD.open("data.txt", FILE_WRITE);
        Serial.println("Guardando datos en la SD");
        adxl.readAccel(&x, &y, &z);
        Serial.print(x);
        Serial.print(", ");
        Serial.print(y);
        Serial.print(", ");
        Serial.println(z);
        if (logFile) { 
          int ejex = x;
          int ejey = y;
          int ejez = z;
          logFile.print("Tiempo:");
          logFile.print(millis());
          logFile.print(" ,   ");
          logFile.print("Medidas:   ");
          logFile.print(ejex);
          logFile.print(" , ");
          logFile.print(ejey);
          logFile.print(" , ");
          logFile.print(ejez);
          logFile.println("");
          logFile.close();
        } 
        else {
          Serial.println("Error al abrir el archivo");
        }
      } while (valorPulsador == LOW);
      delay(2000);
  }
  else {
      digitalWrite(ledPin, LOW);
      Serial.println("No guardando datos en la SD");
  }
   
   delay(100);
}
