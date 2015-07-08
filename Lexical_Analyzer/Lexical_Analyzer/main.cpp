//
//  main.cpp
//  Lexical_Analyzer
//
//

#include <iostream>
#include "Lexical_Analyzer.h"

int main(int argc, const char * argv[]) {
   
    if(argc != 3){
        std::cerr << "USAGE: argv[0]: Program Executable, argv[1]: INPUT_FILE   argv[2]: OUTPUT_FILE" << std::endl;
        return 1;
    }

	Lexical_Analyzer LA;
    LA.parse_file(argv[1], argv[2]);
//    LA.print_token_vector();
//    LA.printTokenCount();
 
    return 0;
}
