#pragma once
#include <string>

class Board1
{
private:
    bool show_demo_window;
    float f;
    int currentItem = 0;
    bool inputClicked;
    std::string input;
    double d;

public:
    Board1();
    void resize(const int &width, const int &height);
    void draw();
};