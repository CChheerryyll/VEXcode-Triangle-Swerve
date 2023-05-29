#include "tswerve.h"

Tswerve::Tswerve() {

}

Tswerve::Tswerve(Module r, Module g, Module b) {
    ModR = r;
    ModG = g;
    ModB = b;
}

void Tswerve::basicDrive() {
    //determine volt from joystick values
    double angleAX = Controller1.Axis1.position()/100.0; //AX = axis
    double driveAX = Controller1.Axis3.position()/100.0;

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
        ModR.getDriveMotor().spin(fwd,MAXVOLT/2*driverev,volt); //6.0
    }
    else {
      ModR.getDriveMotor().spin(fwd,driveAX*driverev,volt);
    }

    //right
    if (Controller1.ButtonRight.pressing()) {
        ModG.getDriveMotor().spin(fwd,MAXVOLT/2*driverev,volt);
    }
    else {
        ModG.getDriveMotor().spin(fwd,driveAX*driverev,volt);
    }

    //left
    if (Controller1.ButtonLeft.pressing()) {
        ModB.getDriveMotor().spin(fwd,MAXVOLT/2*driverev,volt);
    }
    else {
        ModB.getDriveMotor().spin(fwd,driveAX*driverev,volt);
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
            ModR.getAngleMotor().spin(fwd,MAXVOLT/2*angleccw,volt);
        }
        else {
            ModR.getAngleMotor().spin(fwd,angleAX*angleccw,volt);
        }

        //A
        if (Controller1.ButtonA.pressing()) {
            ModG.getAngleMotor().spin(fwd,MAXVOLT/2*angleccw,volt);
        }
        else {
            ModG.getAngleMotor().spin(fwd,angleAX*angleccw,volt);
        }

        //Y
        if (Controller1.ButtonY.pressing()) {
            ModB.getAngleMotor().spin(fwd,MAXVOLT/2*angleccw,volt);
        }
        else {
            ModB.getAngleMotor().spin(fwd,angleAX*angleccw,volt);
        }
    }
}