#pragma once

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "vars.hpp"
using namespace std;
using namespace sf;


bool isTarget(int, int);
bool isStart(int, int);
bool isWall(int, int);
bool containsMouse(RectangleShape);
bool containsMouse(Button);
bool containsMouse(Textbox);
void MouseLeft();
void MouseRight();
void bfsDj();

bool isTarget(int r, int c){
   if(r == xTarget && c == yTarget)
      return true;
   return false;
}

bool isStart(int r, int c){
   if(r == xStart && c == yStart)
      return true;

   return false;
}

bool isWall(int r, int c){
   if(rects[r][c].getFillColor() == Color::Black)
      return true;
   return false;
}

bool containsMouse(RectangleShape rect){

   if(rect.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
         return true;

   return false;
}

bool containsMouse(Button rect){

   if(rect.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
         return true;

   return false;
}

bool containsMouse(Textbox rect){

   if(rect.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
         return true;

   return false;
}

void MouseLeft(){
   if(!isStart(i,j) && !isTarget(i,j))
      rects[i][j].setFillColor(Color::Black);
}

void MouseRight(){

   if(!isStart(i,j) && !isTarget(i,j))
      rects[i][j].setFillColor(Color::White);
}

void bfsDj(){
   vector<vector<bool>> visited(R, vector<bool>(C, false));
   vector<vector<pair<int,int>>> prec(R, vector<pair<int, int>>(C));

   visited[xStart][yStart] = true;
   prec[xStart][yStart] = make_pair(-1,-1);

   list<pair<int,int>> queue;
   pair<int,int> node;

   int r = xStart;
   int c = yStart;

   queue.push_back(make_pair(xStart, yStart));

   while(!queue.empty()){
      node = queue.front();
      r = node.first;
      c = node.second;
      if(!isTarget(r,c)){
         if(!isStart(r,c))
         rects[r][c].setFillColor(Color::Yellow);

         queue.pop_front();

         //UP
         if( r > 0 && !isWall(r-1, c)){
            if(!visited[r-1][c]){
               prec[r-1][c] = make_pair(r, c);
               visited[r-1][c] = true;
               queue.push_back(make_pair(r-1,c));
            }
         }

         //LEFT
         if( c > 0 && !isWall(r, c-1)){
            if(!visited[r][c-1]){
               prec[r][c-1] = make_pair(r, c);
               visited[r][c-1] = true;
               queue.push_back(make_pair(r,c-1));
            }
         }

         //RIGHT
         if( c < C - 1 && !isWall(r, c+1)){
            if(!visited[r][c+1]){
               prec[r][c+1] = make_pair(r, c);
               visited[r][c+1] = true;
               queue.push_back(make_pair(r,c+1));
            }
         }

         //BOTTOM
         if( r < R - 1 && !isWall(r+1, c)){
            if(!visited[r+1][c]){
               prec[r+1][c] = make_pair(r, c);
               visited[r+1][c] = true;
               queue.push_back(make_pair(r+1,c));
            }
         }
      }else{
         break;
      }
      
   }

   if(isTarget(r,c)){
      r = prec[node.first][node.second].first;
      c = prec[node.first][node.second].second;

      while(!isStart(r,c)){
         rects[r][c].setFillColor(Color::Blue);
         node = make_pair(r, c);
         r = prec[node.first][node.second].first;
         c = prec[node.first][node.second].second;
      }
   }
}