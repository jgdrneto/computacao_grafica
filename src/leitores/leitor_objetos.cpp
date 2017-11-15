#include <iostream>

#define PI 3.14159265

/// User-define literal to convert from degrees to radian.
long double convertToDegrees( long double deg )
{
    return deg*PI/180;
}
    
Material* obterMaterial(json j){

    Material* material = nullptr;

    if(j["TIPO"] == "BLINNPHONG"){
        
        BlinnPhongMaterial* l = new BlinnPhongMaterial();

        l->ambiente[CorRGB::R] = j["AMBIENTE"]["R"];
        l->ambiente[CorRGB::G] = j["AMBIENTE"]["G"];
        l->ambiente[CorRGB::B] = j["AMBIENTE"]["B"];
        
        l->difuso[CorRGB::R] = j["DIFUSO"]["R"];
        l->difuso[CorRGB::G] = j["DIFUSO"]["G"];
        l->difuso[CorRGB::B] = j["DIFUSO"]["B"];

        l->especular[CorRGB::R] = j["ESPECULAR"]["R"];
        l->especular[CorRGB::G] = j["ESPECULAR"]["G"];
        l->especular[CorRGB::B] = j["ESPECULAR"]["B"];
                                  
        l->expoenteEspecular = j["EXP_ESPECULAR"];
        
        material = l;

    }else if(j["TIPO"] == "TOON"){

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

    return &*material;
}

std::vector<glm::vec4> realizarTransformacoes(std::vector<glm::vec4> p, json j, Objeto* objeto){

    std::vector<glm::vec4> p_t;

    glm::mat4 transformacao = glm::mat4(1.0f);

    for(unsigned int t = 0;t< j.size();t++){

        if(j[t]["TIPO"]=="TRANSLACAO"){

            glm::vec3 fator_translacao( j[t]["MUDAR"]["X"],
                                        j[t]["MUDAR"]["Y"],
                                        j[t]["MUDAR"]["Z"]);

            glm::mat4 translacao = glm::translate( glm::mat4(1.0f),fator_translacao);
                           
            transformacao  = translacao * transformacao;

        }else if(j[t]["TIPO"]=="ROTACAO"){
            
            if(typeid(*objeto) != typeid(Esfera)){

                std::string coordenada = j[t]["MUDAR"]["EIXO"];

                glm::vec3 vetorTransformacao(0.0f,0.0f,0.0f);

                if(coordenada=="X"){
                    //std::cout << "Entrou no X" << std::endl;
                    vetorTransformacao.x = 1.0f;
                }else if(coordenada=="Y"){
                    //std::cout << "Entrou no Y" << std::endl;
                    vetorTransformacao.y = 1.0f;
                }else if(coordenada=="Z"){
                    //std::cout << "Entrou no Z" << std::endl;
                    vetorTransformacao.z = 1.0f;
                }else{

                }

                float angulo = convertToDegrees(j[t]["MUDAR"]["ANGULO"]);

                glm::mat4 translacao1 = glm::translate( glm::mat4(1.0f), glm::vec3(-p[0].x, -p[0].y,-p[0].z)); 

                glm::mat4 translacao2 = glm::translate( glm::mat4(1.0f), glm::vec3(p[0].x, p[0].y,p[0].z)); 

                glm::mat4 rotacao = glm::rotate(glm::mat4(1.0f), 
                                            angulo, 
                                            vetorTransformacao);

                transformacao  = translacao1 * transformacao;            
    
                transformacao  = rotacao * transformacao;
                
                transformacao  = translacao2 * transformacao;            

            }
            //transformacao  = transformador * transformacao;
        }else if(j[t]["TIPO"]=="ESCALA"){
            
            if(typeid(*objeto) == typeid(Triangulo)){

                double fator_escala = j[t]["MUDAR"];

                glm::mat4 translacao1 = glm::translate( glm::mat4(1.0f), glm::vec3(-p[0].x, -p[0].y,-p[0].z)); 

                glm::mat4 translacao2 = glm::translate( glm::mat4(1.0f), glm::vec3(p[0].x, p[0].y,p[0].z)); 

                glm::mat4 escala = glm::scale(glm::mat4(1.0f), glm::vec3 (fator_escala,fator_escala,fator_escala));
                
                transformacao  = translacao1 * transformacao;  
                
                transformacao = escala * transformacao;

                transformacao  = translacao2 * transformacao;

            }else{

                Esfera* esfera = (Esfera *)objeto;
                
                double fator_escala = j[t]["MUDAR"];

                esfera->r = esfera->r*fator_escala;                             
                
            }
        }
    }


    for(unsigned int i=0; i<p.size(); i++){
        p_t.push_back(transformacao * p[i]);
    }

    return p_t;    
}

std::vector<Objeto*>& LeitorObjetos::lerObjetos(std::string nomeArquivo){
    
    json j = Leitor::abrirArquivo(nomeArquivo);  

    std::vector<Objeto*>* objetos =  new std::vector<Objeto*>();

    for(unsigned int n=0;n<j["OBJETOS"]["ESFERAS"].size();n++){

        Esfera* esfera = new Esfera();

        std::vector<glm::vec4> pontos;
        
        pontos.push_back(
                    glm::vec4(j["OBJETOS"]["ESFERAS"][n]["ORIGEM"]["X"],
                              j["OBJETOS"]["ESFERAS"][n]["ORIGEM"]["Y"],
                              j["OBJETOS"]["ESFERAS"][n]["ORIGEM"]["Z"],
                              j["OBJETOS"]["ESFERAS"][n]["ORIGEM"]["H"]));
            
        /*
        esfera->origem[Vetor3::X] = j["OBJETOS"]["ESFERAS"][n]["ORIGEM"]["X"];
        esfera->origem[Vetor3::Y] = j["OBJETOS"]["ESFERAS"][n]["ORIGEM"]["Y"];
        esfera->origem[Vetor3::Z] = j["OBJETOS"]["ESFERAS"][n]["ORIGEM"]["Z"];
        */    

        esfera->r = j["OBJETOS"]["ESFERAS"][n]["RAIO"];
            
        esfera->material = obterMaterial(j["OBJETOS"]["ESFERAS"][n]["MATERIAL"]);
        
        pontos = realizarTransformacoes(pontos,j["OBJETOS"]["ESFERAS"][n]["TRANSFORMACOES"], esfera);

        
        esfera->origem[Vetor3::X] = pontos[0][0];
        esfera->origem[Vetor3::Y] = pontos[0][1];
        esfera->origem[Vetor3::Z] = pontos[0][2];
        
        objetos->push_back(esfera);
    }

    for(unsigned int n=0;n<j["OBJETOS"]["TRIANGULOS"].size();n++){
        
        Triangulo* triangulo = new Triangulo();

        
        std::vector<glm::vec4> pontos;

        pontos.push_back(
            *(new glm::vec4(j["OBJETOS"]["TRIANGULOS"][n]["V0"]["X"],
                            j["OBJETOS"]["TRIANGULOS"][n]["V0"]["Y"],
                            j["OBJETOS"]["TRIANGULOS"][n]["V0"]["Z"],
                            j["OBJETOS"]["TRIANGULOS"][n]["V0"]["H"]))
            );
        pontos.push_back(
            *(new glm::vec4(j["OBJETOS"]["TRIANGULOS"][n]["V1"]["X"],
                            j["OBJETOS"]["TRIANGULOS"][n]["V1"]["Y"],
                            j["OBJETOS"]["TRIANGULOS"][n]["V1"]["Z"],
                            j["OBJETOS"]["TRIANGULOS"][n]["V1"]["H"]))
            );
        pontos.push_back(    
            *(new glm::vec4(j["OBJETOS"]["TRIANGULOS"][n]["V2"]["X"],
                            j["OBJETOS"]["TRIANGULOS"][n]["V2"]["Y"],
                            j["OBJETOS"]["TRIANGULOS"][n]["V2"]["Z"],
                            j["OBJETOS"]["TRIANGULOS"][n]["V2"]["H"]))
            );
        /*
        triangulo->v0[Vetor3::X] = j["OBJETOS"]["TRIANGULOS"][n]["V0"]["X"];
        triangulo->v0[Vetor3::Y] = j["OBJETOS"]["TRIANGULOS"][n]["V0"]["Y"];
        triangulo->v0[Vetor3::Z] = j["OBJETOS"]["TRIANGULOS"][n]["V0"]["Z"];

        triangulo->v1[Vetor3::X] = j["OBJETOS"]["TRIANGULOS"][n]["V1"]["X"];
        triangulo->v1[Vetor3::Y] = j["OBJETOS"]["TRIANGULOS"][n]["V1"]["Y"];
        triangulo->v1[Vetor3::Z] = j["OBJETOS"]["TRIANGULOS"][n]["V1"]["Z"];

        triangulo->v2[Vetor3::X] = j["OBJETOS"]["TRIANGULOS"][n]["V2"]["X"];
        triangulo->v2[Vetor3::Y] = j["OBJETOS"]["TRIANGULOS"][n]["V2"]["Y"];
        triangulo->v2[Vetor3::Z] = j["OBJETOS"]["TRIANGULOS"][n]["V2"]["Z"];    
        */

        triangulo->material = obterMaterial(j["OBJETOS"]["TRIANGULOS"][n]["MATERIAL"]);

        triangulo->apagarCostas = j["OBJETOS"]["TRIANGULOS"][n]["APG_COSTAS"];
        
        pontos = realizarTransformacoes(pontos,j["OBJETOS"]["TRIANGULOS"][n]["TRANSFORMACOES"],triangulo);
        
        triangulo->v0[Vetor3::X] = pontos[0][0];
        triangulo->v0[Vetor3::Y] = pontos[0][1];
        triangulo->v0[Vetor3::Z] = pontos[0][2];

        triangulo->v1[Vetor3::X] = pontos[1][0];
        triangulo->v1[Vetor3::Y] = pontos[1][1];
        triangulo->v1[Vetor3::Z] = pontos[1][2];

        triangulo->v2[Vetor3::X] = pontos[2][0];
        triangulo->v2[Vetor3::Y] = pontos[2][1];
        triangulo->v2[Vetor3::Z] = pontos[2][2];

        objetos->push_back(triangulo);

    }   

        
    return *(objetos);               
}