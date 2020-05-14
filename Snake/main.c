#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Snake.c"
int main()
{
    enum Direction{STOP=0,LEFT,RIGHT,UP,DOWN};
    int height=20;
    int width=20;
    int x,y,fx,fy,life=3,score=0;
    bool gameOver;
   printf("Press enter to start!");
   char c;
   scanf("%c",&c);
   if(c=='\n')
   {
       draw(width,height);
   }
   else
    printf("See you later!");
    return 0;
}
