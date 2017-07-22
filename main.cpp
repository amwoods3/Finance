#include <iostream>
#include <string>

#include "Calendar.h"
#include "Money.h"
#include "Test.h"

int main(int argv, char ** argc) {
    if (argv > 1) {
        if (std::string(argc[1]) == std::string("test")) {
            test();
        }
    } else {
        Money m("$350.01");
        std::cout << m << std::endl;
    }
    return 0;
}
