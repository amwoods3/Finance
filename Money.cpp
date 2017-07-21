#include "Money.h"


Money::Money(const std::string & amount) {
    currency_ = amount[0];
    amount_ = interpret_amount(amount, 1);
    has_larger_currency_ = string_has(amount, ".");
}


long long unsigned interpret_amount(const std::string & amount,
                                    int start_index) {
    long long unsigned total = 0;
    bool period_found = false;
    for (int i = start_index; i < amount.size(); ++i) {
        if (amount[i] >= '0' && amount[i] <= '9') {
            total += int(amount[i] - '0');
            total *= 10;
        } else if (amount[i] == '.') {
            if (i == amount.size() - 1) {
                // May end in '.' i.e. "$350."
                total *= 100;
                return total;
            }
            if (amount[i+1] >= '0' && amount[i+1] <= '9') {
                total += int(amount[i+1] - '0');
            } else {
                // throw error
            }
            total *= 10;
            if (i == amount.size() - 2) {
                // May end in with only one decimal i.e "$350.2"
                total *= 10;
                return total;
            }
            if (amount[i+2] >= '0' && amount[i+1] <= '9') {
                total += int(amount[i+2] - '0');
            } else {
                // throw error
            }
            return total;
        }
    }
    return total / 10;
}

std::string Money::repr() const {
    std::string representation = currency_;
    if (has_larger_currency()) {
        representation += std::to_string(amount_ / 100);
        representation += ".";
        int am = amount_ % 100;
        if (am < 10) {
            representation += "0";
        }
        representation += std::to_string(am);
        return representation;
    }
    return representation + std::to_string(amount_);
}

bool string_has(const std::string & s, const std::string & target) {
    int found = s.find(target);
    return found != std::string::npos;
}
