//
// Created by anton on 17/11/2024.
//

#ifndef PR3B_CILINDROBASE_H
#define PR3B_CILINDROBASE_H

#include "MallaTriangulos.h"

class CilindroBase : public MallaTriangulos {

public:
    float radio, altura;
    int segmentos;

    CilindroBase(float r, float h, int s);

    void construirMalla();
};


#endif //PR3B_CILINDROBASE_H
