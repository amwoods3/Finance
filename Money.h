#ifndef MONEY_H
#define MONEY_H

#include <string>
#include <iostream>
#include <iomanip>
#include <exception>


class CurrencyMismatch: private std::exception {};

// class to represent money. A double could be used, but it is inprecise
// when representing numbers like 0.1 (10 cents) and also represents too many
// decimals a better representation would be an integer representing the number
// of cents 

class Money {
public:
    // start the string with the currency sign (USD with '$', JPY with '¥', etc)
    // If currency has smaller part (cents for USD, pence for British Pound)
    //   then include a . with the amount for smaller currency.
    Money(const std::string & amount, const std::string & currency);
    Money(long long unsigned amount)
        : amount_(amount) {}

    void translate_type_to(Money & m) const;

    // currently calculates no matter then currency type
    Money operator+(const Money & m) const;
    Money operator-(const Money & m) const;

    // comparison operators
    bool operator<(const Money & m) const;
    bool operator>(const Money & m) const;
    bool operator==(const Money & m) const;
    bool operator>=(const Money & m) const;
    bool operator<=(const Money & m) const;
    bool operator!=(const Money & m) const;

    void currency_match_assurance(const Money & m) const;
    double to_double() { return double(amount_) / 100.0; }
    long long unsigned to_integer() const {return amount_;}

    long long unsigned amount() const {return amount_;}

    bool has_larger_currency() const {return has_larger_currency_;}

    void set_larger_currency(bool t) {has_larger_currency_ = t;}

    std::string currency() const { return currency_;}
    std::string symbol() const { return currency_symbol_; }
    std::string repr() const;
private:
    long long unsigned amount_;
    bool has_larger_currency_;
    std::string currency_;
    std::string currency_symbol_;
};

inline
std::ostream & operator<<(std::ostream & os, const Money & m) {
    os << m.repr();
    return os;
}

long long unsigned interpret_amount(const std::string & amount,
                                    int start_index);
bool string_has(const std::string & s, const std::string & target);

#endif
