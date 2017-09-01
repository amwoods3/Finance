#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

#include <string>

#include "Money.h"
#include "Calendar.h"
// class used for representing a transaction.
// This class will be used for determining money flow
// The transaction can have a category (such as Food Expense, Utilities Expense,
// etc.) This category is set by the user and the category list is to be created
// by the user. Not all users will have the same type of expenses, maybe
// one user has two hobbies, and wants to separate the expenses of both hobbies,
// maybe one user wants to track how much money specifically they are spending
// on specifically cigarettes. Etc.

class Transaction {
public:
    // category (what kind of transaction), if the account affected was
    // a decrease and how much money was involved
    Transaction(bool decrease, Money amount, Calendar date=Calendar());
    Transaction(const std::string & description,
                bool decrease, Money amount,
                Calendar date=Calendar());
                
    // get the amount of money remaining after the transaction
    Money amount_after(Money original_amount);

    Money amount() { return amount_; }
    bool is_decrease() { return decrease_;}
    std::string description() { return description_; }
    void set_description(const std::string & descr)
    { description_ = descr; }
private:
    bool decrease_;
    Money amount_;
    std::string description_;
    Calendar date_;
};

#endif
