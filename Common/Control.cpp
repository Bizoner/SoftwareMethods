#include "Control.h"

Control::Control(short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor) :
        left(left), top(top), width(width), height(height), border(border), textColor(textColor), backgroundColor(backgroundColor) {}

Control::~Control() {
}

void Control::draw(Graphics& g, int x, int y, size_t z) {
    g.setForeground(textColor);
    g.setBackground(backgroundColor);
    g.setCursorVisibility(false);
    if (border) {
        border->drawBorder(g,x, y, width, height);
    }
}

Control* Control::focus = nullptr;
void Control::setFocus(Control &control) {
    if(control.canGetFocus()) {
        focus = &control;
    }
}
