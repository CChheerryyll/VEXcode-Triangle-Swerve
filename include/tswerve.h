#ifndef TSWERVE_H
#define TSWERVE_H

#include "module.h"
#include "constants.h"

class Tswerve {
    public:

    Module ModR, ModG, ModB;
    Module mods[3];

    Tswerve();
    
    Tswerve(Module r, Module g, Module b);

    /**
     * @brief collect any necessary data 
     */
    void runSwerve();

    void basicDrive();
    
    /**
     * @brief every module will align its marker to the linetracker
     */
    void calibrateModuleAngle();
};

#endif

extern Tswerve Drivetrain;