Rip::Rip(std::string descricao){

    json j = Leitor::abrirArquivo(descricao);

    std::string arquivoCena = j["CENA"]; 
    std::string arquivoObjs = j["OBJETOS"];
    std::string arquivoCam = j["CAMERA"];
    std::string sombreador = j["SOMBREADOR"];

    this->renderizador.cena = LeitorCena::lerCena(arquivoCena);
    //std:: cout << "leu cena" << std::endl;
    this->renderizador.cena.objetos = LeitorObjetos::lerObjetos(arquivoObjs);
    //std:: cout << "leu objetos" << std::endl;
    this->renderizador.camera = LeitorCamera::lerConfCamera(arquivoCam);
    //std:: cout << "leu camera" << std::endl;

    if(sombreador=="blinnphong"){ 
        this->renderizador.acertarObjetos = BlinnPhong::acertarObjetos;
        this->renderizador.nAcertarObjetos =  BlinnPhong::nAcertarObjetos;
    }else if(sombreador=="toon"){ 
        this->renderizador.acertarObjetos = Toon::acertarObjetos;
        this->renderizador.nAcertarObjetos =  Toon::nAcertarObjetos;
    }else{
        std::cerr << "Sombreador não suportado" << std::endl;
    }

    std:: cout << "Renderizador de Imagem Progressivo(RIP)\n" << std::endl;
    /*
    std::cout << "Nome: " << renderizador.cena.nome << std::endl;
    std::cout << "Tipo: " << renderizador.cena.tipo << std::endl;
    std::cout << "Codificacao: " << renderizador.cena.codificacao << std::endl;
    std::cout << "Largura: " << renderizador.cena.largura << std::endl;
    std::cout << "Altura: " << renderizador.cena.altura << std::endl; 
    std::cout << "Gama: " << renderizador.cena.gama << std::endl;
    std::cout << "Superior Esquerdo: " << renderizador.cena.superiorEsquerdo << std::endl;
    std::cout << "Superior Direito: " << renderizador.cena.superiorDireito << std::endl;
    std::cout << "Inferior Esquerdo: " << renderizador.cena.inferiorEsquerdo << std::endl;
    std::cout << "Inferior Direito: " << renderizador.cena.inferiorDireito << std::endl;
    std::cout << "Ultimo Plano: " << renderizador.cena.ultimoPlano << std::endl;
    std::cout << "Primeiro Plano: " << renderizador.cena.primeiroPlano << std::endl;
    std::cout << "Profundidade Maxima: " << renderizador.cena.profundidadeMaxima << std::endl;
    std::cout << "Profundidade Raio: " << renderizador.cena.profundidadeRaio << std::endl;
    
    std:: cout << "luz ambiente" << std::endl;

    std::cout << "Intensidade: " << renderizador.cena.luzAmbiente->intensidade << std::endl;
    */
    /*
    std::cout << "Luzes\n" << std::endl;

    for(unsigned int i=0;i<this->renderizador.cena.luzes.size();i++){
        std::cout << "Luz " << i << std::endl;
        std::cout << "Intensidade: " << this->renderizador.cena.luzes[i]->intensidade << std::endl;
        std::cout << "Direcao: " << this->renderizador.cena.luzes[i]->direcao << std::endl;
    }
    */
    /*    
    for(Objeto* obj : this->renderizador.cena.objetos){
        std::cout << "Origem: " << obj->origem << std::endl;
        std::cout << "raio: " << ((Esfera*)obj)->r << std::endl;
        std::cout << "KA : " << ((Lambertiano*)obj->material)->ambiente << std::endl;
        std::cout << "KD : " << ((Lambertiano*)obj->material)->difuso << std::endl;
        std::cout << "KS : " << ((Lambertiano*)obj->material)->especular << std::endl;
        std::cout << "ES : " << ((Lambertiano*)obj->material)->expoenteEspecular << std::endl;
    }
    */
    /*
    for(Objeto* obj : this->renderizador.cena.objetos){
        std::cout << "Origem: " << obj->origem << std::endl;
        std::cout << "Raio: " << ((Esfera*)obj)->r << std::endl;
        std::cout << "Gradientes: " << std::endl;
        for(CorRGB c : ((ToonMaterial*)obj->material)->gradientes){
            std::cout << "\tCor: " << c << std::endl;
        }
        std::cout << "Angulos: "; 
        for(float t : ((ToonMaterial*)obj->material)->angulos){
            std::cout << t << " ";
        };
        std::cout << "" << std::endl;
    } 
    */   
}

/*
void Rip::renderizar(CorRGB (*nAcertarObjetos)(Raio&,Renderizador&, Acerto&), CorRGB (*nNacertarObjetos)(Raio&,Renderizador&, Acerto&) = nullptr){
        
    std::cout << "Realizando Renderização da imagem..." << std::endl;
    
    this->renderizador.acertarObjetos = nAcertarObjetos;
    this->renderizador.nAcertarObjetos = nNacertarObjetos;

    this->imagem = this->renderizador.criarImagem();

}
*/

void Rip::renderizar(){

    std::cout << "Realizando Renderização da imagem..." << std::endl;    

    this->imagem = this->renderizador.criarImagem();
}

void Rip::salvarImagem(std::string tipo,std::string nomeArquivo){
    
    if(this->imagem.largura>0 && this->imagem.altura>0){
        Impressora::salvarImagem(this->imagem, tipo,nomeArquivo);
    }else{
        std::cout << "É necessário renderizar uma imagem primeiro" << std::endl;
    }
}
