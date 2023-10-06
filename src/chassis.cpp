#include "main.h"
#include "robotInit.h"

class Chassis {
    public:
        /* #region Initialize motors */
        Motor lf = Motor(LF_PORT,  MOTOR_GEAR_BLUE);
        Motor lr = Motor(LR_PORT,  MOTOR_GEAR_BLUE);

        /** NOTE: negative port number reverses direction */
        Motor rr = Motor(-RR_PORT,  MOTOR_GEAR_BLUE);
        Motor rf = Motor(-RF_PORT,  MOTOR_GEAR_BLUE);

        MotorGroup left = MotorGroup({lf, lr});
        MotorGroup right = MotorGroup({rf, rr});
        /* #endregion drivetrain motors */

        // Sets chassis motor speeds with power range [-1, 1], set time and stops
        void drive(double leftPower, double rightPower, int time=0, bool stops=false) {
            left.move(leftPower*127);
            right.move(rightPower*127);
            delay(time);
            if (stops) brake(); 
        }

        // Stops the chassis
        void brake() {
            left.move(0);
            right.move(0);
        }

        // Preloads catapult
};