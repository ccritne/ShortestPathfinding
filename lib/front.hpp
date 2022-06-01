#pragma once

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "vars.hpp"
#include "back.hpp"
using namespace std;
using namespace sf;


void createRects();
void ClickGrid();
void clearGrid();

void createRects(){

   rects.clear();

   xStartG = 50;
   yStartG = 50;
   
   marginCeilsX = 1;
   marginCeilsY = 1;
   
   width = window.getSize().x*0.95;
   height = window.getSize().y*0.95;
   
   widthrect = (width-marginCeilsX*(C-1))/C;
   heightrect = (height-marginCeilsY*(R-1))/R;
   
   x = xStartG;
   y = yStartG;

   vector<RectangleShape> tempVet;
   for(int i = 0; i < R; i++){
      x = xStartG;
      for(int j = 0; j < C; j++){
         RectangleShape tmp;
         tmp.setSize(Vector2f(widthrect, heightrect));
         tmp.setPosition(x, y);
         x += widthrect + marginCeilsX;
         tempVet.push_back(tmp);
      }
      rects.push_back(tempVet);
      tempVet.clear();
      y += heightrect + marginCeilsY;
   }

   width = x - xStartG;
   height = y - yStartG;

   rects[0][0].setFillColor(Color::Green);
   rects[R-1][C-1].setFillColor(Color::Red);

   perimeter.setSize(Vector2f(width, height));
   perimeter.setPosition(xStartG, yStartG);
   perimeter.setOutlineColor(Color::Green);
   
}

void ClickGrid(){
   
   //Clicked cell
   int mX = Mouse::getPosition(window).x;
   int mY = Mouse::getPosition(window).y;

   double mXminus = mX - xStartG; 
   double mYminus = mY - yStartG; 

   j = mXminus*C/width;
   i = mYminus*R/height;
   
   if(i >= 0 && i < R  && j >= 0 && j < C){
      if(Mouse::isButtonPressed(Mouse::Left))
            MouseLeft();
      if(Mouse::isButtonPressed(Mouse::Right))
            MouseRight();
   }
   

}

void clearGrid(){
   for(int  i = 0; i < R; i++)
      for(int j = 0; j < C; j++)
         rects[i][j].setFillColor(Color::White);
      
   rects[0][0].setFillColor(Color::Green);
   rects[R-1][C-1].setFillColor(Color::Red);
}