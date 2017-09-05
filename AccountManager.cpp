#include "AccountManager.h"

namespace AccountManager {

    Account create(const std::string & account) {
        std::vector<std::string> account_components = Parsing::split(account);
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

        // If a date is included, we should use it
        if (account_components.size() > 6) {
            return Account(name, currency, c, cents, amount,
                           account_components[6]);
        }
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
        if (add_command.size() > 4) {
            ac.add_amount(add_command[2], comment, Calendar(add_command[4]));
        } else {
            ac.add_amount(add_command[2], comment);
        }
    }

    void take(Account & ac, std::vector<std::string> take_command) {
        // assume the command starts from 2 (after the add command)
        // the comment is from position 3 onward
        std::string comment = get_comment(take_command, 3);
        if (take_command.size() > 4) {
            std::cout << '(' << take_command[4] << ')' << std::endl;
            ac.take_amount(take_command[2], comment,
                           Calendar(take_command[4]));
        } else {
            ac.take_amount(take_command[2], comment);
        }
    }
    
    void perform_command(const std::string & command,
                         AccountMap &accounts) {
        std::vector<std::string> command_parts = Parsing::split_grouping(command);
        if (command_parts[0] == "create") {
            if (command_parts[1] == "create" ||
                command_parts[1] == "load" ||
                command_parts[1] == "list") {
                std::cout << "Cannot name a file that! " << std::endl;
                return;
            }
            Account t = create(command_parts);
            accounts.insert(AccountPair(t.name(), t));
        } else if (command_parts[0] == "load") {

            // if we are loading an account already in the map,
            // we will have issues, so let's not load that
            if (accounts.find(command_parts[1]) != accounts.end()) {
                // We have been told to load an account that is already
                // loaded, let's stop
                std::cout << "This account is already loaded!" << std::endl;
                return;
            }
            
            // Here we want to load the account that is here
            // load all previous transaction history
            std::ifstream account_to_load;
            account_to_load.open("Accounts/" + command_parts[1] + ".account");
            if (account_to_load.is_open()) {
                std::string load_command;
                while (std::getline(account_to_load, load_command)) {
                    perform_command(load_command, accounts);
                }
                std::cout << "successfully loaded " << command_parts[1]
                          << "!" << std::endl;
                account_to_load.close();
                return;
            } else {
                std::cout << "could not find accout " << command_parts[1]
                          << "!" << std::endl;
                return;
            }
        } else if (command_parts[0] == "list") {
            for (AccountIterator ait = accounts.begin(); ait != accounts.end();
                 ++ait) {
                std::cout << ait->first << ' ' << ait->second.current_amount()
                          << std::endl;
            }
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
                } else if (command_parts[1] == "show") {
                    ac->second.show_transaction_history();
                }
            } else {
                std::cout << "Unknown account " << command_parts[0]
                          << std::endl;
            }
        }
    }

    void save_accounts(AccountMap & am) {
        for (AccountIterator ait = am.begin(); ait != am.end(); ++ait) {
            std::cout << "saving account " << ait->first << std::endl;
            ait->second.save();
        }
    }

};
