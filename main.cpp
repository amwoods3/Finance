#include <iostream>
#include <string>

#include "Calendar.h"
#include "Test.h"

int main(int argv, char ** argc) {
    if (argv > 1) {
        if (std::string(argc[1]) == std::string("test")) {
            test();
        }
    }
    return 0;
}
