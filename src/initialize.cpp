#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize();
    leftMotors.tare_position();
    rightMotors.tare_position();
    cataMotor.tare_position();
    // wings.setPosition(-1, -1);
}
