#include "main.h"

class Odometry {
    private:
        double currDist = 0;
    public:
        Odometry();
        void resetEncoderPos();
        double getLocalDistance();
        void setCurrDist(double distIn);
};

class RobotPosition {
    public:
        double x, y, angle;
        RobotPosition(double xIn, double yIn, double angleIn) {
            x = xIn;
            y = yIn;
            angle = angleIn;
        }
};