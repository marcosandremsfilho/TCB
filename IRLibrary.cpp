#include <Arduino.h>

#define pin 2

unsigned long time;
unsigned long decode;
unsigned long highSignal;
unsigned long lowSignal;
unsigned long signal;

int maquina = 0;

void setup() {
    pinMode(pin, INPUT);
}

void loop(){
    switch(maquina){

    }
   

}

void inicial() {
    signal = digitalRead(pin);
}