#include <Arduino.h>
#include "IRLibrary.h"

void testingInitialSignal()
{
    int aux = 0;
    do
    {
        startSignal = digitalRead(pin);
        if (startSignal)
        {
            timeHigh = micros();
        }
        else if (!startSignal)
        {
            timeLow = micros();
        }
        else if (timeHigh > 4400 || timeHigh < 4600)
        {
            if (timeLow > 4400 || timeLow < 4600) {
                aux = 1;
            }
        }
    } while (aux == 0);
    stateMachine = 1;

    return;
}

void decodingSignal() {
    timeHigh = 0;
    timeLow = 0;
    do{
        signal = digitalRead(pin);

    }while (bitContagem <= 32)
}