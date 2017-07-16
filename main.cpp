#include <iostream>

#include "Calendar.h"

int main() {

    Calendar today = Calendar(true);
    std::cout << today << std::endl;
    return 0;
}
