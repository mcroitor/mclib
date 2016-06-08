#ifndef STRMANIP_H
#define STRMANIP_H
#include <string>

/*
 * string manipulation
 */

namespace mc{
    // string modification actions. usefull for Levenshtein (or any other) distance
    std::string _D(std::string /* str */, size_t /* index */); // delete symbol at index from str
    std::string _I(std::string /* str */, size_t /* index */, char /* chr */); // insert symbol chr at index from str
    std::string _R(std::string /* str */, size_t /* index */, char /* chr */); // replace symbol chr at index from str
    
    size_t distLevenshtein(std::string, std::string);
}

#endif /* STRMANIP_H */

