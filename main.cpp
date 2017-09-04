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
        AccountMap accounts;
        std::string command;
        while (true) {
            std::getline(std::cin, command);
            if (command == "quit") {
                break;
            } else {
                AccountManager::perform_command(command, accounts);
            }
        }
    }
    return 0;
}


