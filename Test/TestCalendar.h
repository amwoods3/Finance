#ifndef TESTCALENDAR_H
#define TESTCALENDAR_H

#include "Calendar.h"

bool test_leap_year();

// tests for each month with appropriate input
// TODO: test for unwanted input (months beyond december/negative months)
bool test_day_count();

// tests for day_values of various year, month, and day
bool test_day_value_of();

bool test_day_value_constructor();

bool test_go_to_next_day();

bool test_constructor_int_int_int();
#endif
