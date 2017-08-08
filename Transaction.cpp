#include "Transaction.h"

Transaction::Transaction(int cat, bool decrease, Money a, Calendar date)
    : category_(cat), decrease_(decrease), amount_(a), date_(date)
{
    // The credit account may not be known straight away and may 
}

Money Transaction::amount_after(Money oa) {
    if (is_decrease()) {
        // money cannot have a negative amount,
        // negative is represented by direction flow of money
        return oa - amount();
    } else {
        return oa + amount();
    }
}
