#include "main.h"

Odometry::Odometry() {}

void Odometry::setCurrDist(double distIn) {
    currDist = distIn;
}

void Odometry::resetEncoderPos() {
    leftMotors.tare_position();
    rightMotors.tare_position();
}

double Odometry::getLocalDistance() {
    std::vector<double> leftPositions, rightPositions;
    double avgPosition;

    leftPositions = leftMotors.get_positions();
    rightPositions = rightMotors.get_positions();

    for (int i = 0; i < NUM_OF_MOTORS; i++) {
        avgPosition += leftPositions[i];
        avgPosition += rightPositions[i];
    }
    avgPosition /= (NUM_OF_MOTORS * 2);

    currDist = (avgPosition / TICKS_PER_REVOLUTION) * WHEEL_CIRCUMFERENCE * GEAR_RATIO;
    return currDist;
}