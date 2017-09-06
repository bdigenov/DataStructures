// unsorted.cpp: Unsorted Map

#include "map.h"
#include <vector>

// Methods --------------------------------------------------------------------

// INSERT:  Given a key and value, this adds this key-value pair if it is not in the map already. If the key already exists, then the value for the existing std::pair is updated to the new value.
void            UnsortedMap::insert(const std::string &key, const std::string &value) {
    if (entries.size() == 0){                       // If there are no entries yet
        Entry firstEntry(key, value);               // Create the first entry
        entries.push_back(firstEntry);              // Push it to the vector
    }
    else{
        for (size_t i = 0; i < entries.size(); i++){   // Search the entries
            if (entries[i].first == key){           // Key is in the map
                entries[i].second = value;          // Update the value
                return;                             // Exit because it has been updated
            }
        }
        Entry newEntry(key, value);         // Assign key & value
        entries.push_back(newEntry);        // Add it to the map
    }
}

// SEARCH:  Given a key, this returns the Entry containing the key and the associated value. If the key is not in the map, then the sentinel NONE is returned to indicate failure.
const Entry     UnsortedMap::search(const std::string &key) {
    for (size_t i = 0; i < entries.size(); i++){
        // First: word  Second: number
        if (entries[i].first == key){       // Key is in the map
            return entries[i];              // Return that entry
        }
    }
    return NONE;
}

// DUMP:  Given an output stream os, this writes all the key-value pairs in the map to os. The output is formatted based on the flag argument which indicates whether to print out the key, value, key and value, or value and key. For the latter two options, the two components should be separated by the tab character.
void            UnsortedMap::dump(std::ostream &os, DumpFlag flag) {
    // First: word (key)  Second: number (value)
    // std::cout << "In beginning of dump" << std::endl;
    for (size_t i = 0; i < entries.size(); i++){
        if (flag == DUMP_KEY){
            os << entries[i].first << std::endl;
        }
        else if (flag == DUMP_VALUE){
            os << entries[i].second << std::endl;
        }
        else if (flag == DUMP_KEY_VALUE){
            os << entries[i].first << "\t" << entries[i].second << std::endl;
        }
        else if (flag == DUMP_VALUE_KEY){
            os << entries[i].second << "\t" << entries[i].first << std::endl;
        }
    }
}

UnsortedMap::~UnsortedMap(){
        entries.clear();
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
