#pragma once

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

RenderWindow window;
Event event;

int R = 10;
int C = 10;

int xStart = 0;
int yStart = 0;

int xTarget = R-1;
int yTarget = C-1;

int xStartG;
int yStartG;

double marginCeilsX;
double marginCeilsY;

double width;
double height;

double widthrect;
double heightrect;

int x;
int y;

int i, j;

RectangleShape perimeter;
vector<vector<RectangleShape>> rects;
//White => Void
//Black => Wall
//Green => Start
//Red   => End