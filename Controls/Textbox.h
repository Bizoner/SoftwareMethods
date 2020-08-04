#pragma once
#include "Label.h"

class Textbox : public Label {
    public:
        Textbox(short width, short left, short top, Border* border, Color textColor, Color backgroundColor);
        void mousePressed(int x, int y, bool isLeft);
        void keyDown(int keyCode, char character);
        bool canGetFocus(){ return true; }
        void draw(Graphics& g, int x, int y, size_t z);
    private:
        COORD cursor;
};
