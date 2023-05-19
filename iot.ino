#include <Keypad.h>

int LDR1 = A15;
int LDR2 = A14;
int LDR3 = A13;
int LDR4 = A12;

int servo = A0;

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
    Serial.begin(9600);
    pinMode(LDR1, INPUT);
    pinMode(LDR2, INPUT);
    pinMode(LDR3, INPUT);
    pinMode(LDR4, INPUT);
    pinMode(servo, OUTPUT);
}

void loop() {

    float ldr1 = analogRead(LDR1);
    float ldr2 = analogRead(LDR2);
    float ldr3 = analogRead(LDR3);
    float ldr4 = analogRead(LDR4);

    ldr1 = map(ldr1, 38, 1022, 0, 100);
    ldr2 = map(ldr2, 38, 1022, 0, 100);
    ldr3 = map(ldr3, 38, 1022, 0, 100);
    ldr4 = map(ldr4, 38, 1022, 0, 100);
    
    float avg = (ldr1 + ldr2 + ldr3 + ldr4) / 4.0;

    if (avg <= 60) {
        digitalWrite(servo, 255);
    }

    char key = keypad.getKey();

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