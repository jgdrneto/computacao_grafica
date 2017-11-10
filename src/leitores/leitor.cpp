json& Leitor::abrirArquivo(std::string arquivo){
		json* j = new json();

		std::ifstream i(arquivo);
	    i >> *j;

	    return *j;
}