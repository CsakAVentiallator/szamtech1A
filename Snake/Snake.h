#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
enum Direction{STOP=0,LEFT,RIGHT,UP,DOWN}dir;
void draw();
void input();
void logic();
void run(char c);
void ScoreCounter();
void LevelCounter();
void LifeCounter();
#endif // SNAKE_H_INCLUDED
