#pragma once
#include <Graphics.h>
#include <Control.h>

class Panel : public Control {
    private:
        vector<Control*> controls;
        int currentControlIndex;
        void CalculateSize();
    public:
        Panel(Border* border, Color textColor, Color backgroundColor);
        ~Panel();
        void addControl(Control* control);
        virtual void draw(Graphics& g, int x, int y, size_t z);
        void mousePressed(int x, int y, bool isLeft);
        void getAllControls(vector<Control*>* controls);
};

