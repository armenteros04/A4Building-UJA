//
// Created by anton on 04/12/2024.
//

#include <GL/gl.h>
#include <GL/freeglut_std.h>
#include "Tablon.h"


void Tablon::pintatablon() {

    GLfloat blancoTablon[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat negroSoportes[] = {0.0f, 0.0f, 0.0f, 1.0f};

    glPushMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_EMISSION, blancoTablon);
    glScalef(2.0f, 1.0f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_EMISSION, negroSoportes);
    glTranslatef(0.0f, 0.55f, 0.0f);
    glScalef(2.1f, 0.1f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.0f, -0.55f, 0.0f);
    glScalef(2.1f, 0.1f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-1.05f, 0.0f, 0.0f);
    glScalef(0.1f, 1.1f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.05f, 0.0f, 0.0f);
    glScalef(0.1f, 1.1f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_EMISSION, negroSoportes);
    glTranslatef(-0.8f, -1.0f, 0.0f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8f, -1.0f, 0.0f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPopMatrix();
}

void Tablon::quadtablon(float ancho, float alto, GLuint textureID) {
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, textureID);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(ancho, 0.0f, 0.0f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(ancho, alto, 0.0f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, alto, 0.0f);

    glEnd();

    glDisable(GL_TEXTURE_2D);
}




