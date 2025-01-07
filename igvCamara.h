#ifndef __IGVCAMARA
#define __IGVCAMARA

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else

#include <GL/glut.h>

#endif   // defined(__APPLE__) && defined(__MACH__)

#include "igvPunto3D.h"

/**
 * Vistas de c�mara
 */
enum poscam
{  panoramica   ///< Vista desde un punto arbitrario
   , planta   ///< Vista de planta (c�mara en el eje Y)
   , perfil   ///< Vista de perfil (c�mara en el eje X)
   , alzado   ///< Vista de alzado (c�mara en el eje Z)
};

/**
 * Etiquetas para los diferentes tipos de c�mara
 */
enum tipoCamara
{  IGV_PARALELA   ///< Proyecci�n paralela
   , IGV_FRUSTUM   ///< Proyecci�n en perspectiva usando OpenGL
   , IGV_PERSPECTIVA   ///< Proyecci�n en perspectiva usando GLU
};

/**
 * Los objetos de esta clase representan c�maras de visualizaci�n en la aplicaci�n
 */
class igvCamara
{  private:
      poscam vis = panoramica;      ///< Posici�n de la c�mara

      tipoCamara tipo = IGV_PARALELA;  ///< Tipo de la c�mara

      GLdouble xwmin = -5    ///< Coordenada X m�nima del frustum/proyecci�n paralela
               , xwmax = 5   ///< Coordenada X m�xima del frustum/proyecci�n paralela
               , ywmin = -5   ///< Coordenada Y m�nima del frustum/proyecci�n paralela
               , ywmax = 5   ///< Coordenada Y m�xima del frustum/proyecci�n paralela
               ;

      GLdouble angulo = 60   ///< �ngulo de apertura (proyecci�n perspectiva)
               , raspecto = 1   ///< Raz�n de aspecto (proyecci�n perspectiva)
               ;

      GLdouble znear = 3    ///< Distancia de la c�mara al plano Z near
               , zfar = 200 ///< Distancia de la c�mara al plano Z far
               ;

      igvPunto3D P0 = { 6, 4, 8 };   ///< Posici�n de la c�mara

      igvPunto3D r = { 0, 0, 0 };   ///< Punto al que mira la c�mara

      igvPunto3D V = { 0, 1, 0 };   ///< Vector que indica la vertical
public:
    poscam getVis() const;

    igvPunto3D getP0() ;

    igvPunto3D getR() ;

    igvPunto3D getV() ;

   public:

      igvCamara () = default;

      ~igvCamara () = default;

      igvCamara ( tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V );

      void set ( igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V );

      void set ( tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V
                 , double _xwmin, double _xwmax, double _ywmin
                 , double _ywmax, double _znear, double _zfar );

      void set ( tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V
                 , double _angulo, double _raspecto, double _znear, double _zfar );

      void aplicar ();

      void zoom ( double factor );
};

#endif   // __IGVCAMARA

