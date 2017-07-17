#ifndef TEST_H
#define TEST_H

#include <exception>

#include "TestCalendar.h"

// A way to make sure that a given value is as expected is to check it against
// expected value. If it is equal to expected value, the assertion will pass.
class AssertionError: private std::exception {};

void assert(bool v) {
    if (v) {
        return;
    }
    AssertionError e = AssertionError();
    throw e;
}

void test() {
    try {
        assert(test_leap_year());
        assert(test_day_count());
        assert(test_day_value_of());
        std::cout << "All tests passed!" << std::endl;
    } catch(AssertionError e) {
        std::cout << "Tests failed\n";
    }
}



#endif
