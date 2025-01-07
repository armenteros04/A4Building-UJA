//
// Created by anton on 14/11/2024.
//

#ifndef PR3B_CONOTRUNCADOPUERTA_H
#define PR3B_CONOTRUNCADOPUERTA_H


#include "MallaTriangulos.h"

class ConoTruncadopuerta : public MallaTriangulos {
public:
    float radioInferior, radioSuperior, altura;
    int segmentos;

    ConoTruncadopuerta(float rInf, float rSup, float h, int seg);

    void construirMallapuerta();

};


#endif //PR3B_CONOTRUNCADOPUERTA_H
