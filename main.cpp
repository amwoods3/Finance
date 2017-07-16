#include <iostream>
#include <string>

#include "Calendar.h"

int main(int argv, char ** argc) {
    if (argv > 1) {
        if (std::string(argc[1]) == std::string("test")) {
            std::cout << "Test Mode!" << std::endl;
        }
    }
    return 0;
}
