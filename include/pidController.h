#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include "vex.h"

/**
 * @brief code sponsored by chaatGPT
 */
class PIDController {
    public:
    float kp,ki,kd;
    float setPoint,errorSum=0,lastError=0;

    PIDController();

    PIDController(float p, float i, float d);

    float update(float error);
};

#endif