Rip::Rip(std::string arquivoCena,std::string arquivoObjs){

    this->renderizador.cena = LeitorCena::lerCena(arquivoCena);
    this->renderizador.cena.objetos = LeitorObjetos::lerObjetos(arquivoObjs);
    this->renderizador.camera = LeitorCamera::lerConfCamera(arquivoCena);

    std:: cout << "Renderizador de Imagem Progressivo(RIP)\n" << std::endl;

    /*
    std::cout << "Amostras: " << renderizador.cena.amostras << std::endl;
    std::cout << "Camera origem: " << renderizador.camera.origem << std::endl;
    std::cout << "Camera horizontal: " << renderizador.camera.horizontal << std::endl;
    std::cout << "Camera vertical: " << renderizador.camera.vertical << std::endl;
    std::cout << "Camera LLC: " << renderizador.camera.canto_inferior_esquerdo << std::endl;
    
    for(unsigned int i=0;i<this->renderizador.cena.luzesAmbientes.size();i++){
        std::cout << "Luz ambiente " << i << std::endl;
        std::cout << "Intensidade: " << this->renderizador.cena.luzesAmbientes[i].intensidade << std::endl;
        std::cout << "Direcao: " << this->renderizador.cena.luzesAmbientes[i].direcao << std::endl;
    }

    std::cout << "Luz Direcional " << std::endl;
    std::cout << "Intensidade: " << this->renderizador.cena.luzDirecional.intensidade << std::endl;
    std::cout << "Direcao: " << this->renderizador.cena.luzDirecional.direcao << std::endl;

    for(Objeto* obj : this->renderizador.cena.objetos){
        std::cout << "Origem: " << obj->origem << std::endl;
        std::cout << "raio: " << ((Esfera*)obj)->r << std::endl;
        std::cout << "KA : " << ((Lambertiano*)obj->material)->ambiente << std::endl;
        std::cout << "KD : " << ((Lambertiano*)obj->material)->difuso << std::endl;
        std::cout << "KS : " << ((Lambertiano*)obj->material)->especular << std::endl;
        std::cout << "ES : " << ((Lambertiano*)obj->material)->expoenteEspecular << std::endl;
    }
    */    
}

Rip::Rip(std::string arquivoCena){

    this->renderizador.cena = LeitorCena::lerCena(arquivoCena);
    this->renderizador.camera = LeitorCamera::lerConfCamera(arquivoCena);
}

void Rip::renderizar(CorRGB (*nAcertarObjetos)(Raio&,Renderizador&, Acerto&), CorRGB (*nNacertarObjetos)(Raio&,Renderizador&, Acerto&) = nullptr){
        
    std::cout << "Realizando Renderização da imagem..." << std::endl;
    
    this->renderizador.acertarObjetos = nAcertarObjetos;
    this->renderizador.nAcertarObjetos = nNacertarObjetos;

    this->imagem = this->renderizador.criarImagem();

}

void Rip::salvarImagem(std::string tipo,std::string nomeArquivo){
    
    if(this->imagem.largura>0 && this->imagem.altura>0){
        Impressora::salvarImagem(this->imagem, tipo,nomeArquivo);
    }else{
        std::cout << "É necessário renderizar uma imagem primeiro" << std::endl;
    }
}
