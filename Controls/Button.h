#pragma once
#include "Label.h"
#include "ButtonListener.h"

class Button : public Label {
    public:
        Button(string value, string id, short left, short top, Border* border, Color textColor, Color backgroundColor);
        void mousePressed(int x, int y, bool isLeft);
        void setListener(ButtonListener* listener);
    protected:
        string id;
        ButtonListener* listener;
};
