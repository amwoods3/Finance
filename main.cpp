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
        MoneyFactory USD("USD", '$', true);
        Account food_budget = Account("USD", '$', true, "50");
        std::cout << food_budget.current_amount() << std::endl;
        food_budget.take_amount(USD("82.33"), 1); // Spend
        std::cout << food_budget.current_amount() << std::endl;
        food_budget.add_amount(USD("100"), 1); // Spend
        std::cout << food_budget.current_amount() << std::endl;
    }
    return 0;
}
