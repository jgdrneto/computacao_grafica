//================================================================

//Useful methods

//================================================================

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>

std::vector<std::string> readLines(std::string file_name){

    std::ifstream file;

    std::string line;
    std::vector<std::string> lines;

    file.open(file_name);

    if (file.is_open()){
        
        while ( getline (file,line) ) {

            //add line in vector of lines

            if(!line.empty()){

                lines.push_back(line);

            }
        }
        file.close();
    }
    
    return lines;
}

std::vector<std::string> split(const std::string& str) {
    std::stringstream ss(str);
    return {std::istream_iterator<std::string>{ss}, std::istream_iterator<std::string>{}};
}

std::vector<std::string> readLexemes(std::vector<std::string> lines){

    std::vector<std::string> lexemes;

    for(std::string line : lines){
        std::vector<std::string> ls = split(line);

        //Add lexeme in return of function
        for(std::string lex : ls){
            lexemes.push_back(lex);
        }
    }

    return lexemes;
}
