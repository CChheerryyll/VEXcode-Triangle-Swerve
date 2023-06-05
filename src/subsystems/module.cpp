#include "module.h"
#include "constants.h"

Module::Module() {
  
}

Module::Module(motor am, motor dm, float o) {
    AngleMotor = am;
    DriveMotor = dm;
    anglePID = PIDController(ANGLE_KP,ANGLE_KI,ANGLE_KD);
    offset = o;
}

void Module::calibrateAngle(line lt) {
    darkRef = -1;
    int initRef = lt.reflectivity();
    //spin module for one rotation
    while (AngleMotor.rotation(deg)*ANGLE_RATIO <= 360) {
        //printf("%f\n",AngleMotor.rotation(deg)*ANGLE_RATIO);

        AngleMotor.spin(fwd,4.0,volt);
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
        AngleMotor.setRotation(offset/0.75, deg);
        while (AngleMotor.rotation(deg)/ANGLE_RATIO > 0) {
            AngleMotor.spin(fwd,-4.0,volt);
        }
        AngleMotor.stop();
        //AngleMotor.resetRotation();
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

void Module::findError(float target) {
    double clockwise = fmod(target - absAngle + 360, 360);
    double counterclockwise = fmod(absAngle - target + 360, 360);

    if (fabs(clockwise) - fabs(counterclockwise) < 5) {
        error = clockwise;
    }
    else if (clockwise <= counterclockwise) {
        if (clockwise <= 180) {
            error = -clockwise;
        }
        else {
            error = 360 - clockwise;
        }
    }
    else {
        if (counterclockwise <= 180) {
            error = counterclockwise;
        }
        else {
            error = 360 - counterclockwise;
        }
    }

    //optimization
    /*if (error > 90) {
        error = error - 180;
        if (lasterror > 90) {
            revdrive*=-1;
        }
    }
    else if (error < -90) {
        error = error + 180;
        if (lasterror < -90) {
            revdrive*=-1;
        }
    }

    lasterror = error;*/
}

