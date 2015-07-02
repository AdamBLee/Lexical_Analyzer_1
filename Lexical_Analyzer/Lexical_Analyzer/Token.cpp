//
//  Token.cpp
//  P2_Parser
//
//  Created by Adam Lee on 5/18/15.
//  Copyright (c) 2015 Adam Lee. All rights reserved.
//

#include "Token.h"

string Token::getType(){
    return Type;
}

string Token::getValue(){
    return Value;
}


int Token::getLine_number(){
    return Line_number;
}


string Token::toString(){
    stringstream ss;
    ss << Line_number;
    string num = ss.str();
    return "(" + getType() + ",\"" + getValue() + "\"," + num + ")";
}