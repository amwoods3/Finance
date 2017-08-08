#include "Account.h"

Account::Account(const std::string & currency,
                 char currency_symbol,
                 bool has_cents,
                 const std::string & start_amount):
    mf_(MoneyFactory(currency, currency_symbol, has_cents))
{
    // Assumes that format is format that the money factory can handle
    Money start = mf_(start_amount);
    add_amount(start, ACCOUNT_OPEN);
    negative_ = false;
}

Account::Account(const MoneyFactory & mf, const std::string & start_amount)
    : mf_(mf)
{
    Money start = mf_(start_amount);
    add_amount(start, ACCOUNT_OPEN);
    negative_ = false;
    
}


void Account::add_amount(const Money & m, int transaction_category) {
    Transaction t = Transaction(transaction_category,
                                negative_,
                                m);
    amount_.push_back(t.amount_after(current_amount()));
    transaction_list_.push_back(t);
}

void Account::take_amount(const Money & m, int transaction_category) {
    Transaction t = Transaction(transaction_category,
                                !negative_,
                                m);
    amount_.push_back(t.amount_after(current_amount()));
    transaction_list_.push_back(t);
}

Money Account::current_amount() const {
    if (amount_.size() == 0) {
        return mf_("0");
    }
    else {
        return amount_[amount_.size()-1];
    }
}
