Vetor3 LuzLocal::obterDirecao(Ponto3 ponto){
	Vetor3 dir = this->origem - ponto;

	Vetor3 direcao = this->origem - this->direcao;

	float cosseno = dot(this->direcao, dir) / (direcao.length() * dir.length());

	if(cosseno >=angulo){
		return direcao;
	}else{
		return *(new Vetor3());
	}
}

Vetor3 LuzLocal::obterIntensidade(){
	return this->intensidade;
}