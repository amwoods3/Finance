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
        Account food_budget = Account("USD", '$', true, "50");
        std::cout << "Open food account with $50 "
                  << food_budget.amount_repr() << std::endl;
        food_budget.take_amount("82.33", 1); // Spend
        std::cout << "spent $82.33 on food "
                  << food_budget.amount_repr() << std::endl;
        food_budget.add_amount("100", 1); // Spend
        std::cout << "add $100 to food budget "
                  << food_budget.amount_repr() << std::endl;
    }
    return 0;
}
