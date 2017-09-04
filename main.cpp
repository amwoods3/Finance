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
        AccountMap am;
        AccountManager::perform_command("create cash USD $ y 37.43 2017/09/02",
                                        am);
        AccountManager::perform_command(
            "cash take 13.12 'buy kefir and kombucha' 2017/09/03",
            am);
        am.find("cash")->second.show_transaction_history();
    }
    return 0;
}


