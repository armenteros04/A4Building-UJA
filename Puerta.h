//
// Created by jacob on 13/11/2024.
//
#include <GL/glut.h>
#ifndef PR3B_PUERTA_H
#define PR3B_PUERTA_H
enum tipo{
    IZQ,DER
};

class Puerta {

public:

    float angulo;
    tipo tipoPuerta;
    float color[3]={ 0.5,0.25,0};
    GLbyte id;


    Puerta(tipo t);

    void visualizaMarco();
    void visualizaPuerta();


};


#endif //PR3B_PUERTA_H
