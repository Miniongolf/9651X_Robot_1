#include "main.h"

// MOTORS
pros::Motor left1(LEFT_1_PORT, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left2(LEFT_2_PORT, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::MotorGroup leftMotors({left1, left2});

pros::Motor right1(RIGHT_1_PORT, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right2(RIGHT_2_PORT, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::MotorGroup rightMotors({right1, right2});

pros::Motor cataMotor(CATA_PORT, pros::E_MOTOR_GEAR_RED, false, pros::E_MOTOR_ENCODER_DEGREES);

Chassis chassis;
Wings wings;

// PNEUMATICS
pros::ADIDigitalOut leftwing(LEFT_WING_PORT);
pros::ADIDigitalOut rightwing(RIGHT_WING_PORT);

// MISC
Gamepad gamepad1(pros::E_CONTROLLER_MASTER);
Gamepad gamepad2(pros::E_CONTROLLER_PARTNER);