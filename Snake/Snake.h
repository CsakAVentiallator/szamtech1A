#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
void Setup(int x,int y,int fx, int fy,int height, int width, bool gameOver);
void draw(int width, int height);
void ScoreCounter();
void LevelCounter();
void GeneratePoint();
void LifeCounter();
#endif // SNAKE_H_INCLUDED
