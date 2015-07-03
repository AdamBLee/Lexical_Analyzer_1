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
    
public:
    void print_filestring();
    bool open_files(string filein, string fileout);
    bool infile_to_string(ifstream &filein);
    void parse_file(string filename, string outfile);
    Token getCurrentToken();
    void increase_token_count();
    void increase_line_count();
    void print_to_outfile(string token, int linenumber, bool i_d, bool undefined, int tokCategory);
    void print_token_vector();
    vector<Token> getToken_vector();
    int getTokenCount();
    void printTokenCount();
};



#endif /* defined(____Lexical_Analyzer__) */
