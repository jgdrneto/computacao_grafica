#include <iostream>
    
std::vector<Objeto*>& LeitorObjetos::lerObjetos(std::string nomeArquivo){
    
    std::vector<Objeto*>* objetos =  new std::vector<Objeto*>();

    std::vector<std::string> lexemas = lerLexemas(lerLinhas(nomeArquivo));
    
    for(unsigned int i =0;i<lexemas.size();){
        if(lexemas[i]=="TYPE"){

            if(lexemas[i+2]=="SPHERE"){
                
                i=i+3;
                
                Esfera* esfera = new Esfera();    

                if(i<lexemas.size() && lexemas[i]=="RADIUS"){
                    esfera->r =  std::stof(lexemas[i+2].c_str());
                    i=i+3;
                }
                
                if(i<lexemas.size() && lexemas[i]=="ORIGIN"){
                    esfera->origem[Vetor3::X] = std::stof(lexemas[i+2].c_str());
                    esfera->origem[Vetor3::Y] = std::stof(lexemas[i+3].c_str());
                    esfera->origem[Vetor3::Z] = std::stof(lexemas[i+4].c_str());
                    i=i+5;
                }
                if(i<lexemas.size() && lexemas[i]=="MATERIAL"){

                    //AINDA SEM O HASH_MAP DE MATEIRAIS

                    esfera->material = *(new Material());
                    i=i+3;
                }

                objetos->push_back(esfera);
            }
        }
    }

    return *(objetos);             
}