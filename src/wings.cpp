#include "main.h"
#include "robotInit.h"

class Wings {
    private:
        ADIDigitalOut leftWing {LEFT_WING_PORT};
        ADIDigitalOut rightWing {RIGHT_WING_PORT};
        
        bool leftIsExtended = false;
        bool rightIsExtended = false;

    public:
        // Constructor
        Wings() {}

        // Returns whether or not each piston is extended
        bool getStatus() {
            bool statuses[2] = {leftIsExtended, rightIsExtended};
            return statuses;
        }

        /*  Sets the position for pneumatics 
            1 = extend, -1 = retract, 0 = stay */
        void setPosition(int leftPos, int rightPos) {
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

        /** NOTE: This overloads setPosition(),
            functionally the same as defaulting right param to left */
        void setPosition(int bothPos) {
            setPosition(bothPos, bothPos);
        }

        
};