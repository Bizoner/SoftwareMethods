#include <Border/SingleBorder.h>
#include "Radiobox.h"

Radiobox::Radiobox(vector<string> options, short left, short top, short width, Border *border, Color textColor, Color backgroundColor) :
Control(left, top, width, top, border, textColor, backgroundColor) {
    for (int i=0; i<options.size(); i++) {

        items.push_back(new ListItem(options[i],options[i],"o",left + 1,(items.size() * 3) + 1,width - 2,new SingleBorder(), textColor, backgroundColor));
    }
    setHeight((items.size() * 3) + 1);
}

void Radiobox::draw(Graphics& g, int x, int y, size_t z) {
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

bool Radiobox::selectItem(int itemIndex) {
    if (selectedIndex != -1) {
        items[selectedIndex]->toggleSelected();
    }
    items[itemIndex]->toggleSelected();
    selectedItem = items[itemIndex]->getValue();
    selectedIndex = itemIndex;
    return true;
}

bool Radiobox::clearItem() {
    selectedItem = "";
    items[selectedIndex]->toggleSelected();
    selectedIndex = -1;
    return true;
}

void Radiobox::handleSelection(int index) {
    bool selected = items[index]->getIsSelected();
    if (!selected) {
        selectItem(index);
    } else {
        clearItem();
    }
}

void Radiobox::keyDown(int keyCode, char character) {
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