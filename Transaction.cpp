#include "Transaction.h"

Transaction::Transaction(bool decrease, Money a, Calendar date)
    : decrease_(decrease), amount_(a), date_(date)
{
    // The credit account may not be known straight away and may 
}

Transaction::Transaction(const std::string & description,
                         bool decrease, Money a,
                         Calendar date)
    : description_(description), decrease_(decrease), amount_(a),
      date_(date)
{
}

Money Transaction::amount_after(Money oa) {
    if (is_decrease()) {
        // money cannot have a negative amount,
        // negative is represented by direction flow of money
        if (oa >= amount()) {
            return oa - amount();
        } else {
            return amount() - oa;
        }
    } else {
        return oa + amount();
    }
}
