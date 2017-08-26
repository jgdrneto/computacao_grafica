Esfera::Esfera(Ponto3 nOrigem,Material nMaterial, float nR)
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
    auto b = dot(oc, raio.getDirecao());
    auto c = dot(oc, oc) - this->r*this->r;

    float descriminante = b*b - a*c;

    float temp=0;

    if(descriminante > 0){

    	temp = (-b -sqrt(b*b-a*c))/a;

    	if(temp < tMax && temp>tMin){

            acerto = new Acerto();

    	   	acerto->t = temp;
    		acerto->ponto = raio.apontar(acerto->t);	
    		acerto->normal = (acerto->ponto - this->origem)/this->r;
    	    
            return acerto;   
        }	

    	temp = (-b +sqrt(b*b-a*c))/a;

    	if(temp < tMax && temp>tMin){
    		
            Acerto* acerto = new Acerto();

            acerto->t = temp;
            acerto->ponto = raio.apontar(acerto->t);    
            acerto->normal = (acerto->ponto - this->origem)/this->r;
            
            return acerto;  
        }	
    	
	}

	return acerto;
}