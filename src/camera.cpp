
Camera::Camera(){
	//NULL
}

Camera::Camera(POnto3& nCie, Vetor3& nHorizontal,Vetor3& nVertical,point3& nOrigem){
	this->canto_inferior_esquerdo = nCie;
	this->horizontal = nHorizontal;
	this->vertical = nVertical;
	this->origem = nOrigem;
}
