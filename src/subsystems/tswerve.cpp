#include "tswerve.h"

Tswerve::Tswerve() {
   
}

void Tswerve::basicDrive() {
    //determine volt from joystick values
    float angleAX = Controller1.Axis1.position()/100.0; //AX = axis
    float driveAX = Controller1.Axis3.position()/100.0;

    if (angleAX <= DEADBAND) {
      angleAX = 0.0;
    }
    if (driveAX <= DEADBAND) {
      driveAX = 0.0;
    }

    angleAX *= MAXVOLT;
    driveAX *= MAXVOLT;

    //reverse motors if needed
    int driverev = 1;
    int angleccw = 1;
    
    if (Controller1.ButtonL1.pressing()) {
      driverev = -1;
    }
    if (Controller1.ButtonR1.pressing()) {
      angleccw = -1;
    }

    //up
    if (Controller1.ButtonUp.pressing()) {
        ModR.DriveMotor.spin(fwd,MAXVOLT/2*driverev,volt); //6.0
    }
    else {
        ModR.DriveMotor.spin(fwd,driveAX*driverev,volt);
    }

    //right
    if (Controller1.ButtonRight.pressing()) {
        ModG.DriveMotor.spin(fwd,MAXVOLT/2*driverev,volt);
    }
    else {
        ModG.DriveMotor.spin(fwd,driveAX*driverev,volt);
    }

    //left
    if (Controller1.ButtonLeft.pressing()) {
        ModB.DriveMotor.spin(fwd,MAXVOLT/2*driverev,volt);
    }
    else {
        ModB.DriveMotor.spin(fwd,driveAX*driverev,volt);
    }

    //calibration button
    if (Controller1.ButtonDown.pressing()) {
        calibrateModuleAngle();
    }
    
    //B (reset button, enable pid)
    if (Controller1.ButtonB.pressing()) {
        //ModR.spinAngleMotorPID(0);
        //ModG.spinAngleMotorPID(0);
        //ModB.spinAngleMotorPID(0);
    }
    else {
        //X
        if (Controller1.ButtonX.pressing()) {
            ModR.AngleMotor.spin(fwd,MAXVOLT/2*angleccw,volt);
        }
        else {
            ModR.AngleMotor.spin(fwd,angleAX*angleccw,volt);
        }

        //A
        if (Controller1.ButtonA.pressing()) {
            ModG.AngleMotor.spin(fwd,MAXVOLT/2*angleccw,volt);
        }
        else {
            ModG.AngleMotor.spin(fwd,angleAX*angleccw,volt);
        }

        //Y
        if (Controller1.ButtonY.pressing()) {
            ModB.AngleMotor.spin(fwd,MAXVOLT/2*angleccw,volt);
        }
        else {
            ModB.AngleMotor.spin(fwd,angleAX*angleccw,volt);
        }
    }
}

void Tswerve::nonKinematicsDrive() {
  
    //calibration button
    if (Controller1.ButtonDown.pressing()) {
        calibrateModuleAngle();
    }

    float vR = ModR.anglePID.update(ModR.error);
    ModR.AngleMotor.spin(fwd,vR,volt);
    
}

void Tswerve::calibrateModuleAngle() {
    ModR.calibrateAngle(LineR);
    ModG.calibrateAngle(LineG);
    ModB.calibrateAngle(LineB);
}

void Tswerve::targetHeading() {
    float x = Controller1.Axis4.position();
    float y = Controller1.Axis3.position();
    //make sure the heading sticks even if 
    //the joystick is returned to default state
    if (fabs(x) > 20 && fabs(y) > 20) { 
        targetHd = atan2f(y, x) * -(180/M_PI);
        if (targetHd < 0) { //convert to 0-360 deg range
            targetHd += 360;
        }
        targetHd += 90; //align 0 deg to the front
        if (targetHd > 360) { //convert to 0-360 deg range
            targetHd -= 360;
        }
    }

    //enhance the values
    if (x<15 && x>-15) {
        if (y>0 && y>15) { //up
            targetHd = 0;
        }
        else if (y<0 && y<-15) { //down
            targetHd = 180;
        }
    }
    if (y<15 && y>-15) {
        if (x>0 && x>15) { //right
            targetHd = 90;
        }
        else if (x<0 && x<-15){ //left
            targetHd = 270;
        }
    }
}

