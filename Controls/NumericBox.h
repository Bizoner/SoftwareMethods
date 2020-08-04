#pragma once
#include <Control.h>
#include "Button.h"

class NumericBox : public Control, public ButtonListener {
    protected:
        int maxValue;
        int minValue;
        Label value;
        Button addButton;
        Button subtractButton;
    public:
        NumericBox(int maxValue, int minValue,short left, short top, Border* border, Color textColor, Color backgroundColor);
        void draw(Graphics& g, int x, int y, size_t z);
        void mousePressed(int x, int y, bool isLeft);
        void buttonPressed(string buttonId);
};
