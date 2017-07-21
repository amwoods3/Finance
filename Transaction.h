#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

#include "Money.h"
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
    
private:
    int category;
    Money amount;
    
};

#endif
