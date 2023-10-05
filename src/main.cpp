#include "main.h"
#include "robot.cpp"
#include "robotInit.h"
#include <math.h>

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

void on_center_button() {
	ADIDigitalOut piston (LEFT_WING_PORT);
	

	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		lcd::set_text(2, "I was pressed!");

		piston.set_value(true);
  		delay(1000);
  		piston.set_value(false);

	} else {
		lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	Robot robot = Robot();
	ADIDigitalOut piston (LEFT_WING_PORT);
	Controller master(CONTROLLER_MASTER);

	robot.wings.setPosition(1);
	delay(1500);
	robot.wings.setPosition(-1, 1);
	delay(1500);
	robot.wings.setPosition(0, 1);
	delay(1500);
	robot.wings.setPosition(1, -1);
	delay(1500);
	robot.wings.setPosition(-1, 0);
	delay(1500);
	robot.wings.setPosition(-1);
	delay(1500);

	while (true) {
		if (master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
			robot.wings.setPosition(1, 0);
		} else robot.wings.setPosition(-1, 0);

		if (master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
			robot.wings.setPosition(0, 1);
		} else robot.wings.setPosition(0, -1);
	}

	// while (true) {
	// 	piston.set_value(true);
	// 	delay(2000);
	// 	piston.set_value(false);
	// 	delay(2000);
	// }

	lcd::initialize();
	lcd::set_text(1, "Hello PROS User!");

	lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	// Initialization
	Controller master(CONTROLLER_MASTER);
	Robot chassis = Robot();
	Wings wings = Wings();

	chassis.left.set_brake_modes(MOTOR_BRAKE_HOLD);
	chassis.right.set_brake_modes(MOTOR_BRAKE_HOLD);

	// Main loop
	while (true) {
		/** NOTE: denominator is 127.0 because of int division imprecisions
			Changes range of inputs to -1 <= x <= 1 for normalization */
		double leftY = master.get_analog(ANALOG_LEFT_Y)/127.0;
		double rightX = master.get_analog(ANALOG_RIGHT_X)/127.0;
		
		double leftPower = (leftY + rightX * TURN_CONST);
		double rightPower = (leftY - rightX * TURN_CONST);

		// Normalizing speeds to max out at 1 while preserving ratio
		// Use fabs instead of abs to preserve floating point precisino
		double highPower = std::max(fabs(leftPower), fabs(rightPower));
		leftPower = (leftPower/highPower) * SPEED_CONST;
		rightPower = (rightPower/highPower) * SPEED_CONST;

		chassis.drive(leftPower, rightPower);

		/** NOTE: all infinite loops must have a delay >= 2ms */
		delay(20); 
	}
}
