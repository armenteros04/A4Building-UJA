#ifndef __IGVINTERFAZ
#define __IGVINTERFAZ

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else

#include <GL/glut.h>

#endif   // defined(__APPLE__) && defined(__MACH__)

#include <string>
#include <iostream>
#include "igvEscena3D.h"
#include "igvCamara.h"

/**
 * Los objetos de esta clase encapsulan la interfaz y el estado de la aplicaci�n
 */


enum modoInterfaz {
    IGV_VISUALIZAR ///< En la ventana se va a visualizar de manera normal la escena
    , IGV_SELECCIONAR /**< Se ha hecho clic en la ventana de visualizaciï¿½n, y la
                      *   escena se debe visualizar en modo selecciï¿½n
                      */
};
class igvInterfaz
{  private:
      int ancho_ventana = 0; ///< Ancho de la ventana de visualizaci�n
      int alto_ventana = 0;  ///< Alto de la ventana de visualizaci�n

      igvEscena3D escena; ///< Escena que se visualiza en la ventana definida por igvInterfaz
      igvCamara camara; ///< C�mara que se utiliza para visualizar la escena


      int puertaSeleccionada=-1;

        modoInterfaz modo = IGV_VISUALIZAR;
    bool boton_retenido = false;

    int cursorX = 0
    , cursorY = 0;

      static igvInterfaz* _instancia; ///< Direcci�n de memoria del objeto �nico de la clase
      igvInterfaz () = default;

   public:
    bool _animacionActiva = false;
    int cont=0;
    int ratio=100;
        Dron* dron;
      static igvInterfaz& getInstancia ();

      ~igvInterfaz () = default;

      static void keyboardFunc ( unsigned char key, int x, int y ); // m�todo para control de eventos del teclado
      static void reshapeFunc ( int w, int h ); // m�todo que define la camara de vision y el viewport
      static void displayFunc (); // m�todo para visualizar la escena
      static void idleFunc (); // m�todo para animar la escena


      void crear_mundo ();
      void configura_entorno ( int argc, char **argv // par�metros del main
                               , int _ancho_ventana, int _alto_ventana // ancho y alto de la ventana de visualizaci�n
                               , int _pos_X, int _pos_Y // posici�n inicial de la ventana de visualizaci�n
                               , std::string _titulo // t�tulo de la ventana de visualizaci�n
                             );
      void inicializa_callbacks (); // inicializa todos los callbacks
      void inicia_bucle_visualizacion (); // visualiza la escena y espera a eventos sobre la interfaz

      int get_ancho_ventana ();

      int get_alto_ventana ();

      void set_ancho_ventana ( int _ancho_ventana );

      void set_alto_ventana ( int _alto_ventana );

      static void mouseFunc(GLint boton, GLint estado, GLint x, GLint y);

      static void motionFunc(GLint x, GLint y);


};

#endif   // __IGVINTERFAZ
