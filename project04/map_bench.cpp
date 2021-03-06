// map_bench.cpp

#include "map.h"

#include <cassert>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <string>

#include <strings.h>
#include <unistd.h>

// Type Definitions ------------------------------------------------------------

typedef std::chrono::high_resolution_clock  Clock;

// Utility functions -----------------------------------------------------------

void usage(int status) {
    std::cout << "usage: map_bench" << std::endl
              << "    -b BACKEND    Which Map backend (unsorted, sorted, bst, rbtree, treap, unordered, chained, open)" << std::endl
              << "    -n NITEMS     Number of items to benchmark" << std::endl
              << "    -p PADLENGTH  Amount to pad the keys with leading 0's" << std::endl;

    exit(status);
}

void parse_command_line_options(int argc, char *argv[], Map *&map, int &nitems, int &padlength, double &lfactor) {
    int c;

    while ((c = getopt(argc, argv, "hb:n:p:")) != -1) {
        switch (c) {
            case 'b':
                if (strcasecmp(optarg, "unsorted") == 0) {
                    map = new UnsortedMap();
                } else if (strcasecmp(optarg, "sorted") == 0) {
                    map = new SortedMap();
                } else if (strcasecmp(optarg, "bst") == 0) {
                    map = new BSTMap();
                } else if (strcasecmp(optarg, "rbtree") == 0) {
                    map = new RBTreeMap();
                } else if (strcasecmp(optarg, "treap") == 0) {
                    map = new TreapMap();
                } else if (strcasecmp(optarg, "unordered") == 0) {
                    map = new UnorderedMap();
                } else if (strncasecmp(optarg, "chained", 7) == 0) {
                    // lfactor = X.X;
                    map = new ChainedMap();
                } else if (strncasecmp(optarg, "open-X.X", 4) == 0) {
                    std::string openArg(optarg);
                    int stringLength = openArg.length();
                    // std::cout << "String Length: " << stringLength << std::endl;
                    if (stringLength == 8){
                        std::string lfactorS = openArg.substr(5, 8);
                        // std::cout << lfactorS << std::endl;
                        std::string::size_type sz;     // alias of size_t
                        lfactor = std::stod (lfactorS,&sz);
                        std::cout << "Lfactor: " << lfactor << std::endl;
                        map = new OpenMap(nitems, lfactor);
                    }
                    else if (stringLength != 4 || stringLength != 8){
                        usage(1);
                    }
                    else{
                        map = new OpenMap(nitems, .9);
                    }
                    
                } else {
                    usage(1);
                }
                break;
            case 'n':
                nitems = atoi(optarg);
                break;
            case 'p':
                padlength = atoi(optarg);
                break;
            case 'h':
                usage(0);
                break;
            default:
                usage(1);
                break;
        }
    }

    if (map == nullptr) {
    	map = new UnsortedMap();
    }
}

std::string int_to_key(int i, size_t padlength) {
    std::string k = std::to_string(i);
    if (padlength > k.size())
        k.insert(k.begin(), padlength - k.size(), '0');
    return k;
}

// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {
    Map *map       = nullptr;
    int  nitems    = 1;
    int  padlength = 1;
    double lfactor = 0.9;
    parse_command_line_options(argc, argv, map, nitems, padlength, lfactor);

    // Insert
    auto insert_start = Clock::now();
    for (int i = 0; i < nitems; i++) {
        std::string k = int_to_key(i, padlength);
        std::string v = k;
        map->insert(k, v);
    }
    auto insert_stop  = Clock::now();
    auto insert_diff  = insert_stop - insert_start;
    
    std::cout << "NItems: " << nitems << "\t" << "Lfactor: " << lfactor << std::endl;
    std::cout << "Insert: " << std::setprecision(5) << std::chrono::duration<double>(insert_diff).count() << " s" << std::endl;

    // Search
    auto search_start = Clock::now();
    for (int i = 0; i < nitems; i++) {
        std::string k = int_to_key(i, padlength);
        map->search(k);
    }
    auto search_stop  = Clock::now();
    auto search_diff  = search_stop - search_start;

    std::cout << "Search: " << std::setprecision(5) << std::chrono::duration<double>(search_diff).count() << " s" << std::endl;
    
    std::cout << std::endl;

    delete map;
    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
