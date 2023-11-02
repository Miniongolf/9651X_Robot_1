#include "main.h"

class Button {
    private:
        bool prevState = false, currState = false;

    public:
        Button();
        bool pressed, released, held;
        void setStatus(bool isPressed);
};