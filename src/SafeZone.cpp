#include "SafeZone.h"
#include <iostream>

SafeZone::SafeZone(int startRadius) {
    radius = startRadius;
}

void SafeZone::shrink() {
    if (radius > 0) {
        radius -= 10;
        std::cout << "SafeZone shrinks! New radius: " << radius << "\n";
    }
}
