#pragma once
#include "../Common/Control.h"
#include <string>


using namespace std;

class Label: public Control
{
    protected:
        string value;
    public:
        Label(string value,short left, short top, Border* border, Color textColor, Color backgroundColor);
        string getValue();
        void setValue(string);
        void draw(Graphics& g, int x, int y, size_t z);
};