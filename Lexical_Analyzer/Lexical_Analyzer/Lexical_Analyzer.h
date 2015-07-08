//
//  Lexical_Analyzer.h
//  
//
//  Created by Adam Lee on 4/30/15.
//
//

#ifndef ____Lexical_Analyzer__
#define ____Lexical_Analyzer__

#include "Token.h"
#include <sstream>
#include <stdio.h>
#include <fstream>
//#include <ofstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Lexical_Analyzer{
public:
    Lexical_Analyzer(){
        token_count = 0;
        line_count = 1;
    }
    ~Lexical_Analyzer(){}
    
    
private:
    int token_count;
    int line_count;
    std::ifstream ss;
    std::ofstream ofs;
    string filestring;
    vector<Token> token_vector;
    Token current_token;
    
   const static int PERIOD = 1;
   const static int COMMA = 2;
   const static int Q_MARK = 3;
   const static int L_PAREN = 4;
   const static int R_PAREN = 5;
   const static int COLON = 6;
   const static int COLON_DASH = 7;
   const static int COMMENT = 8;
   const static int SCHEMES = 9;
   const static int FACTS = 10;
   const static int RULES = 11;
   const static int QUERIES = 12;
   const static int E_O_F = 13;
   const static int STRING = 14;
   const static int ID = 15;
   const static int UNDEFINED = 16;
    
    
public:
    void print_filestring();
    bool open_files(string filein, string fileout);
    bool infile_to_string(ifstream &filein);
    void parse_file(string filename, string outfile);
    Token getCurrentToken();
    void increase_token_count();
    void increase_line_count();
    void print_to_outfile(string token, int linenumber, int tokCategory);
    void print_token_vector();
    vector<Token> getToken_vector();
    int getTokenCount();
    void printTokenCount();
    void checkComment( ifstream& ss);
    void checkString( ifstream& ss);
    void checkKeywordOrId( ifstream& ss);
};



#endif /* defined(____Lexical_Analyzer__) */
