using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor DriveG;
extern motor AngleB;
extern motor AngleG;
extern motor DriveR;
extern motor AngleR;
extern motor DriveB;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );