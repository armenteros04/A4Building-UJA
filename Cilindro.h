//
// Created by anton on 13/11/2024.
//

#ifndef PR3B_CILINDRO_H
#define PR3B_CILINDRO_H

#include "MallaTriangulos.h"

class Cilindro : public MallaTriangulos {
public:
    float radio, altura;
    int segmentos;

    Cilindro(float r, float h, int s);

    void construirMalla();
};



#endif //PR3B_CILINDRO_H
