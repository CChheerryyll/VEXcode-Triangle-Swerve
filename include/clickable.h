#include "vex.h"

#ifndef CLICKABLE_H
#define CLICKABLE_H

class Clickable {
    public:

    int lastClickedX, lastClickedY;
    int x_1, y_1, x_2, y_2;
    char flag = ' ';

    Clickable();
    
    /**
     * @brief x2>x1, y2>y1
     */
    Clickable(int x1, int x2, int y1, int y2, char f);

    bool isClicked();

    char getFlag();
};

#endif