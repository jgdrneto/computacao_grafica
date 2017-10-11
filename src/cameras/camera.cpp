
Camera::Camera(){
	//NULL
}

Camera::Camera(Ponto3& nCie, Vetor3& nHorizontal,Vetor3& nVertical,Ponto3& nOrigem){
	this->canto_inferior_esquerdo = nCie;
	this->horizontal = nHorizontal;
	this->vertical = nVertical;
	this->origem = nOrigem;
}
