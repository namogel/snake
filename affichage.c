#include "snake.h"

void printGrille(){
  attron(COLOR_PAIR(1));
  //barres verticales
  for(int i=-1; i<=WIDTH; i++){
    mvprintw(TOP_SIDE+i,LEFT_SIDE-1," ");
    mvprintw(TOP_SIDE+i,LEFT_SIDE+3*WIDTH," ");
  }
  //barres horyzontales
  for(int i=-1; i<=3*WIDTH; i++){
    mvprintw(TOP_SIDE-1,LEFT_SIDE+i," ");
    mvprintw(TOP_SIDE+WIDTH,LEFT_SIDE+i," ");
  }
  attroff(COLOR_PAIR(1));
}

void moveSnake(int *key2){
  int key=*key2;
  for(int k=SNAKE_LENGTH;k>0; k--)
    SNAKE[k]=SNAKE[k-1];
  switch(key){
  case KEY_RIGHT: //déplacement vers la droite
    SNAKE[0].i=((SNAKE[0].i)+2)%(3*WIDTH);
    //timeout(80);
    timeout(SPEED);
    break;
  case KEY_LEFT: //déplacement vers la gauche
    SNAKE[0].i=((SNAKE[0].i)+3*WIDTH-2)%(3*WIDTH);
    //timeout(80);
    timeout(SPEED);
    break;
  case KEY_DOWN: //déplacement vers le bas
    SNAKE[0].j=((SNAKE[0].j)+1)%WIDTH;
    //timeout(60);
    timeout(SPEED*4/5);
    break;
  case KEY_UP: //déplacement vers le haut
    SNAKE[0].j=((SNAKE[0].j)+WIDTH-1)%WIDTH;
    //timeout(60);
    timeout(SPEED*4/5);
    break;
  }
  key=getch();
  if ((key==KEY_RIGHT && *key2!=KEY_LEFT) || (key==KEY_UP && *key2!=KEY_DOWN) || (key==KEY_DOWN && *key2!=KEY_UP) || (key==KEY_LEFT && *key2!=KEY_RIGHT)) 
    *key2=key;
}

void printSnake(){
  attron(COLOR_PAIR(2));
  for(int k=0;k<SNAKE_LENGTH; k++){
    mvprintw(TOP_SIDE+(SNAKE[k]).j,LEFT_SIDE+(SNAKE[k]).i," ");
    mvprintw(TOP_SIDE+(SNAKE[k]).j,LEFT_SIDE+(SNAKE[k]).i+1," ");
  }
  attroff(COLOR_PAIR(2));
}

void cleanSnake(){
  attron(COLOR_PAIR(3));
  mvprintw(TOP_SIDE+SNAKE[SNAKE_LENGTH].j,LEFT_SIDE+(SNAKE[SNAKE_LENGTH]).i," ");
  mvprintw(TOP_SIDE+SNAKE[SNAKE_LENGTH].j,LEFT_SIDE+(SNAKE[SNAKE_LENGTH]).i+1," ");
  attroff(COLOR_PAIR(3));
}

void printFruit(){
  int k=0;
  srand (time (NULL));
  FRUIT.j=(1+ (rand()%(WIDTH-1)));
  FRUIT.i=(1+ (rand()%(3*(WIDTH-1)/2)));
  while(k < SNAKE_LENGTH){
    while((FRUIT.j == SNAKE[k].j) &&  (2*FRUIT.i == SNAKE[k].i)){
      FRUIT.j=(1+ (rand()%(WIDTH)));
      FRUIT.i=(1+ (rand()%(3*WIDTH/2)));
    }
    k++;
  }
  FRUIT.i*=2;
  attron(COLOR_PAIR(1));
  mvprintw(TOP_SIDE+FRUIT.j,LEFT_SIDE+FRUIT.i,"(");
  mvprintw(TOP_SIDE+FRUIT.j,LEFT_SIDE+FRUIT.i+1,")");
  attroff(COLOR_PAIR(1));
}
/*do{
  FRUIT.i=(1+ (rand()%(WIDTH)));
  }while(FRUIT.i == FRUIT.j);*/
