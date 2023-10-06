#include "main.h"

class inputBuffer {
    private:
        Controller gamepad(CONTROLLER_MASTER);
        /** NOTE: denominator is 127.0 because of int division imprecisions
			Changes range of inputs to -1 <= x <= 1 for normalization */
        
        double leftX = gamepad.get_analog(ANALOG_LEFT_X)/127.0;
		double leftY = gamepad.get_analog(ANALOG_LEFT_Y)/127.0;
		double rightX = gamepad.get_analog(ANALOG_RIGHT_X)/127.0;
        double rightY = gamepad.get_analog(ANALOG_RIGHT_Y)/127.0;

        
}