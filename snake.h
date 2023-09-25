#ifndef __SNAKE__
#define __SNAKE__

#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 30
#define LEFT_SIDE 20
#define TOP_SIDE 5
#define SNAKE_LENGTH_MAX 50

struct couple{
  int i;
  int j;
};

extern int SNAKE_LENGTH;
extern struct couple SNAKE[SNAKE_LENGTH_MAX];
extern struct couple FRUIT;
extern int SPEED;

void mySleep(float delay);
void printGrille();
void moveSnake(int *key2);
void printSnake();
void cleanSnake();
void printFruit();
void affichage();

#endif 
