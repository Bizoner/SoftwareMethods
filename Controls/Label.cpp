#include "Label.h"
#include <iostream>

Label::Label(string value,short left, short top, Border* border, Color textColor, Color backgroundColor) :
    Control(left,top,value.size(),1,border,textColor,backgroundColor), value(value) {};

string Label::getValue()
{
    return this->value;
}

void Label::setValue(string value)
{
    this->value = value;
}


void Label::draw(Graphics& g, int x, int y, size_t z)
{
    if (z == 0) {
        Control::draw(g,x,y,z);
        g.write(x + 1, y + 1, value);
    }
}
