Renderer::Renderer(Scene& n_Scene){
	this->scene = n_Scene;

	//Make camera

	point3* lower_left_corner =  new point3( -2, -1, -1 ); // lower left corner of the view plane.
    vec3* horizontal =  new vec3( 4, 0, 0 ); // Horizontal dimension of the view plane.
    vec3* vertical =  new vec3(0, 2, 0); // Vertical dimension of the view plane.
    point3* origin = new point3(0, 0, 0); // the camera's origin.

    this->camera = *(new Camera(*lower_left_corner,*horizontal,*vertical,*origin));

}

bool hit_sphere( const Ray & r_, const point3 & c_, float radius_){
    auto oc = r_.get_origin() - c_;
    auto a = dot(r_.get_direction(), r_.get_direction());
    auto b = 2 * dot(oc, r_.get_direction());
    auto c = dot(oc, oc) - (radius_* radius_);

    return (b*b - 4*a*c) >=0;

}

rgb colorSphere(const Ray & r_, Scene& scene){
    rgb top (0.5, 0.7, 1 );
    rgb bottom(1,1,1);
    
    if(hit_sphere(r_, point3(0.5,0,-1), 0.5)){
        return rgb(1,0,0);
    }

    auto unit_ray = unit_vector(r_.get_direction());

    auto unit_ray_y = unit_ray.y();

    auto t = 0.5*(unit_ray_y+1);

    rgb result = bottom*(1-t)+top*t;

    // TODO: determine the background color, which is an linear interpolation between bottom->top.
    // The interpolation is based on where the ray hits the background.
    // Imagine that the background is attached to the view-plane; in other words,
    // the virtual world we want to visualize is empty!

    return result; // Stub, replace it accordingly
}

Image& Renderer::createSphImage(){
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
            Ray r( this->camera.origin, end_point - this->camera.origin );

            // Determine the color of the ray, as it travels through the virtual space.
            auto c = colorSphere( r ,this->scene);
  
            int ir = int( 255.99f * c[rgb::R] );
            int ig = int( 255.99f * c[rgb::G] );
            int ib = int( 255.99f * c[rgb::B] );
            
            //std::cout << ir << " " << ig << " " << ib << "\n";

            image->pixels[cont++] = *(new rgb(ir,ig,ib));
        }
    }

    return *(image);
}

rgb color( const Ray & r_, Scene& scene)
{	

	rgb upper_left = scene.upper_left/255;
	rgb upper_right = scene.upper_right/255;
	rgb lower_left = scene.lower_left/255;
	rgb lower_right = scene.lower_right/255;

	/*
    rgb top (0.5, 0.7, 1 );
    rgb bottom(1,1,1);
    
    if(hit_sphere(r_, point3(0.5,0,-1), 0.2))
        return rgb(1,0,0);

    if(hit_sphere(r_, point3(0,0,-1), 0.2))
        return rgb(1,0,0);

    if(hit_sphere(r_, point3(-0.5,0,-1), 0.2))
        return rgb(1,0,0);
	*/
    auto unit_ray = r_.get_direction();

    auto unit_ray_y = unit_ray.y();
    auto unit_ray_x = unit_ray.x();

    auto t = 0.5*(unit_ray_y)+0.5;
    auto u = 0.25*(unit_ray_x)+0.5;

    rgb result = (lower_left*(1-t)*(1-u) +
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

Image& Renderer::createILImage(){
	
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
            Ray r( this->camera.origin, end_point - this->camera.origin );

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



