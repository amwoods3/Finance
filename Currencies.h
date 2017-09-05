#ifndef CURRENCIES_H
#define CURRENCIES_H

#include <string>
#include <map>

// Map currency names to symbols
typedef std::map<std::string, char> SymbolMap;
typedef std::pair<std::string, char> SymbolPair;
typedef std::map<std::string, char>::iterator SymbolIterator;

typedef std::pair<std::string, bool> StringBool;
// 

char get_symbol(const std::string & currency);
bool has_cents(const std::string & currency);
bool is_known(const std::string & currency);

// initialize the currencies
SymbolMap initialize_known_symbols();
std::map<std::string, bool> initialize_cents();
#endif
