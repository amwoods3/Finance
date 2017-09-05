#include "Currencies.h"


std::map<std::string, bool> hasCentsMap = initialize_cents();
SymbolMap known_symbols = initialize_known_symbols();

char get_symbol(const std::string & currency) {
    SymbolIterator si = known_symbols.find(currency);
    if (si != known_symbols.end()) {
        return si->second;
    }
    return '\0';
}


bool has_cents(const std::string & currency) {
    std::map<std::string, bool>::iterator hc = hasCentsMap.find(currency);
    if (hc != hasCentsMap.end()) {
        return hc->second;
    }
    // this is a problem
    return false;
}

bool is_known(const std::string & currency) {
    SymbolIterator si = known_symbols.find(currency);
    std::map<std::string, bool>::iterator hc = hasCentsMap.find(currency);
    return (si != known_symbols.end() && hc != hasCentsMap.end());
}


SymbolMap initialize_known_symbols() {
    SymbolMap ks;
    ks.insert(SymbolPair("USD", '$'));
    ks.insert(SymbolPair("JPY", 'Y'));
    return ks;
}

std::map<std::string, bool> initialize_cents() {
    std::map<std::string, bool> cents;
    cents.insert(StringBool("USD", true));
    cents.insert(StringBool("JPY", false));
    return cents;
}
