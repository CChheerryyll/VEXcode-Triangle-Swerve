/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\lijia                                            */
/*    Created:      Sat May 27 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// DriveG               motor         20              
// AngleB               motor         19              
// AngleG               motor         7               
// DriveR               motor         6               
// AngleR               motor         5               
// DriveB               motor         4               
// Controller1          controller                    
// LineR                line          A               
// LineG                line          B               
// LineB                line          C               
// Inertial             inertial      1               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "software.h"
#include "tswerve.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while (1) {
      ModR.absoluteAngle(LineR);
      ModG.absoluteAngle(LineG);
      ModB.absoluteAngle(LineB);
      Drivetrain.targetHeading();
      ModR.findError(Drivetrain.targetHd);
      ModG.findError(Drivetrain.targetHd);
      ModB.findError(Drivetrain.targetHd);

      //refresh software
      tSwerve.refresh();
      if (tSwerve.getKey() == 'b') {
          Drivetrain.basicDrive();
      }
      else if (tSwerve.getKey() == 'n') {
          Drivetrain.nonKinematicsDrive();
      }
  }
  
}
