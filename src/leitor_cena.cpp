#include <iostream>
    
Cena& LeitorCena::lerCena(std::string nomeArquivo){
    
    Cena* cena = new Cena();

    std::vector<std::string> lexemas = lerLexemas(lerLinhas(nomeArquivo));
    
    for(unsigned int i =0;i<lexemas.size();i++){
        if(lexemas[i]=="NAME"){
            cena->nome = lexemas[i+2];
        }else{
            if(lexemas[i]=="TYPE" ){
                cena->tipo = lexemas[i+2];
            }else{
                if(lexemas[i]=="CODIFICATION"){
                    cena->codificacao = lexemas[i+2];
                }else{
                    if(lexemas[i]=="WIDTH"){
                        cena->largura = std::stoi(lexemas[i+2],nullptr,0);
                    }else{
                        if(lexemas[i]=="HEIGHT"){
                            cena->altura = std::stoi(lexemas[i+2],nullptr,0);
                        }else{
                            if(lexemas[i]=="UPPER_LEFT"){
                                cena->superiorEsquerdo[CorRGB::R] = std::stof(lexemas[i+2].c_str())/255;
                                cena->superiorEsquerdo[CorRGB::G] = std::stof(lexemas[i+3].c_str())/255;
                                cena->superiorEsquerdo[CorRGB::B] = std::stof(lexemas[i+4].c_str())/255;
                            }else{
                                if(lexemas[i]=="UPPER_RIGHT"){
                                    cena->superiorDireito[CorRGB::R] = std::stof(lexemas[i+2].c_str())/255;
                                    cena->superiorDireito[CorRGB::G] = std::stof(lexemas[i+3].c_str())/255;
                                    cena->superiorDireito[CorRGB::B] = std::stof(lexemas[i+4].c_str())/255;
                                }else{
                                    if(lexemas[i]=="LOWER_RIGHT"){
                                        cena->inferiorDireito[CorRGB::R] = std::stof(lexemas[i+2].c_str())/255;
                                        cena->inferiorDireito[CorRGB::G] = std::stof(lexemas[i+3].c_str())/255;
                                        cena->inferiorDireito[CorRGB::B] = std::stof(lexemas[i+4].c_str())/255;
                                    }else{
                                        if(lexemas[i]=="LOWER_LEFT"){
                                            cena->inferiorEsquerdo[CorRGB::R] = std::stof(lexemas[i+2].c_str())/255;
                                            cena->inferiorEsquerdo[CorRGB::G] = std::stof(lexemas[i+3].c_str())/255;
                                            cena->inferiorEsquerdo[CorRGB::B] = std::stof(lexemas[i+4].c_str())/255;
                                        }else{
                                            if(lexemas[i]=="FOREGROUND_DEPTH"){
                                                cena->primeiroPlano[CorRGB::R] = std::stof(lexemas[i+2].c_str())/255;
                                                cena->primeiroPlano[CorRGB::G] = std::stof(lexemas[i+3].c_str())/255;
                                                cena->primeiroPlano[CorRGB::B] = std::stof(lexemas[i+4].c_str())/255;
                                            }else{
                                                if(lexemas[i]=="BACKGROUND_DEPTH"){
                                                    cena->ultimoPlano[CorRGB::R] = std::stof(lexemas[i+2].c_str())/255;
                                                    cena->ultimoPlano[CorRGB::G] = std::stof(lexemas[i+3].c_str())/255;
                                                    cena->ultimoPlano[CorRGB::B] = std::stof(lexemas[i+4].c_str())/255;
                                                }else{
                                                    if(lexemas[i]=="MAX_DEPHT"){
                                                        cena->profundidadeMaxima = std::stof(lexemas[i+2].c_str());
                                                    }else{
                                                        if(lexemas[i]=="SAMPLES"){
                                                            cena->amostras = std::stoi(lexemas[i+2].c_str(), nullptr,0);
                                                        }else{
                                                            if(lexemas[i]=="RAY_DEPTH"){
                                                                cena->profundidadeRaio = std::stoi(lexemas[i+2].c_str(), nullptr,0);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return *(cena);
}
