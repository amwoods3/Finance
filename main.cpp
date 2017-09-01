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
        AccountMap accm;
        AccountManager::perform_command("create test USD $ y 853", accm);
        accm.find("test")->second.show_transaction_history();
        AccountManager::perform_command("test add 482.32 payday", accm);
        AccountManager::perform_command("test take 72.33 game", accm);
        accm.find("test")->second.show_transaction_history();
        AccountManager::perform_command("food add 50.00 transfer", accm);
        AccountManager::perform_command("create food USD $ y 50", accm);
        AccountManager::perform_command("food take 10.00 cereal/milk", accm);
        accm.find("food")->second.show_transaction_history();
        
        
    }
    return 0;
}
