//
// Created by anton on 17/11/2024.
//

#include <cmath>
#include "CilindroBase.h"

CilindroBase::CilindroBase(float r, float h, int s) : radio(r), altura(h), segmentos(s) {
    construirMalla();
}
void CilindroBase::construirMalla() {

    float anguloPaso = 2 * M_PI / segmentos;

    // Vertices para colocar la malla
    for (int i = 0; i <= segmentos; i++) {
        float angulo = i * anguloPaso;
        float x = radio * cos(angulo);
        float z = radio * sin(angulo);

        // Vértices suelo
        vertices.push_back(x);
        vertices.push_back(0);
        vertices.push_back(z);

        // Vértices techo
        vertices.push_back(x);
        vertices.push_back(altura);
        vertices.push_back(z);
    }

    // Centro de las bases
    int base_inferior = vertices.size() / 3;
    vertices.push_back(0); vertices.push_back(0); vertices.push_back(0);     // Centro suelo
    int base_superior = vertices.size() / 3;
    vertices.push_back(0); vertices.push_back(altura); vertices.push_back(0); // Centro techo

    for (int i = 0; i < segmentos; i++) {  // -2.5 es para el pasante y que no se cierre completo
        int p1 = i * 2;
        int p2 = p1 + 1;
        int p3 = (p1 + 2) % (segmentos * 2);
        int p4 = (p1 + 3) % (segmentos * 2);

        // Malla lateral
        indices.push_back(p1);
        indices.push_back(p3);
        indices.push_back(p2);

        indices.push_back(p2);
        indices.push_back(p3);
        indices.push_back(p4);
    }

    // Malla completa del suelo
    for (int i = 0; i < segmentos; i++) {
        int p1 = i * 2;
        indices.push_back(p1);
        indices.push_back((i + 1) % segmentos * 2);
        indices.push_back(base_inferior);
    }

    // Malla completa del techo
    for (int i = 0; i < segmentos; i++) {
        int p2 = i * 2 + 1;
        indices.push_back(p2);
        indices.push_back(base_superior);
        indices.push_back((i + 1) % segmentos * 2 + 1);
    }
}
