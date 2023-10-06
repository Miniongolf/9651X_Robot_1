#include "main.h"
#include "robotInit.h"

class Catapult {
    private:
        // Initialize catapult motor
        Motor cata = Motor(CATA_PORT, MOTOR_GEAR_RED, false);

    public:
        void run() {
            cata.move(127);
        }
};