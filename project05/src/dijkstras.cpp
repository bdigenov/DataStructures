// dijsktras.cpp
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include <vector>

using namespace std;

void string_to_int_pair (int & a, int & b, string l);

// Main Execution

int main(int argc, char *argv[]) {
    string line;
    
    //Read in each map 
    while(getline(cin,line)){
        cout << "IN BIG WHILE LOOP" << endl;
        map<char,int> tile_map;
        vector< vector<char> > board;
        
        int num_inputs;
        num_inputs = atoi(line.c_str());
        cout << num_inputs << endl;
        //Iterate through all the tile types and add them to the map
        for (int s = 0; s < num_inputs; s++) {
            getline(cin,line);
            cout << "IN FOR LOOP"
            //Insert tyle type and value pair to map 
            tile_map.insert(pair<char,int>(line[0],line[2]));
        }
        
        getline(cin,line);
        int int_rows, int_cols;
        string_to_int_pair (int_rows, int_cols, line);
        
        //Read into board vector 
        for (int i = 0; i < int_rows; i++) {
            int line_spot = 0;
            getline(cin,line);
            for (int j = 0; j < int_cols; j++) {
                board[i][j] = line[line_spot];
                line_spot += 2;
            }
        }  
        
        pair<int,int> start;
        pair<int,int> end;
        int start1, start2, end1, end2;
        
        getline(cin, line);
        string_to_int_pair(start1, start2, line);
        start = make_pair(start1,start2);
        getline(cin, line);
        string_to_int_pair(end1, end2, line);
        end = make_pair(end1, end2);
        
        //Perform Dijkstras algorithm 
    }
    
    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:

void string_to_int_pair (int & a, int & b, string l) {
        string rows, columns;
        size_t s = 0;
        int int_rows, int_cols;
        
        while (l[s] != ' ') {
            rows += l[s];
            s++;
        }
        s++;
        while (s < l.length()) {
            columns += l[s];
            s++;
        }
        
        int_rows = atoi(rows.c_str());
        int_cols = atoi(columns.c_str());
        
        a = int_rows;
        b = int_cols;
}