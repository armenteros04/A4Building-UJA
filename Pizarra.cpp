//
// Created by anton on 28/11/2024.
//

#include "Pizarra.h"
#include "igvTextura.h"
#include <GL/glut.h>
#include <GL/gl.h>

void Pizarra::pintapizarra() {


    glPushMatrix();

    glRotatef(-45,0,1,0);
    glTranslatef(-159, 4.9,27);
    glScalef(3,3,3);

    glPushMatrix();
    glTranslatef(50,0,0);
    glPushMatrix();
    glTranslatef(-1.5f, 0.0f, 0.0f);
    glScalef(0.2f, 2.5f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Soporte derecho
    glPushMatrix();
    glTranslatef(1.5f, 0.0f, 0.0f);
    glScalef(0.2f, 2.5f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Pizarra
    glPushMatrix();


    glPushMatrix();
    GLfloat verdePizarra[] = {0.0f, 0.3f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, verdePizarra);

    glTranslatef(0.0f, 0.5f, 0.0f);
    glScalef(3.0f, 1.5f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();


}