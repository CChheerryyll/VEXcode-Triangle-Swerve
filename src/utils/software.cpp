#include "software.h"

Software::Software() {
    initialize();
}

void Software::initialize() {
    //testInterface.drawTestInterface();
}

void Software::refresh() {
    int x1 = Brain.Screen.xPosition();
    int y1 = Brain.Screen.yPosition();

    if (lastX != x1 || lastY != y1) {
      if (menuOpenButton.isClicked() && currentkey != 'm') {
          currentkey = 'm';
      }
      else if (testButton.isClicked()) {
          currentkey = 't';
      }
      else if (basicButton.isClicked()) {
          currentkey = 'b';
      }

      if (currentkey == 't') {
          testInterface.refreshInterface();
      }
      else if (currentkey == 'm') {
          menuInterface.refreshInterface();
      }
      else if (currentkey == 'b') {
          basicInterface.refreshInterface();
      }
      
    }

    lastX = x1;
    lastY = y1;
}

char Software::getKey() {
    return currentkey;
}