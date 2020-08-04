#pragma once
#include <string>
#include "Button.h"

using namespace std;

class ListItem : public Button {
public:
    ListItem(string value, string id, string symbol, short left, short top, short width, Border* border, Color textColor, Color backgroundColor);
    void draw(Graphics& g, int x, int y, size_t z);
    bool toggleSelected();
    void setActive(bool);
    bool getIsSelected(){ return isSelected;}
protected:
    Color initTextColor;
    Color initBackgroundColor;
    string symbol;
    bool active = false;
    bool isSelected = false;
};
