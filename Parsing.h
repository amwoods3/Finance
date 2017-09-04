#ifndef PARSING_H
#define PARSING_H

#include <vector>
#include <string>

namespace Parsing {
    std::vector<std::string> split(const std::string & to_split, char splitter=' ');

    // split grouping allows for splitting, and grouping based on
    // either single or double quotes
    std::vector<std::string> split_grouping(const std::string & to_split,
                                   char splitter=' ');
};

#endif

