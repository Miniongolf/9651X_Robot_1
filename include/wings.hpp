#include "main.h"
#include "pros/adi.hpp"

class Wings {
    private:
        ADIAnalogOut leftWing;
        ADIAnalogOut rightWing;
    
    public:
        std::array<bool,2> getStatus()
        
};