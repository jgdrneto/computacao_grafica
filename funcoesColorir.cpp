
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