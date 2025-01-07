#include "igvMaterial.h"


/**
 * Constructor de copia
 * @param p Material del que se copian las propiedades
 */
igvMaterial::igvMaterial ( const igvMaterial &p ): Ka ( p.Ka ), Kd ( p.Kd )
                                                   , Ks ( p.Ks ), Ns ( p.Ns )
{}

/**
 * Constructor parametrizado
 * @param _Ka Valor para el coeficiente de reflexi�n ambiental
 * @param _Kd Valor para el coeficiente de reflexi�n difusa
 * @param _Ks Valor para el coeficiente de reflexi�n Especular
 * @param _Ns Valor para el exponente de Phong
 */
igvMaterial::igvMaterial ( igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns ):
                         Ka ( _Ka ), Kd ( _Kd ), Ks ( _Ks ), Ns ( _Ns )
{}


/**
 * M�todo para aplicar las propiedades del material llamando a las funciones
 * de OpenGL
 */
void igvMaterial::aplicar ()
{


    glMaterialfv(GL_FRONT, GL_AMBIENT, Ka.cloneToFloatArray());
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Kd.cloneToFloatArray());
    glMaterialfv(GL_FRONT, GL_SPECULAR, Ks.cloneToFloatArray());
    GLfloat phong = Ns;
    glMaterialfv(GL_FRONT, GL_SHININESS, &phong);
    GLfloat emision[3] = { 0.0, 0.0, 0.0 };
    glMaterialfv(GL_FRONT, GL_EMISSION, emision);


}

/**
 * Cambia las propiedades del material
 * @param _Ka Valor para el coeficiente de reflexi�n ambiental
 * @param _Kd Valor para el coeficiente de reflexi�n difusa
 * @param _Ks Valor para el coeficiente de reflexi�n Especular
 * @param _Ns Valor para el exponente de Phong
 * @pre Se asume que los par�metros tienen valores v�lidos
 * @post Las propiedades del material cambian
 */
void igvMaterial::set ( igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns )
{  Ka = _Ka;
   Kd = _Kd;
   Ks = _Ks;
   Ns = _Ns;
}



