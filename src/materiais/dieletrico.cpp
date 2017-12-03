Vetor3 DieletricoMaterial::reflexao(Vetor3 v, Vetor3 n){
    float cosI = - dot(n, v);
    return v + 2*cosI*n;
    //i = v; 
}

bool DieletricoMaterial::refracao(Vetor3 v, Vetor3& n, float ni_over_nt, Vetor3& refratado){

	Vetor3 uv = unit_vector(v);
    float dt = dot(v, n);
    float discriminante =  1.0 - ni_over_nt*ni_over_nt * (1 -dt*dt);
    if(discriminante > 0){
        refratado = ni_over_nt*(v - n*dt) - n*sqrt(discriminante);
        return true;
    }else
        return false;

}

float DieletricoMaterial::schlick(float coseno, float ref_idx){
	float r = (1.f - ref_idx) / (1.f + ref_idx);
    r = r * r;
    return (r + (1.f - r) * std::pow((1.f - coseno), 5.f));
}

void DieletricoMaterial::obterDispersao(Raio& raio, Acerto& acerto,Vetor3& atenuacao, Raio& raioDisperso){

	Vetor3 outward_normal, refratado ;
    float ni_over_nt, reflect_prob, coseno;
    Vetor3 refletido = this->reflexao(raio.getDirecao(), acerto.normal);
    atenuacao = Vetor3(1,1,1);
    
    if(dot(raio.getDirecao(), acerto.normal) > 0){

        outward_normal =-acerto.normal;
        ni_over_nt = indRef;
        coseno = indRef * dot(raio.getDirecao(), acerto.normal) / raio.getDirecao().length();
    
    }else{
        outward_normal = acerto.normal;
        ni_over_nt = 1.0/indRef;
        coseno = -dot(raio.getDirecao(), acerto.normal) / raio.getDirecao().length();
    }

    if(refracao(raio.getDirecao(), outward_normal, ni_over_nt, refratado)){

        reflect_prob = schlick(coseno, ni_over_nt);
        raioDisperso = Raio(acerto.ponto, refratado);
    
    }else{
        reflect_prob = 1.0;
        raioDisperso = Raio(acerto.ponto, refletido);
    }

    if(drand48() <= reflect_prob){
        raioDisperso = Raio(acerto.ponto, refletido);
    }else{
        raioDisperso = Raio(acerto.ponto, refratado);
    }

}