#include "main.h"

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
	pros::Task inputs_task(inputs_task_fn, NULL, "Gamepad Input Task");
    pros::lcd::print(1, "opmode");
	double leftVel, rightVel, highVel;
	double targetLeftVel = 0, targetRightVel = 0;

	bool usingAccel = false;

	while (true) {
		leftVel = gamepad1.leftY + gamepad1.rightX*TURN_CONST;
		rightVel = gamepad1.leftY - gamepad1.rightX*TURN_CONST;
		
		highVel = fabs(std::max(fabs(leftVel), fabs(rightVel)));
		
		// Normalize to [-1, 1]
		if (highVel > 1 || gamepad1.rb.held) {
			leftVel /= highVel;
			rightVel /= highVel;
		}

		// Slow down the chassis to half speed
		if (gamepad1.rb.held) {
			leftVel /= 2;
			rightVel /= 2;
		}

		chassis.drive(leftVel, rightVel);

		pros::delay(20); // Delay to prevent from overdrawing cpu resources
	}
}

// Task to continuously take inputs during opmode
void inputs_task_fn(void* params) {
	gamepad1.getInputs();
	gamepad2.getInputs();
	pros::delay(20);
}