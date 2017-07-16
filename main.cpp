#include <iostream>

#include "Calendar.h"

int main() {

    std::cout << leap_year(1900) << " == 0" << std::endl;
    std::cout << leap_year(1600) << " == 1" << std::endl;
    std::cout << leap_year(2004) << " == 1" << std::endl;
    std::cout << leap_year(2005) << " == 0" << std::endl;
    return 0;
}
