//
// Created by anton on 26/11/2024.
//

#ifndef PR3B_IGVTEXTURA_H
#define PR3B_IGVTEXTURA_H

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else

#include <GL/glut.h>

#endif   // defined(__APPLE__) && defined(__MACH__)

#include <string>

/**
 * Los objetos de esta clase representan texturas OpenGL
 */
class igvTextura
{  private:
    // Atributos
    unsigned int idTextura = 0; ///< Identificador de la textura OpenGL
    unsigned int alto = 0  ///< Alto de la textura
    , ancho = 0; ///< Ancho de la textura


public:
    /// Constructor por defecto
    igvTextura () = default;
    igvTextura ( std::string fichero ); // Textura cargada desde un fichero
    ~igvTextura ();

    void aplicar (); //Establece la textura como la activa
    void setIdTextura ( unsigned int id );

    unsigned int getIdTextura ();
};


#endif //PR3B_IGVTEXTURA_H
