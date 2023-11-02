#include "main.h"

class Chassis {
    private:
        // Odometry odomSys;
    public:
        Chassis();
        void drive(double leftPower, double rightPower, int runtime = 0, bool stops = true);
        // void driveDistance(double targetDist, double kP, bool stops = true);
        void turnAngle(double targetAngle, bool stops = true);
        void brake();
        // void p2pDrive(Coord targetPos, double p2pVel, double disTolerance, double endVel, bool stopAtEnd, int timeOut);
};