#ifndef MONEYFACTORY_H
#define MONEYFACTORY_H

#include "Money.h"

// Class meant for making Money instances. This will separate the need of
// stating the currency type every call preventing from errors and such.

class MoneyFactory {
public:
    MoneyFactory(const std::string & c, const char & symbol, bool hc)
        : currency_(c), symbol_(symbol), has_cents_(hc)
    {}

    Money get_money(std::string) const;

    Money operator()(const std::string & s) const { return get_money(s);}
private:
    std::string currency_;
    char symbol_;
    bool has_cents_;
};

#endif
