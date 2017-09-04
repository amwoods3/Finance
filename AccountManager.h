#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>

#include "Account.h"

typedef std::map<std::string, Account> AccountMap;
typedef std::pair<std::string, Account> AccountPair;
typedef std::map<std::string, Account>::iterator AccountIterator;

namespace AccountManager {
    std::vector<std::string> split(const std::string & to_split, char splitter=' ');

    // split grouping allows for splitting, and grouping based on
    // either single or double quotes
    std::vector<std::string> split_grouping(const std::string & to_split,
                                   char splitter=' ');
    Account create(const std::string & account_information);
    Account create(const std::vector<std::string> & account_components);
    void perform_command(const std::string & command, AccountMap &accounts);
};

#endif
