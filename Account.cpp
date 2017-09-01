#include "Account.h"

Account::Account(const std::string & name,
                 const std::string & currency,
                 char currency_symbol,
                 bool has_cents,
                 const std::string & start_amount):
    mf_(MoneyFactory(currency, currency_symbol, has_cents)), name_(name)
{
    // Assumes that format is format that the money factory can handle
    Money start = mf_(start_amount);
    add_amount(start, "Open " + name + " account.");
    negative_.push_back(false);
}

Account::Account(const std::string & name, const MoneyFactory & mf,
                 const std::string & start_amount)
    : mf_(mf), name_(name)
{
    Money start = mf_(start_amount);
    add_amount(start, "Open " + name + " account.");
    negative_.push_back(false);
    
}


void Account::add_amount(const Money & m, const std::string & description) {
    // If we are adding an amount to a negative amount, that amount
    // gets smaller so it is a decrease if negative
    Transaction t = Transaction(description,
                                negative(),
                                m);


    // If negative and the amount added is less than current_amount
    // it stays negative, otherwise it is no longer negative.
    // if it was not negative, it is not negative now.
    negative_.push_back(negative() && m < current_amount());
    amount_.push_back(t.amount_after(current_amount()));
    transaction_list_.push_back(t);
}

void Account::add_amount(const std::string & m, const std::string & description) {
    add_amount(mf_(m), description);
}

void Account::take_amount(const Money & m, const std::string & description) {
    // If we are subtracting a negative amount from a negative number,
    // we just make it bigger thus, it is a decrease if it is not negative
    Transaction t = Transaction(description,
                                !negative(),
                                m);

    // If we took more than we had, we go negative.
    // If we were negative, we stay negative.
    negative_.push_back(negative() || m > current_amount());
    amount_.push_back(t.amount_after(current_amount()));
    transaction_list_.push_back(t);
}

void Account::take_amount(const std::string & m, const std::string & description) {
    take_amount(mf_(m), description);
}

Money Account::current_amount() const {
    if (amount_.size() == 0) {
        return mf_("0"); // Money Factory will automatically set currency type
    }
    else {
        return amount_[amount_.size()-1];
    }
}

bool Account::negative() const {
    if (negative_.size() == 0) {
        return false;
    }
    return negative_[negative_.size() - 1];
}

std::string Account::amount_repr() const {
    if (negative()) {
        return "-" + current_amount().repr();
    }
    return current_amount().repr();
}
