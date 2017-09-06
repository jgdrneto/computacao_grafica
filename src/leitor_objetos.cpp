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
                if(i<lexemas.size() && lexemas[i] == "MAT_TYPE"){
                    
                    if(lexemas[i+2]=="LAMBERTIAN"){
                        i+=3;
                        
                        Lambertiano* l = new Lambertiano();

                        if(lexemas[i]=="MAT_AMB"){
                            l->ambiente[CorRGB::R] = std::stof(lexemas[i+2].c_str());
                            l->ambiente[CorRGB::G] = std::stof(lexemas[i+3].c_str());
                            l->ambiente[CorRGB::B] = std::stof(lexemas[i+4].c_str());
                        
                        i+=5;
                        }

                        if(lexemas[i]=="MAT_DIF"){
                            l->difuso[CorRGB::R] = std::stof(lexemas[i+2].c_str());
                            l->difuso[CorRGB::G] = std::stof(lexemas[i+3].c_str());
                            l->difuso[CorRGB::B] = std::stof(lexemas[i+4].c_str());
                        
                        i+=5;
                        }

                        if(lexemas[i]=="MAT_ESP"){
                            l->especular[CorRGB::R] = std::stof(lexemas[i+2].c_str());
                            l->especular[CorRGB::G] = std::stof(lexemas[i+3].c_str());
                            l->especular[CorRGB::B] = std::stof(lexemas[i+4].c_str());
                        
                        i+=5;
                        }

                        if(lexemas[i]=="EXP_ESP"){
                            l->expoenteEspecular = std::stoi(lexemas[i+2].c_str(), nullptr,0);
                        
                        i+=3;
                        
                        }

                        esfera->material = l;
                    }else{
                        esfera->material = nullptr;
                    }
                }

                objetos->push_back(esfera);
            }
        }
    }

    return *(objetos);             
}