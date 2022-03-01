//#include <Arduino.h>
#ifndef IRLIBRARY.H
#define IRLIBRARY.H

// define sensro output pin 
#define pin 2

// time variables
float timeHigh;
float timeLow;

// decoding signal variables
unsigned long decode;
unsigned long highSignal;
unsigned long lowSignal;
int bitContagem;

//Reading singnal variables 
bool startSignal;
bool signal;

// Machine variables
int stateMachine;

#endif