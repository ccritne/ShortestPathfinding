#include "lib/TextBox.hpp"
#include "lib/Button.hpp"
#include "lib/front.hpp"
#include "lib/back.hpp"
#include "lib/vars.hpp"
using namespace std;
using namespace sf;

int main(){
   
	ContextSettings settings;
	settings.antialiasingLevel = 8;

   window.create(VideoMode(1920, 1080), "SHORTEST PATHFINDING DIJKSTRA", Style::Default, settings);
	window.setFramerateLimit(60);

   createRects();

   Font font;
   font.loadFromFile("need/arial.ttf");
   Button startBut(width/2 - 30, 10, 60, 30, font);
   startBut.setText("START");

   Button createBut(width/2 + 110, 10, 60, 30, font);
   createBut.setText("CREATE");

   Button ClearBut(width/2 + 40, 10, 60, 30, font);
   ClearBut.setText("CLEAR");

   Textbox txtR(width/2 - 150, 10, 30, 30, font);
   txtR.setText("10");
   Textbox txtC(width/2 - 80, 10, 30, 30, font);
   txtC.setText("10");

   string string_r = "10";
   string string_c = "10";
   
   Text txt_r, txt_c;

   txt_r.setFont(font);
   txt_r.setPosition(Vector2f(width/2 - 170, 18));
   txt_r.setCharacterSize(15);
   txt_r.setString("R:");

   txt_c.setFont(font);
   txt_c.setPosition(Vector2f(width/2 - 100, 18));
   txt_c.setCharacterSize(15);
   txt_c.setString("C:");

   bool start = false;
   bool drag = false;
   bool condR = false;
   bool condC = false;

   while(window.isOpen()){

		while (window.pollEvent(event)){

			if (event.type == Event::Closed)
				window.close();
         
         if (event.type == Event::MouseButtonPressed){
            drag = true;
         
            if(containsMouse(startBut))
               start = true;

            if(containsMouse(txtR))
               condR = true, condC = false;

            if(containsMouse(txtC))
               condC = true, condR = false;

            if(containsMouse(ClearBut))
               clearGrid();

            if(containsMouse(createBut)){
               if(isNumber(string_r) && isNumber(string_c)){
                  R = stoi(string_r);
                  C = stoi(string_c);
               }else{
                  R = 10;
                  C = 10;
               }
            
               xTarget = R - 1;
               yTarget = C - 1;
               
               createRects();
            }
         }
         
         if (event.type == Event::MouseButtonReleased)
            drag = false;

         if(event.type == Event::TextEntered && event.text.unicode != 8 && event.text.unicode != 13){
            char add = static_cast<char>(event.text.unicode);
            if(isdigit(add)){
               if(condR)
                  string_r += add;
               if(condC)
                  string_c += add;
            }
         }

         if (event.type == Event::KeyPressed && event.key.code == Keyboard::BackSpace){
            if(condR && !string_r.empty())
               string_r.pop_back();
            if(condC && !string_c.empty())
               string_c.pop_back();
         }

      }

      if(drag && containsMouse(perimeter))
         ClickGrid();
      
      if(txtR.getText() != string_r)
         txtR.setText(string_r);

      if(txtC.getText() != string_c)
         txtC.setText(string_c);

      if(start){
         bfsDj();
         start = false;
      }


      window.clear();
      
      for(int r = 0; r < R; r++)
         for(int c = 0; c < C; c++) 
            window.draw(rects[r][c]);

      window.draw(startBut);
      window.draw(createBut);
      window.draw(ClearBut);
      window.draw(txtR);
      window.draw(txt_r);
      window.draw(txtC);
      window.draw(txt_c);
      window.display();
      
   }   
   
   return 0;
}
