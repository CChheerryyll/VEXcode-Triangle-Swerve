#ifndef SOFTWARE_H
#define SOFTWARE_H

#include "interface.h"

//screen size: 480 x 272

/**
 * @brief the designated software system of the triangle swerve
 */
class Software {
    public:

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

};

#endif

using namespace vex;