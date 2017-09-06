// open.cpp: Open Addressing Map
// Author: Margaret Thomann

#include "map.h"

#include <stdexcept>

using namespace std;
// Methods --------------------------------------------------------------------

// Insert:  Given a key and value, this adds this key-value pair using open addressing with linear probing.
//          Open Addressing - All entry records are stored in the bucket array itself
//          Linear Probing  - Searches the table for the closest free location and inserts the value there
void            OpenMap::insert(const std::string &key, const std::string &value) {
    elementCount++;                                 // Adding an element, so increase the count
    // Check for Resizing potential
    if (elementCount/tableSize > loadFactor){       // If the table size should be increased
        resize(tableSize*2);                        // Call resize with double the table size
    }
    
    size_t bucket = locate(key);                    // Call locate to check the bucket to insert
    table[bucket].first = key;                      // Update the Entry with the new key
    table[bucket].second = value;                   // Update the Entry with the new value
    // std::cout << "Bucket: " << bucket << " Element Key: " <<  key << "  Element Value: " << value << std::endl;

}

// Search:  Given a key, this returns the Entry containing the key and the associated value. If the key is not in the map, then the sentinel NONE is returned to indicate failure.
const Entry     OpenMap::search(const std::string &key) {
    // cout << "Searching for: " << key << endl;
    size_t hashedBucket = hfunc(key) % tableSize;       // Compute the hashed bucket
    for (int i = 0; i < tableSize; i++){                // Loop through the table
        // cout << "************************************" << endl;
        // cout << "I:  " << i << endl;
        // cout << "Checking:  " << table[hashedBucket].first << " at Bucket: " << hashedBucket << endl;
        if (table[hashedBucket].first == key){                     // If the key is in the map
            // cout << "Found:  " << table[hashedBucket].first << endl;
            return table[hashedBucket];                            // Return the pair (Entry)
        }
        // cout << "Before increasing: " << hashedBucket << endl;
        hashedBucket++;                                 // Increase the hashed bucket index
        // cout << "After increasing: " << hashedBucket << endl;
        hashedBucket %= tableSize;                      // Rehash by modding with the tableSize
        // cout << "After modding: " << hashedBucket << endl;
        // cout << "Table Size: " << tableSize << endl;
        // cout << "************************************" << endl;
    }
    return NONE;                                    // NONE is returned since the key isn't in the map
}

// Dump:  Given an output stream os, this writes all the key-value pairs in the map to os. The output is formatted based on the flag argument which indicates whether to print out the key, value, key and value, or value and key. For the latter two options, the two components should be separated by the tab character.
void            OpenMap::dump(std::ostream &os, DumpFlag flag) {
    for (int i = 0; i < tableSize; i++) {
        switch (flag) {
            case DUMP_KEY:          os << table[i].first  << std::endl; break;
            case DUMP_VALUE:        os << table[i].second << std::endl; break;
            case DUMP_KEY_VALUE:    os << table[i].first  << "\t" << table[i].second << std::endl; break;
            case DUMP_VALUE_KEY:    os << table[i].second << "\t" << table[i].first  << std::endl; break;
        }
    }
}

// Locate:  Given a key, this function returns the bucket that either contains this key or is the next empty bucket.  If locate fails to find an empty bucket, resize should be called next.
size_t          OpenMap::locate(const std::string &key) {
    size_t hashedBucket = hfunc(key) % tableSize;       // Compute the hashed bucket
    for (int i = 0; i < tableSize; i++){                // Loop through the entire table, where i represents a bucket
        if (table[hashedBucket] == NONE || table[hashedBucket].first == key){ // If there is an empty bucket or a matching key
            return hashedBucket;                        // Return the bucket
        }
        hashedBucket++;                                 // Increase the hashed bucket index
        hashedBucket %= tableSize;                      // Rehash by modding with the tableSize
    }
    resize(tableSize*2);                                // Nothing has been returned so resize the table
    return locate(key);                                 // Call locate again until an empty bucket or the bucket that contains the key is returned
}

// Resize:  Given a new_size, this method allocates a new table of the given new_size, copies all the entries from the old table to this new table, and then deallocates the old table.
void            OpenMap::resize(const size_t new_size) {
    Entry * newTable = new Entry[new_size];             // Initialize a new table
    size_t hashedValue;                                 // Initialize a hashed value
    
    for (int i = 0; i < tableSize; i++){                // Iterate through the whole table
        hashedValue = hfunc(table[i].first) % new_size; // Compute a new hashed value
        newTable[hashedValue] = make_pair(table[i].first, table[i].second); // Add the pair to the new table
    }
    
    delete[] table;                                     // Delete the old table
    table = newTable;                                   // Set the private table variable equal to the new table
    tableSize = new_size;                               // Set the private table size variable equal to the new one
}


// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
