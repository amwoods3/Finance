#ifndef TESTMONEY_H
#define TESTMONEY_H

#include <iostream>
#include <exception>

#include "Money.h"

bool test_Money_operator_plus_different_currency_type() {
    try {
        Money usd = Money("$34.23", "USD");
        Money jpy = Money("¥1844", "JPY");
        Money wont_work = usd + jpy;
        return false;
    } catch (CurrencyMismatch e) {
        return true;
    }
}

#endif

