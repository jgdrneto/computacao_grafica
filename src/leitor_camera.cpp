#include <iostream>
    
Camera& LeitorCamera::lerConfCamera(std::string nomeArquivo){
    
    Camera* camera = new Camera();

    std::vector<std::string> lexemas = lerLexemas(lerLinhas(nomeArquivo));
    
    for(unsigned int i = 0;i<lexemas.size();i++){
        if(i<lexemas.size() && lexemas[i]=="CAMERA_LLC"){
            camera->canto_inferior_esquerdo[Ponto3::X] = std::stof(lexemas[i+2].c_str());
            camera->canto_inferior_esquerdo[Ponto3::Y] = std::stof(lexemas[i+3].c_str());
            camera->canto_inferior_esquerdo[Ponto3::Z] = std::stof(lexemas[i+4].c_str());
            i=i+5;
        }
        if(i<lexemas.size() && lexemas[i]=="CAMERA_HOR"){
            camera->horizontal[Vetor3::X] = std::stof(lexemas[i+2].c_str());
            camera->horizontal[Vetor3::Y] = std::stof(lexemas[i+3].c_str());
            camera->horizontal[Vetor3::Z] = std::stof(lexemas[i+4].c_str());
            i=i+5;
        }
        if(i<lexemas.size() && lexemas[i]=="CAMERA_VER"){
            camera->vertical[Vetor3::X] = std::stof(lexemas[i+2].c_str());
            camera->vertical[Vetor3::Y] = std::stof(lexemas[i+3].c_str());
            camera->vertical[Vetor3::Z] = std::stof(lexemas[i+4].c_str());
            i=i+5;
        }
        if(i<lexemas.size() && lexemas[i]=="CAMERA_ORI"){
            camera->origem[Ponto3::X] = std::stof(lexemas[i+2].c_str());
            camera->origem[Ponto3::Y] = std::stof(lexemas[i+3].c_str());
            camera->origem[Ponto3::Z] = std::stof(lexemas[i+4].c_str());
            i=i+5;
        }

    }

    return *(camera);
}
