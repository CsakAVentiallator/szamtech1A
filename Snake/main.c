#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Snake.c"
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
int main()
{
    system("COLOR F2");
   printf("Press enter to start!");
   char c;
   scanf("%c",&c);
   PlaySound(TEXT("C:\\Users\\Joco\\Documents\\GitHub\\szamtech1A\\Undertale - Megalovania.wav"),NULL,SND_ASYNC  | SND_FILENAME);

    run(c);

    return 0;
}
