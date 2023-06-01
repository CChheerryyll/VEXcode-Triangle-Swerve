#include "software.h"
#include "constants.h"

Software::Software() {
    initialize();
}

void Software::initialize() {
    //testInterface.drawTestInterface();
}

void Software::refresh() {
    int x1 = Brain.Screen.xPosition();
    int y1 = Brain.Screen.yPosition();
    
    //if anything's clicked
    if (lastX != x1 || lastY != y1) {
      if (menuOpenButton.isClicked() && currentkey != 'm') {
          currentkey = 'm';
      }

      if (currentkey == 't') {
          testInterface.refreshInterface();
      }
      else if (currentkey == 'm') {
          menuInterface.refreshInterface();
          if (testButton.isClicked()) {
            currentkey = 't';
          }
          else if (basicButton.isClicked()) {
            currentkey = 'b';
          }
      }
      else if (currentkey == 'b') {
          basicInterface.refreshInterface();
      }
      
    }

    if (currentkey == 'b') {
        float angleR = AngleR.rotation(deg)*ANGLE_RATIO;
        Brain.Screen.printAt(50,45,"%f",angleR);
        float angleG = AngleG.rotation(deg)*ANGLE_RATIO;
        Brain.Screen.printAt(196,45,"%f",angleG);
        float angleB = AngleB.rotation(deg)*ANGLE_RATIO;
        Brain.Screen.printAt(340,45,"%f",angleB);
    }

    lastX = x1;
    lastY = y1;
}

char Software::getKey() {
    return currentkey;
}