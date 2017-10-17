
Camera* LeitorCamera::lerConfCamera(std::string nomeArquivo){
    
    json j = Leitor::abrirArquivo(nomeArquivo);  

    Camera* camera = nullptr; 

    Vetor3 origem(j["CAMERA"]["ORIGEM"]["X"],
                  j["CAMERA"]["ORIGEM"]["Y"],
                  j["CAMERA"]["ORIGEM"]["Z"]);

    Ponto3 olhando(j["CAMERA"]["OLHANDO"]["X"],
                   j["CAMERA"]["OLHANDO"]["Y"],
                   j["CAMERA"]["OLHANDO"]["Z"]);

    Vetor3 vetorSuperior(j["CAMERA"]["VETOR_SUP"]["X"],
                         j["CAMERA"]["VETOR_SUP"]["Y"],
                         j["CAMERA"]["VETOR_SUP"]["Z"]);    

    if(j["CAMERA"]["TIPO"]=="PERSPECTIVA"){

        float fov = j["CAMERA"]["FOV"];

        float aspecto = j["camera"]["ASPECTO"];

        float abertura = j["camera"]["ABERTURA"];

        float distanciaFocal = j["camera"]["DIST_FOCAL"];

        camera = new CameraPerspectiva(origem, olhando, vetorSuperior, fov, aspecto, abertura, distanciaFocal);

    }else if(j["CAMERA"]["TIPO"]=="PARALELA"){
        /*
        float acima = j["CAMERA"]["ACIMA"]; 
        
        float abaixo = j["CAMERA"]["ABAIXO"];

        float esquerda = j["CAMERA"]["ESQUERDA"];

        float direita = j["CAMERA"]["DIREITA"];

        camera = new CameraParalela(origem, olhando, vetorSuperior, esquerda, direita, abaixo, acima);  
        */
        camera = nullptr;
    }

    return camera;
}
