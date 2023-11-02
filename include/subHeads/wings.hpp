#include "main.h"

class Wings {
    private:    
        bool leftIsExtended = false, rightIsExtended = false;

    public:
        // Wings class constructor (no args)
        Wings();

        // Returns whether or not each piston is extended
        std::array<bool,2> getStatus();

        // Sets the position for pneumatics
        // 1 = extend | -1 = retract | 0 = stay
        void setPosition(int leftPos, int rightPos);

        /** Nxunctionally the same as defaulting right param to left */
        void setPosition(int bothPos);
};