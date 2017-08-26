Esfera::Esfera(Ponto3 nOrigem,Material nMaterial, float nR)
{
	this->origem = nOrigem;
	this->material = nMaterial;
	this->r = nR;
}
	
Acerto* Esfera::acertar (Raio raio,float tMin,float tMax){
	Acerto* acerto = nullptr;

	auto oc = raio.getOrigem() - this->origem;
    auto a = dot(raio.getDirecao(), raio.getDirecao());
    auto b = dot(oc, raio.getDirecao());
    auto c = dot(oc, oc) - (this->r*this->r);

    float descriminante = b*b - a*c;

    if(descriminante >0){

    	acerto = new Acerto();

    	float temp = (-b - sqrt(b*b-a*c)/a);

    	if(temp < tMax && temp>tMin){

    		acerto->t = temp;
    		acerto->ponto = raio.apontar(temp);	
    		acerto->normal = (acerto->ponto - this->origem)/this->r;
    	}	

    	temp = (-b +sqrt(b*b-a*c))/a;

    	if(temp < tMax && temp>tMin){

    		acerto->t = temp;
    		acerto->ponto = raio.apontar(temp);	
    		acerto->normal = (acerto->ponto - this->origem)/this->r;
    	}	
    	
	}

	return acerto;
}