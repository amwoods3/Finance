#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>

#include "Account.h"
#include "Parsing.h"

typedef std::map<std::string, Account> AccountMap;
typedef std::pair<std::string, Account> AccountPair;
typedef std::map<std::string, Account>::iterator AccountIterator;

namespace AccountManager {
    Account create(const std::string & account_information);
    Account create(const std::vector<std::string> & account_components);
    void perform_command(const std::string & command, AccountMap &accounts);
};

#endif
