// unordered.cpp: Unordered Map

#include "map.h"

#include <algorithm>

// Methods --------------------------------------------------------------------

void            UnorderedMap::insert(const std::string &key, const std::string &value) {
        if (entries.find(key) != entries.end()) {
            auto it = entries.find(key);
            it->second = value;
        }
        
        else {
             entries.insert({key,value});
        }
}

const Entry     UnorderedMap::search(const std::string &key) {
    if (entries.find(key) != entries.end()) {
       std::pair <std::string, std::string> temp_entry = std::make_pair( key , entries[key] );

        return temp_entry;
    }
    return NONE;
}

void            UnorderedMap::dump(std::ostream &os, DumpFlag flag) {
    for (auto it = entries.begin(); it != entries.end(); it++) {
        switch (flag) {
            case DUMP_KEY:          os << it->first  << std::endl; break;
            case DUMP_VALUE:        os << it->second << std::endl; break;
            case DUMP_KEY_VALUE:    os << it->first  << "\t" << it->second << std::endl; break;
            case DUMP_VALUE_KEY:    os << it->second << "\t" << it->first  << std::endl; break;
        }
    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
