#ifndef _LEITOR_OBJETOS_H_
#define _LEITOR_OBJETOS_H_

#include <string>
#include <vector>
#include <ios>
#include <iomanip>

#include "leitor.h"
#include "../objetos/objeto.h"
#include "../objetos/esfera.h"
#include "../objetos/triangulo.h"
#include "../objetos/plano.h"
#include "../materiais/blinnphong.h"
#include "../materiais/toon.h"
#include "../materiais/lambertiano.h"
#include "../materiais/dieletrico.h"
#include "../texturas/constante.h"
#include "../texturas/quadriculada.h"
#include "../vetor.h"

//GLM arquivo
#include "../glm/glm.hpp"
// translação, rotação, escala, perspectiva
#include "../glm/gtc/matrix_transform.hpp"

std::ostream & operator<<( std::ostream& os, const glm::mat4& m )
{
    for (auto i(0) ; i < 4 ; ++i )
    {
        os << "[ ";
        for ( auto j(0) ; j < 4 ; ++j )
            os << std::fixed << std::right << std::setw(6) << std::setprecision(2) << m[j][i] << " ";
        os << "]\n";
    }

    return os;
}

std::ostream & operator<<( std::ostream& os, const glm::vec4& v )
{
        os << "[ ";
        for ( auto j(0) ; j < 4 ; ++j )
            os << std::right << std::setw(6) << std::setprecision(2) << v[j] << " ";
        os << "]";
    return os;
}

class LeitorObjetos {

    public :
        static std::vector<Objeto*>& lerObjetos(std::string); 
};

#include "../../src/leitores/leitor_objetos.cpp"

#endif
