// sorted.cpp: Sorted Map

#include "map.h"
#include <vector>

#include <algorithm>

// Type Definitions ------------------------------------------------------------

typedef std::vector<Entry>::iterator IT;

// Prototypes ------------------------------------------------------------------

const Entry     binary_search(const IT &start, const IT &end, const std::string &key);

// Methods ---------------------------------------------------------------------

// COMPARE:  Used as the third parameter for sort to determine which key is larger
bool compare_key(Entry keyA, Entry keyB){
    return (keyA.first < keyB.first);
}

// INSERT:  Given a key and value, this adds this key-value pair in sorted order if it is not in the map already. If the key already exists, then the value for the existing std::pair is updated to the new value.
void            SortedMap::insert(const std::string &key, const std::string &value) {
    if (search(key) == NONE){                                       // If the value is not in there
        //std::cout << "Brand new value" << std::endl;
		// std::cout << "\t key: " << key << "\t val: " << value << std::endl;
        Entry newEntry(key, value);                                 // Assign key & value
        entries.push_back(newEntry);                                // Add it to the map
        // std::sort(entries.begin(), entries.end(), compare_key);     // Sort the map
    }
    else{
		// std::cout << "we need a new incoming" << std::endl;
        for (size_t i = 0; i < entries.size(); i++){                   // Iterate through the entries
           if (entries[i].first == key){                // Call compare to check which key is greater
               // std::cout << "New incoming" << std::endl;
			   // std::cout << entries[i].second << std::endl;
			   entries[i].second = value;                          // Set the entry to the updated value
			   // std::cout << entries[i].second << std::endl;
			}
        }
    }
}
// SEARCH:  Given a key, this returns the Entry containing the key and the associated value. If the key is not in the map, then the sentinel NONE is returned to indicate failure.
const Entry     SortedMap::search(const std::string &key) {
    return binary_search(entries.begin(), entries.end(), key);
}
// DUMP:  Given an output stream os, this writes all the key-value pairs in the map to os. The output is formatted based on the flag argument which indicates whether to print out the key, value, key and value, or value and key. For the latter two options, the two components should be separated by the tab character.
void            SortedMap::dump(std::ostream &os, DumpFlag flag) {
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

// Internal Functions ----------------------------------------------------------

bool compare(Entry element, const std::string &key){
    return (element.first < key);
}

// BINARY SEARCH:  Speeds up the search operation and returns the actual item itself
const Entry   binary_search(const IT &start, const IT &end, const std::string &target) {
    //std::cout << "Binary search is called" << std::endl;
    // IT item = std::lower_bound(start, end, target, compare);
    // if (item != end && !(compare(*item, target))){
        // return *item;
    // }
    // else {
        // return NONE;
    // }
	
	for(IT item = start; item != end; item++){
		if(item->first == target){
			return *item;
		}
	}
	return NONE;
	
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
