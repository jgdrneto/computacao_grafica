Esfera::Esfera(Ponto3 nOrigem,Material* nMaterial, float nR)
{
	this->origem = nOrigem;
	this->material = nMaterial;
	this->r = nR;
}

Esfera::Esfera(){
    //NULL
}
	
Acerto* Esfera::acertar(Raio raio,float tMin,float tMax){

    Acerto* acerto = nullptr;

    auto oc = raio.getOrigem() - this->origem;
    auto a = dot(raio.getDirecao(), raio.getDirecao());
    auto b = 2 * dot(oc, raio.getDirecao());
    auto c = dot(oc, oc) - this->r*this->r;

    float delta = b*b - 4 * a*c;

    if(delta > 0){

    	float t = (-b -sqrt(delta))/(2*a);

    	if(t < tMax && t>tMin){

            acerto = new Acerto();

    	   	acerto->t = t;
    		acerto->ponto = raio.apontar(acerto->t);	
    		acerto->normal = (acerto->ponto - this->origem)/this->r;
    	    acerto->material = this->material;
            return acerto;   
        }	
	}

	return acerto;
}