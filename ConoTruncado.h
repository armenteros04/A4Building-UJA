//
// Created by anton on 13/11/2024.
//

#ifndef PR3B_CONOTRUNCADO_H
#define PR3B_CONOTRUNCADO_H


#include "MallaTriangulos.h"

class ConoTruncado : public MallaTriangulos {
public:
    float radioInferior, radioSuperior, altura;
    int segmentos;

    ConoTruncado(float rInf, float rSup, float h, int seg);


    void construirMalla();

    void construirMallapuerta();

};

#endif //PR3B_CONOTRUNCADO_H
