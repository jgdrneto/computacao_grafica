Triangulo::Triangulo()
{
	this->origem = Ponto3(0,0,0);
}

	
Acerto* Triangulo::acertar(Raio raio,float tMin,float tMax){

    Acerto* acerto = nullptr;

    Vetor3 e1, e2, h, s, q;
    float det,det_inv,u,v;
 
    e1 = (this->v1 - this->v0);
    e2 = (this->v2 - this->v0);

    h = cross(raio.getDirecao(), e2);

    det = dot(e1, h);

    if(this->apagarCostas){

        if (det < 0.00001){
            return nullptr;
        }

        s =  raio.getOrigem() - this->v0;

        u = dot(s, h);

        if (u < 0.0 || u > det){
            return nullptr;
        }

        q = cross(s, e1);
        v = dot(raio.getDirecao(), q);
    
        if (v < 0.0 || u + v > det){
            return nullptr;
        }
        
        det_inv = 1.0/det;

        float t = det_inv * dot(e2, q);

        t*=det_inv;
        u*=det_inv;
        v*=det_inv;

        if(t <= tMax && t>0.00001){

            acerto = new Acerto();

            acerto->t = t;
            acerto->ponto = raio.apontar(t);    
            acerto->normal = unit_vector(cross(e1,e2));
            acerto->material = this->material;

            return acerto;
        }else{
            return nullptr;
        }    
           
    }else{

        if (det > -0.0001 && det < 0.0001){
            return nullptr;
        }

        det_inv = 1.0/det;

        s =  raio.getOrigem() - this->v0;

        u = det_inv * dot(s, h);

        if (u < 0.0 || u > 1.0){
            return nullptr;
        }

        q = cross(s, e1);
        v = det_inv * dot(raio.getDirecao(), q);
        
        if (v < 0.0 || u + v > 1.0){
            return nullptr;
        }
        
        float t = det_inv * dot(e2, q);

        if(t <= tMax && t>0.0001){

            acerto = new Acerto();

            acerto->t = t;
            acerto->ponto = raio.apontar(acerto->t);    
            acerto->normal = unit_vector(cross(e1,e2));
            acerto->material = this->material;
            
            return acerto;   
        }else{
            return nullptr;
        }

    }
}