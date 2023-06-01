#include "interface.h"

color gray = color(125,125,125);
color darkgray = color(70,70,70);
color lightblue = color(95,176,229);
color deepblue = color(34,36,70);
color lightred = color(223,73,103);
color deepred = color(156,38,62);
color lightcyan = color(63,213,213);
color deepcyan = color(35,48,148);
color lightgreen = color(73,233,66);
color deepgreen = color(40,137,36);
color lighterblue = color(170,217,249);

Clickable redMod = Clickable(60,140,10,90,'r');
Clickable greenMod = Clickable(170,250,90,170,'g');
Clickable blueMod = Clickable(60,140,150,230,'b');

Clickable angleRight = Clickable(430,460,95,125,'n');
Clickable angleLeft = Clickable(320,350,95,125,'n');
Clickable angleStop = Clickable(360,390,95,125,'n');
Clickable driveRight = Clickable(430,460,195,225,'n');
Clickable driveLeft = Clickable(320,350,195,225,'n');
Clickable driveStop = Clickable(360,390,195,225,'n');

Interface::Interface() {
    
}

Interface::Interface(char k) {
    key = k;
}

void Interface::drawTestInterface() {
    Brain.Screen.drawRectangle(0,0,480,240,deepblue);
    Brain.Screen.drawRectangle(0,0,40,240,lightblue);
    Brain.Screen.drawRectangle(280,0,200,240,black);
    Brain.Screen.drawLine(100,50,100,210);
    Brain.Screen.drawLine(100,50,210,130);
    Brain.Screen.drawLine(100,190,210,130);
    Brain.Screen.drawCircle(100,50,40,deepred);
    Brain.Screen.drawCircle(100,50,20,lightred);
    Brain.Screen.drawCircle(210,130,40,deepgreen);
    Brain.Screen.drawCircle(210,130,20,lightgreen);
    Brain.Screen.drawCircle(100,190,40,deepcyan);
    Brain.Screen.drawCircle(100,190,20,lightcyan);
    drawTriangleRight(10, 100, 20, lighterblue);
}

void Interface::drawMenuInterface() {
    Brain.Screen.drawRectangle(0,0,480,240,black);
    Brain.Screen.printAt(50,25,"MENU");
    Brain.Screen.drawRectangle(0,0,40,240,lightblue);
    drawTriangleRight(10, 100, 20, lighterblue);
    Brain.Screen.drawRectangle(40,40,220,100,black);
    Brain.Screen.drawRectangle(40,140,220,100,black);
    Brain.Screen.drawRectangle(260,40,220,100,black);
    Brain.Screen.printAt(50,70,"Test Mode");
    Brain.Screen.printAt(270,70,"Basic Controls");
    //Brain.Screen.printAt(10,170,"Nonkinematics");
    //Brain.Screen.printAt(10,220,"Kinematics");
}

void Interface::drawBasicInterface() {
    Brain.Screen.drawRectangle(0,0,480,240,black);
    Brain.Screen.drawRectangle(0,0,40,240,lightblue);
    drawTriangleRight(10, 100, 20, lighterblue);
    //Brain.Screen.drawRectangle(40,0,480,80,black);
    Brain.Screen.drawRectangle(186,0,146,240,black);
    //Brain.Screen.drawRectangle(40,160,480,80,black);
    Brain.Screen.printAt(50,25,"RED MODULE");
    Brain.Screen.printAt(196,25,"GREEN MODULE");
    Brain.Screen.printAt(340,25,"BLUE MODULE");
}

void Interface::refreshInterface() {
    setCurrentFlag();
    if (key == 't') {
        if (currentFlag == ' ') {
            drawTestInterface();
        }
        else if (currentFlag == 'r') {
            drawTestInterface();
            Brain.Screen.drawCircle(100,50,40,white);
            Brain.Screen.drawCircle(100,50,20,lightred);
            Brain.Screen.printAt(290,20,"RED MODULE");
            Brain.Screen.printAt(290,60,"angle: port 5");
            Brain.Screen.printAt(290,160,"drive: port 6");
            float arpm = AngleR.velocity(rpm);
            float drpm = DriveR.velocity(rpm);
            Brain.Screen.printAt(290,80,"rpm: %d", arpm);
            Brain.Screen.printAt(290,180,"rpm: %d", drpm);
            Brain.Screen.drawRectangle(360, 95, 30, 30, white);
            Brain.Screen.drawRectangle(360, 195, 30, 30, white);
            drawTriangleRight(430, 95, 15, white);
            drawTriangleRight(430, 195, 15, white);
            drawTriangleLeft(320,95,15,white);
            drawTriangleLeft(320,195,15,white);
        }
        else if (currentFlag == 'g') {
            drawTestInterface();
            Brain.Screen.drawCircle(210,130,40,white);
            Brain.Screen.drawCircle(210,130,20,lightgreen);
            Brain.Screen.printAt(290,20,"GREEN MODULE");
            Brain.Screen.printAt(290,60,"angle: port 7");
            Brain.Screen.printAt(290,160,"drive: port 20");
            float arpm = AngleG.velocity(rpm);
            float drpm = DriveG.velocity(rpm);
            Brain.Screen.printAt(290,80,"rpm: %d", arpm);
            Brain.Screen.printAt(290,180,"rpm: %d", drpm);
            Brain.Screen.drawRectangle(360, 95, 30, 30, white);
            Brain.Screen.drawRectangle(360, 195, 30, 30, white);
            drawTriangleRight(430, 95, 15, white);
            drawTriangleRight(430, 195, 15, white);
            drawTriangleLeft(320,95,15,white);
            drawTriangleLeft(320,195,15,white);
        }
        else if (currentFlag == 'b') {
            drawTestInterface();
            Brain.Screen.drawCircle(100,190,40,white);
            Brain.Screen.drawCircle(100,190,20,lightcyan);
            Brain.Screen.printAt(290,20,"BLUE MODULE");
            Brain.Screen.printAt(290,60,"angle: port 19");
            Brain.Screen.printAt(290,160,"drive: port 4");
            float arpm = AngleB.velocity(rpm);
            float drpm = DriveB.velocity(rpm);
            Brain.Screen.printAt(290,80,"rpm: %d", arpm);
            Brain.Screen.printAt(290,180,"rpm: %d", drpm);
            Brain.Screen.drawRectangle(360, 95, 30, 30, white);
            Brain.Screen.drawRectangle(360, 195, 30, 30, white);
            drawTriangleRight(430, 95, 15, white);
            drawTriangleRight(430, 195, 15, white);
            drawTriangleLeft(320,95,15,white);
            drawTriangleLeft(320,195,15,white);
        }
    }
    else if (key == 'm') {
        drawMenuInterface();
    }
    else if (key == 'b') {
        drawBasicInterface();
    }
}

void Interface::setCurrentFlag() {
    //testInterface
    if (redMod.isClicked()) {
        //printf("redMod is clicked\n");
        currentFlag = redMod.getFlag();
        //printf("%c\n", redMod.getFlag());
    }
    else if (greenMod.isClicked()) {
        currentFlag = greenMod.getFlag();
    }
    else if (blueMod.isClicked()) {
        currentFlag = blueMod.getFlag();
    }

    if (angleRight.isClicked()) {
        if (currentFlag == 'r') {
            AngleR.spin(fwd,6.0,volt);
        }
        else if (currentFlag == 'g') {
            AngleG.spin(fwd,6.0,volt);
        }
        else if (currentFlag == 'b') {
            AngleB.spin(fwd,6.0,volt);
        }
    }
    else if (angleLeft.isClicked()) {
        if (currentFlag == 'r') {
            AngleR.spin(fwd,-6.0,volt);
        }
        else if (currentFlag == 'g') {
            AngleG.spin(fwd,-6.0,volt);
        }
        else if (currentFlag == 'b') {
            AngleB.spin(fwd,-6.0,volt);
        }
    }
    else if (angleStop.isClicked()) {
        if (currentFlag == 'r') {
            AngleR.spin(fwd,0.0,volt);
        }
        else if (currentFlag == 'g') {
            AngleG.spin(fwd,0.0,volt);
        }
        else if (currentFlag == 'b') {
            AngleB.spin(fwd,0.0,volt);
        }
    }

    if (driveRight.isClicked()) {
        if (currentFlag == 'r') {
            DriveR.spin(fwd,6.0,volt);
        }
        else if (currentFlag == 'g') {
            DriveG.spin(fwd,6.0,volt);
        }
        else if (currentFlag == 'b') {
            DriveB.spin(fwd,6.0,volt);
        }
    }
    else if (driveLeft.isClicked()) {
        if (currentFlag == 'r') {
            DriveR.spin(fwd,-6.0,volt);
        }
        else if (currentFlag == 'g') {
            DriveG.spin(fwd,-6.0,volt);
        }
        else if (currentFlag == 'b') {
            DriveB.spin(fwd,-6.0,volt);
        }
    }
    else if (driveStop.isClicked()) {
        if (currentFlag == 'r') {
            DriveR.spin(fwd,0.0,volt);
        }
        else if (currentFlag == 'g') {
            DriveG.spin(fwd,0.0,volt);
        }
        else if (currentFlag == 'b') {
            DriveB.spin(fwd,0.0,volt);
        }
    }

}

void Interface::drawTriangleRight(int x, int y, int halflength, color col) {
    Brain.Screen.setPenColor(col);
    for (int i=0; i<halflength; i++) {
        Brain.Screen.drawLine(x,y+i,x+i,y+i);
    }
    y+=halflength-1;
    for (int j=1; j<=halflength;j++) {
        Brain.Screen.drawLine(x,y+j,x+halflength-j,y+j);
    }
    Brain.Screen.setPenColor(white);
}

void Interface::drawTriangleLeft(int x, int y, int halflength, color col) {
    Brain.Screen.setPenColor(col);
    for (int i=0; i<halflength; i++) {
        Brain.Screen.drawLine(x,y+i,x-i,y+i);
    }
    y+=halflength-1;
    for (int j=1; j<=halflength; j++) {
        Brain.Screen.drawLine(x,y+j,x-halflength+j,y+j);
    }
    Brain.Screen.setPenColor(white);
}