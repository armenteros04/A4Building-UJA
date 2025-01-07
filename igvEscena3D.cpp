#include <cstdio>
#include <iostream>
#include "igvEscena3D.h"
#include "ExteriorA4.h"
#include "igvTextura.h"
#include "igvFuenteLuz.h"
#include "igvMaterial.h"
#include<GL/gl.h>
#include<GL/glut.h>

double radio;
double altura;
double segmentos;
double radioinf;
double radiosup;


/**
 * Constructor por defecto
 */
igvEscena3D::igvEscena3D ()
{
    playmobil = new Playmobil;
    puertaIzq=new Puerta(IZQ);
    puertaDer=new Puerta(DER);
    exterior = new ExteriorA4;
}

/**
 * Destructor
 */
igvEscena3D::~igvEscena3D ()
{
}

/*
void igvEscena3D::loadObj(std::string fname) {
    FILE *fp;
    int read;
    GLfloat x, y, z;
    char ch;
    elephant=glGenLists(1);
    fp=fopen(fname.c_str(),"r");
    if (!fp)
    {
        std::cout<<("can't open file %s\n", fname);
        exit(1);
    }
    glPointSize(2.0);
    glNewList(elephant, GL_COMPILE);
    {
        glPushMatrix();
        glBegin(GL_POINTS);
        while(!(feof(fp)))
        {
            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
            if(read==4&&ch=='v')
            {
                glVertex3f(x,y,z);
            }
        }
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);
}

void igvEscena3D::drawOBJ()
{
    glPushMatrix();
    glTranslatef(0.0,0.0,0.0);
    glScalef(0.1,0.1,0.1);
    glCallList(CLASSROOM);
    glPopMatrix();

}
*/

/**
 * M�todo para pintar los ejes coordenados llamando a funciones de OpenGL
 */
void igvEscena3D::pintar_ejes()
{	GLfloat rojo[] = { 1,0,0,1.0 };
   GLfloat verde[] = { 0, 1, 0, 1.0 };
   GLfloat azul[] = { 0, 0, 1, 1.0 };

   glMaterialfv ( GL_FRONT, GL_EMISSION, rojo );
   glBegin ( GL_LINES );
   glVertex3f ( 1000, 0, 0 );
   glVertex3f ( -1000, 0, 0 );
   glEnd ();

   glMaterialfv ( GL_FRONT, GL_EMISSION, verde );
   glBegin ( GL_LINES );
   glVertex3f ( 0, 1000, 0 );
   glVertex3f ( 0, -1000, 0 );
   glEnd ();

   glMaterialfv ( GL_FRONT, GL_EMISSION, azul );
   glBegin ( GL_LINES );
   glVertex3f ( 0, 0, 1000 );
   glVertex3f ( 0, 0, -1000 );
   glEnd ();
}



/**
 * M�todo con las llamadas OpenGL para visualizar la escena
 */
void igvEscena3D::visualizar ()
{


   GLfloat luz0[4] = { 30.0, 30.0, 30.0, 1 };                         ///EL VALOR POR DEFECTO ERA 5 !!!!!!!
                                                                                        ///A 35-40 ESTA BIEN
                                                                                ///A 70  se veia brillosos

    glLightfv ( GL_LIGHT0, GL_POSITION, luz0 ); // la luz se coloca aqu� si permanece fija y no se mueve con la escena
    glEnable ( GL_LIGHT0 );


    igvFuenteLuz foco(GL_LIGHT1, igvPunto3D(45.0, 1.0, -1.0),
                                    igvColor(0.0, 0.0, 0.0, 0.0),
                                    igvColor(1.0, 1.0, 1.0, 1.0),
                                    igvColor(1.0, 1.0, 0.0, 1.0), 1.0, 0.0, 0.0,
                                    igvPunto3D(0.0, 1.0, 3.1), 45.0, 0.0);


    foco.aplicar();


   glPushMatrix ();

   if ( ejes )
   { pintar_ejes ();
       }





glPushMatrix();
   glScalef(3.0,3.0,3.0);

    glPushMatrix();
    exterior->inicializarCilindro(radio, altura, segmentos);
    glPopMatrix();

    glPushMatrix();
    exterior->inicializarCilindro2(radio, altura, segmentos);
    glPopMatrix();

    glPushMatrix();
    exterior->inicializarCilindrobase(radio, altura, segmentos);
    glPopMatrix();

    glPushMatrix();
    exterior->inicializarCilindrobase2(radio, altura, segmentos);
    glPopMatrix();

    glPushMatrix();
    exterior->inicializarCilindrobase3(radio, altura, segmentos);
    glPopMatrix();

    glPushMatrix();
    exterior->inicializarConoTruncado(radioinf, radiosup, altura, segmentos);
    glPopMatrix();

    glPushMatrix();
    exterior->InicicializarEscaleras( );
    glPopMatrix();


    glPopMatrix();

    //loadObj("C://Users//anton//Desktop//A4BuildingUJA//OBJ//CLASSROOM.obj");

    glPushMatrix();

    glTranslatef(28.0,3.0,-10.0);
    glRotatef(55,0.0,1.0,0.0);
    glScalef(0.75,0.75,0.75);
    playmobil->pintaplaymobil();

    glTranslatef(24.0,3.0,-8.0);
    glRotatef(55,0.0,1.0,0.0);
    glScalef(0.75,0.75,0.75);
    playmobil->pintaplaymobil();

    glPopMatrix();

    interior->inicializarmesa();

    interior->inicializarsilla();

    interior->inicializarfilas();

    glPushMatrix();

    exterior->inicializarmonolito();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-25.0,4.6,-1.4);
    glRotatef(55,0.0,1.0,0.0);
    glScalef(0.5,0.5,0.5);
    playmobil->pintaplaymobil();
    glPopMatrix();

    glPushMatrix();
        puertaIzq->visualizaMarco();
        puertaIzq->visualizaPuerta();
        puertaDer->visualizaPuerta();
    glPopMatrix();


glPushMatrix();
interior->inicializarpizarra();
glPopMatrix();

    glPushMatrix();
    glScalef(3,3,3);
    glTranslatef(7,2.4,5.2);
    interior->inicializartablon();
    glPopMatrix();

    glPopMatrix ();


}

/**
 * M�todo para consultar si hay que dibujar los ejes o no
 * @retval true Si hay que dibujar los ejes
 * @retval false Si no hay que dibujar los ejes
 */
bool igvEscena3D::get_ejes ()
{  return ejes;
}

/**
 * M�todo para activar o desactivar el dibujado de los _ejes
 * @param _ejes Indica si hay que dibujar los ejes (true) o no (false)
 * @post El estado del objeto cambia en lo que respecta al dibujado de ejes,
 *       de acuerdo al valor pasado como par�metro
 */
void igvEscena3D::set_ejes ( bool _ejes )
{  ejes = _ejes;
}

void igvEscena3D::pintaPuntoVision() {
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(10.0);                  // Tamaño del punto

    glBegin(GL_POINTS);                // Inicia el dibujo de puntos
    glVertex3f(a,b,c);      // Especifica la posición del punto
    glEnd();


}

void igvEscena3D::setPunto(igvCamara a1) {
    a=a1.getR().getX();
    b=a1.getR().getY();
    c=a1.getR().getZ();
}

void igvEscena3D::visualizar2() {

    glPushMatrix ();

    glPushMatrix();
    glScalef(3.0,3.0,3.0);


    glPushMatrix();
    exterior->inicializarCilindro(radio, altura, segmentos);
    glPopMatrix();

    glPushMatrix();
    exterior->inicializarCilindro2(radio, altura, segmentos);
    glPopMatrix();

    glPushMatrix();
    exterior->inicializarCilindrobase(radio, altura, segmentos);
    glPopMatrix();

    glPushMatrix();
    exterior->inicializarCilindrobase2(radio, altura, segmentos);
    glPopMatrix();

    glPushMatrix();
    exterior->inicializarCilindrobase3(radio, altura, segmentos);
    glPopMatrix();

    glPushMatrix();
    exterior->inicializarConoTruncado(radioinf, radiosup, altura, segmentos);
    glPopMatrix();

    glPushMatrix();
    exterior->InicicializarEscaleras( );
    glPopMatrix();


    glPopMatrix();

    //loadObj("C://Users//anton//Desktop//A4BuildingUJA//OBJ//CLASSROOM.obj");

    // drawOBJ();

    glPushMatrix();


    glScalef(50.0,50.0,50.0);
    glPopMatrix();


    glPushMatrix();

    glTranslatef(30.0,3.5,8.0);
    glRotatef(110,0.0,1.0,0.0);
    glScalef(0.75,0.75,0.75);
    playmobil->pintaplaymobil();

    glPopMatrix();


    glPushMatrix();

    glTranslatef(30.0,3.5,-8.0);
    glRotatef(55,0.0,1.0,0.0);
    glScalef(0.75,0.75,0.75);
    playmobil->pintaplaymobil();

    glPopMatrix();

    glPushMatrix();
    interior->inicializarmesa();

    interior->inicializarsilla();

    interior->inicializarfilas();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-25.0,4.45,-1.4);
    glRotatef(55,0.0,1.0,0.0);
    glScalef(0.5,0.5,0.5);
    playmobil->pintaplaymobil();
    glPopMatrix();
    glPushMatrix();
    puertaIzq->visualizaMarco();
    puertaIzq->visualizaPuerta();
    puertaDer->visualizaPuerta();
    glPopMatrix();


    glPopMatrix ();
}




