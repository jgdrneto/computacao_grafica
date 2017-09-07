
void Impressora::salvarImagem(Imagem& imagem,std::string tipo ,std::string nomeArquivo){
	
	std::stringstream ss;

	ss << nomeArquivo << "." << tipo;

	std::ofstream arquivo (ss.str());
	
	if(tipo=="ppm"){
		
		arquivo << "P3\n";
		arquivo << imagem.largura << " " << imagem.altura << "\n";
		arquivo << "255\n";
		for(unsigned int i=0;i<imagem.largura*imagem.altura;i++){
			arquivo << imagem.pixeis[i].e[CorRGB::R] << " " << imagem.pixeis[i].e[CorRGB::G] << " " << imagem.pixeis[i].e[CorRGB::B] << "\n";
		}
	}

	arquivo.close();
}
