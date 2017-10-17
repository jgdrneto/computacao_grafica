
Camera* LeitorCamera::lerConfCamera(std::string nomeArquivo){
    
    json j = Leitor::abrirArquivo(nomeArquivo);  

    Camera* camera = nullptr; 

    Vetor3 origem(j["CAMERA"]["ORIGEM"]["X"],
                  j["CAMERA"]["ORIGEM"]["Y"],
                  j["CAMERA"]["ORIGEM"]["Z"]);

    //std::cout << "Origem da camera" << origem << std::endl;

    Ponto3 olhando(j["CAMERA"]["OLHANDO"]["X"],
                   j["CAMERA"]["OLHANDO"]["Y"],
                   j["CAMERA"]["OLHANDO"]["Z"]);

    //std::cout << "olhando: " << olhando << std::endl;

    Vetor3 vetorSuperior(j["CAMERA"]["VETOR_SUP"]["X"],
                         j["CAMERA"]["VETOR_SUP"]["Y"],
                         j["CAMERA"]["VETOR_SUP"]["Z"]);    

    //std::cout << "vetorSuperior: " <<vetorSuperior << std::endl;

    if(j["CAMERA"]["TIPO"]=="PERSPECTIVA"){

        float fov = j["CAMERA"]["FOV"];

        //std::cout << "fov: " << fov << std::endl;

        float aspecto = j["CAMERA"]["ASPECTO"];

        //std::cout << "aspecto: " << aspecto << std::endl;

        float abertura = j["CAMERA"]["ABERTURA"];

        //std::cout << "abertura: " << abertura << std::endl;

        float distanciaFocal = j["CAMERA"]["DIST_FOCAL"];

        //std::cout << "distanciaFocal: " << distanciaFocal << std::endl;

        camera = new CameraPerspectiva(origem, olhando, vetorSuperior, fov, aspecto, abertura, distanciaFocal);
        /*
        std::cout << "Valor de u: " << ((CameraPerspectiva*)camera)->u << std::endl;
        std::cout << "Valor de v: " << ((CameraPerspectiva*)camera)->v << std::endl;
        std::cout << "Valor de w: " << ((CameraPerspectiva*)camera)->w << std::endl;
        std::cout << "CANTOINFERIORESQUERDO: " << camera->canto_inferior_esquerdo << std::endl;
        std::cout << "Horizontal:" << camera->horizontal << std::endl;
        std::cout << "Vertical: " << camera->vertical << std::endl;
        std::cout << "Origem" << camera->origem << std::endl; 
        */
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
