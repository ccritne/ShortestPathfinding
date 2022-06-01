#pragma once

#include "NecessaryLib.hpp"

class Textbox: public Drawable, public Transformable
{
    private:
        RectangleShape box;
        Text text;
        float h;
        float w;

        virtual void draw(RenderTarget& target, RenderStates states) const{    
            target.draw(box);
            target.draw(text);
        }
    public:
        Textbox(float x, float y, float width, float height, Font& font);
        void setText(string text);
        Vector2f getCoord();
        dim getDim();
        string getText();
        FloatRect getGlobalBounds();
        void setCharacterSize(int dim);
};

Textbox::Textbox(float x, float y, float width, float height, Font& font){
    h = height;
    w = width;

    box.setPosition(Vector2f(x, y));
    box.setSize(Vector2f(width, height));
    box.setOutlineThickness(1);
    box.setFillColor(Color::Black);
    box.setOutlineColor(Color::White);

    text.setFont(font);
    text.setPosition(Vector2f(x, y));
    text.setCharacterSize(12);
    text.setString("");
}

void Textbox::setText(string txt){
    text.setString(txt);
}

string Textbox::getText(){
    return text.getString();
}

Vector2f Textbox::getCoord(){
    return box.getPosition();
}

dim Textbox::getDim(){
    return {w, h};
}

void Textbox::setCharacterSize(int dim){
    text.setCharacterSize(dim);
}

FloatRect Textbox::getGlobalBounds(){
    return box.getGlobalBounds();
}