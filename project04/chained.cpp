// chained.cpp: Separate Chaining Map

#include "map.h"

#include <stdexcept>

// Methods --------------------------------------------------------------------

using namespace std;

void            ChainedMap::insert(const std::string &key, const std::string &value) {
	count++;
	if(count/tsize > loadfactor){
		resize(tsize*2);
		
	}
	
	size_t hval = hfunc(key) % tsize;
	auto it = values[hval].find(key);
	if(it != values[hval].end()){
		it->second = value;
	} else {
		values[hval].insert(make_pair(key, value));
	}
	
}

const Entry     ChainedMap::search(const std::string &key) {
	size_t hval = hfunc(key) % tsize;
	
	auto it = values[hval].find(key);
	if(it != values[hval].end()){
		return *it;
	} 
	
    return NONE;
}

void            ChainedMap::dump(std::ostream &os, DumpFlag flag) {
	for(int i=0; i<tsize; i++){
		//cout << "[ " << i;				
		for(auto it = values[i].begin(); it != values[i].end(); ++it){
			//cout << " | " << it->first << " : " << it->second;
			cout << it->first << " : " << it->second << endl;
		}
		//cout << " ]" << endl;
	}
}

void            ChainedMap::resize(const size_t new_size) {
	
	map<string, string> *newvals = new map<string, string>[new_size];
	size_t hval;

	for(int i=0; i<tsize; i++){
		for(auto it = values[i].begin(); it != values[i].end(); ++it){
			
			hval = hfunc(it->first) % new_size;
			newvals[hval].insert(make_pair(it->first, it->second));

		}
	}
	
	delete[] values;
	values = newvals;
	
	tsize = new_size;
	
	
	
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
