//
// Created by anton on 21/11/2024.
//

#include <GL/gl.h>
#include <GL/freeglut_std.h>
#include "Mesa.h"

void Mesa::pintamesa() {
// PATA 1

    GLfloat marron_madera_ambiente[] = {0.40f, 0.20f, 0.05f, 1.0f};
    glMaterialfv ( GL_FRONT, GL_EMISSION, marron_madera_ambiente );
    glPushMatrix();
    glTranslatef(-1.0f, -0.5f, -1.0f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

// PATA 2
    glPushMatrix();
    glTranslatef(1.0f, -0.5f, -1.0f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

// PATA 3
    glPushMatrix();
    glTranslatef(-1.0f, -0.5f, 1.0f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

// PATA 4
    glPushMatrix();
    glTranslatef(1.0f, -0.5f, 1.0f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

// SUPERFICIE DE LA MESA
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(3.0f, 0.2f, 3.0f);
    glutSolidCube(1.0);
    glPopMatrix();

}

