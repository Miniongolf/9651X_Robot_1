#include "main.h"

class Gamepad {
    private:
        pros::controller_id_e_t controllerID;
        
        // List of all controller buttons
        std::array<pros::controller_digital_e_t, 12> numToButton = {
            DIGITAL_A,
            DIGITAL_B,
            DIGITAL_X,
            DIGITAL_Y,
            DIGITAL_UP,
            DIGITAL_RIGHT,
            DIGITAL_LEFT,
            DIGITAL_DOWN,
            DIGITAL_L1,
            DIGITAL_L2,
            DIGITAL_R1,
            DIGITAL_R2
        };

        std::array<pros::controller_analog_e_t, 4> numToStick = {
            ANALOG_LEFT_X,
            ANALOG_LEFT_Y,
            ANALOG_RIGHT_X,
            ANALOG_RIGHT_Y
        };

    public:
        double leftX, leftY, rightX, rightY;
        Button a, b, x, y;
        Button dpadUp, dpadRight, dpadLeft, dpadDown;
        Button lb, lt, rb, rt;

        std::array<double*, 4> ptrSticksArr = {
            &leftX, &leftY, &rightX, &rightY
        };

        std::array<Button*, 12> ptrButtonsArr = {
            &a, &b, &x, &y,
            &dpadUp, &dpadRight, &dpadLeft, &dpadDown,
            &lb, &lt, &rb, &rt
        };

        Gamepad(pros::controller_id_e_t id);
        void getInputs();
};
