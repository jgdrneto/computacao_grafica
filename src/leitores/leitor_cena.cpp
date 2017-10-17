#include <iostream>
    
std::vector<Luz*>& LeitorCena::lerLuzes(json j, Cena* cena){
    
    std::vector<Luz*>* luzes = new std::vector<Luz*>();

    for(unsigned int i=0;i<j["LUZES"].size();i++){

        Luz* luz = nullptr;

        if(j["LUZES"][i]["TIPO"]=="AMBIENTE"){

            cena->luzAmbiente = new LuzPontual();

            cena->luzAmbiente->intensidade[CorRGB::R] = j["LUZES"][i]["INTENSIDADE"]["R"];
            cena->luzAmbiente->intensidade[CorRGB::G] = j["LUZES"][i]["INTENSIDADE"]["G"];
            cena->luzAmbiente->intensidade[CorRGB::B] = j["LUZES"][i]["INTENSIDADE"]["B"];        

        }else if(j["LUZES"][i]["TIPO"] == "DIRECIONAL"){

            LuzDirecional* luzD = new LuzDirecional();

            luzD->intensidade[CorRGB::R] = j["LUZES"][i]["INTENSIDADE"]["R"];
            luzD->intensidade[CorRGB::G] = j["LUZES"][i]["INTENSIDADE"]["G"];
            luzD->intensidade[CorRGB::B] = j["LUZES"][i]["INTENSIDADE"]["B"];

            luzD->direcao[Vetor3::X] = j["LUZES"][i]["DIRECAO"]["X"];
            luzD->direcao[Vetor3::Y] = j["LUZES"][i]["DIRECAO"]["Y"];
            luzD->direcao[Vetor3::Z] = j["LUZES"][i]["DIRECAO"]["Z"];            

            luz = luzD;

        }else if(j["LUZES"][i]["TIPO"] == "PONTUAL"){

            LuzPontual* luzP = new LuzPontual();

            luzP->intensidade[CorRGB::R] = j["LUZES"][i]["INTENSIDADE"]["R"];
            luzP->intensidade[CorRGB::G] = j["LUZES"][i]["INTENSIDADE"]["G"];
            luzP->intensidade[CorRGB::B] = j["LUZES"][i]["INTENSIDADE"]["B"];

            luzP->origem[Vetor3::X] = j["LUZES"][i]["ORIGEM"]["X"];
            luzP->origem[Vetor3::Y] = j["LUZES"][i]["ORIGEM"]["Y"];
            luzP->origem[Vetor3::Z] = j["LUZES"][i]["ORIGEM"]["Z"];

            luz = luzP;

        }else if(j["LUZES"][i]["TIPO"] == "LOCAL"){

            LuzLocal* luzL = new LuzLocal();

            luzL->intensidade[CorRGB::R] = j["LUZES"][i]["INTENSIDADE"]["R"];
            luzL->intensidade[CorRGB::G] = j["LUZES"][i]["INTENSIDADE"]["G"];
            luzL->intensidade[CorRGB::B] = j["LUZES"][i]["INTENSIDADE"]["B"];

            luzL->origem[Vetor3::X] = j["LUZES"][i]["ORIGEM"]["X"];
            luzL->origem[Vetor3::Y] = j["LUZES"][i]["ORIGEM"]["Y"];
            luzL->origem[Vetor3::Z] = j["LUZES"][i]["ORIGEM"]["Z"];

            luzL->direcao[Vetor3::X] = j["LUZES"][i]["DIRECAO"]["X"];
            luzL->direcao[Vetor3::Y] = j["LUZES"][i]["DIRECAO"]["Y"];
            luzL->direcao[Vetor3::Z] = j["LUZES"][i]["DIRECAO"]["Z"];

            luzL->angulo = j["LUZES"][i]["ANGULO"];

            luz = luzL;

        }else{
            luz = nullptr;
        }

        if(luz !=nullptr){
            luzes->push_back(luz);
        }
        
    }

    return *(luzes);
}

Cena& LeitorCena::lerCena(std::string nomeArquivo){
    
    json j = Leitor::abrirArquivo(nomeArquivo);

    Cena* cena = new Cena();

    cena->nome = j["NOME"];
    cena->tipo = j["TIPO"];
    cena->codificacao = j["CODIFICACAO"];
    cena->largura = j["LARGURA"];
    cena->altura = j["ALTURA"];

    cena->superiorEsquerdo[CorRGB::R] = j["SUP_ESQUERDO"]["R"];
    cena->superiorEsquerdo[CorRGB::G] = j["SUP_ESQUERDO"]["G"]; 
    cena->superiorEsquerdo[CorRGB::B] = j["SUP_ESQUERDO"]["B"];
    
    cena->superiorDireito[CorRGB::R] = j["SUP_DIREITO"]["R"];
    cena->superiorDireito[CorRGB::G] = j["SUP_DIREITO"]["G"]; 
    cena->superiorDireito[CorRGB::B] = j["SUP_DIREITO"]["B"];

    cena->inferiorEsquerdo[CorRGB::R] = j["INF_ESQUERDO"]["R"];
    cena->inferiorEsquerdo[CorRGB::G] = j["INF_ESQUERDO"]["G"]; 
    cena->inferiorEsquerdo[CorRGB::B] = j["INF_ESQUERDO"]["B"];
    
    cena->inferiorDireito[CorRGB::R] = j["INF_DIREITO"]["R"];
    cena->inferiorDireito[CorRGB::G] = j["INF_DIREITO"]["G"]; 
    cena->inferiorDireito[CorRGB::B] = j["INF_DIREITO"]["B"];
    
    cena->primeiroPlano[CorRGB::R] = j["PRI_PLANO"]["R"];
    cena->primeiroPlano[CorRGB::G] = j["PRI_PLANO"]["G"];
    cena->primeiroPlano[CorRGB::B] = j["PRI_PLANO"]["B"];

    cena->ultimoPlano[CorRGB::R] = j["ULT_PLANO"]["R"];
    cena->ultimoPlano[CorRGB::G] = j["ULT_PLANO"]["G"];
    cena->ultimoPlano[CorRGB::B] = j["ULT_PLANO"]["B"];

    cena->profundidadeMaxima = j["PRO_MAXIMA"];

    cena->amostras = j["AMOSTRAS"];

    cena->profundidadeRaio = j["PRO_RAIO"];

    cena->gama = j["GAMA"];

    cena->luzes = lerLuzes(j, cena);

    return *(cena);
}
