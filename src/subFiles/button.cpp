#include "main.h"

// Default constructor
Button::Button() {}

// Sets the button state of pressed, held, and released
void Button::setStatus(bool isPressed) {
    currState = isPressed;
    
    // Button pressed
    if (!prevState && currState) {
        pressed = true;
        held = true;
        released = false;
    }
    
    // Button held down
    else if (prevState && currState) {
        pressed = false;
        held = true;
        released = false;
    }
    
    // Button released
    else if (prevState && !currState) {
        pressed = false;
        held = false;
        released = true;
    }
    
    // Button not held down
    else {
        pressed = false;
        held = false;
        released = false;
    }

    // Update prevState for next run
    prevState = currState;
}

