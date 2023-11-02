#include "main.h"

Cata::Cata() {}

void Cata::runContinuous(int runtime) {
    cataMotor.move(127);
    if (runtime > 0) {
        pros::delay(runtime);
        cataMotor.move(0);
    }
}