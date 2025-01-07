//
// Created by anton on 13/11/2024.
//

#include "ConoTruncado.h"
#include <cmath>

ConoTruncado::ConoTruncado(float rInf, float rSup, float h, int seg)
        : radioInferior(rInf), radioSuperior(rSup), altura(h), segmentos(seg) {
    construirMalla();
}



void ConoTruncado::construirMalla() {
    float anguloPaso = 2 * M_PI / segmentos;

    // Vertices techo
    for (int i = 0; i <= segmentos; i++) {
        float angulo = i * anguloPaso;
        float xInf = radioInferior * cos(angulo);
        float zInf = radioInferior * sin(angulo);
        float xSup = radioSuperior * cos(angulo);
        float zSup = radioSuperior * sin(angulo);

        // Malla suelo
        vertices.push_back(xInf);
        vertices.push_back(0);
        vertices.push_back(zInf);

        //Malla techop
        vertices.push_back(xSup);
        vertices.push_back(altura);
        vertices.push_back(zSup);
    }

    // Indices malla lateral
    for (int i = 0; i < segmentos-20; i++) {
        int p1 = i * 2;
        int p2 = p1 + 1;
        int p3 = (p1 + 2) % (segmentos * 2);
        int p4 = (p1 + 3) % (segmentos * 2);

        indices.push_back(p1);
        indices.push_back(p3);
        indices.push_back(p2);

        indices.push_back(p2);
        indices.push_back(p3);
        indices.push_back(p4);
    }
}


