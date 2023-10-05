#include "main.h"
#include "robotInit.h"
#include "wings.cpp"

class Robot {
    public:
        /* #region Initialize motors */
            /* #region drivetrain motors */
                Motor lf = Motor(LF_PORT,  MOTOR_GEAR_BLUE, false);
                Motor lm = Motor(LM_PORT,  MOTOR_GEAR_BLUE, false);
                Motor lr = Motor(LR_PORT,  MOTOR_GEAR_BLUE, false);

                Motor rf = Motor(RF_PORT,  MOTOR_GEAR_BLUE, true);
                Motor rm = Motor(RM_PORT,  MOTOR_GEAR_BLUE, true);
                Motor rr = Motor(RR_PORT,  MOTOR_GEAR_BLUE, true);

                MotorGroup left = MotorGroup({lf, lm, lr});
                MotorGroup right = MotorGroup({rf, rm, rr});
            /* #endregion drivetrain motors */

            // catapult motor
            Motor cata = Motor(CATA_PORT, MOTOR_GEAR_RED, false);
        /* #endregion Initialize motors */

        // Initialize wings
        Wings wings = Wings();

        // Sets chassis motor speeds with power range [-1, 1]
        void drive(double leftPower, double rightPower) {
            left.move(leftPower*127);
            right.move(rightPower*127);
        }
};