#include "software.h"
#include "tswerve.h"

Software::Software() {
    initialize();
}

void Software::initialize() {
    //menuInterface.drawMenuInterface();
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
          else if (nonkButton.isClicked()) {
            currentkey = 'n';
          }
      }
      else if (currentkey == 'b') {
          basicInterface.refreshInterface();
      }
      else if (currentkey == 'n') {
          nonkInterface.refreshInterface();
      }
      
    }

    //updating values to the brain
    if (currentkey == 'b') {
        Brain.Screen.printAt(50,45,"%f",ModR.absAngle);
        Brain.Screen.printAt(196,45,"%f",ModG.absAngle);
        Brain.Screen.printAt(340,45,"%f",ModB.absAngle);
    }
    else if (currentkey == 'n') {
        Brain.Screen.printAt(60,20,"target: %f",Drivetrain.targetHd);
        Brain.Screen.printAt(60,40,"abs: %f",ModR.absAngle);
        Brain.Screen.printAt(60,60,"error: %f",ModR.error);
        Brain.Screen.printAt(60,80,"%d",ModR.revdrive);
    }

    lastX = x1;
    lastY = y1;
}

char Software::getKey() {
    return currentkey;
}