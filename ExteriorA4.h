//
// Created by jacob on 13/11/2024.
//

#ifndef PR3B_EXTERIORA4_H
#define PR3B_EXTERIORA4_H


#include "Cilindro.h"
#include "ConoTruncado.h"
#include "Monolito.h"

class ExteriorA4 {
private:

    Cilindro* cilindro;
    ConoTruncado* conoTruncado;
    Monolito* monolito;

public:
    ExteriorA4();

    void inicializarCilindro(float radio, float altura, int segmentos);

    void inicializarCilindro2(float radio, float altura, int segmentos);

    void inicializarCilindrobase(float radio, float altura, int segmentos);

    void inicializarCilindrobase2(float radio, float altura, int segmentos);

    void inicializarCilindrobase3(float radio, float altura, int segmentos);

    void quadMonolito(float div_x, float div_z, float witdh, float height);

    void quadMonolitoPosterior(float div_x, float div_z, float witdh, float height);

    void quadcartel(float div_x, float div_z, float witdh, float height);

    void quadPizarra(float div_x, float div_z, float witdh, float height);

    void inicializarConoTruncado(float radioInferior, float radioSuperior, float altura, int segmentos);

    void InicicializarEscaleras();

    void inicializarmonolito();

    ~ExteriorA4();

};


#endif //PR3B_EXTERIORA4_H
