#include "main.h"

Gamepad::Gamepad(pros::controller_id_e_t id) {
    controllerID = id;
}

void Gamepad::getInputs() {
    pros::Controller controller(controllerID);

    // Get the input value for the stick axes
    for (int i = 0; i < 4; i++) {
        *ptrSticksArr[i] = controller.get_analog(numToStick[i])/127.0;
        *ptrSticksArr[i] = *ptrSticksArr[i];

        // Cross deadzone
        if (fabs(*ptrSticksArr[i]) <= CONTROLLER_DEADZONE) {*ptrSticksArr[i] = 0;}
    }

    // Get the status for the buttons
    for (int i = 0; i < 12; i++) {
        (*ptrButtonsArr[i]).setStatus(controller.get_digital(numToButton[i]));
    }
}
