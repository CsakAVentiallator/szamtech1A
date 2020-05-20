#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
enum Direction{STOP=0,LEFT,RIGHT,UP,DOWN}dir;//a lehetseges iranyok
bool gameOver=false;
int height;
    int width;
    int x,y,fx=2,fy=2,life=3,score=0,LifeCounter=3;
    int tailX[100],tailY[100], ntail=0; //a source fajlban hasznalt valtozok
void getMap();//beolvassa a palya meretei es a jatekos nevet
void Catalogue();//kiirja egy allomanyba a jatekos nevet es eredmenyet
void draw();//megrajzolja a palyat, a vonatot es a vagonokat
void input();//beolvassa a leutott karaktert
void logic();//kezeli a lutott karaktert
void run(char c);//futtatja a jatekot
#endif // SNAKE_H_INCLUDED
