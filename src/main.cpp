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
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "software.h"
#include "tswerve.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //create an instance of Software
  Software tSwerve = Software();

  //creating the drivetrain
  Module ModR = Module(AngleR,DriveR);
  Module ModG = Module(AngleG,DriveG);
  Module ModB = Module(AngleB,DriveB);
  Tswerve Drivetrain = Tswerve(ModR,ModG,ModB);

  while (1) {
      //refresh software
      tSwerve.refresh();
      if (tSwerve.getKey() == 'b') {
          Drivetrain.basicDrive();
      }
  }
  
}
