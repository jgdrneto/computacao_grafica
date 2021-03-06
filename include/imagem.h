#ifndef _IMAGEM_H_
#define _IMAGEM_H_

class Imagem {
    
    public:
    
        // Image pixels
        CorRGB* pixeis;
        // Image width
        unsigned int largura;
        // Image height
        unsigned int altura;

        /**
         * Image constructor.
         *
         * @param Image width
         * @param Image height
         */
        Imagem(unsigned int, unsigned int);
        
        /**
         * Image destructor.
         */
        ~Imagem();
};

#include "../src/imagem.cpp"

#endif
