
namespace BlinnPhong{

	float max(float a, float b){
		if(a>b){
			return a;
		}
		
		return b;
	}

	CorRGB corrigirCor(CorRGB c){
		if(c.r() > 1){
			c.e[0] = 1.0;
		}
		if(c.g() > 1){
			c.e[1] = 1.0;
		}
		if(c.b() > 1){
			c.e[2] = 1.0;
		}
		if(c.r() < 0){
			c.e[0] = 0.0;
		}
		if(c.g() < 0){
			c.e[1] = 0.0;
		}
		if(c.b() < 0){
			c.e[2] = 0.0;
		}
		return c;
	}

	CorRGB acertarObjetos(Raio& raio, Renderizador& renderizador, Acerto& acerto){

		//std::cout << "Raio D:" << raio.getDirecao() << std::endl;

		BlinnPhongMaterial* bfm = (BlinnPhongMaterial*)acerto.material;

		//std::cout << "Difuso: " << bfm->difuso  << std::endl;

		CorRGB cor;

		CorRGB corAmbiente = bfm->ambiente * renderizador.cena.luzAmbiente->intensidade;

		//std::cout << "CorAmbiente: " << corAmbiente << std::endl;

		cor+=corAmbiente;

		Vetor3 raioUnit = unit_vector(raio.getDirecao());

		//std::cout << "RaioUnit: " << raioUnit << std::endl;

		//Raio refletido
		Vetor3 raioRefletido = raio.getDirecao() - 2 * dot(raio.getDirecao(), acerto.normal) * acerto.normal;

		//std::cout << "raioRefletido: " << raioRefletido << std::endl;

		//Raio que volta para a camera
		Vetor3 v = unit_vector(Vetor3( raioUnit.x(),  raioUnit.y(), raioUnit.z()) * Vetor3(-1,-1,-1));

		//std::cout << " vetor v: " << v << std::endl;

		//Iterando entre as luzes
		for(Luz* luz : renderizador.cena.luzes){

			Vetor3 luzNormalizada = luz->obterDirecao(acerto.ponto);

			//std::cout << "DIRECAO LUZ: " << luzNormalizada << std::endl;

			Raio sr = Raio(acerto.ponto, luzNormalizada);

			//std::cout << "Vetor luz normalizada: " << luzNormalizada << std::endl;

			Acerto* acerto2 = renderizador.cena.acertarObjetos(sr,0.001f,1);

			if(acerto2==NULL){

				//Direçao da luz normalizada
				luzNormalizada = unit_vector(luzNormalizada);

				//Componente difuso
				CorRGB difuso = bfm->difuso * max(0.f, dot(luzNormalizada, acerto.normal)) * luz->obterIntensidade();
				
				//std::cout << "Difuso: " << difuso << std::endl;

				//Vetor mediano entre a a luz e o raio da camera
				Vetor3 H = unit_vector(luzNormalizada + v);	

				//std::cout << "Vetor h: " << H << std::endl;

				//Componente especular
				Vetor3 especular = bfm->especular * pow(max(0.f, dot(acerto.normal, H)) , bfm->expoenteEspecular /*5 Componente Alfa*/ ) * luz->obterIntensidade();

				//std::cout << "Especular: " << especular << std::endl;

				CorRGB espelhado(0,0,0);

				if(renderizador.cena.profundidadeRaio>0){

					//std::cout << "REFLETIDO" << std::endl;

					renderizador.cena.profundidadeRaio-=1;

					//std::cout << "Cor da 1 interacao: " << cor+difuso+especular << std::endl;
					//std::cout << "Ponto:"<< acerto.ponto << std::endl;
					//std::cout << "Raio refletido:"<< raioRefletido << std::endl;
					cor += espelhado*renderizador.colorir(*(new Raio(acerto.ponto , raioRefletido)));
					
					renderizador.cena.profundidadeRaio=renderizador.cena.contProfundidadeRaio;
				}

				cor += difuso + especular; 
			}
		}	


		return corrigirCor(cor);
	}

	CorRGB nAcertarObjetos(Raio& raio,Renderizador& renderizador, Acerto& acerto){
		CorRGB top (0.5, 0.7, 1 );
	    CorRGB bottom(1,1,1);

	    Vetor3 unit_ray = unit_vector(raio.getDirecao());
	    float t = 0.5*(unit_ray.y()+1.0);
	    return (1-t)*bottom+t*top;
	}
}	