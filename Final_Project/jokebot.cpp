//THIS PROGRAM USES STD::MAP
//C++ program to respond with jokes about a topic the user wants to hear about 
//If the joke is not in the map, consult reddit for a new joke and update map.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "joke_map.h"
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//Declare Functions
void parse_input(string r, Jokemap, set<string> &); 	//Parses the input of the user
int is_keyword(string w, set<string> &); 							//Ignores stop words
int need_new_joke(string w, Jokemap); 				//Determines if there is already a relevant joke in the map
void load_ignore_words(set<string> &); 								//Loads list of stop words from a file (words that are ignored like 'the')
void load_joke_map(Jokemap);							//Loads jokes already stored in map from joke.txt
string search_reddit(string);										//Calls python and searches reddit for a joke based on keyword input
void search_jokes(string, Jokemap); 					//This function searches the map for jokes based on keyword
void print_joke(string);											//Prints joke in proper format 

//Main Function

int main(int argc, char** argv) {
	
	//Define and fill map and set for jokes and stop words 
	Jokemap joke_map;
	set<string> ignore_words;
	
	load_ignore_words(ignore_words);
	load_joke_map(joke_map);
	
    if (argc > 1) { // there is an input file; probably doing testing
        cout << "YO! LET ME KNOW IF YOU WANT TO HEAR A JOKE. TYPE 'x' TO EXIT." << endl;
        // cout << "There is an input file" << endl;
        ifstream ifile(argv[1]);
        string line;
        while (getline(ifile, line)) {
            if (line[0] == 'x' ) return 0;
            // cout << "line: " << line << endl;
            //Parse user input
            parse_input(line, joke_map, ignore_words);
        }
        
    }
    else { // No input file has been passed so just read from cin
        //Interact with user
        cout << "YO! LET ME KNOW IF YOU WANT TO HEAR A JOKE. TYPE 'x' TO EXIT." << endl;
        while (true) {
            string response;
            getline (cin , response);
            
            if (response[0] == 'x' ) return 0;
            
            //Parse user input
            parse_input(response, joke_map, ignore_words);
        }
    }
    
    
    return 0;
}


//Define Functions
void parse_input(string r, Jokemap m, set<string> & iw) {
	set<string> keywords;
	set<string> get_words;
	
	stringstream linestream(r);
	
	//I think this line goes one more loop through than it should 
	while (linestream){
		string temp;
		getline(linestream, temp, ' '); //Break apart input by words
		
		if (!isalpha(temp[0]) ) break;
		
		//If the word actually indicates a type of joke process the word 
		if (is_keyword(temp, iw)) {
			if (need_new_joke(temp, m)) {
			//do stuff with python to get a new joke and put it in the datastructure otherwise there is already a joke
				string joke;
				joke = search_reddit(temp);
				
				//cout << "INSERTING JOKE TO MAP: " << joke << endl;
				m.insert(temp,joke); //Add new keyword, joke pair to the map
				
				ofstream jokefile;
				jokefile.open("joke.txt", ios::app);
				jokefile << temp << "\t" << joke;
				jokefile.close();
			}
			
			else {
				search_jokes(temp, m);
			}			
			keywords.insert(temp);	//Put the new keyword in the set 
		}
	}
	
	//This will loop through all the keywords and print out all the jokes related to them 
	//PROBABLY SHOULD BE UPDATED LATER
	/*for (auto it = keywords.begin(); it != keywords.end(); it++) {
		search_jokes( *it , m);
	}*/
}


//Checks words against the ignore words set 
int is_keyword(string w, set<string> & iw) {
	
	if(iw.find(w) != iw.end()) return 0;
	
	return 1;
}


//Determines if joke for topic is already in the map 
int need_new_joke(string w, Jokemap m){
	
	//Call joke map function 
	return m.need_joke(w);
}


//Loads set of words to ignore 
void load_ignore_words(set<string> & iw){
	fstream ignorefile ("ignore.txt");
	string line;
	
	//Read in jokes that are already in the local store of jokes 
	if (ignorefile.is_open()) {
		while (getline (ignorefile, line) ) {
			stringstream linestream(line);
			string temp;
			
			//Split joke into first line and punch line 
			getline(linestream, temp, '\n');
			
			//Insert joke into joke map 
			iw.insert(temp);
		}
		
		ignorefile.close();
	}
	
	//If file could not be opened, output appropriate error message 
	else {
		cout << "ERROR READING IN FILE OF WORDS TO IGNORE. PLEASE MAKE SURE ignore.txt IS NOT CORRUPTED." << endl;
	}	
	
}


//Loads map of keywords and relevant jokes 
void load_joke_map(Jokemap jm){
	fstream jokefile ("joke.txt");
	string line;
	
	//Read in jokes that are already in the local store of jokes 
	if (jokefile.is_open()) {
		while (getline (jokefile, line) ) {
			stringstream linestream(line);
			string joke1, joke2;
			
			//Split joke into first line and punch line 
			getline(linestream, joke1, '\t');
			getline(linestream, joke2 );
			
			//Insert joke into joke map 
			jm.insert(joke1, joke2);
			
		}
		
		jokefile.close();
	}
	
	//If file could not be opened, output appropriate error message 
	else {
		cout << "ERROR READING IN JOKE FILE. PLEASE MAKE SURE joke.txt IS NOT CORRUPTED." << endl;
	}	
	
}

//This function runs the python script to search reddit
//CHANGE TO STRING LATER 
string search_reddit(string word){
	string joke_response;
	string line;
	
	system(("./run_python.sh " + word).c_str());

	//RETURN WHATEVER PYTHON GETS BACK AS A STRING and UPDATE JOKE RESPONSE 
	ifstream myfile;
	myfile.open("temp.txt");
	while (getline(myfile,line)) {
		joke_response += line;
		joke_response += '\t';
	}
	joke_response += '\n';
	myfile.close();
	remove("temp.txt");
	
	print_joke(joke_response);

	return joke_response;
}

void search_jokes(string word, Jokemap m) {
	//Find keyword in map using joke_map function
	m.search_jokes(word);
}

void print_joke(string word) {
	stringstream linestream(word);
	string joke1, joke2;
	
	//Split joke into first line and punch line 
	getline(linestream, joke1, '\t');
	getline(linestream, joke2 );
	
	//Print out the joke for that keyword 
	cout << joke1 << endl;
	cout << joke2 << endl;
}
