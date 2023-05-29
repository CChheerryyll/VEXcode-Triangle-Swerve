#include "vex.h"

#ifndef MODULE_H
#define MODULE_H

class Module {
    public:

    motor driveMotor = motor(-1), angleMotor = motor(-1);

    Module();

    Module(motor am, motor dm);

    motor getAngleMotor();

    motor getDriveMotor();
};

#endif