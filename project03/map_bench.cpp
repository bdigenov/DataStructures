// map_bench: run tests on maps 

#include "map.h"

#include <cassert>
#include <chrono>
#include <strings.h>
#include <unistd.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Constants-------------------------------------------------------------------

const int N = 100;

// Globals---------------------------------------------------------------------
string map_type;
int number_of_items;
int padlength;


//Function Definitions----------------------------------------------------------
string     int_to_key(int num, size_t plength);

// Utility functions -----------------------------------------------------------

void usage(int status) {
    std::cout << "usage: map_bench -h" << std::endl;
    std::cout << "    -b BACKEND    Which Map backend (unsorted, sorted, bst, rbtree, treap)" << std::endl;
    std::cout << "    -n NITEMS     Number of items to benchmark" << std::endl;
    std::cout << "    -p PADLENGTH  Amount to pad the keys with leading 0's" << std::endl;

    exit(status);
}

void parse_command_line_options(int argc, char *argv[], Map *&map, int &number_of_items, int &padlength) {
    int c;

    while ((c = getopt(argc, argv, "hb:n:p:")) != -1) {
        switch (c) {
            case 'b':
                if (strcasecmp(optarg, "unsorted") == 0) {
                    map_type = "UNSORTED";
                    map = new UnsortedMap();
                } else if (strcasecmp(optarg, "sorted") == 0) {
                    map_type = "SORTED  ";
                    map = new SortedMap();
                } else if (strcasecmp(optarg, "bst") == 0) {
                    map_type = "  BST   ";
                    map = new BSTMap();
                } else if (strcasecmp(optarg, "rbtree") == 0) {
                    map_type = " RBTREE ";
                    map = new RBTreeMap();
                } else if (strcasecmp(optarg, "treap") == 0) {
                    map_type = "  TREAP ";
                    map = new TreapMap();
                } else {
                    usage(1);
                }
                break;
            case 'n':
                number_of_items = atoi(optarg);
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

// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {
    setprecision(10);
    
    Map *map = nullptr;
    map_type = "UNSORTED";
    number_of_items = 1000;
    padlength = 1;

     cout << " | Backend     | NITEMS    | PADLENGTH | Insert Time   | Search Time   |" << endl;
     cout << " |-------------|-----------|-----------|---------------|---------------|" << endl;
    //Evaluate arguments 
    parse_command_line_options(argc, argv, map, number_of_items, padlength);
    
        
        //record start time for insert 
        auto insert_start = std::chrono::high_resolution_clock::now();
        
        for (int i=0; i < number_of_items; i++) {
            map->insert(int_to_key(i, padlength), int_to_key(i, padlength));
        }
        
        //Record end time for insert 
        auto insert_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff_insert = insert_end-insert_start;
        
        //Record initial time for search 
        auto search_start = std::chrono::high_resolution_clock::now();
        for (int i=0; i < number_of_items; i++) {
    
            // Search
            map->search(int_to_key(i, padlength));
        } 
            // record end time for search 
            auto search_end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff_search = search_end-search_start;
          
    
    cout << " |   " << map_type << "  |  " << number_of_items << "       |    " << padlength << "      |  " << diff_insert.count() << "   |    " << diff_search.count() << " |" << endl;

}


string     int_to_key(int num, size_t plength){
        
        std::string temp_key = std::to_string(num);
        std::string full_temp_key;
        
        for (size_t i = 0; i < plength; i++ ) {
            full_temp_key += '0';
        }
        
        full_temp_key += temp_key;
        
        return full_temp_key;
}

