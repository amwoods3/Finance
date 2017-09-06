#include "Account.h"

Account::Account(const std::string & name,
                 const std::string & currency,
                 char currency_symbol,
                 bool has_cents,
                 const std::string & start_amount,
                 Calendar date):
    mf_(MoneyFactory(currency, currency_symbol, has_cents)), name_(name)
{
    // Assumes that format is format that the money factory can handle
    Money start = mf_(start_amount);
    add_amount(start, "Open " + name + " account.", date);
}

Account::Account(const std::string & name, const MoneyFactory & mf,
                 const std::string & start_amount,
                 Calendar date)
    : mf_(mf), name_(name)
{
    Money start = mf_(start_amount);
    add_amount(start, "Open " + name + " account.", date);
}


void Account::add_amount(const Money & m, const std::string & description,
                         Calendar date) {
    // If we are adding an amount to a negative amount, that amount
    // gets smaller so it is a decrease if negative
    Transaction t = Transaction(description,
                                negative(),
                                m, date);


    // If negative and the amount added is less than current_amount
    // it stays negative, otherwise it is no longer negative.
    // if it was not negative, it is not negative now.
    negative_.push_back(negative() && m < current_amount());
    amount_.push_back(t.amount_after(current_amount()));
    transaction_list_.push_back(t);
    if (negative()) {
        std::cout << "We still haven't gotten out of the hole" << std::endl;
    }
}

void Account::add_amount(const std::string & m, const std::string & description,
                         Calendar date) {
    add_amount(mf_(m), description);
}

void Account::take_amount(const Money & m, const std::string & description,
                          Calendar date) {
    // If we are subtracting a negative amount from a negative number,
    // we just make it bigger thus, it is a decrease if it is not negative
    Transaction t = Transaction(description,
                                !negative(),
                                m, date);

    // If we took more than we had, we go negative.
    // If we were negative, we stay negative.
    negative_.push_back(negative() || m > current_amount());
    amount_.push_back(t.amount_after(current_amount()));
    transaction_list_.push_back(t);
}

void Account::take_amount(const std::string & m, const std::string & description,
                          Calendar date) {
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

bool Account::negative(int i) const {
    if (negative_.size() == 0) {
        return false;
    }
    if (i == -1) {
        return negative_[negative_.size() - 1];
    } else {
        return negative_[i];
    }
}

std::string Account::amount_repr(int i) const {
    if (negative(i)) {
        if (i == -1) {
            return "-" + current_amount().repr();
        } else {
            return "-" + amount_[i].repr();
        }
    }
    if (i == -1)
        return current_amount().repr();
    return amount_[i].repr();
}

void Account::show_transaction_history(int past_transactions) const {
    const int length = 100;
    std::cout << "Transactions for " << name_ << ":\n";
    std::cout << std::setfill('#') << std::setw(length);
    std::cout << "#" << std::endl;
    std::cout << std::setw(1);
    std::cout << "# Amount     # Balance            # Date ";
    std::cout << std::setfill(' ') << std::setw(14);
    std::cout << "#";
    std::cout << std::setfill(' ') << std::setw(43);
    std::cout << std::left << " Description";
    std::cout << "#" << std::endl;
    std::cout << std::setfill('#') << std::setw(length) << "#" << std::endl;
    int n = past_transactions;
    if (past_transactions <= -1) {
        n = number_transactions();
    }
    for (int i = number_transactions() - n; i < number_transactions(); ++i) {
        std::cout << "# ";
        // Print the amount of the transaction
        std::cout << std::setfill(' ') << std::setw(10) << std::left;
        std::cout << transaction_list_[i].amount_repr();
        std::cout << std::setw(1);
        std::cout << " # ";

        // Next print the amount left in the account after the transaction
        std::cout << std::setfill(' ') << std::setw(18) << std::left;
        std::cout << amount_repr(i) << " # ";
        
        // Print the date of the transaction
        std::cout << std::setfill(' ') << transaction_list_[i].date() << " # ";
        
        // Finally print the description of the transaction
        std::cout << std::setfill(' ') << std::setw(42) << std::left;
        std::cout << transaction_list_[i].description();
        std::cout << "#" << std::endl;
        
    }
    std::cout << std::setfill('#') << std::setw(length) << "#" << std::endl;
}

void Account::save() const {
    std::ofstream account_file;
    account_file.open("Accounts/" + name_ + ".account");
    account_file << "create " << name() << ' ' << mf_.currency() << ' ';
    account_file << transaction_list_[0].amount().repr() << ' ';
    Calendar date = transaction_list_[0].date();
    account_file << date.year() << '/' << date.month()+1 << '/' << date.day();
    account_file << '\n';
    for (int i = 1; i < transaction_list_.size(); ++i) {
        Transaction t = transaction_list_[i];
        account_file << name_ << ' ';
        if (t.is_decrease()) {
            account_file << "take ";
        } else {
            account_file << "add ";
        }
        account_file << t.amount().repr() << " '";
        account_file << t.description() << "' ";
        Calendar date = t.date();
        account_file << date.year() << '/' << date.month()+1 << '/' << date.day();
        account_file << '\n';
    }
    account_file.close();
}
