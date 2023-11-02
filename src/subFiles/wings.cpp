#include "main.h"

Wings::Wings() {}

std::array<bool, 2> Wings::getStatus() {
    return {leftIsExtended, rightIsExtended};
}

void Wings::setPosition(int leftPos, int rightPos) {
    if (leftPos == 1 && !leftIsExtended) {
        leftWing.set_value(true);
        leftIsExtended = true;
    } else if (leftPos == -1 && leftIsExtended) {
        leftWing.set_value(false);
        leftIsExtended = false;
    }
    
    if (rightPos == 1 && !rightIsExtended) {
        rightWing.set_value(true);
        rightIsExtended = true;
    } else if (rightPos == -1 && rightIsExtended) {
        rightWing.set_value(false);
        rightIsExtended = false;
    } 
}

void Wings::setPosition(int bothPos) {
    setPosition(bothPos, bothPos);
}

        