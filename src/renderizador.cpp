Renderizador::Renderizador(){
    //NULL
}

Renderizador::Renderizador(Cena& nCena){
    /*
    this->cena = nCena;

    //Make camera

    Ponto3* canto_inferior_esquerdo =  new Ponto3( -2, -1, -1 ); // lower left corner of the view plane.
    Vetor3* horizontal =  new Vetor3( 4, 0, 0 ); // Horizontal dimension of the view plane.
    Vetor3* vertical =  new Vetor3(0, 2, 0); // Vertical dimension of the view plane.
    Ponto3* origem = new Ponto3(0, 0, 0); // the camera's origin.

    this->camera = *(new Camera(*canto_inferior_esquerdo,*horizontal,*vertical,*origem));

    //Criando objetos na cena

    Esfera* esfera = new Esfera(Ponto3(0,0,-1),Material(),0.5f);

    this->cena.objetos.push_back(esfera);
    */
}

CorRGB colorSphere(Raio& raio, Cena& cena){
    
    CorRGB top (0.5, 0.7, 1 );
    CorRGB bottom(1,1,1);

    Acerto* acerto = cena.acertarObjetos(raio,0,cena.profundidadeMaxima);

    if(acerto!=nullptr){
        return 0.5*Vetor3(acerto->normal.x()+1,acerto->normal.y()+1,acerto->normal.z()+1);
    }else{
        Vetor3 unit_ray = unit_vector(raio.getDirecao());
        float t = 0.5*(unit_ray.y()+1.0);
        return (1-t)*bottom+t*top;
    }

}

Imagem& Renderizador::criarImagem(CorRGB (*colorir)(Raio&,Cena&)){
    
    Imagem* imagem = new Imagem(this->cena.largura,this->cena.altura);

    int cont=0;

    for ( auto row{this->cena.altura-1} ; row >= 0 ; --row ) // Y
    {
        for( auto col{0} ; col < this->cena.largura ; col++ ) // X
        {   
            CorRGB somaCores(0,0,0);

            for(int i=0;i<cena.amostras;i++)
            {
                // Determine how much we have 'walked' on the image: in [0,1]
                auto u = float(col + drand48()) / float( this->cena.largura ); // walked u% of the horizontal dimension of the view plane.
                auto v = float(row + drand48()) / float( this->cena.altura ); // walked v% of the vertical dimension of the view plane.

                // Determine the ray's direction, based on the pixel coordinate (col,row).
                // We are mapping (matching) the view plane (vp) to the image.
                // To create a ray we need: (a) an origin, and (b) an end point.
                //
                // (a) The ray's origin is the origin of the camera frame (which is the same as the world's frame).
                //
                // (b) To get the end point of ray we just have to 'walk' from the
                // vp's origin + horizontal displacement (proportional to 'col') +
                // vertical displacement (proportional to 'row').
                Ponto3 end_point = this->camera.canto_inferior_esquerdo + u*this->camera.horizontal + v*this->camera.vertical ;
                // The ray:
                Raio r( this->camera.origem, end_point - this->camera.origem );

                // Determine the color of the ray, as it travels through the virtual space.
                somaCores+=colorir( r ,this->cena);
            }

                CorRGB c = somaCores/cena.amostras;

                int ir = int( 255.99f * c[CorRGB::R] );
                int ig = int( 255.99f * c[CorRGB::G] );
                int ib = int( 255.99f * c[CorRGB::B] );

                imagem->pixeis[cont++] = *(new CorRGB(ir,ig,ib));
        }
    }

    return *(imagem);
}
/*
CorRGB color(Raio& r_, Cena& cena)
{	
	
	CorRGB upper_left = cena.superiorEsquerdo;
	CorRGB upper_right = cena.superiorDireito;
	CorRGB lower_left = cena.inferiorEsquerdo;
	CorRGB lower_right = cena.inferiorDireito;

	
    CorRGB top (0.5, 0.7, 1 );
    CorRGB bottom(1,1,1);
    
    if(hit_sphere(r_, Ponto3(0.5,0,-1), 0.2))
        return CorRGB(1,0,0);

    if(hit_sphere(r_, Ponto3(0,0,-1), 0.2))
        return CorRGB(1,0,0);

    if(hit_sphere(r_, Ponto3(-0.5,0,-1), 0.2))
        return CorRGB(1,0,0);
	
    auto unit_ray = r_.getDirecao();

    auto unit_ray_y = unit_ray.y();
    auto unit_ray_x = unit_ray.x();

    auto t = 0.5*(unit_ray_y)+0.5;
    auto u = 0.25*(unit_ray_x)+0.5;

    CorRGB result = (lower_left*(1-t)*(1-u) +
    			  upper_left*t*(1-u) +
    			  lower_right*(1-t)*(u) +
    			  upper_right*t*u 	
    			  );

    // TODO: determine the background color, which is an linear interpolation between bottom->top.
    // The interpolation is based on where the ray hits the background.
    // Imagine that the background is attached to the view-plane; in other words,
    // the virtual world we want to visualize is empty!

    return result; // Stub, replace it accordingly
    
}
*/
/*
Image& Renderizador::createILImage(){
	
	Image* image = new Image(this->scene.width,scene.height);

	int cont=0;

	for ( auto row{this->scene.height-1} ; row >= 0 ; --row ) // Y
    {
        for( auto col{0} ; col < this->scene.width ; col++ ) // X
        {
            // Determine how much we have 'walked' on the image: in [0,1]
            auto u = float(col) / float( this->scene.width ); // walked u% of the horizontal dimension of the view plane.
            auto v = float(row) / float( this->scene.height ); // walked v% of the vertical dimension of the view plane.

            // Determine the ray's direction, based on the pixel coordinate (col,row).
            // We are mapping (matching) the view plane (vp) to the image.
            // To create a ray we need: (a) an origin, and (b) an end point.
            //
            // (a) The ray's origin is the origin of the camera frame (which is the same as the world's frame).
            //
            // (b) To get the end point of ray we just have to 'walk' from the
            // vp's origin + horizontal displacement (proportional to 'col') +
            // vertical displacement (proportional to 'row').
            point3 end_point = this->camera.lower_left_corner + u*this->camera.horizontal + v*this->camera.vertical ;
            // The ray:
            Raio r( this->camera.origin, end_point - this->camera.origin );

            // Determine the color of the ray, as it travels through the virtual space.
            auto c = color( r ,this->scene);
  
            int ir = int( 255.99f * c[rgb::R] );
            int ig = int( 255.99f * c[rgb::G] );
            int ib = int( 255.99f * c[rgb::B] );
			
            //std::cout << ir << " " << ig << " " << ib << "\n";

			image->pixels[cont++] = *(new rgb(ir,ig,ib));
        }
    }

    return *(image);
}            

//=====================================================================================================
*/
/*  
 * Returns de Z component, if the ray hits the sphere, or infinity otherwise  
 *  
 * TODO: only works with a 2D sphere  
 */
/*  
float hit_sphere_z ( const Raio & r_, const point3 & c_, float radius_ )
{  
    // First, manipulate the 1), 2) and 3) line to create the 4) equation   
    // 1) (point - center) * (point - center) - radius² = 0     
    // 2) point == ray  // 3) ray(t) = origin + direction*t     
    // 4) d*d*t² + 2(origin - center)*d*t + (origin - center)*(origin - center) - radius² = 0   
    
    // Second, calculate the a, b and c from the equation 4) (a*t² + b*t + c = 0)   
    auto oc = r_.get_origin() - c_; // (origin - center)    
    
    auto a = dot( r_.get_direction(), r_.get_direction() );   // d*d  
    auto b = 2 * dot( oc, r_.get_direction() );               // 2(origin - center)*d
    auto c = dot(oc, oc) - (radius_ * radius_);               // (origin - center)*(origin - center) - radius²

    // Third, calculate the delta (b² - 4ac)    
    auto delta = b * b - 4 * a * c;     

    // Last, return the t component if the ray hit the sphere 
    if (delta >= 0){
        auto t = (-b - sqrt(delta))/(2*a);
        return t;   
    }

    // or return infinity otherwise
    return std::numeric_limits<float>::infinity(); 
} 

rgb colorSpheres(const Raio & r_, Cena& scene){

    rgb top (0.5, 0.7, 1 );
    rgb bottom(1,1,1);
    
    Sphere spheres[] = {
        Sphere(point3(0,-100.5, -3),Material(), 99.f),
        Sphere(point3(0.3,0, -1),Material(), 0.4),
        Sphere(point3(0,1, -2),Material(), 0.6),
        Sphere(point3(-0.4,0, -3),Material(), 0.7)
    };
    bool hit_any_sphere=false;
    float t_min =  std::numeric_limits<float>::infinity();
    float t_valor;
    vec3 normal;

    for(Sphere s : spheres){
        if(hit_sphere(r_,s.origin,s.radius)){
            
            t_valor = hit_sphere_z(r_,s.origin,s.radius);

            if(t_valor<t_min && t_valor>0){
                hit_any_sphere =true;
                t_min = t_valor;
                normal = unit_vector(r_.point_at(t_valor)-s.origin);
            }
        }
    }

    if(hit_any_sphere==true){
        
        float d=0;

        if(t_min>0 && t_min<=scene.max_depth){
            d = t_min/scene.max_depth;
        }else{
            d = 1;
        }

        //std:: cout << "Valor de d: " << d << std::endl; 

        return scene.foreground_depth*(1-d) + scene.background_depth*d;

    }

    return scene.background_depth;   
}

Image& Renderizador::createSpheresImage(){
    
    Image* image = new Image(this->scene.width,scene.height);

    int cont=0;

    for ( auto row{this->scene.height-1} ; row >= 0 ; --row ) // Y
    {
        for( auto col{0} ; col < this->scene.width ; col++ ) // X
        {
            // Determine how much we have 'walked' on the image: in [0,1]
            auto u = float(col) / float( this->scene.width ); // walked u% of the horizontal dimension of the view plane.
            auto v = float(row) / float( this->scene.height ); // walked v% of the vertical dimension of the view plane.

            // Determine the ray's direction, based on the pixel coordinate (col,row).
            // We are mapping (matching) the view plane (vp) to the image.
            // To create a ray we need: (a) an origin, and (b) an end point.
            //
            // (a) The ray's origin is the origin of the camera frame (which is the same as the world's frame).
            //
            // (b) To get the end point of ray we just have to 'walk' from the
            // vp's origin + horizontal displacement (proportional to 'col') +
            // vertical displacement (proportional to 'row').
            point3 end_point = this->camera.lower_left_corner + u*this->camera.horizontal + v*this->camera.vertical ;
            // The ray:
            Raio r( this->camera.origin, end_point - this->camera.origin );

            // Determine the color of the ray, as it travels through the virtual space.
            auto c = colorSpheres( r ,this->scene);
  
            int ir = int( 255.99f * c[rgb::R] );
            int ig = int( 255.99f * c[rgb::G] );
            int ib = int( 255.99f * c[rgb::B] );
            
            //std::cout << ir << " " << ig << " " << ib << "\n";

            image->pixels[cont++] = *(new rgb(ir,ig,ib));
        }
    }

    return *(image);
}            
*/
