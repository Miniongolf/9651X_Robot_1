#include "main.h"

PID::PID(double kPin, double kIin, double kDin) {
    startTime = pros::millis();
    kP = kPin, kI = kIin, kD = kDin;
}

void PID::setPID(double kPin, double kIin, double kDin) {
    kP = kPin, kI = kIin, kD = kDin;
}

void PID::setTarget(double targetIn) {
    target = targetIn;
}

double PID::calculate(double errorIn) {
    double output = 0;

    error = errorIn;

    derivative = error - lastError;
    
    // filter derivative
    derivative = filterAlpha*derivative + (1-filterAlpha)*lastDerivative;

    // start integrating when the error enters integral range
    if (fabs(error) < fabs(integralRange)) {
        integral += kI * error;
    }

    // reset integral when error flips signs
    if ((shouldResetOnCross) && (error*lastError < 0)) {
        integral = 0;
    }

    // clamp integral and output into (min, max)
    integral = std::clamp(integral, -maxSumIntegral, maxSumIntegral);
    output = kP*error + integral + kD*derivative;
    output = std::clamp(output, minOutput, maxOutput);
    
    // update lastDerivative and lastError for next cycle
    lastDerivative = derivative;
    lastError = error;

    return output;
}

double PID::calculateLinearKP(double errorIn) {
    double error = errorIn, currDist = 0, targetVel;

    targetVel = kP * (error - currDist);
    targetVel = std::clamp(targetVel, -1.0, 1.0);

    return targetVel;
}