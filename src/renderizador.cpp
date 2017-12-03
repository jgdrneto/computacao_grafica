Renderizador::Renderizador(){
    //NULL
}

Renderizador::Renderizador(Cena& nCena){
    /*
    this->cena = nCena;

    //Make camera

    Ponto3* canto_inferior_esquerdo =  new Ponto3( -2, -1, -1 ); // lower left corner of the view plane.
    Vetor3* horizontal =  new Vetor3( 4, 0, 0 ); // Horizontal dimension of the view plane.
    Vetor3* vertical =  new Vetor3(0, 2, 0); // Vertical dimension of the view plane.
    Ponto3* origem = new Ponto3(0, 0, 0); // the camera's origin.

    this->camera = *(new Camera(*canto_inferior_esquerdo,*horizontal,*vertical,*origem));

    //Criando objetos na cena

    Esfera* esfera = new Esfera(Ponto3(0,0,-1),Material(),0.5f);

    this->cena.objetos.push_back(esfera);
    */
}

CorRGB Renderizador::colorir(Raio& raio){
    
    //std::cout << "Raio D:" << raio.getDirecao() << std::endl;
    //std::cout << "Raio O:" << raio.getOrigem() << std::endl;

    Acerto* acerto = this->cena.acertarObjetos(raio,0.001,this->cena.profundidadeMaxima);

    if(acerto!=nullptr){
        /*
        std::cout << "Especular: " << ((BlinnPhongMaterial*)acerto->material)->especular << std::endl;
        std::cout << "ambiente: " << ((BlinnPhongMaterial*)acerto->material)->ambiente << std::endl;
        */
        return this->acertarObjetos(raio, *(this), *(acerto));
    
    }else{
        
    	if(this->nAcertarObjetos!=nullptr){
    		return this->nAcertarObjetos(raio,*(this),*(acerto));
		}else{
			return cena.ultimoPlano;
		}
    }

}

/*
void tentativa(Renderizador* renderizador,Imagem* imagem, int row,int col,int cont){
    CorRGB somaCores(0,0,0);

    for(int i=0;i<renderizador->cena.amostras;i++)
            {   
        // Determine how much we have 'walked' on the image: in [0,1]
        auto u = float(col + drand48()) / float( imagem->largura ); // walked u% of the horizontal dimension of the view plane.
        auto v = float(row + drand48()) / float( imagem->altura ); // walked v% of the vertical dimension of the view plane.

        // Determine the ray's direction, based on the pixel coordinate (col,row).
        // We are mapping (matching) the view plane (vp) to the image.
        // To create a ray we need: (a) an origin, and (b) an end point.
        //
        // (a) The ray's origin is the origin of the camera frame (which is the same as the world's frame).
        //
        // (b) To get the end point of ray we just have to 'walk' from the
        // vp's origin + horizontal displacement (proportional to 'col') +
        // vertical displacement (proportional to 'row').
        
        Ponto3 end_point = renderizador->camera.canto_inferior_esquerdo + u*renderizador->camera.horizontal + v*renderizador->camera.vertical ;
        // The ray:
        Raio r( renderizador->camera.origem, end_point - renderizador->camera.origem );

        // Determine the color of the ray, as it travels through the virtual space.
        somaCores+=renderizador->colorir(r);
    }

    CorRGB c = somaCores/renderizador->cena.amostras;

    c = CorRGB(pow(c[CorRGB::R],1.0/renderizador->cena.gama),pow(c[CorRGB::G],1.0/renderizador->cena.gama),pow(c[CorRGB::B],1.0/renderizador->cena.gama));

    int ir = int( 255.99f * c[CorRGB::R] );
    int ig = int( 255.99f * c[CorRGB::G] );
    int ib = int( 255.99f * c[CorRGB::B] );

    imagem->pixeis[cont++] = *(new CorRGB(ir,ig,ib));

    renderizador->barraProgresso.incrementar();
}
*/

Imagem& Renderizador::criarImagem(){
   	
   	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

   	this->barraProgresso.setDimensao(this->cena.altura*this->cena.largura);

    Imagem* imagem = new Imagem(this->cena.largura,this->cena.altura);

    int cont=0;

    //std::cout << "Altura:" << this->cena.altura << std::endl; 
    //std::cout << "Largura:" << this->cena.largura << std::endl; 

    for ( auto row{this->cena.altura-1} ; row >= 0 ; --row ) // Y
    {
        for( auto col{0} ; col < this->cena.largura ; col++ ) // X
        {   
                        
            CorRGB somaCores(0,0,0);

            for(int i=0;i<cena.amostras;i++)
            {   
                // Determine how much we have 'walked' on the image: in [0,1]
                auto u = float(col + drand48()) / float( this->cena.largura ); // walked u% of the horizontal dimension of the view plane.
                auto v = float(row + drand48()) / float( this->cena.altura ); // walked v% of the vertical dimension of the view plane.

                // Determine the ray's direction, based on the pixel coordinate (col,row).
                // We are mapping (matching) the view plane (vp) to the image.
                // To create a ray we need: (a) an origin, and (b) an end point.
                //
                // (a) The ray's origin is the origin of the camera frame (which is the same as the world's frame).
                //
                // (b) To get the end point of ray we just have to 'walk' from the
                // vp's origin + horizontal displacement (proportional to 'col') +
                // vertical displacement (proportional to 'row').
                // The ray:

                //std::cout<< "VALOR U: " << u << std::endl;
                //std::cout<< "VALOR V: " << v << std::endl; 

                Raio r = this->camera->obterRaio(u,v);
                /*
                std::cout << "Raio\n"<< std::endl;
                std::cout << "Origem :" << r.getOrigem() << std::endl;
                std::cout << "Direcao :" << r.getDirecao() << std:: endl;
                */    
                // Determine the color of the ray, as it travels through the virtual space.
                
                CorRGB cor = this->colorir(r);
                /*
                std::cout << "Cor:" << cor << std::endl;

                system("read -p \"Pressione enter para sair\" saindo");
                */
                somaCores+=cor;    
            }

                //std::cout << "Cor: " << somaCores << std::endl;

                CorRGB c = somaCores/cena.amostras;
                
            
                c = CorRGB(pow(c[CorRGB::R],1.0/this->cena.gama),pow(c[CorRGB::G],1.0/this->cena.gama),pow(c[CorRGB::B],1.0/this->cena.gama));

                int ir = int( 255.99f * c[CorRGB::R] );
                int ig = int( 255.99f * c[CorRGB::G] );
                int ib = int( 255.99f * c[CorRGB::B] );

                imagem->pixeis[cont++] = *(new CorRGB(ir,ig,ib));

                barraProgresso.incrementar();
        }
    }

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
     
    std::chrono::duration<double> duration = t2 - t1;

    std::cout << "\nTempo de renderização: " <<     duration.count() << " segundo(s)" << std::endl;

    return *(imagem);
}
