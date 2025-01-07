#include "igvTextura.h"
#include "lodepng.h"
#include <vector>
#include <stdexcept>

/**
 * Constructor parametrizado. Carga una textura de archivo
 * @param fichero
 */
igvTextura::igvTextura ( std::string fichero )
{

    glEnable ( GL_TEXTURE_2D );

    if ( !glIsTexture ( idTextura ) )
    {  std::vector<unsigned char> texeles;
        unsigned int error = lodepng::decode ( texeles, ancho, alto, fichero );

        if ( error )
        {  std::string mensaje = "Error leyendo el archivo ";
            throw std::runtime_error ( mensaje + fichero );
        }

        glGenTextures(1, &idTextura);
        glBindTexture(GL_TEXTURE_2D, idTextura);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ancho, alto, 0, GL_RGBA, GL_UNSIGNED_BYTE, texeles.data());
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    }
}

/**
 * Destructor. Elimina la textura OpenGL relacionada
 */
igvTextura::~igvTextura ()
{  glDeleteTextures ( 1, &idTextura );
}

/**
 * Activa la textura OpenGL relacionada
 */
void igvTextura::aplicar ()
{  glBindTexture ( GL_TEXTURE_2D, idTextura );
}

/**
 * Cambia el identificador de la textura OpenGL relacionada
 * @param id Nuevo identificador de texturas
 * @pre Se asume que el parámetro es válido
 * @post El identificador de la textura OpenGL cambia
 */
void igvTextura::setIdTextura ( unsigned int id )
{  this->idTextura = id;
}

/**
 * Consulta del identificador de la textura OpenGL
 * @return El identificador de la textura OpenGL relacionada
 */
unsigned int igvTextura::getIdTextura ()
{  return this->idTextura;
}