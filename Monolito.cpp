//
// Created by anton on 23/11/2024.
//
#include <GL/glut.h>
#include <GL/gl.h>
#include "Monolito.h"

void Monolito::pintamonolito() {

    glPushMatrix();
    GLfloat gris[] = {0.01f, 0.01f, 0.01f, 1.0f};
    glMaterialfv ( GL_FRONT, GL_EMISSION, gris );

    glTranslatef(57,5.4,10.0);
    glRotatef(90,0.0,1.0,0.0);
    glScalef(2.0,15.0,10.0);
    glutSolidCube(1);

    glPopMatrix();
}
