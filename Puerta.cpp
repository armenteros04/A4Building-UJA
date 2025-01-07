//
// Created by jacob on 13/11/2024.
//

#include "Puerta.h"

Puerta::Puerta(tipo t) {
    tipoPuerta=t;
    angulo=0;
    if(tipoPuerta==IZQ) {
        color[2]=0.09765625;
        id=25;
    }
    if(tipoPuerta==DER){
        color[2]=0.12;
        id=31;
    }
}

void Puerta::visualizaMarco() {
    GLfloat colorNegro[] = {0, 0, 0, 1};
    glMaterialfv(GL_FRONT, GL_EMISSION, colorNegro);
    //marco sup
    glPushMatrix();
        glTranslatef(11.1,15,0);
        glScalef(1.5,1.5,12);
        glutSolidCube ( 1 );
    glPopMatrix();



    //marco izq

    glPushMatrix();
        glTranslatef(11.1,9.3,5.7);
        glScalef(1.5,12.6,1.5);
        glutSolidCube ( 1 );
    glPopMatrix();


    //marco der

    glPushMatrix();
        glTranslatef(11.1,9.3,-5.7);
        glScalef(1.5,12.6,1.5);
        glutSolidCube ( 1 );
    glPopMatrix();

}

void Puerta::visualizaPuerta() {
    glMaterialfv(GL_FRONT, GL_EMISSION, color);
    glColor3fv(color);
    if(tipoPuerta==IZQ){
        glPushMatrix();
            glTranslatef(11.1,3,5.7);
            glRotatef(angulo,0,1,0);
            glScalef(0.2,11.2,5.7);
            glTranslatef(0.5,0.5,-0.5);
            glutSolidCube ( 1 );
        glPopMatrix();
    }
    if(tipoPuerta==DER){
        glPushMatrix();
        glTranslatef(11.1,3,-5.7);

        glRotatef(angulo,0,1,0);
        glScalef(0.2,11.2,5.7);
        glTranslatef(0.5,0.5,0.5);
        glutSolidCube ( 1 );
        glPopMatrix();

    }
}
