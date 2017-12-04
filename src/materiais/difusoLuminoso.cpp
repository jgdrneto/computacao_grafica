Vetor3 DifusoLuminosoMaterial::obterEmissaoLuz(float u, float v, Vetor3& p){
    return this->textura->valor(u,v,p);
}