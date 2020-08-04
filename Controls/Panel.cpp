#include "Panel.h"

Panel::Panel(Border *border, Color textColor, Color backgroundColor) :
    Control(0,0,0,0,border,textColor,backgroundColor){
}

Panel::~Panel() {}

void Panel::CalculateSize() {
    short tempWidth = 0;
    short tempHeight = 0;
    for (int i=0; i<controls.size(); i++) {
        short controlMaxX = controls[i]->getLeft() + controls[i]->getWidth();
        if (controlMaxX > tempWidth) {
            tempWidth = controlMaxX;
        };
        short controlMaxY = controls[i]->getTop() + controls[i]->getHeight();
        if (controlMaxY > tempHeight) {
            tempHeight = controlMaxY;
        };
    }
    setHeight(tempHeight);
    setWidth(tempWidth);
}

void Panel::addControl(Control* control) {
    controls.push_back(control);
    if (getFocus() == nullptr && control->canGetFocus()) {
        setFocus(*control);
    }
    CalculateSize();
}

void Panel::draw(Graphics &g, int x, int y, size_t z) {
    if (z == 0) {
        Control::draw(g,x,y,z);
        for (int i=0; i<controls.size(); i++) {
            int relativeX = controls[i]->getLeft();
            int relativeY = controls[i]->getTop();
            controls[i]->draw(g,x + relativeX,y + relativeY,z);
        }
    }
}

void Panel::mousePressed(int x, int y, bool isLeft) {
    for (Control* control : controls)
    {
        control->mousePressed(x,y,isLeft);
    }
}

void Panel::getAllControls(vector<Control*>* controls) { *controls = this->controls; }