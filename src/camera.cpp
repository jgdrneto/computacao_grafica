
Camera::Camera(){
	//NULL
}

Camera::Camera(point3& n_llc,vec3& n_horizontal,vec3& n_vertical,point3& n_origin){
	this->lower_left_corner = n_llc;
	this->horizontal = n_horizontal;
	this->vertical = n_vertical;
	this->origin = n_origin;
}