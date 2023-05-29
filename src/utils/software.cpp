#include "software.h"

char currentkey = 't';
Interface testInterface = Interface('t');
Interface menuInterface = Interface('m');
int lastX = -1, lastY = -1;

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
      if (currentkey == 't') {
          testInterface.refreshInterface();
      }
      else if (currentkey == 'm') {
          
      }
      
    }

    lastX = x1;
    lastY = y1;
}

