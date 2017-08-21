#ifndef _SCENE_H_
#define _SCENE_H_

#include <string>

#include "Vetor.h"

class Cena {
    
    public:
        // Image name
        std::string nome;
        // Image type
        std::string tipo;
        // Image codification
        std::string codificacao;
        // Image width
        int largura;
        // Image height
        int altura;

        //Values of pixels of bords
        rgb upper_left;
        rgb lower_left;
        rgb upper_right;
        rgb lower_right;

        rgb foreground_depth;
        rgb background_depth;

        float profundidadeMaxima;
    
};

#endif
