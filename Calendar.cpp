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
        os << c.year() << "/" << c.month() + 1 << "/" << c.day();
    }
    return os;

}
