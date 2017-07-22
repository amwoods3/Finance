#include <iostream>
#include <string>

#include "Calendar.h"
#include "MoneyFactory.h"
#include "Test.h"

int main(int argv, char ** argc) {
    if (argv > 1) {
        if (std::string(argc[1]) == std::string("test")) {
            test();
        }
    } else {
        MoneyFactory usd("USD", '$', true);
        Money allowance = usd("$50");
        std::cout << allowance << std::endl;
    }
    return 0;
}
