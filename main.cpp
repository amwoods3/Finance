#include <iostream>
#include <string>

#include "Test.h"
#include "Account.h"

int main(int argv, char ** argc) {
    if (argv > 1) {
        if (std::string(argc[1]) == std::string("test")) {
            test();
        }
    } else {
        Account wallet("USD", '$', true, "0");
        std::cout << wallet.current_amount() << std::endl;
    }
    return 0;
}
