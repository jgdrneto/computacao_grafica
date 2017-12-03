
Plano::Plano(){

}

Acerto* Plano::acertar(Raio raio,float tMin,float tMax){
	
	Acerto* acerto = nullptr;

	for(Triangulo t : this->triangulos){
		
		acerto = t.acertar(raio,tMin,tMax);

		if(acerto!=nullptr){
			return acerto;
		}
	}
	return nullptr;
}