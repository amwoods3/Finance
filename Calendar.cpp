#include "Calendar.h"

Calendar::Calendar(int year, int month, int day, bool display_english) {
    year_ = year;
    month_ = month;
    day_ = day;
    display_in_English_ = display_english;
}

Calendar::Calendar(bool display_english) {
        std::time_t t = std::time(0);
        struct tm * now = std::localtime(&t);
        year_ = now->tm_year + 1900;
        month_ = now->tm_mon;
        day_ = now->tm_mday;
        display_in_English_ = display_english;
}


std::ostream & operator<<(std::ostream & os, const Calendar & c) {
    if (c.displaysEnglish()) {
        os << months[c.month()] << " " << c.day() << ", " << c.year();
    } else {
        // month is one less than how humans write so we add 1 to it.
        os << c.year() << "/" << c.month() + 1 << "/" << c.day();
    }
    return os;

}

bool leap_year(int year) {
    // Leap year happens every 4 years, but is skipped on years
    // that are divisible by 100 unless they are divisible by 400
    // as well. 
    if (year % 4 == 0) {
        // skip if the year is divisible by 100 but not 400
        return year % 100 != 0 || year % 400 == 0;
    }
    return false;
}

int day_count(int month, int year) {
    if (month == 1) {
        // This is February
        if (leap_year(year)) {
            return 29;
        }
        return 28;
    } if (month < 7) {// August and July has the same value
        if (month % 2 == 0) {
            return 31;
        }
        return 30;
    }
    if (month % 2 == 1) {
        return 31;
    }
    return 30;
}
