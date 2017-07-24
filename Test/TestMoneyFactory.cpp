#include "TestMoneyFactory.h"

bool test_MoneyFactory_get_money() {
    MoneyFactory t("TEST", 't', true);
    Money m = t.get_money("5");
    if (m.amount() != 500) {
        std::cout << "test_MoneyFactory_get_money() failed cents test"
                  << std::endl;
        return false;
    }
    MoneyFactory t2("TEST2", 'T', false);
    Money m2 = t2.get_money("5");
    if (m2.amount() != 5) {
        std::cout << "test_MoneyFactory_get_money() failed standard test"
                  << std::endl;
        return false;
    }
    return true;
}
