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
        AccountManager::perform_command("test add 482.32 'payday from company' this should not appear in description",
                                        accm);
        AccountManager::perform_command("test take 72.33 'buy playstation game'",
                                        accm);
        accm.find("test")->second.show_transaction_history();
        AccountManager::perform_command("food add 50.00 transfer", accm);
        AccountManager::perform_command("test take 50.00 'transfer to food'", accm);
        AccountManager::perform_command("create food USD $ y 50", accm);
        AccountManager::perform_command("food take 10.00 'cereal, milk and bananas'",
                                        accm);
        accm.find("food")->second.show_transaction_history();
        
        
    }
    return 0;
}
