
namespace BlinnPhong{

	float max(float a, float b){
		if(a>b){
			return a;
		}
		
		return b;
	}

	CorRGB corrigirCor(CorRGB c){
		if(c.r() > 1.f){
			c.e[0] = 1.0;
		}
		if(c.g() > 1.f){
			c.e[1] = 1.0;
		}
		if(c.b() > 1.f){
			c.e[2] = 1.0;
		}
		if(c.r() < 0.f){
			c.e[0] = 0.0;
		}
		if(c.g() < 0.f){
			c.e[1] = 0.0;
		}
		if(c.b() < 0.f){
			c.e[2] = 0.0;
		}
		return c;
	}

	CorRGB acertarObjetos(Raio& raio, Renderizador& renderizador, Acerto& acerto){

		Lambertiano* lambertiano = (Lambertiano*)acerto.material;

		CorRGB cor;

		CorRGB corAmbiente = lambertiano->ambiente * renderizador.cena.luzAmbiente.intensidade;

		cor+=corAmbiente;

		//Origem do raio da sombra
		Vetor3 p = raio.getOrigem() + acerto.t * raio.getDirecao();

		Vetor3 raioUnit = unit_vector(raio.getDirecao());

		//Raio refletido
		Vetor3 raioRefletido = raio.getDirecao() - 2 * dot(raio.getDirecao(), acerto.normal) * acerto.normal;

		//Raio que volta para a camera
		Vetor3 v = unit_vector(Vetor3( raioUnit.x(),  raioUnit.y(), raioUnit.z()) * Vetor3(-1,-1,-1));

		//Iterando entre as luzes
		for(Luz luz : renderizador.cena.luzesDirecionais){

			Acerto* acerto2 = renderizador.cena.acertarObjetos(*(new Raio(p,luz.direcao)),0.001,renderizador.cena.profundidadeMaxima);

			if(acerto2==NULL){

				//Direçao da luz normalizada
				Vetor3 luzNormalizada = unit_vector(luz.direcao - raio.getDirecao());

				//Componente difuso
				CorRGB difuso = lambertiano->difuso * max(0.f, dot(luzNormalizada, acerto.normal)) * luz.intensidade;
				
				//Vetor mediano entre a a luz e o raio da camera
				Vetor3 H = unit_vector(luzNormalizada + v);	

				//Componente especular
				Vetor3 especular = lambertiano->especular * pow(max(0.f, dot(acerto.normal, H)) , lambertiano->expoenteEspecular /*5 Componente Alfa*/ ) * luz.intensidade;

				CorRGB espelhado(1,1,1);

				if(renderizador.cena.profundidadeRaio>0){

					renderizador.cena.profundidadeRaio-=1;

					cor += espelhado*renderizador.colorir(*(new Raio(p , raioRefletido)));

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