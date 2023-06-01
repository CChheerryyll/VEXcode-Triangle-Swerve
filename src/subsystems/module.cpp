#include "module.h"
#include "constants.h"

Module::Module() {
  
}

Module::Module(motor am, motor dm, double o) {
    AngleMotor = am;
    DriveMotor = dm;
    offset = o;
}

motor Module::getAngleMotor() {
    return AngleMotor;
}

motor Module::getDriveMotor() {
    return DriveMotor;
}

void Module::calibrateAngle(line lt) {
    darkRef = -1;
    AngleMotor.resetRotation();
    int initRef = lt.reflectivity();
    //spin module for one rotation
    while (AngleMotor.rotation(deg)*ANGLE_RATIO <= 360) {
        //printf("%f\n",AngleMotor.rotation(deg)*ANGLE_RATIO);

        AngleMotor.spin(fwd,8.0,volt);
        int currentRef = lt.reflectivity();
        //printf("init:%d,current:%d\n",initRef,currentRef);
        if (currentRef - RANGE > initRef) { //darker
            AngleMotor.stop(brake);
            darkRef = currentRef;
            absAngle = offset;
            break;
        }
    }
    AngleMotor.stop();
    if (darkRef > -1) {
        //print calibration success
        //printf("success\n");
    }
    else {
        //print calibration failed
    }
}

void Module::absoluteAngle(line lt) {
    
}