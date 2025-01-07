#include <cstdlib>
#include <cmath>
#include "igvInterfaz.h"


int main(int argc, char** argv) {



	// inicializa la ventana de visualizaci�n
   igvInterfaz::getInstancia().configura_entorno ( argc, argv
                                                   , 1000, 1000 // tama�o de la ventana
                                                   , 100, 100 // posici�n de la ventana
                                                   , "Edificio A4 - Universidad de Jaen" // t�tulo de la ventana
                                                 );

   glClearColor(0.53f, 0.81f, 0.98f, 1.0f);  //COLOR DEL CIELO
    //glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
   // establece las funciones callbacks para la gesti�n de los eventos
   igvInterfaz::getInstancia().inicializa_callbacks ();

   // inicia el bucle de visualizaci�n de GLUT
   igvInterfaz::getInstancia().inicia_bucle_visualizacion ();



    return(0);
}
