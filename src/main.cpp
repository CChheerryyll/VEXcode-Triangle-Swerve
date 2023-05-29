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
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "software.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //create an instance of Software
  Software tSwerve = Software();

  while (1) {
      //refresh software
      tSwerve.refresh();
  }
  
}