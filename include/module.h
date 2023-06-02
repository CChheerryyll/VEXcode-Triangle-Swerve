#ifndef MODULE_H
#define MODULE_H

#include "vex.h"

class Module {
    public:

    motor DriveMotor = motor(-1), AngleMotor = motor(-1);
    float offset, absAngle;
    int darkRef = -1; //dark zone reflectivity

    Module();
    
    /**
     * @brief create a swerve module
     * @am angle motor
     * @dm drive motor
     * @offset dark zone abs angle 
     */
    Module(motor am, motor dm, float offset);

    motor getAngleMotor();

    motor getDriveMotor();
    
    /**
     * @brief align every module to the front
     * and set the reflectivity of the dark zone
     */
    void calibrateAngle(line lt);

    /**
     * @brief set the current absolute angle of
     * the module on a range of 360 degrees cw 
     */
    void absoluteAngle(line lt);
    

};

#endif

extern Module ModR;
extern Module ModG;
extern Module ModB;