Vetor3 LuzLocal::obterDirecao(Ponto3 ponto){
	Vetor3 direcao = this->origem - ponto;

	float cosseno = dot(-this->direcao, direcao) / ((-this->direcao).length() * direcao.length());

	if(cosseno >=angulo){
		return direcao;
	}else{
		return *(new Vetor3());
	}
}

Vetor3 LuzLocal::obterIntensidade(){
	return this->intensidade;
}