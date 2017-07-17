#include "Calendar.h"

Calendar::Calendar(int year, int month, int day, bool display_english) {
    year_ = year;
    // count from 0 to year_ to get number of days
    if (month < 0 || month > 11) {
        MonthError me;
        throw me;
    }
    day_ = day;
    day_value_ = day_value_of(year_, month_, day_);
    display_in_English_ = display_english;
}

Calendar::Calendar(bool display_english) {
        std::time_t t = std::time(0);
        struct tm * now = std::localtime(&t);
        year_ = now->tm_year + 1900;
        month_ = now->tm_mon;
        day_ = now->tm_mday;
        day_value_ = day_value_of(year_, month_, day_);
        display_in_English_ = display_english;
        
}

Calendar::Calendar(int day_value, bool display_english) {
    int dv = 0;
    year_ = 0;
    month_ = 0;
    if (day_value > 0) {
        int days_in_this_year = 366;
        while (dv + days_in_this_year <= day_value) {
            dv += days_in_this_year;
            year_ += 1;
            days_in_this_year = (leap_year(year_) ? 366 : 365);
        }
        int days_in_this_month = 31;
        while (dv + days_in_this_month < day_value) {
            dv += days_in_this_month;
            month_ += 1;
            days_in_this_month = day_count(month_, year_);
        }
        day_ = day_value - dv + 1;
    } else if (day_value < 0) {
        int days_in_this_year = 365;
        while (dv - days_in_this_year > day_value) {
            dv -= days_in_this_year;
            year_ -= 1;
            days_in_this_year = (leap_year(year_ - 1) ? 366 : 365);
        }
        // go back one more year to be able to go up...
        dv -= days_in_this_year;
        year_ -= 1;
        int days_in_this_month = 31;
        while (dv + days_in_this_month < day_value) {
            dv += days_in_this_month;
            month_ += 1;
            days_in_this_month = day_count(month_, year_);
        }
        day_ = day_value - dv + 1;
    } else {
        day_ = 1;
    }

    display_in_English_ = display_english;
    day_value_ = day_value;
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

int day_value_of(int year, int month, int day) {
    int y = 0;
    int m = 0;
    int dv = 0;
    if (month < 0 || month > 11) {
        MonthError me;
        throw me;
    }
    if (year < 0) {
        // count backwards
        while (y > year) {
            y -= 1;
            if (leap_year(y)) {
                dv -= 366;
            } else {
                dv -= 365;
            }
        }
    } else {
        while (y < year) {
            if (leap_year(y)) {
                dv += 366;
            } else {
                dv += 365;
            }
            y += 1;
        }
    }

    
    for (m = 0; m < month; ++m) {
        dv += day_count(m, year);
    }

    dv += day - 1;
    return dv;
    
}
