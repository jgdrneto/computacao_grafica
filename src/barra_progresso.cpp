BarraProgresso::BarraProgresso(int nTamanho = 40){
	this->tamanho = nTamanho;
}

void BarraProgresso::resetar(){
    this->porcentagem = 0;
    this->tamanho = 0;
}

void BarraProgresso::setDimensao(int nDimensao){
    this->dimensao = nDimensao;
}

void BarraProgresso::incrementar(){
    this->tamanho++;
    int nPorcentagem = (this->tamanho*1.0/this->dimensao*1.0)*100;

    if(nPorcentagem > this->porcentagem){
        this->porcentagem = nPorcentagem;
        imprimir();
    }
}

void BarraProgresso::imprimir() {
           
    std::string barra;

    for(int i = 0; i < 50; i++){
        if( i < (this->porcentagem/2)){
            barra.replace(i,1,"=");
        }else{ 
        	if( i == (this->porcentagem/2)){
            	barra.replace(i,1,">");
        	}else{
            	barra.replace(i,1," ");
        	}
        }	
    }

    std::cout<< "\r" "[" << barra << "] ";
    std::cout.width( 3 );
    std::cout << this->porcentagem << "%     " << std::flush;
}