#include "Snake.h"
#include <time.h>
#include <conio.h>
bool gameOver=false;
int height=20;
    int width=20;
    int x=10,y=10,fx=2,fy=2,life=3,score=0;
    int tailX[100],tailY[100], ntail=0;
void draw()
{
   system("cls");
   for(int i=0;i<=width;i++){
     for(int j=0;j<=height;j++)
     {
         if(j==0 || i==0 || i==20 || j==20)
         {
             printf("%c",'|');
         }
         else{
            if(i==y && j==x)
                printf("%c",'V');
            else{
                if(i==fy && j==fx)
                printf("%c",'u');
                else
                    printf("%c",' ');
            }
         }
     }printf("\n");
   }
}
void input()
{
    if(_kbhit())
    {
        switch(_getch()){
        case 'w':  dir=UP;   break;
        case 'a':  dir=LEFT;   break;
        case 's':  dir=DOWN;   break;
        case 'd':  dir=RIGHT;   break;
        case 'x': gameOver=true; break;
        default: break;
        }
    }
}
void logic()
{
    int prevX,int prevY, prev2X, prev2Y;
    tailX
    srand(time(0));
    switch(dir)
    {
       case UP:  y--; break;
       case DOWN:  y++; break;
       case LEFT:  x--; break;
       case RIGHT: x++; break;
       default: break;
    }
    if(x==width || y==height || x==0 || y==0)
        gameOver=true;
    if(x==fx && y==fy){
        score++;
     fx=1+rand()%18;
     fy=1+rand()%18;
     ntail++;
    }
}
void run(char c)
{

    if(c=='\n'){
        while(!gameOver)
        {
            draw();
            input();
            logic();
        }
        if(gameOver)
        {
            printf("Well played, your score is:%i",score);
        }
    }
}
