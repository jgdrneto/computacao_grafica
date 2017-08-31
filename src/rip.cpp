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

    for(Objeto* obj : renderizador.cena.objetos){
        std::cout << "Origem: " << obj->origem << std::endl;
        std::cout << "raio: " << ((Esfera*)obj)->r << std::endl;
    }
    */
}

Rip::Rip(std::string arquivoCena){

    this->renderizador.cena = LeitorCena::lerCena(arquivoCena);
    this->renderizador.camera = LeitorCamera::lerConfCamera(arquivoCena);
}

void Rip::renderizar(CorRGB (*colorir)(Raio&,Cena&)){
        
    std::cout << "Realizando Renderização da imagem..." << std::endl;
        
    this->imagem = this->renderizador.criarImagem(colorir);

}

void Rip::salvarImagem(std::string tipo,std::string nomeArquivo){
    
    if(this->imagem.largura>0 && this->imagem.altura>0){
        Impressora::salvarImagem(this->imagem, tipo,nomeArquivo);
    }else{
        std::cout << "É necessário renderizar uma imagem primeiro" << std::endl;
    }
}
