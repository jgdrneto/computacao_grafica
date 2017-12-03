namespace Lambertiano{

	CorRGB acertarObjetos(Raio& raio, Renderizador& renderizador, Acerto& acerto){
		
		Raio raioDisperso = raio;
        CorRGB atenuacao = CorRGB(1,1,1);
        CorRGB cor =  CorRGB(0,0,0);

		if(renderizador.cena.profundidadeRaio>0){

			if (acerto.material->nome == "LAMBERTIANO"){
      			
      			LambertianoMaterial* lm = (LambertianoMaterial*)acerto.material;
    			lm->obterDispersao(raio,acerto,atenuacao,raioDisperso);

    		}else{

    			DieletricoMaterial* dm = (DieletricoMaterial*)acerto.material;
    			dm->obterDispersao(raio,acerto,atenuacao,raioDisperso);
    			
    		}

			renderizador.cena.profundidadeRaio-=1;

			cor += atenuacao*renderizador.colorir(raioDisperso);

		}else{
			cor = CorRGB(0,0,0);
		}


		renderizador.cena.profundidadeRaio=renderizador.cena.contProfundidadeRaio;

		return cor;
	}

	CorRGB nAcertarObjetos(Raio& raio,Renderizador& renderizador, Acerto& acerto){
		CorRGB top (0.5, 0.7, 1 );
	    CorRGB bottom(1,1,1);

	    Vetor3 unit_ray = unit_vector(raio.getDirecao());
	    float t = 0.5*(unit_ray.y()+1.0);
	    return (1-t)*bottom+t*top;
	}
}	