#include "main.h"
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
void autonomous() {
    
    

    // double pidParams[4] = {10.0, 0.5, 0.0, 0.0};
    // double* ptrPidParams = pidParams;
    // pros::Task pid_task(pid_task_fn, (void*)ptrPidParams);
}


/*
// Define the pid task
void pid_task_fn(void* params) {
    uint32_t curTime, startTime = pros::millis();
    double* pidParams = (double*)params;
    double targetPos = pidParams[0], kP = pidParams[1], kI = pidParams[2], kD = pidParams[3];
	
    double P, It, D;

    double startPos = left1.get_position(), curPos, curPosTicks, curError, prevError = 0, moved;
    double speed = 0.0;

    double output;

    while (fabs(curError) > 1) {
        curTime = pros::millis() - startTime;
        curPosTicks = left1.get_position();
        // Convert from wheel degrees 
        curPos = (curPosTicks/360 * WHEEL_CIRCUMFERENCE) / TICKS_PER_REVOLUTION;
        moved = curPos - startPos;
        curError = targetPos - curPos;

        P = kP * curError;
        It += kI * curError * 20;
        D = kD * (prevError - curError)/20;
        output = P + It + D;

        prevError = curError;
        pros::delay(20);
    }
}
*/