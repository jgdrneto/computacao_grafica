#ifndef _UTILIDADES_
#define _UTILIDADES_

//================================================================

//Métodos uteis

//================================================================

#include <string>
#include <vector>

#include <iostream>

#include <sstream>
#include <fstream>
#include <iterator>

std::vector<std::string> lerLinhas(std::string nomeArquivo){

    std::ifstream arquivo;

    std::string linha;
    std::vector<std::string> linhas;

    arquivo.open(nomeArquivo);

    if (arquivo.is_open()){
        
        while ( getline (arquivo,linha) ) {

            //add line in vector of lines

            if(!linha.empty()){

                linhas.push_back(linha);

            }
        }
        arquivo.close();
    }
    
    return linhas;
}

std::vector<std::string> split(const std::string& str) {
    std::stringstream ss(str);
    return {std::istream_iterator<std::string>{ss}, std::istream_iterator<std::string>{}};
}

std::vector<std::string> lerLexemas(std::vector<std::string> linhas){

    std::vector<std::string> lexemas;

    for(std::string linha : linhas){
        std::vector<std::string> ls = split(linha);

        //Add lexeme in return of function
        for(std::string lex : ls){
            lexemas.push_back(lex);
        }
    }

    return lexemas;
}

#endif