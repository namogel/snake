#include "snake.h"
#define TAILLE_MAX 200

int SNAKE_LENGTH=10;
struct couple SNAKE[SNAKE_LENGTH_MAX];
struct couple FRUIT;
int SPEED=80;

void mySleep(float delay){
  float t1=clock();
  float t2;
  do{
    t2=clock();
  }while((t2-t1)/CLOCKS_PER_SEC<delay);
}

void message(unsigned char var){
  unsigned char debut, fin, y2;
  int whereX, whereY;
  y2=0;
  //message d'acceuil
  if(var==1){
    debut=20;
    fin=54;
    whereY=0;
    whereX=3;
  }
  //message de défaite
  else if(var==2){
    debut=5;
    fin=17;
    whereY=TOP_SIDE+WIDTH/5;
    whereX=LEFT_SIDE+WIDTH/5;
  }
  
  FILE* fichier = NULL;
  fichier=fopen("ascii.txt","r");
  char chaine_actuelle[TAILLE_MAX] = "";
  
  if(fichier != NULL){
    attron(COLOR_PAIR(3+var));
    for(int y=1; fgets(chaine_actuelle,TAILLE_MAX,fichier) != NULL; y++){
      if(y>=debut && y <=fin){
	mvprintw(whereY+y2,whereX,"%s",chaine_actuelle);
	y2++;
      }
    }    
    fclose(fichier);
    attroff(COLOR_PAIR(3+var));
  }
  refresh();
}

void clean(){
  attron(COLOR_PAIR(3));
  for(int i=0;i<200;i++)
    mvprintw(i,0,"%200c",0x70);
  attroff(COLOR_PAIR(3));
  refresh();
}

void affichage(){
  int key2=KEY_RIGHT;
  unsigned char win=1, score=0;
  printGrille(); 
  printFruit();
  printSnake();
  refresh();
  int key=getch();
  while(win){
    cleanSnake();    
    moveSnake(&key2);
    printSnake();
    //if eaten generate new fruit
    if((SNAKE[0].j == FRUIT.j) && (SNAKE[0].i == FRUIT.i)){
      SNAKE_LENGTH++;
      score++;
      SPEED-=2;
      printFruit();
    }
    //if beaten you lose
    for(int k=1; k<SNAKE_LENGTH; k++){
      if((SNAKE[0].j == SNAKE[k].j) && (SNAKE[0].i == SNAKE[k].i)){
	win=0;
	k=SNAKE_LENGTH;
	clean();
	message(2);
	mvprintw(TOP_SIDE+WIDTH-3,LEFT_SIDE+2*WIDTH/5,"Votre score est: %d",score);
	printGrille();
      }
    }
    move(0,0);
    refresh();
  }
}

int main(){
  int key;
  for(int k=0;k<=SNAKE_LENGTH; k++){
    (SNAKE[k]).j=5;
    (SNAKE[k]).i=60-k;
  }    
  initscr();     
  keypad(stdscr, TRUE);
  cbreak();
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_BLACK, COLOR_BLUE); 
  init_pair(3, COLOR_BLACK, COLOR_BLACK); 
  init_pair(4, COLOR_WHITE, COLOR_BLACK); 
  init_pair(5, COLOR_RED, COLOR_BLACK); 
  message(1);
  key=getch();
  clean();
  affichage();
  timeout(100000);
  key=getch();
  endwin();
  return 0;
}

