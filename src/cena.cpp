Cena::Cena():
nome("Nulo"),
tipo("PPM"),
codificacao("ascii"),
largura(0),
altura(0),
amostras(1),
profundidadeMaxima(10)
{
	//NULL
}

Acerto* Cena::acertarObjetos(Raio& raio, float tMin, float tMax){
	
	Acerto* tempAcerto = nullptr;
	Acerto* acerto = nullptr;

	double tDec = tMax;

	for(unsigned int i=0;i<this->objetos.size();i++){
		
		tempAcerto = this->objetos[i]->acertar(raio,tMin,tDec);

		if(tempAcerto!=nullptr){
			
			tDec = tempAcerto->t;

			acerto = tempAcerto;
			
		}
	}

	return acerto;
}