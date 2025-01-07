//
// Created by anton on 14/11/2024.
//
#include <cmath>
#include "ConoTruncadoPuerta.h"

ConoTruncadopuerta::ConoTruncadopuerta(float rInf, float rSup, float h, int seg)
        : radioInferior(rInf), radioSuperior(rSup), altura(h), segmentos(seg) {
    construirMallapuerta();
}


void ConoTruncadopuerta::construirMallapuerta() {
    float anguloPaso = 2 * M_PI / segmentos;

    float anguloInicioHueco1 = M_PI / 4;
    float anguloFinHueco1 = 3 * M_PI / 4;
    float anguloInicioHueco2 = anguloInicioHueco1 + M_PI;
    float anguloFinHueco2 = anguloFinHueco1 + M_PI;
    float alturaHueco = altura;

    for (int i = 0; i <= segmentos; i++) {
        float angulo = i * anguloPaso;
        float xInf = radioInferior * cos(angulo);
        float zInf = radioInferior * sin(angulo);
        float xSup = radioSuperior * cos(angulo);
        float zSup = radioSuperior * sin(angulo);

        vertices.push_back(xInf);
        vertices.push_back(0);
        vertices.push_back(zInf);

        vertices.push_back(xSup);
        vertices.push_back(alturaHueco);
        vertices.push_back(zSup);

        vertices.push_back(xSup);
        vertices.push_back(altura);
        vertices.push_back(zSup);
    }

    for (int i = 0; i < segmentos; i++) {
        float angulo = i * anguloPaso;

        if (!((angulo >= anguloInicioHueco1 && angulo <= anguloFinHueco1) ||
              (angulo >= anguloInicioHueco2 && angulo <= anguloFinHueco2))) {
            int p1 = i * 3;
            int p2 = p1 + 1;
            int p3 = ((i + 1) % segmentos) * 3;
            int p4 = p3 + 1;

            // Triángulo 1 de la parte inferior
            indices.push_back(p1);
            indices.push_back(p3);
            indices.push_back(p2);

            // Triángulo 2 de la parte inferior
            indices.push_back(p2);
            indices.push_back(p3);
            indices.push_back(p4);
        }

        int p2 = i * 3 + 1;
        int p3 = ((i + 1) % segmentos) * 3 + 1;
        int p4 = ((i + 1) % segmentos) * 3 + 2;
        int p5 = i * 3 + 2;

        // Triángulo 1 de la parte superior
        indices.push_back(p2);
        indices.push_back(p3);
        indices.push_back(p5);

        // Triángulo 2 de la parte superior
        indices.push_back(p5);
        indices.push_back(p3);
        indices.push_back(p4);
    }

    int indiceCentroTapa = vertices.size() / 3;
    vertices.push_back(0);
    vertices.push_back(altura);
    vertices.push_back(0);

    for (int i = 0; i < segmentos; i++) {
        int p1 = i * 3 + 2;
        int p2 = ((i + 1) % segmentos) * 3 + 2;

        indices.push_back(indiceCentroTapa);
        indices.push_back(p1);
        indices.push_back(p2);
    }
}