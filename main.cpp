#include <iostream>
#include <string>

#include "Test.h"
#include "Account.h"
#include "AccountManager.h"

int main(int argv, char ** argc) {
    if (argv > 1) {
        if (std::string(argc[1]) == std::string("test")) {
            test();
        }
    } else {
        Account a = AccountManager::create("testaccount USD $ y 7654321.98");
        a.show_transaction_history();
    }
    return 0;
}
