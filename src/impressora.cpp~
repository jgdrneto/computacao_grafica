
Impressora::Impressora(Imagem& imagem,std::string tipo ,std::string nomeArquivo){
	
	std::ofstream arquivo (nomeArquivo);
	
	if(tipo=="PPM"){
		
		arquivo << "P3\n";
		arquivo << imagem.largura << " " << imagem.altura << "\n";
		arquivo << "255\n";
		for(unsigned int i=0;i<imagem.altura*imagem.altura;i++){
			arquivo << imagem.pixeis[i].e[CorRGB::R] << " " << imagem.pixeis[i].e[CorRGB::G] << " " << imagem.pixeis[i].e[CorRGB::B] << "\n";
		}
	}

	arquivo.close();
}
