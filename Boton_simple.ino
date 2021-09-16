C++
/*
  Creado: Luis del Valle (ldelvalleh@programarfacil.com)
  https://programarfacil.com
*/

// Constantes para definir los pines
const int pulsadorPin = 2;
const int ledPin = 13;

int valorPulsador = 0;

void setup() {
    // Activamos los pines de entrada y salida
    pinMode(pulsadorPin, INPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Leemos el valor del pin
    valorPulsador = digitalRead(pulsadorPin);
 
  // Encendemos o apagamos el pin del LED según convenga
  if (valorPulsador == HIGH) {
      digitalWrite(ledPin, HIGH);
  }
  else {
      digitalWrite(ledPin, LOW);
  }
}
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
/*
  Creado: Luis del Valle (ldelvalleh@programarfacil.com)
  https://programarfacil.com
*/
 
// Constantes para definir los pines
const int pulsadorPin = 2;
const int ledPin = 3;
 
int valorPulsador = 0;
 
void setup() {
    // Activamos los pines de entrada y salida
    pinMode(pulsadorPin, INPUT);
    pinMode(ledPin, OUTPUT);
}
 
void loop() {
    // Leemos el valor del pin
    valorPulsador = digitalRead(pulsadorPin);
 
  // Encendemos o apagamos el pin del LED según convenga
  if (valorPulsador == HIGH) {
      digitalWrite(ledPin, HIGH);
  }
  else {
      digitalWrite(ledPin, LOW);
  }
