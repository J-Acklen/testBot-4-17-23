/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "testAutonomous.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

// moveForwardWait() will drive forward [distance]. This program will wait to be completed before moving on.
void moveForwardWait(int distance){
  controller1.Screen.clearScreen();
  controller1.Screen.print("Moving Forwards");
  leftMotor.spinFor(forward, distance, degrees, false);
  rightMotor.spinFor(forward, distance, degrees, true);
}

// moveForwardWait() will drive forward [distance]. This program will NOT wait to be completed before moving on.
void moveForwardNoWait(int distance){
  controller1.Screen.clearScreen();
  controller1.Screen.print("Moving Forwards");
  leftMotor.spinFor(forward, distance, degrees, false);
  rightMotor.spinFor(forward, distance, degrees, false);
}

// moveForwardWait() will drive forward [distance]. This program will wait to be completed before moving on.
void moveReverseWait(int distance){
  controller1.Screen.clearScreen();
  controller1.Screen.print("Moving Reverse");
  leftMotor.spinFor(reverse, distance, degrees, false);
  rightMotor.spinFor(reverse, distance, degrees, true);
}

// moveForwardWait() will drive forward [distance]. This program will NOT wait to be completed before moving on.
void moveReverseNoWait(int distance){
  controller1.Screen.clearScreen();
  controller1.Screen.print("Moving Reverse");
  leftMotor.spinFor(reverse, distance, degrees, false);
  rightMotor.spinFor(reverse, distance, degrees, false);
}



// turnRight() will turn [distance] degrees to the right in a tank fashion
void turnRight(int distance){
  controller1.Screen.clearScreen();
  controller1.Screen.print("Turning Right");
  leftMotor.spinFor(forward, distance, rev, false);
  rightMotor.spinFor(reverse, distance, rev, true);
}

// turnLeft() will turn [distance] degrees to the left in a tank fashion
void turnLeft(int distance){
  controller1.Screen.clearScreen();
  controller1.Screen.print("Turning Left");
  rightMotor.spinFor(forward, distance, degrees, false);
  leftMotor.spinFor(reverse, distance, degrees, true);
}

// spinRollerWait() will rotate the rollerMotor 180 degrees in the forward direction. This program will wait to be completed before moving on.
void spinRollerWait(){
  controller1.Screen.clearScreen();
  controller1.Screen.print("Spinning roller");
  rollerMotor.spinFor(forward, 180, degrees, true);
}

// spinRollerNoWait() will rotate the rollerMotor 180 degrees in the forward direction. This program will NOT wait to be completed before moving on.
void spinRollerNoWait(){
  controller1.Screen.clearScreen();
  controller1.Screen.print("Spinning roller");
  rollerMotor.spinFor(forward, 180, degrees, false);
}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  turnRollerFromShortStart();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.


    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {

  // Run the pre-autonomous function.
  pre_auton();

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}