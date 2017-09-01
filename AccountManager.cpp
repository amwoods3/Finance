#include "AccountManager.h"

namespace AccountManager {
    std::vector<std::string> split(const std::string & s, char splitter) {
        std::vector<std::string> splits;
        std::string sub;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == splitter) {
                splits.push_back(sub);
                sub = "";
            } else {
                sub += s[i];
            }
        }
        if (sub.size() > 0) {
            splits.push_back(sub);
        }
        return splits;
    }
    Account create(const std::string & account) {
        std::vector<std::string> account_components = split(account);
        for (int i = 0; i < account_components.size(); ++i) {
            std::cout << account_components[i] << std::endl;
        }
        // expected order is name, currency, currency symbol, y/n for cent,
        // and finally the starting amount for the account.
        std::string name = account_components[0];
        std::string currency = account_components[1];
        char c = account_components[2].c_str()[0];
        bool cents = account_components[3] == "y";
        std::string amount = account_components[4];
        return Account(name, currency, c, cents, amount);
    }
};
