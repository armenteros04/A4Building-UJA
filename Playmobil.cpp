//
// Created by jacob on 06/11/2024.
//

#include "Playmobil.h"

Playmobil::Playmobil() {
    color_pieza= new float [3];
    color_pieza[0]=0;
    color_pieza[1]=0.25;
    color_pieza[2]=0;
    alturaTronco=2;
    anguloCabeza=0;
    anguloBrazoDerecho=0;
    anguloBrazoIzq=0;


}


void Playmobil::sentadilla() {

    if(anguloRodillas==0){
        anguloRodillas=45;
        alturaTronco=(alturaTronco*0.70710678118);
    }else{
        anguloRodillas=0;
        alturaTronco=(alturaTronco*1.41421356237);
    }
}

void Playmobil::subeBrazoIzq(float a) {
    anguloBrazoIzq-=a;
}

void Playmobil::subeBrazoDer(float a) {
    anguloBrazoDerecho-=a;
}

void Playmobil::giraCabeza(float a) {
    anguloCabeza+=a;
}

void Playmobil::pintaCabeza() {

    GLfloat colorPiel[] = {0.96f, 0.76f, 0.6f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, colorPiel);
    glRotatef(anguloCabeza,0,1,0);
    glTranslatef(0.0f,alturaTronco+2.75 , 0.0f);
    glutSolidCube ( 1 );


}

void Playmobil::pintaTorso() {

    GLfloat amarillo[] = {1.0f, 1.0f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, amarillo);
    glTranslatef(0.0f,alturaTronco+1.3 , 0.0f);
    glScalef(1.25f, 2.0f, 1.25f);

    glutSolidCube ( 1 );
}




void Playmobil::pintaBrazoDer() {
    GLfloat colorPiel[] = {0.96f, 0.76f, 0.6f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, colorPiel);


    glTranslatef(0.8f,alturaTronco+1.7f , 0.0f);
    glRotatef(anguloBrazoDerecho,1,0,0);
    glutSolidSphere(0.2f, 20, 20); //Articulacion

    glTranslatef(0.0f,-0.6 , 0.0f); //Brazo
    glScalef(0.5f, 1.75f, 0.5f);
    glutSolidCube ( 1 );

}


void Playmobil::pintaBrazoIzq(){
    GLfloat colorPiel[] = {0.96f, 0.76f, 0.6f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, colorPiel);


    glTranslatef(-0.8f,alturaTronco+1.7f , -0.0f);
    glRotatef(anguloBrazoIzq,1,0,0);
    glutSolidSphere(0.2f, 20, 20); //Articulacion

    glTranslatef(-0.1f,-0.6 , 0.0f); //Brazo
    glScalef(0.5f, 1.75f, 0.5f);
    glutSolidCube ( 1 );

}

void Playmobil::pintaPiernaSupDer() {
    GLfloat azulVaquero[] = {0.1f, 0.2f, 0.6f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, azulVaquero);
    glTranslatef(0.35,alturaTronco , 0.1f);
    glRotatef(-anguloRodillas,1,0,0);
    glScalef(0.5f, 1.0f, 0.5f);
    glutSolidCube ( 1 );

}

void Playmobil::pintaPiernaSupIzq() {
    GLfloat azulVaquero[] = {0.1f, 0.2f, 0.6f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, azulVaquero);
    glTranslatef(-0.35,alturaTronco , 0.1f);
    glRotatef(-anguloRodillas,1,0,0);
    glScalef(0.5f, 1.0f, 0.5f);
    glutSolidCube ( 1 );

}

void Playmobil::pintaPiernaInfDer() {
    GLfloat azulVaquero[] = {0.1f, 0.2f, 0.6f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, azulVaquero);
    glTranslatef(0.35,alturaTronco -0.82, 0.1f);
    glRotatef(anguloRodillas,1,0,0);
    glScalef(0.5f, 1.2f, 0.5f);
    glutSolidCube ( 1 );

}

void Playmobil::pintaPiernaInfIzq() {
    GLfloat azulVaquero[] = {0.1f, 0.2f, 0.6f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, azulVaquero);
    glTranslatef(-0.35,alturaTronco -0.82, 0.1f);
    glRotatef(anguloRodillas,1,0,0);
    glScalef(0.5f, 1.2f, 0.5f);
    glutSolidCube ( 1 );
}

void Playmobil::pintaPieIzq() {
    GLfloat negro[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, negro);
    glTranslatef(-0.35,0.25f, 0.2f);
    glScalef(0.5f, 0.6f, 1.2f);
    glutSolidCube ( 1 );
}

void Playmobil::pintaPieDer() {

    GLfloat negro[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, negro);
    glTranslatef(0.35,0.25f, 0.2f);
    glScalef(0.5f, 0.6f, 1.2f);
    glutSolidCube ( 1 );
}

void Playmobil::pintaOjoIzquierdo() {
    GLfloat color_ojos[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, color_ojos);
    glTranslatef(-0.2f, 0.25f, 0.51f); // PosiciÃ³n del ojo izquierdo
    glutSolidSphere(0.1, 20, 20);
}

void Playmobil::pintaOjoDerecho() {
    GLfloat color_ojos[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, color_ojos);
    glTranslatef(0.2f, 0.25f, 0.51f); // PosiciÃ³n del ojo derecho
    glutSolidSphere(0.1, 20, 20);
}

void Playmobil::pintaBoca() {
    GLfloat color_ojos[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, color_ojos);
    glTranslatef(0.0f, -0.1f, 0.51f); // PosiciÃ³n de la boca
    glScalef(0.5f, 0.1f, 0.1f);
    glutSolidCube(1.0);
}

void Playmobil::pintaRodilla() {
    glTranslatef(0.0f,0.3f,0.0f);
    glutSolidSphere(0.5f, 20, 20); //Articulacion
}

void Playmobil::pintaGorra() {
    GLfloat colorGorra[] = {0.0f, 0.0f, 1.0f, 1.0f}; // Color azul
    glMaterialfv(GL_FRONT, GL_EMISSION, colorGorra);

    // Dibuja la parte superior de la gorra (un cubo pequeño)
    glPushMatrix();
    glTranslatef(0.0f, 0.65f, 0.0f); // Coloca la gorra ligeramente por encima de la cabeza
    glScalef(1.0f, 0.3f, 1.0f); // Escala para hacerla más plana
    glutSolidCube(1.0f); // Parte superior de la gorra
    glPopMatrix();

    // Dibuja la visera de la gorra (un cubo delgado)
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.6f); // Coloca la visera frente a la cabeza
    glScalef(1.0f, 0.1f, 0.3f); // Escala para hacer la visera más ancha y delgada
    glutSolidCube(1.0f);
    glPopMatrix();
}


void Playmobil::pintaplaymobil() {

    glPushMatrix();
    this->pintaTorso();
    glPopMatrix();

    glPushMatrix();
    this->pintaCabeza();

// Añadir gorra
    glPushMatrix();
    this->pintaGorra();
    glPopMatrix();

// Añadir ojos y boca
    glPushMatrix();
    this->pintaOjoIzquierdo();
    glPopMatrix();

    glPushMatrix();
    this->pintaOjoDerecho();
    glPopMatrix();

    glPushMatrix();
    this->pintaBoca();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    this->pintaBrazoDer();
    glPopMatrix();

    glPushMatrix();
    this->pintaBrazoIzq();
    glPopMatrix();


    glPushMatrix();
    this->pintaPiernaSupDer();
    glPopMatrix();


    glPushMatrix();
    this->pintaPiernaSupIzq();
    glPopMatrix();

    glPushMatrix();
    this->pintaPiernaInfDer();
    glPushMatrix();
    this->pintaRodilla();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    this->pintaPiernaInfIzq();
    glPushMatrix();
    this->pintaRodilla();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    this->pintaPieDer();
    glPopMatrix();

    glPushMatrix();
    this->pintaPieIzq();
    glPopMatrix();

    glPopMatrix();


}


