Sphere::Sphere(point3 n_origin,Material n_material, float n_radius)
{
	this->origin = n_origin;
	this->material = n_material;
	this->radius = n_radius;
}
	
HitRecord* Sphere::hit (Ray ray,float x_value,float y_value){
	HitRecord* hit = nullptr;

	return hit;
}