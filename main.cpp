#include <iostream>

#include "Calendar.h"

int main() {

    std::cout << day_count(0, 2004) << " == 31" << std::endl;
    std::cout << day_count(1, 1600) << " == 29" << std::endl;
    std::cout << day_count(1, 1601) << " == 28" << std::endl;
    std::cout << day_count(2, 2004) << " == 31" << std::endl;
    std::cout << day_count(3, 2004) << " == 30" << std::endl;
    std::cout << day_count(4, 2004) << " == 31" << std::endl;
    std::cout << day_count(5, 2004) << " == 30" << std::endl;
    std::cout << day_count(6, 2004) << " == 31" << std::endl;
    std::cout << day_count(7, 2003) << " == 31" << std::endl;
    std::cout << day_count(8, 2003) << " == 30" << std::endl;
    std::cout << day_count(9, 2004) << " == 31" << std::endl;
    std::cout << day_count(10, 2005) << " == 30" << std::endl;
    std::cout << day_count(11, 2004) << " == 31" << std::endl;
    return 0;
}
