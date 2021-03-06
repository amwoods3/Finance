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
    } if (!leap_year(0)) {
        std::cout << "leap_year(0) fail\n";
        return false;
    }
    return true;
}

bool test_day_count() {
    if (day_count(1, 2005) != 28) {
        std::cout << "day_count(1, 2005) fail\n";
        return false;
    } else if (day_count(1, 2004) != 29) {
        std::cout << "day_count(1, 2004) fail\n";
        return false;
    } else if (day_count(1, 1900) != 28) {
        std::cout << "day_count(1, 1900) fail\n";
        return false;
    } else if (day_count(0, 1900) != 31) {
        std::cout << "day_count(0, 1900) fail\n";
        return false;
    } else if (day_count(2, 1907) != 31) {
        std::cout << "day_count(2, 1907) fail\n";
        return false;
    } else if (day_count(3, 1907) != 30) {
        std::cout << "day_count(3, 1907) fail\n";
        return false;
    } else if (day_count(4, 1908) != 31) {
        std::cout << "day_count(4, 1908) fail\n";
        return false;
    } else if (day_count(5, 1908) != 30) {
        std::cout << "day_count(5, 1908) fail\n";
        return false;
    } else if (day_count(6, 1908) != 31) {
        std::cout << "day_count(6, 1908) fail\n";
        return false;
    } else if (day_count(7, 1908) != 31) {
        std::cout << "day_count(7, 1908) fail\n";
        return false;
    } else if (day_count(8, 1908) != 30) {
        std::cout << "day_count(8, 1908) fail\n";
        return false;
    } else if (day_count(9, 1908) != 31) {
        std::cout << "day_count(9, 1908) fail\n";
        return false;
    } else if (day_count(10, 1908) != 30) {
        std::cout << "day_count(10, 1908) fail\n";
        return false;
    } else if (day_count(11, 1908) != 31) {
        std::cout << "day_count(11, 1908) fail\n";
        return false;
    } 
    return true;
}


bool test_day_value_of() {
    if (day_value_of(0, 0, 1) != 0) {
        std::cout << "day_value_of(0, 0, 1) fail\n";
        return false;
    } else if (day_value_of(1, 0, 1) != 366) {
        std::cout << "day_value_of(1, 0, 1) fail\n";
        std::cout << day_value_of(1, 0, 1) << " != 366" << std::endl;
        return false;
    } else if (day_value_of(4, 0, 5) != 1465) {
        std::cout << "day_value_of(4, 0, 5) fail\n";
        std::cout << day_value_of(4, 0, 5) << " != 1465" << std::endl;
        return false;
    } else if (day_value_of(4, 2, 1) != 1521) {
        std::cout << "day_value_of(4, 2, 1) fail\n";
        return false;
    } else if (day_value_of(-1, 11, 31) != -1) {
        // 1 day before day 0, it should be -1
        std::cout << "day_value_of(-1, 11, 31) fail\n";
        return false;
    } else if (day_value_of(-1, 0, 1) != -365) {
        std::cout << "day_value_of(-1, 0, 1) fail\n";
        return false;
    } else if (day_value_of(-4, 0, 1) != -1461) {
        std::cout << "day_value_of(-4, 0, 1) fail\n";
        return false;
    }

    return true;
}

bool test_day_value_constructor() {
    for (int day = -50000; day < 50000; ++day) {
        Calendar test_calendar = Calendar(day);
        if (day_value_of(test_calendar.year(),
                         test_calendar.month(),
                         test_calendar.day()) != test_calendar.day_value()) {
            std::cout << "test_day_value_constructor() on day " << day << " failed\n";
            return false;
        }
    }
    return true;
}

bool test_go_to_next_day() {
    Calendar c1 = Calendar(0, 11, 31);
    c1.go_to_next_day();
    if (c1.year() != 1 || c1.month() != 0 || c1.day() != 1) {
        std::cout << "Failed to wrap year on go_to_next_day()" << std::endl;
        std::cout << c1 << std::endl;
        return false;
    }
    Calendar c2 = Calendar(0, 1, 28);
    c2.go_to_next_day();
    if (c2.year() != 0 || c2.month() != 1 || c2.day() != 29) {
        std::cout << "Failed to account for leap year in go_to_next_day()"
                  << std::endl;
        std::cout << c2 << std::endl;
        return false;
    }
    return true;
}
