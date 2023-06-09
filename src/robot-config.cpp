#include "vex.h"
#include "tswerve.h"
#include "software.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor DriveG = motor(PORT20, ratio18_1, false);
motor AngleB = motor(PORT19, ratio18_1, true);
motor AngleG = motor(PORT7, ratio18_1, true);
motor DriveR = motor(PORT6, ratio18_1, false);
motor AngleR = motor(PORT5, ratio18_1, true);
motor DriveB = motor(PORT4, ratio18_1, false);
controller Controller1 = controller(primary);
line LineR = line(Brain.ThreeWirePort.A);
line LineG = line(Brain.ThreeWirePort.B);
line LineB = line(Brain.ThreeWirePort.C);
inertial Inertial = inertial(PORT1);

// swerve
//create an instance of Software
  Software tSwerve = Software();

//creating the drivetrain
Module ModR = Module(AngleR,DriveR,OFFSET_R);
Module ModG = Module(AngleG,DriveG,OFFSET_G);
Module ModB = Module(AngleB,DriveB,OFFSET_B);
Tswerve Drivetrain = Tswerve();

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}