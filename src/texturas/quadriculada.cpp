CorRGB QuadriculadaTextura::valor(float u, float v, const Vetor3& p){
	
	float sines = sin(10*p.x()) * sin(10*p.y()) * sin(10*p.z());
	if(sines < 0){
		return this->cor1;
	}else{
		return this->cor2;
	}
}