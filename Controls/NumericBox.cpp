#include "NumericBox.h"
#include "../Common/Border/SingleBorder.h"

NumericBox::NumericBox(int maxValue, int minValue, short left, short top, Border *border, Color textColor, Color backgroundColor) :
    Control(left, top, 13, 3, border, textColor, backgroundColor),
    addButton("+","add", left + 2, top + 1, new SingleBorder(), textColor, backgroundColor),
    value("0",left + 6, top + 1, new SingleBorder(), textColor, backgroundColor),
    subtractButton("-","subtract",left + 10, top + 1, new SingleBorder(), textColor, backgroundColor),
    maxValue(maxValue), minValue(minValue) {
        addButton.setListener(this);
        subtractButton.setListener(this);
}

void NumericBox::buttonPressed(string buttonId) {
    if (buttonId == "add") {
        int num = atoi(value.getValue().c_str());
        if (num + 1 <= maxValue) {
            value.setValue(to_string(num+1));
        }
    } else if (buttonId == "subtract") {
        int num = atoi(value.getValue().c_str());
        if (num - 1 >= minValue) {
            value.setValue(to_string(num-1));
        }
    }
}

void NumericBox::draw(Graphics &g, int x, int y, size_t z) {
    if (z == 0) {
        Control::draw(g,x,y,z);
        value.draw(g,value.getLeft(),value.getTop(),z);
        addButton.draw(g,addButton.getLeft(),addButton.getTop(),z);
        subtractButton.draw(g,subtractButton.getLeft(),subtractButton.getTop(),z);
    }
}

void NumericBox::mousePressed(int x, int y, bool isLeft) {
    addButton.mousePressed(x,y,isLeft);
    subtractButton.mousePressed(x,y,isLeft);
}

