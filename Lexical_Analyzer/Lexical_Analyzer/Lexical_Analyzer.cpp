//
//  Lexical_Analyzer.cpp
//  
//
//  Created by Adam Lee on 4/30/15.
//
//

#include "Lexical_Analyzer.h"
#include <iostream>
#include <fstream>
#include <string>


string add_to_word(string &word , char c){
    stringstream sss;
    string s;
    sss << c;
    s = sss.str();
    word = word + s;
    return word;
}


void Lexical_Analyzer::print_filestring(){
    cout << filestring << "--" << endl;
}

void Lexical_Analyzer::print_to_outfile(string token, int linenumber,  int tokCategory){
//    char c = token[0];
    token = token.c_str();
    Token t;
    
    switch (tokCategory) {
        case 1:
            t = Token("PERIOD", token, linenumber);
            token_vector.push_back(t);
            increase_token_count();
            break;
        case 2:
            t = Token("COMMA", token, linenumber);
            token_vector.push_back(t);
            increase_token_count();
            break;
        case 3:
            t = Token("Q_MARK", token, linenumber);
            token_vector.push_back(t);
            increase_token_count();
            break;
        case 4:
            t = Token("LEFT_PAREN", token, linenumber);
            token_vector.push_back(t);
            increase_token_count();
            break;
        case 5:
            t = Token("RIGHT_PAREN", token, linenumber);
            token_vector.push_back(t);
            increase_token_count();
            break;
        case 6:
            t = Token("COLON", token, linenumber);
            token_vector.push_back(t);
            increase_token_count();
            break;
        case 7:
            t = Token("COLON_DASH", token, linenumber);
            token_vector.push_back(t);
            increase_token_count();
            break;
        case 8:
            t = Token("COMMENT", token, linenumber);
            //  token_vector.push_back(t);
            increase_token_count();
            break;
        case 9:
            t = Token("SCHEMES", token, linenumber);
            token_vector.push_back(t);
            increase_token_count();
            break;
        case 10:
            t = Token("FACTS", token, linenumber);
            token_vector.push_back(t);
            increase_token_count();
            break;
        case 11:
            t = Token("RULES", token, linenumber);
            token_vector.push_back(t);
            increase_token_count();
            break;
        case 12:
            t = Token("QUERIES", token, linenumber);
            token_vector.push_back(t);
            increase_token_count();
            break;
        case 13:
            t = Token("EOF", "", linenumber);
            token_vector.push_back(t);
            increase_token_count();
            break;
        case 14:
            t = Token("STRING", token, linenumber);
            token_vector.push_back(t);
            increase_token_count();
            break;
        case 15:
            t = Token("ID", token, linenumber);
            token_vector.push_back(t);
            increase_token_count();
            break;
        case 16:
            t = Token("UNDEFINED", token, linenumber);
            token_vector.push_back(t);
            increase_token_count();
            break;
        default:
            break;
    }
    
//    int case1 = 1;  period
//    int case2 = 2;    comma
//    int case3 = 3;    Q_mark
//    int case4 = 4;    L Paren
//    int case5 = 5;    R Paren
//    int case6 = 6;    Colon
//    int case7 = 7;    Colon-dash
//    int case8 = 8;    comment
//    int case9 = 9;    Schemes
//    int case10 = 10;  Facts
//    int case11 = 11;  Rules
//    int case12 = 12;  Queries
//    int case13 = 13;  EOF
//    int case14 = 14;  String
//    int case15 = 15;  ID
//    int case16 = 16;  Undefined
   
}

void Lexical_Analyzer::parse_file(string filename, string outfile){
    string str;
    stringstream sss;
    string s;
    ss.open(filename.c_str());
    ofs.open(outfile.c_str());
    string word;
    int line = 0;
    char c;
    
    bool endblock = false;
    stringstream word_stream;
    
    while(ss.get(c)){
        endblock = false;
        word = "";
        word_stream.str(string());
        word_stream.clear();
        bool i_d = false;
        switch (c) {
            case '\t':
                break;
            case '.':
                print_to_outfile(".", line_count, PERIOD);
                break;
            case ',':
                print_to_outfile(",", line_count, COMMA);
                break;                          
            case '?':
                print_to_outfile("?", line_count, Q_MARK);
                break;                         
            case '(':
                print_to_outfile("(", line_count, L_PAREN);
                break;                         
            case ')':
                print_to_outfile(")", line_count, R_PAREN);
                break;                         
            case ':':
                if(ss.peek() == '-'){
                    print_to_outfile(":-", line_count, COLON_DASH);
                    ss.get(c);
                }
                else{
                   // ss.put(c);
                    print_to_outfile(":", line_count,  COLON);
                }                                   
                break;
/*Comments*/case '#':
                checkComment(ss);
                break;
/*Strings*/case '\'':
                checkString(ss);
//                line = line_count;
//                word = add_to_word(word, c);
//                endblock = false;
//                while(ss.get(c)){
//                    if(c == '\n'){
//                        increase_line_count();
//                    }
//                    if(ss.tellg() == -1){
//                        word = add_to_word(word, c);
//                        print_to_outfile(word, line, UNDEFINED); //CHECK THIS
//                            //TODO
//                        break;
//                    }
//                    if(c == '\'' && ss.peek() == '\''){
//                        word = add_to_word(word, c);
//                        ss.get(c);
//                        word = add_to_word(word, c);
//                    }
//                    else if(c == '\'' && ss.peek() != '\''){
//                        word = add_to_word(word, c);
//                        print_to_outfile(word, line, STRING);
//                        endblock = true;
//                        break;
//                    }
//                    else{
//                        word = add_to_word(word, c);
//                    }
//                }
//                if(endblock == false){
//                    
//                    print_to_outfile(word, line, UNDEFINED); //CHECK THIS
//                    //TODO
//                }
                break;
/*newline*/ case '\n':
                increase_line_count();
                break;
/*Schemes*/ case 'S':
                i_d = false;
                line = line_count;
                if(ss.peek() == 'c'){
                    word_stream << c;
                    ss.get(c);
                    while(isalpha(c) || isdigit(c)){
                        if(isdigit(c)){
                            i_d = true;
                        }
                        word_stream << c;
                        ss.get(c);
                        if(!isalpha(c) && !isdigit(c)){
                            ss.putback(c);
                        }
                        if(c == '\n'){
                    //        increase_line_count();   // take out????
                            break;
                        }
                    }
                    word_stream >> word;
                    if(word == "Schemes"){
                        print_to_outfile(word, line, SCHEMES);
                    }
                    else{
                        print_to_outfile(word, line, ID);
                    }
                }
                else{
                    string test_id;
                    while(!isspace(c)) {
                        word_stream << c;
                        ss.get(c);
                        if(!isalpha(c) && !isdigit(c)){
                            ss.putback(c);
                            break;
                        }
                        if (ss.eof()){
                            break;
                        }
                    }
                    word_stream >> word;
                    print_to_outfile(word, line, ID);
                }
                break;
 /*Facts*/  case 'F':
                i_d = false;
                line = line_count;
                if(ss.peek() == 'a'){
                    word_stream << c;
                    ss.get(c);
                    while(isalpha(c) || isdigit(c)){
                        if(isdigit(c)){
                            i_d = true;
                        }
                        word_stream << c;
                        ss.get(c);
                        if(!isalpha(c) && !isdigit(c)){
                            ss.putback(c);
                        }
                        if(c == '\n'){
                        //    increase_line_count();
                            break;
                        }
                    }
                    word_stream >> word;
                    if(word == "Facts"){
                        print_to_outfile(word, line, FACTS);
                    }
                    else{
                        print_to_outfile(word, line, ID);
                    }
                }
                else{
                     string test_id;
                     while(!isspace(c)) {
                         word_stream << c; 
                         ss.get(c);
                         if(!isalpha(c) && !isdigit(c)){
                             ss.putback(c);
                             break;
                         }
                         if (ss.eof()){ 
                             break; 
                         } 
                     } 
                     word_stream >> word; 
                     print_to_outfile(word, line, ID);
                }
                break;
/*Rules*/  case 'R':
                i_d = false;
                line = line_count;
                if(ss.peek() == 'u'){
                    word_stream << c;
                    ss.get(c);
                    while(isalpha(c) || isdigit(c)){
                        if(isdigit(c)){
                            i_d = true;
                        }
                        word_stream << c;
                        ss.get(c);
                        if(!isalpha(c) && !isdigit(c)){
                            ss.putback(c);
                        }
                        if(c == '\n'){
                        //    increase_line_count();
                            break;
                        }
                    }
                    word_stream >> word;
                    if(word == "Rules"){
                        print_to_outfile(word, line, RULES);
                    }
                    else{
                        print_to_outfile(word, line, ID);
                    }
                }
                else{
                    string test_id;
                    while(!isspace(c)) {
                        word_stream << c;
                        ss.get(c);
                        if(!isalpha(c) && !isdigit(c)){
                            ss.putback(c);
                            break;
                        }
                        if (ss.eof()){
                            break;
                        }
                    }
                    word_stream >> word;
                    print_to_outfile(word, line, ID);
                    
                }
                break;
/*Queries*/case 'Q':
                i_d = false;
                line = line_count;
                if(ss.peek() == 'u'){
                    word_stream << c;
                    ss.get(c);
                    while(isalpha(c) || isdigit(c)){
                        if(isdigit(c)){
                            i_d = true;
                        }
                        word_stream << c;
                        ss.get(c);
                        if(!isalpha(c) && !isdigit(c)){
                            ss.putback(c);
                        }
                        if(c == '\n'){
                   //         increase_line_count();
                            break;
                        }
                    }
                    word_stream >> word;
                    if(word == "Queries"){
                        print_to_outfile(word, line, QUERIES);
                        word_stream.str(string());
                    }
                    else{
                        print_to_outfile(word, line, ID);
                        word_stream.str(string());
                    }
                }
                else{
                    string test_id;
                    while(!isspace(c)) {
                        word_stream << c;
                        ss.get(c);
                        if(!isalpha(c) && !isdigit(c)){
                            ss.putback(c);
                            break;
                        }
                        if (ss.eof()){
                            break;
                        }
                    }
                    word_stream >> word;
                    print_to_outfile(word, line, ID);
                }
                break;
            case ' ':
                break;
            default:
                if (isalpha(c)){
                   // word_stream(c);
                   // string cstr = &c;
                    word_stream << c;
                    line = line_count;
                    ss.get(c);
                    if(!isalpha(c) && !isdigit(c)){
                        ss.putback(c);
                    }
                    while(isalpha(c) || isdigit(c)){
                        word_stream << c;
                        ss.get(c);
                        if(!isalpha(c) && !isdigit(c)){
                            ss.putback(c);
                        }
                        if(c == '\n'){
                      //      increase_line_count();
                            break;
                        }
                    }
                    word_stream >> word;
                    print_to_outfile(word, line, ID);
                    
                }
                else{
                    stringstream s;
                    s << c;
                    print_to_outfile(s.str(), line_count, UNDEFINED);
                }
                break;
        }
    }
    print_to_outfile("eof", line_count, E_O_F);
    print_token_vector();
    printTokenCount();
    ss.close();
    ofs.close();
}

void Lexical_Analyzer::increase_token_count(){
    token_count++;
}
void Lexical_Analyzer::increase_line_count(){
    line_count++;
}
Token Lexical_Analyzer::getCurrentToken(){
    return current_token;
}

vector<Token> Lexical_Analyzer::getToken_vector(){
    return token_vector;
}

void Lexical_Analyzer::print_token_vector(){
    for(int i = 0; i < token_vector.size(); i++){
        cout << token_vector[i].toString() << endl;
        ofs << token_vector[i].toString() << endl;
        ofs << i << endl;
        
    }
}

int Lexical_Analyzer::getTokenCount(){
    return token_count;
}

void Lexical_Analyzer::printTokenCount(){
    ofs << "Total TOkens = " << token_count << endl;
   cout << "Total Tokens = " << token_count << endl;
}


void Lexical_Analyzer::checkComment( ifstream& ss){
    stringstream word_stream;
    bool endblock = false;
    char c;
    string word = "";
    endblock = false;
    int line = line_count;
   
    word = add_to_word(word, c);
   
    if(ss.peek() == '|'){
        ss.get(c);
        word = add_to_word(word, c);
        while(ss.get(c)){
            if(c == '\n' ){
                increase_line_count();
            }
            if(c == '|'){
                word = add_to_word(word, c);
                if(ss.peek() == '#'){
                    ss.get(c);
                    word = add_to_word(word, c);
                    endblock = true;
                    print_to_outfile(word, line, COMMENT);
                    break;
                }
                else{
                    ss.get(c);
                    word = add_to_word(word, c);
                }
            }
            word = add_to_word(word, c);
        }
    }
    else{
        while(ss.get(c)){
            if(c == '\n'){
                increase_line_count();
                print_to_outfile(word, line, COMMENT);
                endblock = true;
                break;
            }
            word = add_to_word(word, c);
        }
    }
    if(endblock == false){
        print_to_outfile(word, line, UNDEFINED);
    }
    
    return;
}


void Lexical_Analyzer::checkString(ifstream& ss){
   
    int line = line_count;
    
    char c;
   
    string word = add_to_word(word, c);
   
    bool endblock = false;
   
    while(ss.get(c)){
        if(c == '\n'){
            increase_line_count();
        }
        if(ss.tellg() == -1){
            word = add_to_word(word, c);
            print_to_outfile(word, line, UNDEFINED); //CHECK THIS
            //TODO
            break;
        }
        if(c == '\'' && ss.peek() == '\''){
            word = add_to_word(word, c);
            ss.get(c);
            word = add_to_word(word, c);
        }
        else if(c == '\'' && ss.peek() != '\''){
            word = add_to_word(word, c);
            print_to_outfile(word, line, STRING);
            endblock = true;
            break;
        }
        else{
            word = add_to_word(word, c);
        }
    }
    if(endblock == false){
        
        print_to_outfile(word, line, UNDEFINED); //CHECK THIS
        //TODO
    }
    return;
    
    
}

void Lexical_Analyzer::checkKeywordOrId(ifstream& ss){
   
}
