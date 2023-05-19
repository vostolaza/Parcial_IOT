#include <Keypad.h>
#include <Servo.h>

// Declaramos los pins de los LDRs
int LDR1 = A15;
int LDR2 = A14;
int LDR3 = A13;
int LDR4 = A12;

// Declaramos el servo
Servo servo;

// Declaramos las entradas del teclado
const byte ROWS = 2;
const byte COLS = 2;

char keys[ROWS][COLS] = {
  {'1','2'},
  {'3','4'}
};

byte rowPins[ROWS] = {39, 37};
byte colPins[COLS] = {31, 33};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


void setup() {
    // Hacemos el setup del Serial monitor
    Serial.begin(9600);
    // Inicializamos el tipo de pin
    pinMode(LDR1, INPUT);
    pinMode(LDR2, INPUT);
    pinMode(LDR3, INPUT);
    pinMode(LDR4, INPUT);
    servo.attach(2);
}

void loop() {

    // Leemos el valor de los LDRs
    float ldr1 = analogRead(LDR1);
    float ldr2 = analogRead(LDR2);
    float ldr3 = analogRead(LDR3);
    float ldr4 = analogRead(LDR4);


    // Convertimos sus valores de entrada de 10 bits (maximo 1024) a el máximo de 100
    ldr1 = map(ldr1, 38, 1022, 0, 100);
    ldr2 = map(ldr2, 38, 1022, 0, 100);
    ldr3 = map(ldr3, 38, 1022, 0, 100);
    ldr4 = map(ldr4, 38, 1022, 0, 100);
    
    // Obtenemos el promedio
    float avg = (ldr1 + ldr2 + ldr3 + ldr4) / 4.0;

    // En caso el promedio sea > a 60, encendemos el servo
    if (avg >= 60) {
        servo.write(180);
    }

    // Leemos el valor del keypad
    char key = keypad.getKey();

    // Si es que se presionó una tecla, mostramos el valor del LDR correspondiente
    if (key != NO_KEY) {
        if (key == '1'){ 
            Serial.println("LDR elegido: 1");
            Serial.println("Valor: " + String(ldr1) + "%");
        }
        if (key == '2'){ 
            Serial.println("LDR elegido: 2");
            Serial.println("Valor: " + String(ldr2) + "%");
        }
        if (key == '3'){ 
            Serial.println("LDR elegido: 3");
            Serial.println("Valor: " + String(ldr3) + "%");
        }
        if (key == '4'){ 
            Serial.println("LDR elegido: 4");
            Serial.println("Valor: " + String(ldr4) + "%");
        }
    }


}