#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <string>
#include <ctime>

/*
  This Caledar class can tell the difference between two dates, and it can add
  a certain number of days to a given date giving the result date.
 */

const std::string months[] = {"January", "February", "March", "April",
                              "May", "June", "July", "September", "October",
                              "November", "December"};

class Calendar {
public:
    Calendar(int year, int month, int day, bool display_english=false);

    Calendar(bool display_english=false);

    int year() const {
        return year_;
    }

    int month() const {
        return month_;
    }

    int day() const {
        return day_;
    }

    int displaysEnglish() const {
        return display_in_English_;
    }

private:
    int year_;
    int month_;
    int day_;
    bool display_in_English_;
};

std::ostream & operator<<(std::ostream & os, const Calendar & c);

#endif
