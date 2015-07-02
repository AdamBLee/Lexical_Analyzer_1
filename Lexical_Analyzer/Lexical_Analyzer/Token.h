//
//  Token.h
//  
//
//  Created by Adam Lee on 5/18/15.
//  Copyright (c) 2015 Adam Lee. All rights reserved.
//

#ifndef __P2_Parser__Token__
#define __P2_Parser__Token__

#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;


class Token{
public:
    Token(string type, string value, int line){
        Type = type;
        Value = value;
        Line_number = line;
    }
    Token(){
        Line_number = 0;
    }
    
private:
    string Type;
    string Value;
    int Line_number;

public:
    string getType();
    string getValue();
    int getLine_number();
    string toString();
    
};

#endif /* defined(__P2_Parser__Token__) */
