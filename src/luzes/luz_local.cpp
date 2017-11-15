Vetor3 LuzLocal::obterDirecao(Ponto3 ponto){
	Vetor3 dir = this->origem - ponto;

	Vetor3 direcaoV = this->origem - this->direcao;

	float cosseno = dot(direcaoV, dir) / (direcaoV.length() * dir.length());

	//std::cout << "Cosseno: " << cosseno << std::endl; 

	if(cosseno>=this->angulo){
		return dir;
	}else{
		return *(new Vetor3(0,0,0));
	}
}

Vetor3 LuzLocal::obterIntensidade(){
	return this->intensidade;
}