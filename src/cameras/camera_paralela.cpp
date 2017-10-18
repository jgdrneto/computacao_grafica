
CameraParalela::CameraParalela(Ponto3& o, Ponto3& distancia, Vetor3& vup, float esquerda, float direita, float abaixo, float acima){
		this->origem = o; 

        this->w = unit_vector(o -  distancia);
        this->u = unit_vector(cross(vup, w));
        this->v = cross(w,u);

        this->canto_inferior_esquerdo = Ponto3(esquerda, abaixo, o.z());
		this->horizontal = Vetor3(direita - esquerda,0,0);
		this->vertical = Vetor3(0, acima - abaixo,0);
}		

Raio CameraParalela::obterRaio(float u, float v){
	
	return *(new Raio(this->canto_inferior_esquerdo + u* this->horizontal + v * this->vertical,-w));	
}