#include <iostream>

#define PI 3.14159265
    
Material* obterMaterial(json j){

    Material* material = nullptr;

    if(j["TIPO"] = "LAMBERTIANO"){

        Lambertiano* l = new Lambertiano();

        l->ambiente[CorRGB::R] = j["AMBIENTE"]["R"];
        l->ambiente[CorRGB::G] = j["AMBIENTE"]["G"];
        l->ambiente[CorRGB::B] = j["AMBIENTE"]["B"];
                             
        l->difuso[CorRGB::R] = j["DIFUSO"]["R"];
        l->difuso[CorRGB::G] = j["DIFUSO"]["G"];
        l->difuso[CorRGB::B] = j["DIFUSO"]["B"];
                           
        l->especular[CorRGB::R] = j["EXPECULAR"]["R"];
        l->especular[CorRGB::B] = j["EXPECULAR"]["G"];
        l->especular[CorRGB::B] = j["EXPECULAR"]["B"];
                              
        l->expoenteEspecular = j["EXP_ESPECULAR"];
        
        material = l;

    }else if(j["TIPO"] = "TOON"){

        ToonMaterial* t = new ToonMaterial();

        for(unsigned int n = 0; n<j["GRADIENTES"].size();n++){

            t->gradientes.push_back(*(new CorRGB(j["GRADIENTES"][n]["R"],
                                                 j["GRADIENTES"][n]["G"],
                                                 j["GRADIENTES"][n]["B"])));
        }

        for(unsigned int n = 0; n<j["ANGULOS"].size();n++){

            float angulo = j["ANGULOS"][n]["VALOR"];

            angulo = cos(angulo* PI / 180.0);

            t->angulos.push_back(angulo);
        }

        material = t;    
    }

    return material;
}

std::vector<Objeto*>& LeitorObjetos::lerObjetos(std::string nomeArquivo){
    
    json j = Leitor::abrirArquivo(nomeArquivo);  

    std::vector<Objeto*>* objetos =  new std::vector<Objeto*>();

    for(unsigned int n=0;n<j["OBJETOS"]["ESFERAS"].size();n++){

        Esfera* esfera = new Esfera();

        esfera->origem[Vetor3::X] = j["OBJETOS"]["ESFERAS"][n]["ORIGEM"]["X"];
        esfera->origem[Vetor3::Y] = j["OBJETOS"]["ESFERAS"][n]["ORIGEM"]["Y"];
        esfera->origem[Vetor3::Z] = j["OBJETOS"]["ESFERAS"][n]["ORIGEM"]["Z"];
                                   
        esfera->r = j["OBJETOS"]["ESFERAS"][n]["RAIO"];
            
        esfera->material = obterMaterial(j["OBJETOS"]["ESFERAS"][n]["MATERIAL"]);
            
        objetos->push_back(esfera);
    }


    for(unsigned int n=0;n<j["OBJETOS"]["TRIANGULOS"].size();n++){
            
    }
        
    return *(objetos);               
}