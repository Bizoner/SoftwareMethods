#pragma once
#include "Graphics.h"
#include <vector>
#include <Border/Border.h>

using namespace std;

class Control
{

protected:
    short left;
    short top;
    short width;
    short height;
    Color backgroundColor;
    Color textColor;
    Border* border;
    static Control* focus;

public:
	Control();
    Control(short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor);
    static Control* getFocus() { return focus; };
    static void setFocus(Control& control);
	virtual void draw(Graphics& g, int x, int y, size_t z);
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	virtual short getLeft() { return left; };
	virtual short getTop() { return top; };
	virtual Color getBackgroundColor() { return backgroundColor;}
    virtual Color getTextColor() { return textColor;}
    virtual void setBackgroundColor(Color color) { this->backgroundColor = color;}
    virtual void setTextColor(Color color) { this->textColor = color;}
	virtual void setWidth(short width) { this->width = width;}
    virtual void setHeight(short height) { this->height = height;}
    virtual short getWidth() {
        if (border) {
            return width + 2;
        } else {
            return width;
        }
    };
    virtual short getHeight() {
        if (border) {
            return height + 2;
        } else {
            return height;
        }
    };
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return FALSE; };
	~Control();



};

