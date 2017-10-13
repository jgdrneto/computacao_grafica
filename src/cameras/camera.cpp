
Camera::Camera(){
	//NULL
}

Camera::Camera(Ponto3& nCie, Vetor3& nHorizontal,Vetor3& nVertical,Ponto3& nOrigem){
	this->canto_inferior_esquerdo = nCie;
	this->horizontal = nHorizontal;
	this->vertical = nVertical;
	this->origem = nOrigem;
}

Raio Camera::obterRaio(float u, float v){

	Ponto3 ponto_fim = this->canto_inferior_esquerdo + u*this->horizontal + v*this->vertical ;
   
    return *(new Raio(this->origem, ponto_fim - this->origem ));

}