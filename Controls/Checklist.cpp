#include <Border/SingleBorder.h>
#include "Checklist.h"

Checklist::Checklist(vector<string> options, short left, short top, short width, Border *border, Color textColor, Color backgroundColor) :
Control(left, top, width, top, border, textColor, backgroundColor) {
    for (int i=0; i<options.size(); i++) {
        items.push_back(new ListItem(options[i],options[i],"X",left + 1,(items.size() * 3) + 1,width - 2,new SingleBorder(), textColor, backgroundColor));
    }
    setHeight((items.size() * 3) + 1);
}

void Checklist::draw(Graphics& g, int x, int y, size_t z) {
    if (getFocus() == this) {
        if (currentOption == -1) {
            currentOption = 0;
        }
    } else {
        currentOption = -1;
    }
    if (z == 0) {
        Control::draw(g,x,y,z);
        for(int i=0; i<items.size(); i++) {
            items[i]->setActive(i == currentOption);
            items[i]->draw(g,items[i]->getLeft(),items[i]->getTop() + top,z);
        }
    }
}

bool Checklist::addSelectedItem(string item) {
    bool isOptionAvailable = false;
    int itemIndex;
    for (int i=0; i<items.size(); i++) {
        if (item == items[i]->getValue()) {
            isOptionAvailable = true;
            itemIndex = i;
        }
    };
    bool isOptionSelected = false;
    for (int i=0; i<selectedItems.size(); i++) {
        if (item == selectedItems[i]) {
            isOptionSelected = true;
        }
    };
    if (isOptionAvailable) {
        if (!isOptionSelected) {
            selectedItems.push_back(item);
            items[itemIndex]->toggleSelected();
        }
        return true;
    }
    return false;
}

bool Checklist::removeSelectedItem(string item) {
    bool isErased = false;
    for (int i=0; i<selectedItems.size(); i++) {
        if (item == selectedItems[i]) {
            items[i]->toggleSelected();
            selectedItems[i].erase();
            isErased = true;
        }
    }
    return isErased;
}

void Checklist::handleSelection(int index) {
    bool selected = items[index]->getIsSelected();
    if (!selected) {
        addSelectedItem(items[index]->getValue());
    } else {
        removeSelectedItem(items[index]->getValue());
    }
}

void Checklist::keyDown(int keyCode, char character) {
    switch(keyCode) {
        case VK_UP:
            if (currentOption > 0) {
                currentOption = currentOption - 1;
            } else {
                currentOption = items.size() - 1;
            }
            break;
        case VK_DOWN:
            if (currentOption < items.size() - 1) {
                currentOption = currentOption + 1;
            } else {
                currentOption = 0;
            }
            break;
        case VK_RETURN:
            handleSelection(currentOption);
            break;
    }
}

