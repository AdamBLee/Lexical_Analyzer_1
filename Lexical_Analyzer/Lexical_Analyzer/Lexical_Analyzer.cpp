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

void Lexical_Analyzer::print_to_outfile(string token, int linenumber, bool i_d, bool undefined, int tokCategory){
    char c = token[0];
    token = token.c_str();
    
    switch (b) {
        case <#constant#>:
            <#statements#>
            break;
            
        default:
            break;
    }
    
    int case1 = 1;
    int case2 = 2;
    int case3 = 3;
    int case4 = 4;
    int case5 = 5;
    int case6 = 6;
    int case7 = 7;
    int case8 = 8;
    int case9 = 9;
    int case10 = 10;
    int case11 = 11;
    int case12 = 12;
    int case13 = 13;
    int case14 = 14;
    int case15 = 15;
    int case16 = 16;
    
    
    if(token == "."){
        Token t = Token("PERIOD", token, linenumber);
        token_vector.push_back(t);
        increase_token_count();
    }
    else if(token == ","){
        Token t = Token("COMMA", token, linenumber);
        token_vector.push_back(t);
        increase_token_count();                                   
    }
    else if(token == "?"){
        Token t = Token("Q_MARK", token, linenumber);
        token_vector.push_back(t);
        increase_token_count();                                    
    }
    else if(token == "("){
        Token t = Token("LEFT_PAREN", token, linenumber);
        token_vector.push_back(t);
        increase_token_count();                                         
    }
    else if(token == ")"){
        Token t = Token("RIGHT_PAREN", token, linenumber);
        token_vector.push_back(t);
        increase_token_count();                                          
    }
    else if(token == ":"){
        Token t = Token("COLON", token, linenumber);
        token_vector.push_back(t);
        increase_token_count();                                   
    }
    else if(token == ":-"){
        Token t = Token("COLON_DASH", token, linenumber);
        token_vector.push_back(t);
        increase_token_count();                                        
    }
    else if(c == '#' && undefined == false){
        Token t = Token("COMMENT", token, linenumber);
      //  token_vector.push_back(t);
        increase_token_count();                                     
    }
    else if(token == "Schemes"){
        Token t = Token("SCHEMES", token, linenumber);
        token_vector.push_back(t);
        increase_token_count();                                     
    }
    else if(token == "Facts"){
        Token t = Token("FACTS", token, linenumber);
        token_vector.push_back(t);
        increase_token_count();                                   
    }
    else if(token == "Rules"){
        Token t = Token("RULES", token, linenumber);
        token_vector.push_back(t);
        increase_token_count();                                   
    }
    else if(token == "Queries"){
        Token t = Token("QUERIES", token, linenumber);
        token_vector.push_back(t);
        increase_token_count();                                     
    }
    else if(token == "eof"){ //THIS IS A PROBLEM
        Token t = Token("EOF", "", linenumber);
        token_vector.push_back(t);
        increase_token_count();
    }
    else if(c == '\'' && undefined == false){
        Token t = Token("STRING", token, linenumber);
        token_vector.push_back(t);
        increase_token_count();                                    
    }
    else if(i_d){
        Token t = Token("ID", token, linenumber);
        token_vector.push_back(t);
        increase_token_count();                                
    }
    else if(undefined){
        Token t = Token("UNDEFINED", token, linenumber);
        token_vector.push_back(t);
        increase_token_count();                                       
    }
    //cout << endl;
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
                print_to_outfile(".", line_count, false, false);
                break;
            case ',':
                print_to_outfile(",", line_count, false, false);
                break;                          
            case '?':
                print_to_outfile("?", line_count, false, false);
                break;                         
            case '(':
                print_to_outfile("(", line_count, false, false);
                break;                         
            case ')':
                print_to_outfile(")", line_count, false, false);
                break;                         
            case ':':  //SOMETHING HERE
               // ss.get(c);
               // if(c == '-'){
                if(ss.peek() == '-'){
                    print_to_outfile(":-", line_count, false, false);
                    ss.get(c);
                }
                else{
                   // ss.put(c);
                    print_to_outfile(":", line_count, false, false);
                }                                   
                break;
/*Comments*/case '#':
                endblock = false;
                line = line_count;
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
                                print_to_outfile(word, line, false, false);
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
                            print_to_outfile(word, line, false, false);
                            endblock = true;
                            break;
                        }
                        word = add_to_word(word, c);
                    }
                }
                if(endblock == false){
                    print_to_outfile(word, line, false, true);
                }
                break;
/*Strings*/case '\'':
                line = line_count;
                word = add_to_word(word, c);
                endblock = false;
                while(ss.get(c)){
                    if(c == '\n'){
                        increase_line_count();
                    }
                    if(ss.tellg() == -1){
                        word = add_to_word(word, c);
                        print_to_outfile(word, line, false, true);
                        break;
                    }
                    if(c == '\'' && ss.peek() == '\''){
                        word = add_to_word(word, c);
                        ss.get(c);
                        word = add_to_word(word, c);
                    }
                    else if(c == '\'' && ss.peek() != '\''){
                        word = add_to_word(word, c);
                        print_to_outfile(word, line, false, false);
                        endblock = true;
                        break;
                    }
                    else{
                        word = add_to_word(word, c);
                    }
                }
                if(endblock == false){
                    
                    print_to_outfile(word, line, false, true);
                }
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
                        print_to_outfile(word, line, false, false);
                    }
                    else{
                        print_to_outfile(word, line, true, false);
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
                    print_to_outfile(word, line, true, false);
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
                        print_to_outfile(word, line, false, false);
                    }
                    else{
                        print_to_outfile(word, line, true, false);
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
                     print_to_outfile(word, line, true, false); 
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
                        print_to_outfile(word, line, false, false);
                    }
                    else{
                        print_to_outfile(word, line, true, false);
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
                    print_to_outfile(word, line, true, false);
                    
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
                        print_to_outfile(word, line, false, false);
                        word_stream.str(string());
                    }
                    else{
                        print_to_outfile(word, line, true, false);
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
                    print_to_outfile(word, line, true, false);
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
                    print_to_outfile(word, line, true, false);
                    
                }
                else{
                    stringstream s;
                    s << c;
                    print_to_outfile(s.str(), line_count, false, true);
                }
                break;
        }
    }
    print_to_outfile("eof", line_count, false, false);
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
        
        ofs << token_vector[i].toString();
    }
}

int Lexical_Analyzer::getTokenCount(){
    return token_count;
}

void Lexical_Analyzer::printTokenCount(){
   cout << "Total Tokens = " << token_count << endl;
}