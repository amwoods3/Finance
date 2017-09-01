#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include <string>
#include <iostream>

#include "Transaction.h"
#include "MoneyFactory.h"

// The account class is used for keeping track of the amount of money currently
// in the "account" and has a list of transactions within that account as well.

class Account {
public:
    // Create an account
    Account(const std::string & name, const std::string & currency,
            char currency_symbol, bool currency_has_cents,
            const std::string & start_amount);

    Account(const std::string & name, const MoneyFactory & mf,
            const std::string & start_amount);

    
    // TODO: Fix to handle moving to and from negative values
    void add_amount(const Money & m, const std::string & description);
    void take_amount(const Money & m, const std::string & description);
    
    void add_amount(const std::string & m, const std::string & description);
    void take_amount(const std::string & m, const std::string & description);

    Money current_amount() const;
    bool negative() const;
    std::string amount_repr() const;
private:
    std::vector<bool> negative_;
    std::vector<Money> amount_;
    std::vector<Transaction> transaction_list_;
    // Used for easily creating instances of Money when tracking spending
    MoneyFactory mf_;
    std::string name_;
};

#endif
