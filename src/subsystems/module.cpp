#include "module.h"

Module::Module() {
  
}

Module::Module(motor am, motor dm) {
    angleMotor = am;
    driveMotor = dm;
}

motor Module::getAngleMotor() {
    return angleMotor;
}

motor Module::getDriveMotor() {
    return driveMotor;
}