namespace Toon{
	
	#define PI 3.14159265
	#define anguloBorda fabs(cos(80 * PI / 180.0))

	CorRGB acertarObjetos(Raio& raio, Renderizador& renderizador, Acerto& acerto){

        CorRGB hue;
        Vetor3 l;
        double coseno_N_raio;
        double coseno_N_luz;

        //Calcula o coseno do angulo entre a normal do vetor e o raio da câmera
        // dot(N * D) = |N|*|D|*cosϴ
        coseno_N_raio = dot( acerto.normal, raio.getDirecao() )/( acerto.normal.length() * raio.getDirecao().length());

        // Cria a borda
        if (fabs(coseno_N_raio) <= anguloBorda)
        {               
            return CorRGB(0,0,0);             
        }

        ToonMaterial* toonM = (ToonMaterial*)acerto.material;

        //Obtem o tamanho do vetor de angulos
        int tamAngulos = toonM->angulos.size();

        //Posição atual da cor escolhida                            
        int posicaoAnguloEscolhida = tamAngulos;

        //Verifica se o pixel está na sombra
        bool sombra = false;

        //Conta o número de sombras que o pixel tem
        int contSombra = 1;

        for(Luz* luz : renderizador.cena.luzes){

            Acerto* acerto2 = renderizador.cena.acertarObjetos(*(new Raio(acerto.ponto,luz->obterDirecao(acerto.ponto))),0.001f,renderizador.cena.profundidadeMaxima);

            if(acerto2==NULL){

                //Direçao da luz normalizada
                l = luz->obterDirecao(acerto.ponto) - raio.getDirecao();
                
            	coseno_N_luz = dot( acerto.normal, l)/(acerto.normal.length() * l.length());

            	//Checa se o angulo entá entre os outros intervalos
                for (int j = tamAngulos-1; j >= 0; --j)
            	{  
                    
                    //Se ele esta entre o primeiro intervalo, o pixel é colorido com a primeira cor
                    if (j==0 && (coseno_N_luz >= toonM->angulos[0]))
                    {

                        if (posicaoAnguloEscolhida > j )
                        { 
                    
                            posicaoAnguloEscolhida = j;

                            hue = toonM->gradientes[j]; 
                        }
                    }
                    //Se o angulo que a luz acerta o objeto é menos que o angulo do angulo desejado
                    else if( coseno_N_luz >= toonM->angulos[j] &&
                             coseno_N_luz <= toonM->angulos[j-1] )
                    {
                        //Se a atual luz é forte e o angulo é menor 
                        if (posicaoAnguloEscolhida > j )
                        { 
                            posicaoAnguloEscolhida = j;

                            hue = toonM->gradientes[j]; 
                        }
        	    	}
            	}
            }else{

                sombra = true;
                contSombra++;
            }
        }

        if (sombra) {
            return hue/(renderizador.cena.luzes.size() * contSombra);
        }else{
            return hue/renderizador.cena.luzes.size();
        }

	}

	CorRGB nAcertarObjetos(Raio& raio,Renderizador& renderizador, Acerto& acerto){
		CorRGB top (0.5, 0.7, 1 );
	    CorRGB bottom(1,1,1);

	    Vetor3 unit_ray = unit_vector(raio.getDirecao());
	    float t = 0.5*(unit_ray.y()+1.0);
	    return (1-t)*bottom+t*top;
	}

}