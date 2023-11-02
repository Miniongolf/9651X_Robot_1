#include "main.h"

// MOTOR PORTS
#define LEFT_1_PORT 1
#define LEFT_2_PORT 2
#define RIGHT_1_PORT 3
#define RIGHT_2_PORT 4

#define CATA_PORT 10

// PNEUMATICS PORTS
#define LEFT_WING_PORT 'A' // Pneumatics port for left wing
#define RIGHT_WING_PORT 'B' // Pneumatics port for right wing

// MOTORS
extern pros::Motor left1;
extern pros::Motor left2;
extern pros::MotorGroup leftMotors; // Left side drivetrain motor group

extern pros::Motor right1;
extern pros::Motor right2;
extern pros::MotorGroup rightMotors; // Right side drivetrain motor group

extern pros::Motor cataMotor; // Catapult motor

extern Chassis chassis;
extern Wings wings;

// PNEUMATICS
extern pros::ADIDigitalOut leftWing; // Pneumatics for left wing
extern pros::ADIDigitalOut rightWing; // Pneumatics for right wing

// VISION SENSOR
// extern pros::Vision  

// MISC
extern Gamepad gamepad1; // Primary controller
extern Gamepad gamepad2; // Secondary controller

// CONSTANTS
#define NUM_OF_MOTORS 2 // Number of motors per side of chassis
#define M_PI 3.14159265358979323846 // Literally just pi
#define TURN_CONST 0.75 // Turning speed multiplier
#define CONTROLLER_DEADZONE 0.1 // Controller deadzone (cross)
#define TICKS_PER_REVOLUTION 360 // Number of encoder ticks per full motor revolution
#define WHEEL_DIAMETER 3.25 // Wheel diameter in inches
#define WHEEL_CIRCUMFERENCE (M_PI * WHEEL_DIAMETER) // Wheel circumference in inches
#define GEAR_RATIO 0.667 // Motor to wheel gear ratio
