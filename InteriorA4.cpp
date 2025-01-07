//
// Created by jacob on 13/11/2024.
//

#include <GL/gl.h>
#include "InteriorA4.h"
#include "Mesa.h"
#include "Silla.h"
#include "Pizarra.h"
#include "igvTextura.h"
#include "Tablon.h"


void InteriorA4::inicializarmesa() {

    Mesa *mesa;

    glPushMatrix();
    glRotatef(90,0.0,1.0,0.0);
    glScalef(1.5,1.5,1.0);
    glTranslatef(-0.0,3.0,-25.0);
    (*mesa).pintamesa();
    glPopMatrix();
}

void InteriorA4::inicializarsilla() {

    Silla *silla;

    glPushMatrix();
    glRotatef(-90, 0.0,1.0,0.0);

    glTranslatef(0.0,4.2,28.0);
    silla->pintasilla();
    glPopMatrix();
}

void InteriorA4::inicializarfilas() {

    Silla *silla;
    Mesa *mesa;

    ///CENTRO
    glPushMatrix();
    glPushMatrix();
    glRotatef(90,0.0,1.0,0.0);
    glScalef(1.5,1.5,1.0);
    glTranslatef(-0.0,3.0,-15.0);
    mesa->pintamesa();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0.0,1.0,0.0);
    glTranslatef(0.8,4.2,-13.0);
    silla->pintasilla();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0.0,1.0,0.0);
    glTranslatef(-0.8,4.2,-13.0);
    silla->pintasilla();
    glPopMatrix();


///DERECHA
    glPushMatrix();
    glPushMatrix();
    glRotatef(90,0.0,1.0,0.0);
    glScalef(1.5,1.5,1.0);
    glTranslatef(7.0,3.0,-15.0);
    mesa->pintamesa();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0.0,1.0,0.0);
    glTranslatef(9.7,4.2,-13.0);
    silla->pintasilla();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0.0,1.0,0.0);
    glTranslatef(11.7,4.2,-13.0);
    silla->pintasilla();
    glPopMatrix();
    glPopMatrix();


    ///IZQUIERDA
    glPushMatrix();
    glPushMatrix();
    glRotatef(90,0.0,1.0,0.0);
    glScalef(1.5,1.5,1.0);
    glTranslatef(-7.0,3.0,-15.0);
    mesa->pintamesa();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0.0,1.0,0.0);
    glTranslatef(-9.7,4.2,-13.0);
    silla->pintasilla();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0.0,1.0,0.0);
    glTranslatef(-11.7,4.2,-13.0);
    silla->pintasilla();
    glPopMatrix();
    glPopMatrix();




    ///SEGUNDA FILA

    ///CENTRO
    glPushMatrix();
    glPushMatrix();
    glRotatef(90,0.0,1.0,0.0);
    glScalef(1.5,1.5,1.0);
    glTranslatef(-0.0,3.0,-6.0);
    mesa->pintamesa();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0.0,1.0,0.0);
    glTranslatef(0.8,4.2,-4.0);
    silla->pintasilla();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0.0,1.0,0.0);
    glTranslatef(-0.8,4.2,-4.0);
    silla->pintasilla();
    glPopMatrix();


///DERECHA
    glPushMatrix();
    glPushMatrix();
    glRotatef(90,0.0,1.0,0.0);
    glScalef(1.5,1.5,1.0);
    glTranslatef(7.0,3.0,-6.0);
    mesa->pintamesa();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0.0,1.0,0.0);
    glTranslatef(9.7,4.2,-4.0);
    silla->pintasilla();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0.0,1.0,0.0);
    glTranslatef(11.7,4.2,-4.0);
    silla->pintasilla();
    glPopMatrix();
    glPopMatrix();


    ///IZQUIERDA
    glPushMatrix();
    glPushMatrix();
    glRotatef(90,0.0,1.0,0.0);
    glScalef(1.5,1.5,1.0);
    glTranslatef(-7.0,3.0,-6.0);
    mesa->pintamesa();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0.0,1.0,0.0);
    glTranslatef(-9.7,4.2,-4.0);
    silla->pintasilla();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0.0,1.0,0.0);
    glTranslatef(-11.7,4.2,-4.0);
    silla->pintasilla();
    glPopMatrix();
    glPopMatrix();

    
}
void InteriorA4::quadPizarra(float div_x, float div_z, float witdh, float height) {



    float tam_x = witdh;
    float tam_z = height;

    glEnable(GL_TEXTURE_2D); // Habilitar texturas

    glNormal3f(0, 1, 0); // Normal hacia arriba
    glBegin(GL_QUADS);


    glTexCoord2f(0.0f, 1.0f); // Cambiado
    glVertex3f(0.0f, 0.0f, 0.0f);

    glTexCoord2f(1.0f, 1.0f); // Cambiado
    glVertex3f(10.0f, 0.0f, 0.0f);

    glTexCoord2f(1.0f, 0.0f); // Cambiado
    glVertex3f(10.0f, 15.0f, 0.0f);

    glTexCoord2f(0.0f, 0.0f); // Cambiado
    glVertex3f(0.0f, 15.0f, 0.0f);


    glEnd();

    glDisable(GL_TEXTURE_2D); // Deshabilitar texturas al finalizar
}

void InteriorA4::inicializarpizarra() {


    Pizarra* pizarra;

    pizarra->pintapizarra();



}


void InteriorA4::inicializartablon() {

    Tablon* tablon;
    tablon->pintatablon();


}










