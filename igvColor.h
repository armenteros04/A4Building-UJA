#ifndef __IGVCOLOR
#define __IGVCOLOR

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else

#include <GL/glut.h>

#endif   // defined(__APPLE__) && defined(__MACH__)

/**
 * Componentes de color
 */
enum cColor
{  R   ///< Rojo
   , G   ///< Verde
   , B   ///< Azul
   , A   ///< Alfa (transparencia)
};

/**
 * Los objetos de esta clase representan colores RGBA
 */
class igvColor
{  protected:

      double color[4] = { 0, 0, 0, 0 }; ///< Componentes R, G, B, A del color


   public:
      igvColor () = default;
      ~igvColor () = default;

      igvColor ( const double r, const double g, const double b );
      igvColor ( const double r, const double g, const double b, const double a );
      igvColor ( const igvColor &p );   //de copia

      double &operator[] ( const unsigned char idx );
      double operator[] ( const unsigned char idx ) const;

      void aplicar ();
      float *cloneToFloatArray () const;
};

#endif   // __IGVCOLOR

