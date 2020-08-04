#include <Border/SingleBorder.h>
#include "Messagebox.h"

Messagebox::Messagebox(string message, short left, short top, Border *border, Color textColor,Color backgroundColor) :
    Control(left, top, message.size() + 4, top, border, textColor, backgroundColor),
    message(Label(message,left + 2, top+3, nullptr, textColor, backgroundColor)),
    confirm(Button("OK",message+"ok",left + (message.size()/2) + 5, top+7, new SingleBorder, backgroundColor, textColor)),
    cancel(Button("Cancel",message+"cancel",left + (message.size()/2) - 5, top+7, new SingleBorder, backgroundColor, textColor)) {
    setHeight(10);
    confirm.setListener(this);
    cancel.setListener(this);
}

void Messagebox::draw(Graphics &g, int x, int y, size_t z) {
    if (z==0 && isOpen) {
        Control::draw(g,x,y,z);
        message.draw(g,message.getLeft(),message.getTop(),z);
        confirm.draw(g,confirm.getLeft(),confirm.getTop(),z);
        cancel.draw(g,cancel.getLeft(),cancel.getTop(),z);
    }
}

void Messagebox::mousePressed(int x, int y, bool isLeft) {
    confirm.mousePressed(x,y,isLeft);
    cancel.mousePressed(x,y,isLeft);
}

void Messagebox::buttonPressed(string buttonId) {
    isOpen = false;
    if (buttonId == message.getValue()+"ok") {
        selectedValue = "ok";
    } else {
        selectedValue = "cancel";
    }
}