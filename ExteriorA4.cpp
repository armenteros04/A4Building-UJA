//
// Created by jacob on 13/11/2024.
//

#include "ExteriorA4.h"
#include "ConoTruncadoPuerta.h"

#include "Escaleras.h"
#include "CilindroBase.h"
#include "igvTextura.h"

#include <GL/glut.h>

ExteriorA4::ExteriorA4() : cilindro(nullptr), conoTruncado(nullptr) {}

ExteriorA4::~ExteriorA4() {
    delete cilindro;
    delete conoTruncado;
}

void ExteriorA4::quadMonolito(float div_x, float div_z, float witdh, float height) {

    float tam_x = witdh;
    float tam_z = height;

    glEnable(GL_TEXTURE_2D);

    glNormal3f(0, 1, 0);
    glBegin(GL_QUADS);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(10.0f, 0.0f, 0.0f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(10.0f, 15.0f, 0.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 15.0f, 0.0f);




    glEnd();

    glDisable(GL_TEXTURE_2D);
}


void ExteriorA4::quadMonolitoPosterior(float div_x, float div_z, float witdh, float height) {

    float tam_x = witdh;
    float tam_z = height;

    glEnable(GL_TEXTURE_2D);

    glNormal3f(0, 1, 0);
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

    glDisable(GL_TEXTURE_2D);
}


void ExteriorA4::quadcartel(float div_x, float div_z, float witdh, float height) {

    float tam_x = witdh;
    float tam_z = height;

    glEnable(GL_TEXTURE_2D);

    glNormal3f(0, 1, 0);
    glBegin(GL_QUADS);


    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.6f, 0.0f, 0.0f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.6f, 0.6f, 0.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 0.6f, 0.0f);




    glEnd();

    glDisable(GL_TEXTURE_2D);
}



void ExteriorA4::quadPizarra(float div_x, float div_z, float witdh, float height) {

    float tam_x = witdh;
    float tam_z = height;

    glEnable(GL_TEXTURE_2D);

    glNormal3f(0, 1, 0);
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

    glDisable(GL_TEXTURE_2D);
}

//CILINDRO DE FUERA GRANDE CON AULAS
void ExteriorA4::inicializarCilindro(float radio, float altura, int segmentos) {
    GLfloat gris[] = {0.01f, 0.01f, 0.01f, 1.0f};
    glMaterialfv ( GL_FRONT, GL_EMISSION, gris );
    Cilindro A4cilindro(8.0f, 7.4f, 30);
    glTranslatef(-4.0,0.0,0.0);
    //glRotatef(-25,0.0,1.0,0.0);
    glTranslatef(0.0,0.0,0.0);
    A4cilindro.dibujar();
}

void ExteriorA4::inicializarCilindro2(float radio, float altura, int segmentos) {
    GLfloat gris[] = {0.01f, 0.01f, 0.01f, 1.0f};
    glMaterialfv ( GL_FRONT, GL_EMISSION, gris );
    CilindroBase A4cilindro(7.9f, 2.0f, 30);
    glTranslatef(-4.0,5.0,0.0);
    A4cilindro.dibujar();
}

//CILINDRO GRIS QUE RODEA EL EXTERIOR DEL EDIFICO
void ExteriorA4::inicializarCilindrobase(float radio, float altura, int segmentos) {
    GLfloat gris[] = {0.01f, 0.01f, 0.01f, 1.0f};
    glMaterialfv ( GL_FRONT, GL_EMISSION, gris );
    CilindroBase A4cilindro(8.0f, 1.0f, 30);
    glTranslatef(5.0,0.0,0.0);
    //glRotatef(270,0.0,1.0,0.0);
    glTranslatef(0.0,0.0,0.0);
    A4cilindro.dibujar();
}


//CILINDRO CAMEL QUE SIMULA EL SUELO DE LA ENTRADA
void ExteriorA4::inicializarCilindrobase2(float radio, float altura, int segmentos) {

    GLfloat lightBrown[] = {0.65f, 0.50f, 0.39f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, lightBrown);

    CilindroBase A4cilindro(7.9f, 1.0f, 30);
    glTranslatef(5.0,0.001,0.0);
    //glRotatef(270,0.0,1.0,0.0);
    glTranslatef(0.0,0.0,0.0);
    A4cilindro.dibujar();
}

//CILINDRO CAMEL QUE SIMULA EL SUELO DE LA CLASE
void ExteriorA4::inicializarCilindrobase3(float radio, float altura, int segmentos) {

    GLfloat lightBrown[] = {0.65f, 0.50f, 0.39f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, lightBrown);

    CilindroBase A4cilindro(7.9f, 1.0f, 30);
    glTranslatef(-4.0,0.001,0.0);
    //glRotatef(270,0.0,1.0,0.0);
    glTranslatef(0.0,0.0,0.0);
    A4cilindro.dibujar();
}

//PRIMER CONO TRUNCADO CON DOS PASANTES ENFRENTADOS
void ExteriorA4::inicializarConoTruncado(float radioInferior, float radioSuperior, float altura, int segmentos) {
    GLfloat gris[] = {0.01f, 0.01f, 0.01f, 1.0f};
    glMaterialfv ( GL_FRONT, GL_EMISSION, gris );
    glPushMatrix();
    ConoTruncadopuerta A4conopuerta(8.0,6.0,6.5,30);
    glTranslatef(5.0,1.0,0.0);         ///VALOR INICIAL DE Y -> 1
    glRotatef(95,0.0,1.0,0.0);

    A4conopuerta.dibujar();
    glPopMatrix();

//SEGUNDO CONO TRUNCADO QUE RODEA LOS PASANTES Y PONE EL TECHO
    glPushMatrix();
    ConoTruncado A4conosuperior(7.5,5.7,5.0,30); //AJUSTAR SEGUN QUERAMOS TAÑANO DE ENTRADA
    glTranslatef(5.0,2.5,0.0); ///VALOR INICIAL DE Y -> 2.5
    glRotatef(60,0.0,1.0,0.0);
    A4conosuperior.dibujar();
    glPopMatrix();

}

void ExteriorA4::InicicializarEscaleras() {

    Escaleras escaleras;
    glTranslatef(14.2,-0.25,0.0);
    escaleras.dibujar();

    char fichero2[] = "C:\\Users\\anton\\Desktop\\IGV\\PROYECTO FINAL\\A4BuildingUJA\\Imagenes\\cartel1.png";
    glTranslatef(-7,2.3,5.149);
    igvTextura textura2(fichero2);
    textura2.aplicar();
    quadcartel(193, 770, 5, 5);

}

void ExteriorA4::inicializarmonolito() {
    Monolito monolito1;
    monolito1.pintamonolito();

     char fichero[] = "C:\\Users\\anton\\Desktop\\IGV\\PROYECTO FINAL\\A4BuildingUJA\\Imagenes\\monolito.png";
     glTranslatef(52,-2.1,8.99);
     igvTextura textura(fichero);
     textura.aplicar();
     quadMonolito(193, 770, 19.3, 77);

    glPushMatrix();
    glTranslatef(-0.001,0,2.02);
    quadMonolitoPosterior(193, 770, 19.3, 77);
    glPopMatrix();


}





