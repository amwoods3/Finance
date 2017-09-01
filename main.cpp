#include <iostream>
#include <string>

#include "Test.h"
#include "Account.h"

int main(int argv, char ** argc) {
    if (argv > 1) {
        if (std::string(argc[1]) == std::string("test")) {
            test();
        }
    } else {
        Account food_budget = Account("Food", "USD", '$', true, "50");
        Account blah = Account("blah", "USD", '$', true, "100");
        food_budget.take_amount("82.33", "Buy weeks groceries"); // Spend
        food_budget.add_amount("100", "Add $100 to budget from blah account"); // Spend
        blah.take_amount("100", "Move $100 to food");
        std::cout << food_budget.amount_repr() << std::endl;
        food_budget.show_transaction_history(2);
    }
    return 0;
}
