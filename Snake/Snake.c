#include "Snake.h"
#include <time.h>
#include <conio.h>
bool gameOver=false;
int height=20;
    int width=20;
    int x=10,y=10,fx=2,fy=2,life=3,score=0,LifeCounter=3;
    int tailX[100],tailY[100], ntail=0;
int createMap(int width, int lenght)
{
    int **Map;
    Map=(int**)malloc(width*sizeof(int*));
    for(int i=0;i<=height;i++)
    {
        Map[i]=(int*)malloc(width*sizeof(int));
    }
    return Map;
}
int getMap()
{
    int **Map;
    fscanf("map.txt","%i\n",&width);
    fscanf("map.txt","%i\n",&height);
    Map=createMap(width, height)
    for(int i=0;i<=width;i++){
     for(int j=0;j<=height;j++)
     {
         fscanf("map.txt","%i\n",&Map[i][j]);
     }
    }
    return Map;
}
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
                else{
               bool print=false;
                for(int k=0;k<ntail;k++)
                {
                    if(tailX[k]==j && tailY[k]==i){
                    printf("%c",'z');
                    print=true;
                    }
                }
                if(!print)
                 printf("%c",' ');
                }
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
        case 'x': gameOver=true; LifeCounter=0; break;
        default: break;
        }
    }
}
void logic()
{
    int prevX=tailX[0], prevY=tailY[0], prev2X, prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<ntail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    srand(time(0));
    switch(dir)
    {
       case UP:  y--; break;
       case DOWN:  y++; break;
       case LEFT:  x--; break;
       case RIGHT: x++; break;
       default: break;
    }
    if(x==width || y==height || x==0 || y==0){
        gameOver=true;
        LifeCounter--;
        x=width/2;
        y=height/2;
    }
    for(int i=1;i<ntail;i++)
    {
        if(x==tailX[i] && y==tailY[i])
        {
            gameOver=true;
        LifeCounter--;
        x=width/2;
        y=height/2;
        }
    }
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
        while(!gameOver || LifeCounter)
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
    else{
        printf("if you want to play press enter :)");
    }
}
