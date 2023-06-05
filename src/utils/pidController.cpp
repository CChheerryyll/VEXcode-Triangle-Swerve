#include "pidController.h"
#include "constants.h"

PIDController::PIDController() {

}

PIDController::PIDController(float p, float i, float d) {
    kp = p;
    ki = i;
    kd = d;
}

float PIDController::update(float error) {
    errorSum += error;
    float dError = error - lastError;
    float output = kp*error + ki*errorSum + kd*dError;
    if (output > MAXVOLT) {
        output = MAXVOLT;
    }
    lastError = error;
    return output;
}