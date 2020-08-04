#include "Button.h"
#include <Graphics.h>

Button::Button(string value, string id, short left, short top, Border *border, Color textColor, Color backgroundColor) : Label(
        value, left, top, border, textColor, backgroundColor), id(id) {}

void Button::mousePressed(int x, int y, bool isLeft) {
    if ((((x >= left) && (x <= left + width)) && ((y >= top) && (y <= top + height))) && isLeft) {
        listener->buttonPressed(id);
    }
}

void Button::setListener(ButtonListener *listener) {
    this->listener = listener;
}