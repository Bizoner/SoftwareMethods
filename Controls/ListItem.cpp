#include "ListItem.h"

ListItem::ListItem(string value, string id, string symbol, short left, short top, short width, Border *border, Color textColor,
                   Color backgroundColor) : Button(value, id, left, top, border, textColor, backgroundColor),
                   initTextColor(textColor), initBackgroundColor(backgroundColor), symbol(symbol){
    setWidth(width);
}

bool ListItem::toggleSelected() {
    isSelected = !isSelected;
    return isSelected;
}
void ListItem::setActive(bool isActive) {
    active = isActive;
    if (isActive) {
        setBackgroundColor(initTextColor);
        setTextColor(initBackgroundColor);
    } else {
        setBackgroundColor(initBackgroundColor);
        setTextColor(initTextColor);
    }
}

void ListItem::draw(Graphics& g, int x, int y, size_t z) {
    if (z == 0) {
        Button::draw(g, x, y, z);
        if (isSelected) {
            g.write(x + 1, y + 1, "(" + symbol + ") ");
        } else {
            g.write(x + 1, y + 1, "( ) ");
        }
        g.write(x + 5, y + 1, getValue());
    }
}