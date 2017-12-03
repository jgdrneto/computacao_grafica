void LambertianoMaterial::obterDispersao(Raio& raio, Acerto& acerto,Vetor3& atenuacao, Raio& raioDisperso){
	Vetor3 ponto = random_in_unit_sphere();
    Vetor3 alvo = acerto.ponto + acerto.normal + ponto;
    raioDisperso = Raio(acerto.ponto, alvo - acerto.ponto);
    atenuacao = this->textura->valor(0,0, acerto.ponto);
}

Vetor3 LambertianoMaterial::random_in_unit_sphere(){
    Vetor3 p;
    do {
        p = 2.0*Vetor3(drand48(),drand48(),drand48()) - Vetor3(1,1,1);
    }while(dot(p,p) >= 1.0);
    return p;
}	