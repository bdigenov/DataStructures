// map.h

#pragma once

// Includes --------------------------------------------------------------------

#include <iostream>
#include <functional>
#include <map>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>

// Type definitions ------------------------------------------------------------

typedef enum {
    DUMP_KEY,
    DUMP_VALUE,
    DUMP_KEY_VALUE,
    DUMP_VALUE_KEY,
} DumpFlag;

typedef std::pair<std::string, std::string> Entry;
typedef std::hash<std::string>              StringHasher;

// Constants -------------------------------------------------------------------

extern const Entry  NONE;
extern const double DEFAULT_LOAD_FACTOR;
extern const size_t DEFAULT_TABLE_SIZE;

// Structures ------------------------------------------------------------------

struct Node {
    Entry entry;
    int   priority;		
    Node *left;			
    Node *right;		

    ~Node() {
        delete left;
        delete right;
    }
};


// Classes ---------------------------------------------------------------------


class Map {
public:
    virtual void            insert(const std::string &key, const std::string &value) {}
    virtual const Entry     search(const std::string &key) { return NONE; }
    virtual void            dump(std::ostream &os, DumpFlag flag) {}
    virtual                ~Map() {}
};

class UnsortedMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
            //~UnsortedMap() {}
private:
            std::vector<Entry>    entries;
};

class SortedMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
            std::vector<Entry>    entries;
};

class BSTMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
                           ~BSTMap() { delete root; }
private:
            Node    *root = nullptr;
};

class RBTreeMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
            std::map<std::string, std::string> entries;
};

class TreapMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
                           ~TreapMap() { delete root; }
private:
            Node    *root = nullptr;
};

class UnorderedMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
            std::unordered_map<std::string, std::string> entries;
};

class ChainedMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
			ChainedMap(int size, double factor) {
				tsize = size;
				values = new std::map<std::string, std::string>[tsize];
				loadfactor = factor;
			}
			ChainedMap(){
				tsize = DEFAULT_TABLE_SIZE;
				values = new std::map<std::string, std::string>[tsize];
				loadfactor = DEFAULT_LOAD_FACTOR;
			}
			~ChainedMap() { delete[] values; }
			
			
private:
            void            resize(const size_t new_size);
			int tsize;
			std::map<std::string, std::string> *values;
			
			double loadfactor;
			int count = 0;
			StringHasher hfunc;
			
};

class OpenMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
    
            // Constructor
            OpenMap(){
                tableSize = DEFAULT_TABLE_SIZE;
                table = new Entry[tableSize];
                loadFactor = DEFAULT_LOAD_FACTOR;
            }
    
            // Default Constructor
            OpenMap(int size, double factor) {
                tableSize = size;
                table = new Entry[tableSize];
                loadFactor = factor;
            }
    
            // Destructor
            ~OpenMap() {
                delete[] table;
            }

private:
            size_t          locate(const std::string &key);
            void            resize(const size_t new_size);
            // Array of Entries as the table
            Entry * table;
            // Load Factor & Table Size
            double loadFactor;
            int tableSize;
            int elementCount = 0;
            // Type Definition for String Hash Function
            StringHasher    hfunc;
};

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
