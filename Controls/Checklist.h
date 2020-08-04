#pragma once

#include <Control.h>
#include "ButtonListener.h"
#include "ListItem.h"

class Checklist : public Control, public ButtonListener {
    public:
        Checklist(vector<string> options,short left, short top, short width, Border* border, Color textColor, Color backgroundColor);
        void draw(Graphics& g, int x, int y, size_t z);
        void buttonPressed(string buttonId) {}
        void keyDown(int keyCode, char character);
        void setFocus(Control& control);
        bool canGetFocus(){ return true; }
        bool addSelectedItem(string item);
        bool removeSelectedItem(string item);
        vector<string> getSelectedItems() {return selectedItems;};
    protected:
        int currentOption;
        vector<string> selectedItems;
        vector<ListItem *> items;
        void handleSelection(int index);
};