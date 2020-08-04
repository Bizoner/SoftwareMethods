#include "Textbox.h"

Textbox::Textbox(short maxTextSize, short left, short top, Border *border, Color textColor, Color backgroundColor) : Label(
        string(maxTextSize, ' '), left, top, border, textColor, backgroundColor) {
    setValue("");
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    cursor = { static_cast<SHORT>(left + 1), static_cast<SHORT>(top + 1) };
    SetConsoleCursorPosition(handle, cursor);
}

void Textbox::mousePressed(int x, int y, bool isLeft) {
    if ((((x > left) && (x < left + width)) && ((y > top) && (y < top + height))) && isLeft) {
        auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
        if (x > left + getValue().size()) {
            cursor = {static_cast<SHORT>(left + getValue().size()),static_cast<SHORT>(y)};
        } else {
            cursor = {static_cast<SHORT>(x),static_cast<SHORT>(y)};
        }
        SetConsoleCursorPosition(handle, cursor);
    }
}

void Textbox::keyDown(int keyCode, char character) {
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    size_t offset = cursor.X - left;
    if((keyCode >= 0x30  && keyCode <= 122) || keyCode == VK_SPACE){
        if(value.size() >= width) return;
        value.insert(offset - 1, &character);
        cursor = { static_cast<SHORT>(cursor.X + 1), cursor.Y };
        SetConsoleCursorPosition(handle, cursor);
    }
    if (keyCode == VK_RIGHT) {
        if (offset-1 < value.size()) {
            cursor = { static_cast<SHORT>(cursor.X + 1), cursor.Y };
            SetConsoleCursorPosition(handle, cursor);
        }
    }
    if (keyCode == VK_LEFT) {
        if (offset-1 > 0) {
            cursor = { static_cast<SHORT>(cursor.X - 1), cursor.Y };
            SetConsoleCursorPosition(handle, cursor);
        }
    }
    if(value.size() > 0 && (keyCode == VK_BACK || keyCode == VK_DELETE)){
        if(keyCode == VK_BACK && value.size() > 0){
            if(offset - 1 > 0){
                value.erase(value.begin() + offset - 2);
                cursor = { static_cast<SHORT>(cursor.X - 1), cursor.Y };
            }
        }
    }
}

void Textbox::draw(Graphics& g, int x, int y, size_t z){
    if (z == 0) {
        Label::draw(g, x, y, z);
    } else {
        g.moveTo(cursor.X, cursor.Y);
        g.setCursorVisibility(true);
    }
}

