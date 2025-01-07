//
// Created by anton on 16/11/2024.
//
#include <GL/glut.h>
#include "Escaleras.h"

Escaleras::Escaleras() {}

void Escaleras::dibujar() {



    for (int i = 0; i < 3; ++i) {
        glPushMatrix();
        glRotatef(90,0,1,0);
        glTranslatef(0.0f, i * 0.5f, -i * 0.5f);
        glScalef(3.0f, 0.5f, 1.0f);
        glutSolidCube(1.0);
        glPopMatrix();

    }



    //CESPED
    glPushMatrix();
    GLfloat verde[] =  {0.13f, 0.55f, 0.13f, 1.0f};
    glMaterialfv ( GL_FRONT, GL_EMISSION, verde);
    glTranslatef(0,-0.45,0);
    glScalef(500, 0.001, 500);
    glutSolidCube(1);
    glPopMatrix();
}
