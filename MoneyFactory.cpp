#include "MoneyFactory.h"

Money MoneyFactory::get_money(std::string c) const {
    if (has_cents_) {
        // May have left out the period, but we must make sure this doesn't
        // cause any issue.
        // We also have to make sure that if the c only has cents (.50) then
        // we fill in the 0.
        // A string with "50" interpreted as "USD" will be interpreted as
        // "$50.00"
        if (!string_has(c, ".")) {
            // another solution may be to throw an error
            // TODO: think about which solution would be better
            c += ".";
        }
    } else {
        if (string_has(c, ".")) {
            // This is an error, if the currency doesn't have cents,
            // then why would there be a "."?
        }
    }
    if (c[0] != symbol_) {
        return Money(symbol_ + c, currency_);
    } else {
        return Money(c, currency_);
    }
}
