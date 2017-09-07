
Vetor3 aleatoriaNaEsfera(){
	Vetor3 p;

	do{
		p = 2.0*Vetor3(drand48(),drand48(),drand48()) - Vetor3(1,1,1);
	}while(dot(p,p)>=1.0);

	return p;
}

//Função para quando acertar um objeto
CorRGB acertarObjetos(Raio& raio, Renderizador& renderizador, Acerto& acerto){

	Vetor3 alvo = acerto.ponto + acerto.normal + aleatoriaNaEsfera();

	return 0.5*renderizador.colorir( *(new Raio(acerto.ponto, alvo - acerto.ponto)));
}

//Função para quando não acertar um objeto
CorRGB nAcertarObjetos(Raio& raio,Renderizador& renderizador, Acerto& acerto){
	
	CorRGB top (0.5, 0.7, 1 );
    CorRGB bottom(1,1,1);

    Vetor3 unit_ray = unit_vector(raio.getDirecao());
    float t = 0.5*(unit_ray.y()+1.0);
    return (1-t)*bottom+t*top;
}

//=======================================================================

//BlinFound shader

//=======================================================================

float max(float a, float b){
	if(a>b){
		return a;
	}
	
	return b;
}

CorRGB normalizarMinMax(CorRGB c){
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

CorRGB blinnFoundObjetos(Raio& raio, Renderizador& renderizador, Acerto& acerto){

	Lambertiano *lambertiano = (Lambertiano*)acerto.material;
	
	Vetor3 ks = lambertiano->especular;
	float p = lambertiano->expoenteEspecular;
	Vetor3 ia = lambertiano->ambiente;
	Vetor3 kd = lambertiano->difuso;
	Vetor3 N = acerto.normal;
	Vetor3 ka = renderizador.cena.luzesAmbientes[0].intensidade;
	Luz luz = renderizador.cena.luzDirecional;

	CorRGB c1, c2;

	Vetor3 halfDir = unit_vector(unit_vector(luz.direcao) - raio.getDirecao());
	float especular = max(0.0, dot(halfDir, acerto.normal));
	
	especular = pow(especular, p);
		
	c1 += (kd * dot(unit_vector(luz.direcao  - N), acerto.normal)) * luz.intensidade;
	c2 += ks * especular * luz.intensidade; 

	CorRGB c0 = ka*ia;

	return normalizarMinMax(c0+c1+c2);	
}		
