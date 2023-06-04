#ifndef INTERFACE_H
#define INTERFACE_H

#include "clickable.h"

/**
* @brief 
*/
class Interface {
    public:

    char key = ' ';
    char currentFlag = ' ';

    Interface();

    /** 
     * @brief creates a new interface
     */
    Interface(char k);

    void drawTestInterface();

    void drawMenuInterface();

    void drawBasicInterface();

    void drawNkInterface();
    
    /**
     * @brief draw interface only
     * based on current flag 
     */
    void refreshInterface();

    /**
     * @brief check if any buttons are clicked
     */
    bool ifUptodate();

    /**
     * @brief set the current status of the interface
     * and also conduct any robot actions
     * based on status of the buttons
     */
    void setCurrentFlag();
    
    /**
     * @brief draw a triangle pointing to the right
     * @param x x position of the top left corner
     * @param y y position of the top left corner
     * @param halflength half of the length of the triangle
     */
    void drawTriangleRight(int x, int y, int halflength, color col);

    void drawTriangleLeft(int x, int y, int halflength, color col);
};


#endif

using namespace vex;