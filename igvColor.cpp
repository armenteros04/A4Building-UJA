#include "igvColor.h"


/**
 * Constructor parametrizado RGB. La componente alfa se fija a 0
 * @param r Componente roja del nuevo color (valor en el rango [0,1])
 * @param g Componente verde del nuevo color (valor en el rango [0,1])
 * @param b Componente azul del nuevo color (valor en el rango [0,1])
 * @pre Se asume que los par�metros tienen valores v�lidos
 */
igvColor::igvColor ( const double r, const double g, const double b ):
                   color { r, g, b, 0 }
{}

/**
 * Constructor parametrizado RGBA
 * @param r Componente roja del nuevo color (valor en el rango [0,1])
 * @param g Componente verde del nuevo color (valor en el rango [0,1])
 * @param b Componente azul del nuevo color (valor en el rango [0,1])
 * @param a Componente alfa (transparencia) del nuevo color (valor en el rango [0,1])
 * @pre Se asume que los par�metros tienen valores v�lidos
 */
igvColor::igvColor ( const double r, const double g, const double b
                     , const double a ): color { r, g, b, a }
{}

/**
 * Constructor de copia
 * @param p Color del que se copian los valores
 */
igvColor::igvColor ( const igvColor &p ): color { p.color[R], p.color[G]
                                                  , p.color[B], p.color[A] }
{}

// M�todos p�blicos

/**
 * Acceso a una componente de color
 * @param idx Valor de la componente a consultar (R, G, B, A)
 * @return Una referencia a la componente solicitada
 */
double &igvColor::operator[] ( const unsigned char idx )
{  return color[idx];
}

/**
 * Acceso a una componente de color
 * @param idx Valor de la componente a consultar (R, G, B, A)
 * @return Una copia del valor de la componente solicitada
 */
double igvColor::operator[] ( const unsigned char idx ) const
{  return color[idx];
}

/**
 * Llama a la correspondiente funci�n de OpenGL para aplicar el color
 */
void igvColor::aplicar ()
{  glColor4dv ( color );
}

/**
 * Reserva un bloque de memoria con el color en formato float
 * @return La direcci�n de memoria del bloque reservado
 * @note En alg�n momento en el c�digo del programa es necesario liberar este
 *       bloque
 */
float *igvColor::cloneToFloatArray () const
{  float *res = new float[4] { (float) color[0], (float) color[1], (float) color[2], (float) color[3] };
   return res;
}