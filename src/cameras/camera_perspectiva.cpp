CameraPerspectiva::CameraPerspectiva(Ponto3& o, Ponto3& distancia, Vetor3& vup, float foco, float aspecto, float abertura, float distanciaFocal){
	this->origem = origem;

	this->w = unit_vector(o - distancia);
	this->u = unit_vector(cross(vup,w));
	this->v = cross(w,u);

	this->raioLente = abertura/2;

	float theta = foco * M_PI/180;

	float meiaAltura = tan(theta/2);
	float meiaLargura = aspecto * meiaAltura;

	this->canto_inferior_esquerdo = o - meiaLargura * distanciaFocal * u - meiaAltura * distanciaFocal * v - w * distanciaFocal;
	this->horizontal = 2 * meiaLargura * distanciaFocal * u;
	this->vertical = 2 * meiaAltura * distanciaFocal * v;
}

/*
 * Gera um raio aleatório
 */
Vetor3 random_in_unit_sphere()
{
    Vetor3 p;
    do {
        p = 2.0*Vetor3(drand48(),drand48(),0) - Vetor3(1,1,0);
    }while(dot(p,p) >= 1.0);
    return p;
}

Raio CameraPerspectiva::obterRaio(float u, float v){

	Vetor3 rd = this->raioLente * random_in_unit_sphere();
	Vetor3 foraConjunto = this->u * rd.x() + this->v * rd.y();
	
	Ponto3 pontoFinal = this->canto_inferior_esquerdo + this->u * this->horizontal + this->v * this->vertical;

	return *(new Raio(this->origem + foraConjunto, pontoFinal - this->origem - foraConjunto));

}