//
// Created by anton on 21/11/2024.
//

#include <GL/gl.h>
#include <GL/freeglut_std.h>
#include "Silla.h"

void Silla::pintasilla() {
    GLfloat marron_madera[] = {0.40f, 0.20f, 0.05f, 1.0f};
    glMaterialfv (GL_FRONT, GL_EMISSION, marron_madera );

    // PATA 1
    glPushMatrix();
    glTranslatef(-0.5f, -0.5f, -0.5f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

// PATA 2
    glPushMatrix();
    glTranslatef(0.5f, -0.5f, -0.5f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

// PATA 3
    glPushMatrix();
    glTranslatef(-0.5f, -0.5f, 0.5f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

// PATA 4
    glPushMatrix();
    glTranslatef(0.5f, -0.5f, 0.5f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

// ASIENTO
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(1.1f, 0.1f, 1.1f);
    glutSolidCube(1.0);
    glPopMatrix();

// RESPALDO
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.5f);
    glScalef(1.0f, 1.0f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

}






