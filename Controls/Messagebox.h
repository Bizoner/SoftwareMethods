#include <Control.h>
#include "Button.h"

class Messagebox : public Control, public ButtonListener {
public:
    Messagebox(string message, short left, short top, Border* border, Color textColor, Color backgroundColor);
    void draw(Graphics& g, int x, int y, size_t z);
    void buttonPressed(string buttonId);
    void mousePressed(int x, int y, bool isLeft);
    string getSelectedValue(){return selectedValue;}
private:
    Label message;
    Button confirm;
    Button cancel;
    bool isOpen = true;
    string selectedValue;
};