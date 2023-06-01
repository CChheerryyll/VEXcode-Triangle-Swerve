#ifndef SOFTWARE_H
#define SOFTWARE_H

#include "interface.h"

//screen size: 480 x 272

/**
 * @brief the designated software system of the triangle swerve
 */
class Software {
    public:

    char currentkey = 't';
    Interface testInterface = Interface('t');
    Interface menuInterface = Interface('m');
    Interface basicInterface = Interface('b');

    Clickable menuOpenButton = Clickable(0,40,100,140,'n');
    Clickable testButton = Clickable(40,240,40,160,'n');
    Clickable basicButton = Clickable(240,480,40,160,'n');
    Clickable nonkinematicsButton = Clickable();
    Clickable kinematicsButton = Clickable();
    int lastX = -1, lastY = -1;

    /**
     * @brief creates a new software system which 
     *  manipuates multiple interfaces
     */
    Software();

    /**
     * @brief create interfaces
     */
    void initialize();

    void refresh();

    char getKey();

};

#endif

using namespace vex;