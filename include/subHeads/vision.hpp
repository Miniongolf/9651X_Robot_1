#include "main.h"

class CustomVision {
    public:
        std::array<double, 2> relativePos;
        CustomVision();
        void scan();
};