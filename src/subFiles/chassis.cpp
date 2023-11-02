#include "main.h"

Chassis::Chassis() {}

void Chassis::drive(double leftPower, double rightPower, int runtime, bool stops) {
    leftMotors.move(leftPower*127);
    rightMotors.move(rightPower*127);
    pros::delay(runtime);
    if (stops) {brake();} 
}

/*
// Drives a set distance away (in inches) using kP, tolerance of 1
void Chassis::driveDistance(double targetDist, double kP, bool stops) {
    double error = targetDist, currDist = 0, targetVel;
    std::vector<double> leftPositions, rightPositions;
    double avgPosition;
    leftMotors.tare_position();
    rightMotors.tare_position();
    while (fabs(error) > 1) {
        leftPositions = leftMotors.get_positions();
        rightPositions = rightMotors.get_positions();

        for (int i = 0; i < motorCount; i++) {
            avgPosition += leftPositions[i];
            avgPosition += rightPositions[i];
        }
        avgPosition /= (motorCount * 2);

        currDist = (avgPosition / TICKS_PER_REVOLUTION) * WHEEL_CIRCUMFERENCE * GEAR_RATIO;

        error = targetDist - currDist;

        targetVel = kP * (error - currDist);
        targetVel = std::clamp(targetVel, -1.0, 1.0);
    }
}
*/

void Chassis::turnAngle(double targetAngle, bool stops) {

}

void Chassis::brake() {
    leftMotors.move(0);
    rightMotors.move(0);
}