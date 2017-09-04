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

    std::vector<std::string> split_grouping(const std::string & s,
                                            char splitter) {
        std::vector<std::string> splits;
        std::string sub;
        bool in_grouping = false;
        char grouping_char = ' ';
        for (int i = 0; i < s.size(); ++i) {
            if (in_grouping) {
                // If we are grouping, we want to group everything
                // verbatim. We do not want to ingore spaces, etc.
                // This allows for long description and things to
                // follow descriptions, such as transaction dates
                if (s[i] == grouping_char) {
                    grouping_char = ' ';
                    splits.push_back(sub);
                    sub = "";
                } else {
                    // copy verbatim
                    sub += s[i];
                }
            } else {
                if (s[i] == splitter) {
                    splits.push_back(sub);
                    sub = "";
                } else if (s[i] == '\'' || s[i] == '"') {
                    // We may be looking at a description or such
                    // we have to start grouping
                    in_grouping = true;
                    grouping_char = s[i];
                } else {
                sub += s[i];
                }
            }
        }
        if (in_grouping) {
            // we have a problem,
            // TODO: Handle this error
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
        
        return create(account_components);
    }

    Account create(const std::vector<std::string> & account_components) {
        // expected order is name, currency, currency symbol, y/n for cent,
        // and finally the starting amount for the account.
        std::string name = account_components[1];
        std::string currency = account_components[2];
        char c = account_components[3].c_str()[0];
        bool cents = account_components[4] == "y";
        std::string amount = account_components[5];
        return Account(name, currency, c, cents, amount);
    }

    std::string get_comment(std::vector<std::string> command, int start) {
        // this should be now only one part
        return command[start];
    }
    void add(Account & ac, std::vector<std::string> add_command) {
        // assume the command starts from 2 (after the add command)
        // the comment is from position 3 onward
        std::string comment = get_comment(add_command, 3);
        
        ac.add_amount(add_command[2], comment);
    }

    void take(Account & ac, std::vector<std::string> take_command) {
        // assume the command starts from 2 (after the add command)
        // the comment is from position 3 onward
        std::string comment = get_comment(take_command, 3);
        ac.take_amount(take_command[2], comment);
    }
    
    void perform_command(const std::string & command,
                         AccountMap &accounts) {
        std::vector<std::string> command_parts = split_grouping(command);
        if (command_parts[0] == "create") {
            Account t = create(command_parts);
            accounts.insert(AccountPair(t.name(), t));
        } else {
            // the first thing we expect is the account name
            AccountIterator ac = accounts.find(command_parts[0]);
            if (ac != accounts.end()) {
                // we found the account, lets perform the action
                if (command_parts[1] == "add" ||
                    command_parts[1] == "+") {
                    add(ac->second, command_parts);
                } else if (command_parts[1] == "take" ||
                           command_parts[1] == "-") {
                    take(ac->second, command_parts);
                }
            } else {
                std::cout << "Unknown account " << command_parts[0]
                          << std::endl;
            }
        }
    }

};
