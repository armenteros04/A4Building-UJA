#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else

#include <GL/glut.h>
#include "Dron.h"
#include "Playmobil.h"
#include "ExteriorA4.h"
#include "Silla.h"
#include "Mesa.h"
#include "InteriorA4.h"
#include "Puerta.h"
#include "Pizarra.h"

#endif // defined(__APPLE__) && defined(__MACH__)

/**
 * Partes del modelo
 */
enum parte
{	basex   ///< Identifica la base del modelo
   , cuerpoinferior   ///< Identifica el cuerpo inferior del modelo
   , cuerposuperior   ///< Identifica el cuerpo superior del modelo
   , brazo   ///< Identifica el brazo del modelo
};

/**
 * Los objetos de esta clase representan escenas 3D para su visualizaci�n
 */
class igvEscena3D
{  private:
      
      bool ejes = true;   ///< Indica si hay que dibujar los ejes coordenados o no
      double a,b,c;


   public:

    Mesa* mesa;
    Silla* silla;
    Playmobil* playmobil;
    ExteriorA4* exterior;
    InteriorA4 *interior;
    Puerta* puertaIzq;
    Puerta* puertaDer;
    Pizarra* pizarra;
      igvEscena3D();
      ~igvEscena3D();

      void loadObj(std::string fname);
      void drawOBJ();
      void visualizar();
      void visualizar2();
      bool get_ejes ();
      void set_ejes ( bool _ejes );
      void setPunto(igvCamara a1);


   private:

      void pintar_ejes ();
      void pintaPuntoVision();

};

#endif   // __IGVESCENA3D
