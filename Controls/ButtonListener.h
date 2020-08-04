#pragma once
#include <iostream>

class ButtonListener {
    public:
        virtual void buttonPressed(string buttonId) = 0;
};