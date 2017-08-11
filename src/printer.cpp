
Printer::Printer(Image& image,std::string type ,std::string file_name){
	
	std::ofstream outfile (file_name);
	
	if(type=="PPM"){
		
		outfile << "P3\n";
		outfile << image.width << " " << image.height << "\n";
		outfile << "255\n";
		for(unsigned int i=0;i<image.height*image.width;i++){
			outfile << image.pixels[i].e[vec3::R] << " " << image.pixels[i].e[vec3::G] << " " << image.pixels[i].e[vec3::B] << "\n";
		}
	}

	outfile.close();
}