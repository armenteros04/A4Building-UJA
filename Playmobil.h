//
// Created by jacob on 06/11/2024.
//

#ifndef PR3B_PLAYMOBIL_H
#define PR3B_PLAYMOBIL_H

#include <GL/glut.h>


class Playmobil {
private:
    float alturaTronco;

    float anguloBrazoIzq,  anguloBrazoDerecho;

    float anguloCabeza;

    float anguloRodillas;


    GLfloat* color_pieza ;


public:

    Playmobil();
    void pintaPelo();

    void sentadilla();

    void subeBrazoIzq(float a);

    void subeBrazoDer(float a);

    void giraCabeza(float a);

    void pintaCabeza();

    void pintaTorso();

    void pintaBrazoDer();

    void pintaBrazoIzq();

    void pintaPiernaSupDer();

    void pintaPiernaSupIzq();

    void pintaPiernaInfDer();

    void pintaPiernaInfIzq();

    void pintaOjoIzquierdo();

    void pintaOjoDerecho();

    void pintaBoca();

    void pintaPieIzq();

    void pintaPieDer();

    void pintaRodilla();

    void pintaplaymobil();

    void pintaGorra();



};


#endif //PR3B_PLAYMOBIL_H
