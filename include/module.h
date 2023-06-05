#ifndef MODULE_H
#define MODULE_H

#include "pidController.h"

class Module {
    public:

    motor DriveMotor = motor(-1), AngleMotor = motor(-1);
    PIDController anglePID = PIDController();
    PIDController drivePID = PIDController();
    float offset, absAngle;
    int darkRef = -1; //dark zone reflectivity
    float error;
    int revdrive = 1;

    Module();
    
    /**
     * @brief create a swerve module
     * @am angle motor
     * @dm drive motor
     * @offset dark zone abs angle 
     */
    Module(motor am, motor dm, float offset);
    
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
    
    /**
     * @brief code sponsored by chatGPT
     * error means #of degrees the module must
     * turn to reach target. 
     * >0 means turning clockwise
     * <0 means turning counterclockwide
     */
    void findError(float target);


};

#endif

extern Module ModR;
extern Module ModG;
extern Module ModB;