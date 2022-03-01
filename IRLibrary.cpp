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
            if (timeLow > 4400 || timeLow < 4600)
            {
                aux = 1;
            }
        }
    } while (aux == 0);
    stateMachine = 1;

    return;
}

void decodingSignal()
{
    timeHigh = 0;
    timeLow = 0;
    do
    {
        signal = digitalRead(pin);
        if (signal)
        {
            timeHigh = micros();
        }
        else if (!signal)
        {
            timeLow = micros();
        }
        else if (timeHigh > 580 || timeHigh < 600)
        {
            if (timeLow > 1680 || timeLow < 1700)
            {
                decode = (decode << 1) + 1;
                bitContagem++;
            }
            else if (timeLow > 580 || timeLow < 600)
            {
                decode = decode << 1;
                bitContagem++;
            }
        }
    } while (bitContagem <= 32)
    stateMachine = 2;
}

void showingTheSignalCode(){
    Serial.print("Controller in HEX: ");
    Serial.prinln(decode, HEX);
    Serial.print("Controller in BIN: ");
    Serial.prinln(decode);
}