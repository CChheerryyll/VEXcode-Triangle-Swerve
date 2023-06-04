#ifndef TSWERVE_H
#define TSWERVE_H

#include "module.h"
#include "constants.h"

class Tswerve {
    public:

    Module ModR, ModG, ModB;
    Module mods[3];
    float targetHd = 0;

    Tswerve();
    
    Tswerve(Module r, Module g, Module b);

    void basicDrive();

    void nonKinematicsDrive();
    
    /**
     * @brief every module will align itself to the front
     */
    void calibrateModuleAngle();

    void targetHeading();
};

#endif

extern Tswerve Drivetrain;