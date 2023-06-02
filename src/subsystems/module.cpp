#include "module.h"
#include "constants.h"

Module::Module() {
  
}

Module::Module(motor am, motor dm, float o) {
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
        AngleMotor.setRotation(offset/ANGLE_RATIO, deg);
        while (AngleMotor.rotation(deg)/ANGLE_RATIO > 0) {
            AngleMotor.spin(fwd,-4.0,volt);
        }
        AngleMotor.stop();
        AngleMotor.resetRotation();
    }
    else {
        //print calibration failed
    }
}

void Module::absoluteAngle(line lt) {
    if (lt.reflectivity() < darkRef+5 && lt.reflectivity() > darkRef-5) {
        absAngle = offset;
        AngleMotor.setRotation(absAngle,deg);
        printf("recalibrated\n");
    }
    else {
        absAngle = AngleMotor.rotation(deg)*ANGLE_RATIO;
        while (absAngle < 0) {
            absAngle += 360;
        }
        while (absAngle >= 360) {
            absAngle -= 360;
        }
    }
}
