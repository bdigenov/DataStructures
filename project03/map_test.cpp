// map_test.cpp: test map backends

#include "map.h"

#include <cassert>
#include <iostream>
#include <string>

#include <strings.h>
#include <unistd.h>

using namespace std;

// Constants -------------------------------------------------------------------

const int N = 100;

// Utility functions -----------------------------------------------------------

void usage(int status) {
    std::cout << "usage: map_test" << std::endl
              << "    -b BACKEND    Which Map backend (unsorted, sorted, bst, rbtree, treap)" << std::endl;

    exit(status);
}

void parse_command_line_options(int argc, char *argv[], Map *&map) {
    int c;

    while ((c = getopt(argc, argv, "hb:")) != -1) {
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
                } else {
                    usage(1);
                }
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

// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {
    Map *map = nullptr;

    parse_command_line_options(argc, argv, map);

    // Insert 1 - N
    for (int i = 0; i < N; i++) {
	std::string s = std::to_string(i);
    	map->insert(s, s);
    }

    // Search 1 - N
    for (int i = 0; i < N; i++) {
	std::string s = std::to_string(i);
        auto result = map->search(s);
        // std::cout << "Result: " << result.second << std::endl;
	assert(map->search(s) != NONE);
    }

    // Insert 1 - N (double)
    for (int i = 0; i < N; i++) {
	std::string k = std::to_string(i);
	std::string v = std::to_string(i*2);
    	map->insert(k, v);
    }

    // Search 1 - N (double)
    // std::cout << "Search 1 - N (double)" << std::endl;
    for (int i = 0; i < N; i++) {
	std::string k = std::to_string(i);
	std::string v = std::to_string(i*2);
	auto result   = map->search(k);
        // std::cout << "Result: " << result.second << std::endl;
        // std::cout << "V: " << v << std::endl;
        // std::cout << "K: " << k << std::endl;
	assert(result != NONE && result.second == v);
    }

    // Search N - 2*N (should fail)
    for (int i = N; i < 2*N; i++) {
	std::string s = std::to_string(i);
        auto result = map->search(s);
        // std::cout << "Result: " << result.second << std::endl;
	assert(map->search(s) == NONE);
    }
    
    //delete map;
    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
