#pragma once

#include <Control.h>
#include "ButtonListener.h"
#include "ListItem.h"

class Radiobox : public Control {
    public:
        Radiobox(vector<string> options,short left, short top, short width, Border* border, Color textColor, Color backgroundColor);
        void draw(Graphics& g, int x, int y, size_t z);
        void keyDown(int keyCode, char character);
        void setFocus(Control& control);
        bool canGetFocus(){ return true; }
        bool selectItem(int item);
        bool clearItem();
    protected:
        int currentOption = -1;
        string selectedItem;
        int selectedIndex = -1;
        vector<ListItem *> items;
        void handleSelection(int index);
};