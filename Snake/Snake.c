#include "Snake.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
void getMap()
{
    char *l;//ebbe olvassa be a jatekos nevet
    l=(char*)malloc(20*sizeof(char));
    if(!l)
    {
        printf("Baj van fonok!");
        exit(1);
    }
    FILE*f;
    f=fopen("map.txt","rt");
    fscanf(f,"%i ",&width);
    fscanf(f,"%i\n",&height);
    fscanf(f,"%s",l);
    x=width/2;
    y=height/2;
    Catalogue(l);
}
void Catalogue(char *l)
{
    FILE*f;
    f=fopen("Katalogus.txt","wt");
    fprintf(f,"\nA jatekos neve: %s",l);
    fprintf(f," es az altala elert eredmeny: %i",score);
}
void draw()
{
   system("cls");
   for(int i=0;i<=width;i++){
     for(int j=0;j<=height;j++)
     {
         if(j==0 || i==0 || i==width || j==height)
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
        switch(_getch()){//a leutott karaktereket kezelo switch
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
        if(prev2X>=width || prev2Y>=height)
        {
            gameOver=true;
            LifeCounter=0;
        }
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    srand(time(0));
    switch(dir)//a mozgasokat megvalosito switch
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
     fx=1+rand()%(width-3);
     fy=1+rand()%(height-3);
     ntail++;
    }
}
void run(char c)
{

    getMap();
    if(c=='\n'){
        while(!gameOver || LifeCounter)
        {

            draw();
            input();
            logic();

        if(score%5==0 && score)
        {
            width-=2;
            height-=2;
            score++;
        }
        if(score>20){
            printf("You completed all 4 levels!!!\n");
            gameOver=true;
            LifeCounter=0;
        }
        }
        if(gameOver && !LifeCounter)
        {
            printf("Well played, your score is:%i",score);
        }
    }
    else{
        printf("if you want to play press enter :)");
    }
}
