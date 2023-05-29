#include "clickable.h"

Clickable::Clickable() {

}

Clickable::Clickable(int x1, int x2, int y1, int y2, char f) {
    x_1 = x1;
    y_1 = y1;
    x_2 = x2;
    y_2 = y2;
    flag = f;
}

bool Clickable::isClicked() {
    bool clicked = false;
    lastClickedX = Brain.Screen.xPosition();
    lastClickedY = Brain.Screen.yPosition();

    if (lastClickedX >= x_1 && lastClickedX <= x_2) {
        //printf("herex\n");
        //printf("%d, %d, %c\n", y_1, lastClickedY, flag);
        if (lastClickedY >= y_1 && lastClickedY <= y_2) {
            clicked = true;
            //printf("here\n");
        }
    }
    return clicked;
}

char Clickable::getFlag() {
    return flag;
}