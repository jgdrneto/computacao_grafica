#include <iostream>
    
    LeitorCena::LeitorCena(std::string nomeArquivo){
        
        std::vector<std::string> lexemas = lerLexemas(lerLinhas(nomeArquivo));
    
        for(unsigned int i =0;i<lexemas.size();i++){
            if(lexemas[i]=="NAME"){
                this->cena.nome = lexemas[i+2];
            }else{
                if(lexemas[i]=="TYPE" ){
                    this->cena.tipo = lexemas[i+2];
                }else{
                    if(lexemas[i]=="CODIFICATION"){
                        this->cena.codificacao = lexemas[i+2];
                    }else{
                        if(lexemas[i]=="WIDTH"){
                            this->cena.largura = std::stoi(lexemas[i+2],nullptr,0);
                        }else{
                            if(lexemas[i]=="HEIGHT"){
                                this->cena.altura = std::stoi(lexemas[i+2],nullptr,0);
                            }else{
                                if(lexemas[i]=="UPPER_LEFT"){
                                    this->cena.superiorEsquerdo[CorRGB::R] = std::stof(lexemas[i+2].c_str())/255;
                                    this->cena.superiorEsquerdo[CorRGB::G] = std::stof(lexemas[i+3].c_str())/255;
                                    this->cena.superiorEsquerdo[CorRGB::B] = std::stof(lexemas[i+4].c_str())/255;
                                }else{
                                    if(lexemas[i]=="UPPER_RIGHT"){
                                        this->cena.superiorDireito[CorRGB::R] = std::stof(lexemas[i+2].c_str())/255;
                                        this->cena.superiorDireito[CorRGB::G] = std::stof(lexemas[i+3].c_str())/255;
                                        this->cena.superiorDireito[CorRGB::B] = std::stof(lexemas[i+4].c_str())/255;
                                    }else{
                                        if(lexemas[i]=="LOWER_RIGHT"){
                                            this->cena.inferiorDireito[CorRGB::R] = std::stof(lexemas[i+2].c_str())/255;
                                            this->cena.inferiorDireito[CorRGB::G] = std::stof(lexemas[i+3].c_str())/255;
                                            this->cena.inferiorDireito[CorRGB::B] = std::stof(lexemas[i+4].c_str())/255;
                                        }else{
                                            if(lexemas[i]=="LOWER_LEFT"){
                                                this->cena.inferiorEsquerdo[CorRGB::R] = std::stof(lexemas[i+2].c_str())/255;
                                                this->cena.inferiorEsquerdo[CorRGB::G] = std::stof(lexemas[i+3].c_str())/255;
                                                this->cena.inferiorEsquerdo[CorRGB::B] = std::stof(lexemas[i+4].c_str())/255;
                                            }else{
                                                if(lexemas[i]=="FOREGROUND_DEPTH"){
                                                    this->cena.primeiroPlano[CorRGB::R] = std::stof(lexemas[i+2].c_str())/255;
                                                    this->cena.primeiroPlano[CorRGB::G] = std::stof(lexemas[i+3].c_str())/255;
                                                    this->cena.primeiroPlano[CorRGB::B] = std::stof(lexemas[i+4].c_str())/255;
                                                }else{
                                                    if(lexemas[i]=="BACKGROUND_DEPTH"){
                                                        this->cena.ultimoPlano[CorRGB::R] = std::stof(lexemas[i+2].c_str())/255;
                                                        this->cena.ultimoPlano[CorRGB::G] = std::stof(lexemas[i+3].c_str())/255;
                                                        this->cena.ultimoPlano[CorRGB::B] = std::stof(lexemas[i+4].c_str())/255;
                                                    }else{
                                                        if(lexemas[i]=="MAX_DEPHT"){
                                                            this->cena.profundidadeMaxima = std::stof(lexemas[i+2].c_str());
                                                        }else{
                                                            if(lexemas[i]=="SAMPLES"){
                                                                this->cena.amostras = std::stoi(lexemas[i+2].c_str(), nullptr,0);
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
        
    Cena& LeitorCena::getCena(){
        return this->cena;
    }
