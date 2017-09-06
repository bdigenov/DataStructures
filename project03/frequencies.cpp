// freqencies.cpp

#include "map.h"

#include <iostream>
#include <string>
#include <strings.h>
#include <unistd.h>
#include <algorithm>


using namespace std;

// Main execution --------------------------------------------------------------

//GLOBAL DUMPFLAG

DumpFlag dumpflag = DUMP_VALUE_KEY;

void usage(int status) {
    std::cout << "usage: frequencies" << std::endl
              << "    -b BACKEND    Which Map backend (unsorted, sorted, bst, rbtree, treap)" << std::endl
			  << "	  -d DUMPFLAG   Which dump flag (key, value, key_value, value_key)" << endl;
    exit(status);
}

void parse_command_line_options(int argc, char *argv[], Map *&map) {
    int c;

    while ((c = getopt(argc, argv, "hb:d:")) != -1) {
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
			case 'd':
				if(strcasecmp(optarg, "key") == 0){
					dumpflag = DUMP_KEY;
				} else if (strcasecmp(optarg, "value")){
					dumpflag = DUMP_VALUE;
				} else if(strcasecmp(optarg, "key_value")){
					dumpflag = DUMP_KEY_VALUE;
				} else if(strcasecmp(optarg, "value_key")){
					dumpflag = DUMP_VALUE_KEY;
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

void normalize(string &s){
	int length = s.length();
	for(int i=0; i<length; i++){
		if(ispunct(s[i]) || s[i] == ' '){
			s.erase(i, 1);
			i--;
		}
	}
	length = s.length();
	for(int i=0; i<length; i++){
		s[i] = tolower(s[i]);
	}
	
}


int main(int argc, char *argv[]) {
	Map *map = nullptr;
	
	string s;
	int value;
	string val;
	
	parse_command_line_options(argc, argv, map);
	
	while(cin >> s){
		//cout << s << endl;
		normalize(s);
		//cout << s << endl;
		
		Entry e;
		e = map->search(s);
		
		if(e == NONE){
			map->insert(s, "1");
		} else {
			value = stoi(e.second) + 1;
			val = to_string(value);
			map->insert(s, val);
		}
		
		
		
	}
	map->dump(std::cout, dumpflag);
	
    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:




















