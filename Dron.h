//
// Created by jacob on 13/11/2024.
//

#ifndef PR3B_DRON_H
#define PR3B_DRON_H


#include "igvPunto3D.h"
#include "igvCamara.h"
#include <cmath>

class Dron {
private:

    double alfa=90;
    double beta=180;
    double campoDeVision;
    double incAngulo;
public:
    igvPunto3D posDron = { 0, 0,0 };
    igvPunto3D puntVision = { 0, 0, 0 };
    igvPunto3D vArriba = { 0, 1, 0 };


    Dron(igvCamara c);
    void avanza();
    void retrocede();

    void miraArriba();
    void miraAbajo();

    void miraDerecha();
    void miraIzquierda();




};


#endif //PR3B_DRON_H



