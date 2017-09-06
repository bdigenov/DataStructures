// uscheme.cpp

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <unistd.h>

using namespace std;

// Globals ---------------------------------------------------------------------

bool BATCH = false;
bool DEBUG = false;

// Structures ------------------------------------------------------------------

struct Node {
    Node(string value, Node *left=nullptr, Node *right=nullptr) {this->value = value; this->left = left; this->right = right;}
    ~Node();

    string value;
    Node * left;
    Node * right;

    friend ostream &operator<<(ostream &os, const Node &n);
};


Node::~Node(){
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
}

ostream &operator<<(ostream &os, const Node &n) {
    
    if (n.right != nullptr && n.left != nullptr) {
        os << *n.right;
        os << n.value << " ";
        os << *n.left;
    }
    
    else {
        os << n.value << " ";
    }
    
    return os;
}

// Parser COMPLETE ----------------------------------------------------------------------

string parse_token(istream &s) {
        string token;
         
         //Skip Whitespace 
        while (s.peek() == ' ') {
						
            s.ignore();
        }         

         //Handle Parenthises 
        if (s.peek() == '(' || s.peek() == ')' || s.peek() == '+' || s.peek() == '-' || s.peek() == '/' || s.peek() == '*') {
            token = s.get();
        } 

         //Handle numbers 
        else if (isdigit(s.peek())) {
            
            //Read in the entire number 
            while(isdigit(s.peek())) {
                token += s.get();
            }
        } 
    return token;		
}

Node *parse_expression(istream &s) {
    
    string token = parse_token(s);
    
    Node *left = nullptr;
    Node *right = nullptr;
    
    if ( token == ")" || token == "") {
        return nullptr;
    }
    // (+ (+ 1 2) (+ 3 4))
    if ( token == "(" ) {
        token = parse_token(s);
        left = parse_expression(s);
        if (left != nullptr) {
            right = parse_expression(s);
        }
        if (right != nullptr) {
            parse_token(s);
        }
    }
    return new Node( token, left, right); 
}

// Interpreter -----------------------------------------------------------------


void evaluate_r(const Node *n, stack<int> &s) {
    
    if (n->left != nullptr && n->right != nullptr) {
        evaluate_r (n->right, s);
        evaluate_r (n->left, s );

        //Initialize Variables
		string opA, opB;
 		string nodeValue = n->value;
		int result = 0, nodeValInt;
		
        
        //If value is an arithmetic operator 
		if (n->value == "-" || n->value == "+" || n->value == "*" || n->value == "/"){

            int intOpA = 0, intOpB = 0;
            
            //Get two int values from the top of the stack 
            if(!s.empty()) {
                intOpA = s.top();
                s.pop();
            }
            
            if(!s.empty()) {
                intOpB = s.top();
                s.pop();
            }

         
			if (n->value == "-"){
				result = intOpA - intOpB;
			}
			else if (n->value == "+"){
				result = intOpA + intOpB;
			}
			else if (n->value == "/"){
				result = intOpA / intOpB;
			}
			else if (n->value == "*"){
				result = intOpB * intOpA;
			}
			s.push(result);
		} 
             
		else if (isdigit(nodeValue[0])){
		    nodeValInt = atoi(nodeValue.c_str());          
			s.push(nodeValInt);
		}	
    }
    
    else {

        //Initialize Variables
		string opA, opB;
 		string nodeValue = n->value;
		int result = 0, nodeValInt;
		
        
        //If value is an arithmetic operator 
		if (n->value == "-" || n->value == "+" || n->value == "*" || n->value == "/"){

            int intOpA = 0, intOpB = 0;
            
            //Get two int values from the top of the stack 
            if(!s.empty()) {
                intOpA = s.top();
                s.pop();
            }
            
            if(!s.empty()) {
                intOpB = s.top();
                s.pop();
            }
         
			if (n->value == "-"){
				result = intOpA - intOpB;
			}
			else if (n->value == "+"){
				result = intOpA + intOpB;
			}
			else if (n->value == "/"){
				result = intOpA / intOpB;
			}
			else if (n->value == "*"){
				result = intOpB * intOpA;
			}
			s.push(result);
		} 
             
		else if (isdigit(nodeValue[0])){
		    nodeValInt = atoi(nodeValue.c_str());         
			s.push(nodeValInt);
		}	
    } 
}

int evaluate(const Node *n) {
    stack<int> s;
    
    evaluate_r(n, s);
    
    if (!s.empty()) return s.top();
    else return 0;
}

// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {
    string line;
    int c;  

    while ((c = getopt(argc, argv, "bdh")) != -1) {
        switch (c) {
            case 'b': BATCH = true; break;
            case 'd': DEBUG = true; break;
            default:
                cerr << "usage: " << argv[0] << endl;
                cerr << "    -b Batch mode (disable prompt)"   << endl;
                cerr << "    -d Debug mode (display messages)" << endl;
                return 1;
        }
    }

    while (!cin.eof()) {
        if (!BATCH) {
            cout << ">>> ";
            cout.flush();
        }

        if (!getline(cin, line)) {
            break;
        }

        if (DEBUG) { cout << "LINE: " << line << endl; }

        stringstream s(line);

        Node *n = parse_expression(s);
        if (DEBUG) { cout << "TREE: " << *n << endl; }

        cout << evaluate(n) << endl;
        
        delete n;
    }

    return 0;
}

