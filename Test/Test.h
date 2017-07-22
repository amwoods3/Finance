#ifndef TEST_H
#define TEST_H

#include <exception>

#include "TestCalendar.h"

// A way to make sure that a given value is as expected is to check it against
// expected value. If it is equal to expected value, the assertion will pass.
class AssertionError: private std::exception {};

// Test functions
bool (*test_functions[])(void) = {test_leap_year, test_day_count, test_day_value_of,
                           test_day_value_constructor, test_go_to_next_day};

// test function names
std::string function_names[] = {"test_leap_year", "test_day_count",
                              "test_day_value_of", "test_day_value_constructor",
                                "test_go_to_next_day"};

void assert(bool v) {
    if (v) {
        return;
    }
    AssertionError e = AssertionError();
    throw e;
}

void test() {
    int pass = 0;
    int fail = 0;
    for (int i = 0; i < 5; ++i) {
        if (test_functions[i]()) {
            std::cout << function_names[i] << " PASS\n";
            pass += 1;
        } else {
            std::cout << function_names[i] << " FAIL ************\n";
            fail += 1;
            
        }
    }
    std::cout << pass << " PASSES. " << fail << " FAILS\n";
}



#endif
