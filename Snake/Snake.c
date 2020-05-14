#include "Snake.h"
#include <time.h>

void Setup(int x,int y,int fx, int fy,int height, int width,bool gameOver)
{
    srand(time(0));
    gameOver=false;
    x=width/2;
    y=height/2;
    fx=1+rand()%18;
    fy=1+rand()%18;
}
void draw(int width, int height)
{
   system("cls");

   for(int i=0;i<=width;i++){
     for(int j=0;j<=height;j++)
     {
         if(j==0 || i==0 || i==20 || j==20)
         {
             printf("%c",'|');
         }
         else
            printf("%c",' ');
     }printf("\n");
   }
}
