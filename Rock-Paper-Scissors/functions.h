#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdlib.h>

using namespace std;

// store life in this variable
extern int life;
extern int w;

// take player input
int input();

// computer random number generator
int CompAI();

// display game over
int gameover();

// function for each selection of rock paper scissors
void rock();
void paper();
void scissors();

// error display
void default1();

// main game function
void selection();

// display game options
void info();

// check to see that you have enough life to keep playing
void check();

#endif
