
Malha::Malha(){

}

Acerto* Malha::acertar(Raio raio,float tMin,float tMax){
	
	Acerto* acerto = nullptr;

	for(Triangulo t : this->faces){
		
		acerto = t.acertar(raio,tMin,tMax);

		if(acerto!=nullptr){
			return acerto;
		}
	}
	return nullptr;
}