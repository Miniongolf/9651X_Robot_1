#include "main.h"
#include "robotInit.h"

class Gamepad {
    private:
        Controller gamepad{CONTROLLER_MASTER};
    public:
        double leftX = gamepad.get_analog(ANALOG_LEFT_X)/127.0;
        double leftY = gamepad.get_analog(ANALOG_LEFT_Y)/127.0;
        double rightX = gamepad.get_analog(ANALOG_RIGHT_X)/127.0;
        double rightY = gamepad.get_analog(ANALOG_RIGHT_Y)/127.0;

        
};