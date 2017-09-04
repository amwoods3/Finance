#include "Parsing.h"

namespace Parsing {
    std::vector<std::string> split(const std::string & s, char splitter) {
        std::vector<std::string> splits;
        std::string sub;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == splitter) {
                splits.push_back(sub);
                sub = "";
            } else {
                sub += s[i];
            }
        }
        if (sub.size() > 0) {
            splits.push_back(sub);
        }
        return splits;
    }

    std::vector<std::string> split_grouping(const std::string & s,
                                            char splitter) {
        std::vector<std::string> splits;
        std::string sub;
        bool in_grouping = false;
        char grouping_char = ' ';
        for (int i = 0; i < s.size(); ++i) {
            if (in_grouping) {
                // If we are grouping, we want to group everything
                // verbatim. We do not want to ingore spaces, etc.
                // This allows for long description and things to
                // follow descriptions, such as transaction dates
                if (s[i] == grouping_char) {
                    grouping_char = ' ';
                    splits.push_back(sub);
                    sub = "";
                    in_grouping = false;
                } else {
                    // copy verbatim
                    sub += s[i];
                }
            } else {
                if (s[i] == splitter && sub.size() > 0) {
                    splits.push_back(sub);
                    sub = "";
                } else if (s[i] == '\'' || s[i] == '"') {
                    // We may be looking at a description or such
                    // we have to start grouping
                    in_grouping = true;
                    grouping_char = s[i];
                } else {
                    sub += s[i];
                }
            }
        }
        if (in_grouping) {
            // we have a problem,
            // TODO: Handle this error
        }
        if (sub.size() > 0) {
            splits.push_back(sub);
        }
        return splits;
    }
};
