#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <vector>
#include <iostream>
#include <string>

#include "Account.h"

namespace AccountManager {
    std::vector<std::string> split(const std::string & to_split, char splitter=' ');
    Account create(const std::string & account_information);
};

#endif
