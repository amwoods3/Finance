#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <string>
#include <exception>
#include <ctime>

/*
  This Caledar class can tell the difference between two dates, and it can add
  a certain number of days to a given date giving the result date.
 */

const std::string months[] = {"January", "February", "March", "April",
                              "May", "June", "July", "August", "September", "October",
                              "November", "December"};

class MonthError: private std::exception {};

class Calendar {
public:
    Calendar(int year, int month, int day);
    Calendar();

    // Get a day with a certain day_value
    Calendar(int day_value);
    int year() const {
        return year_;
    }

    int month() const {
        return month_;
    }

    int day() const {
        return day_;
    }

    int day_value() const {
        return day_value_;
    }

    static bool displaysEnglish() {
        return display_in_English_;
    }

    static void toggleEnglish() {
        display_in_English_ = !display_in_English_;
    }
    int days_from(const Calendar & c) const;

    void state_days_from(const Calendar & c) const;

    void go_to_next_day();
private:
    int year_;
    int month_;
    int day_;
    int day_value_;
    static bool display_in_English_;
};

// print calendar date, if displaysEnglish() returns true will write month
// out in English
std::ostream & operator<<(std::ostream & os, const Calendar & c);

// returns true if a given year is a leap year. returns false otherwise
bool leap_year(int year);
int day_count(int month, int year);
int day_value_of(int year, int month, int day);

#endif
