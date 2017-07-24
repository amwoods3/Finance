#ifndef TEST_H
#define TEST_H

#include <exception>
#include <vector>
#include <string>

#include "TestCalendar.h"
#include "TestMoney.h"
#include "TestMoneyFactory.h"

// A way to make sure that a given value is as expected is to check it against
// expected value. If it is equal to expected value, the assertion will pass.
class AssertionError: private std::exception {};

// Test functions
std::vector<bool (*)()> test_functions = std::vector<bool (*)()>();

// test function names
std::vector<std::string> function_names = std::vector<std::string>();

void add_test_function(bool (*func)(void), const std::string & func_name) {
    test_functions.push_back(func);
    function_names.push_back(func_name);
}

void assert(bool v) {
    if (v) {
        return;
    }
    AssertionError e = AssertionError();
    throw e;
}

void fill_tests() {
    add_test_function(test_leap_year, "test_leap_year");
    add_test_function(test_day_count, "test_day_count");
    add_test_function(test_day_value_of, "test_day_value_of");
    add_test_function(test_day_value_constructor, "test_day_value_constructor");
    add_test_function(test_go_to_next_day, "test_go_to_next_day");
    add_test_function(test_Money_operator_plus_different_currency_type,
                      "test_Money_operator_plus_different_currency_type");
    add_test_function(test_MoneyFactory_get_money,
                      "test_MoneyFactory_get_money");
}

void test() {
    int pass = 0;
    int fail = 0;
    fill_tests();
    std::vector<std::string> failed_functions;
    for (int i = 0; i < test_functions.size(); ++i) {
        if (test_functions[i]()) {
            std::cout << function_names[i] << " PASS\n";
            pass += 1;
        } else {
            std::cout << function_names[i] << " FAIL ************\n";
            failed_functions.push_back(function_names[i]);
            fail += 1;
            
        }
    }
    std::cout << pass << " PASSES. " << fail << " FAILS\n";
    if (fail > 0) {
        std::cout << "**************************************************\n";
        std::cout << "List of functions that failed:\n";
        std::cout << "**************************************************\n";
        for (int i = 0; i < failed_functions.size(); ++i) {
            std::cout << failed_functions[i] << std::endl;
        }
    }
}



#endif
