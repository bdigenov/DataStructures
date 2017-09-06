// rbtree.cpp: RBTree Map

#include "map.h"
#include <map>
#include <algorithm>

// Methods --------------------------------------------------------------------

void            RBTreeMap::insert(const std::string &key, const std::string &value) {
    // std::cout << "insert has been called" << std::endl;
    std::map<std::string, std::string>::iterator it = entries.find(key);    // Iterate through
    if (it != entries.end()){                                               // Has found the key
        // std::cout << "has found the element" << std::endl;
        it->second = value;                                                 // Update the value
    }
    else {                                                                  // Hasn't found it
        // std::cout << "Hasn't been found" << std::endl;

        entries.insert( std::pair<std::string,std::string>(key,value) );    // Insert the new entry into the map
    }
}

const Entry     RBTreeMap::search(const std::string &key) {
    std::map<std::string,std::string>::iterator it;             // Instantiate the iterator
    it = entries.find(key);                                     // Call the find function
    if (it == entries.end()){                                   // The find function has returned the end; so it hasn't been found
        // std::cout << "Hasn't been found" << std::endl;
        return NONE;                        // Return none because it hasn't been found
    }
    else {                                      // The find function has found the element
        // std::cout << "has found the element" << std::endl;
        return *it;
    }
}

void            RBTreeMap::dump(std::ostream &os, DumpFlag flag) {
    for(auto it = entries.cbegin(); it != entries.cend(); ++it) {
        if (flag == DUMP_KEY){
            os << it->first << std::endl;
        }
        else if (flag == DUMP_VALUE){
            os << it->second << std::endl;
        }
        else if (flag == DUMP_KEY_VALUE){
            os << it->first << "\t" << it->second << std::endl;
        }
        else if (flag == DUMP_VALUE_KEY){
            os << it->second << "\t" << it->first << std::endl;
        }
    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
