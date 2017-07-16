#include "TestCalendar.h"

bool test_leap_year() {
    if (!leap_year(2000)) {
        std::cout << "leap_year(2000) fail\n";
        return false;
    } else if (leap_year(1900)) {
        std::cout << "leap_year(1900) fail\n";
        return false;
    } else if (!leap_year(1904)) {
        std::cout << "leap_year(1904) fail\n";
        return false;
    } else if (leap_year(1907)) {
        std::cout << "leap_year(1907) fail\n";
        return false;
    }
    return true;
}
