#include <cstdlib>
#include <stdio.h>

#include "igvInterfaz.h"

igvInterfaz *igvInterfaz::_instancia = nullptr;


/**
 * M�todo para acceder al objeto �nico de la clase, en aplicaci�n del patr�n de
 * dise�o Singleton
 * @return Una referencia al objeto �nico de la clase
 */
igvInterfaz &igvInterfaz::getInstancia() {
    if (!_instancia) {
        _instancia = new igvInterfaz;
    }

    return *_instancia;
}

/**
 * Crea el mundo que se visualiza en la ventana
 */
void igvInterfaz::crear_mundo() {  // inicia la c�mara
    _instancia->camara.set(IGV_PERSPECTIVA, {82, 5, 0}, {81, 5, 0}, {0, 1.0, 0}, 60, 1, 2, 200);
    _instancia->dron = new Dron(_instancia->camara);

}

/**
 * Inicializa todos los par�metros para crear una ventana de visualizaci�n
 * @param argc N�mero de par�metros por l�nea de comandos al ejecutar la
 *             aplicaci�n
 * @param argv Par�metros por l�nea de comandos al ejecutar la aplicaci�n
 * @param _ancho_ventana Ancho inicial de la ventana de visualizaci�n
 * @param _alto_ventana Alto inicial de la ventana de visualizaci�n
 * @param _pos_X Coordenada X de la posici�n inicial de la ventana de
 *               visualizaci�n
 * @param _pos_Y Coordenada Y de la posici�n inicial de la ventana de
 *               visualizaci�n
 * @param _titulo T�tulo de la ventana de visualizaci�n
 * @pre Se asume que todos los par�metros tienen valores v�lidos
 * @post Cambia el alto y ancho de ventana almacenado en el objeto
 */
void
igvInterfaz::configura_entorno(int argc, char **argv, int _ancho_ventana, int _alto_ventana, int _pos_X, int _pos_Y,
                               std::string _titulo) {  // inicializaci�n de las variables de la interfaz
    ancho_ventana = _ancho_ventana;
    alto_ventana = _alto_ventana;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(_ancho_ventana, _alto_ventana);
    glutInitWindowPosition(_pos_X, _pos_Y);
    glutCreateWindow(_titulo.c_str());

    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);

    crear_mundo(); // crea el mundo a visualizar en la ventana
}

/**
 * M�todo para visualizar la escena y esperar a eventos sobre la interfaz
 */
void igvInterfaz::inicia_bucle_visualizacion() {
    glutMainLoop(); // inicia el bucle de visualizaci�n de GLUT
}

/**
 * M�todo para control de eventos del teclado
 * @param key C�digo de la tecla pulsada
 * @param x Coordenada X de la posici�n del cursor del rat�n en el momento del
 *          evento de teclado
 * @param y Coordenada Y de la posici�n del cursor del rat�n en el momento del
 *          evento de teclado
 * @pre Se asume que todos los par�metros tienen valores v�lidos
 * @post Los atributos de la clase pueden cambiar, dependiendo de la tecla pulsada
 */
void igvInterfaz::keyboardFunc(unsigned char key, int x, int y) {
    switch (key) {

        case 'e': // activa/desactiva la visualizacion de los ejes
            _instancia->escena.set_ejes(!_instancia->escena.get_ejes());
            _instancia->escena.setPunto(_instancia->camara);
            break;
        case 'w':
            _instancia->dron->avanza();
            _instancia->camara.set(IGV_PERSPECTIVA, _instancia->dron->posDron, _instancia->dron->puntVision,
                                   _instancia->dron->vArriba, 60, 1, 2, 200);
            break;
        case 's':
            _instancia->dron->retrocede();
            _instancia->camara.set(IGV_PERSPECTIVA, _instancia->dron->posDron, _instancia->dron->puntVision,
                                   _instancia->dron->vArriba, 60, 1, 2, 200);

            break;

        case 'i':
            _instancia->dron->miraArriba();
            _instancia->camara.set(IGV_PERSPECTIVA, _instancia->dron->posDron, _instancia->dron->puntVision,
                                   _instancia->dron->vArriba, 60, 1, 2, 200);
            break;
        case 'k':
            _instancia->dron->miraAbajo();
            _instancia->camara.set(IGV_PERSPECTIVA, _instancia->dron->posDron, _instancia->dron->puntVision,
                                   _instancia->dron->vArriba, 60, 1, 2, 200);
            break;

        case 'j':
            _instancia->dron->miraIzquierda();
            _instancia->camara.set(IGV_PERSPECTIVA, _instancia->dron->posDron, _instancia->dron->puntVision,
                                   _instancia->dron->vArriba, 60, 1, 2, 200);
            break;

        case 'l':
            _instancia->dron->miraDerecha();
            _instancia->camara.set(IGV_PERSPECTIVA, _instancia->dron->posDron, _instancia->dron->puntVision,
                                   _instancia->dron->vArriba, 60, 1, 2, 200);
            break;
        case 'a' :
            _instancia->_animacionActiva = !_instancia->_animacionActiva;
            break;

        case 27: // tecla de escape para SALIR
            exit(1);
            break;
    }
    glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

/**
 * M�todo que define la c�mara de visi�n y el viewport. Se llama autom�ticamente
 * cuando se cambia el tama�o de la ventana.
 * @param w Nuevo ancho de la ventana
 * @param h Nuevo alto de la ventana
 * @pre Se asume que todos los par�metros tienen valores v�lidos
 */
void igvInterfaz::reshapeFunc(int w, int h) {  // dimensiona el viewport al nuevo ancho y alto de la ventana
    // guardamos valores nuevos de la ventana de visualizacion
    _instancia->set_ancho_ventana(w);
    _instancia->set_alto_ventana(h);

    // establece los par�metros de la c�mara y de la proyecci�n
    _instancia->camara.aplicar();
}

/**
 * M�todo para visualizar la escena
 */
void igvInterfaz::displayFunc() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer
    // se establece el viewport
    glViewport(0, 0, _instancia->get_ancho_ventana(), _instancia->get_alto_ventana());

    if (_instancia->modo == IGV_SELECCIONAR) {

        glDisable(GL_LIGHTING); // desactiva la iluminaciï¿½n de la escena
        glDisable(GL_DITHER);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_CULL_FACE);

        _instancia->camara.aplicar();
        _instancia->escena.visualizar();
        GLubyte pixel[3];
        GLfloat fpixel[3];
        glReadPixels(_instancia->cursorX, _instancia->alto_ventana - _instancia->cursorY, 1, 1, GL_RGB,GL_UNSIGNED_BYTE, &pixel);
        for(int i=0;i<3;i++){
            fpixel[i]=((GLfloat ) pixel[i])/256;
        }
        if( pixel[2]== _instancia->escena.puertaIzq->id){
            _instancia->puertaSeleccionada=0;
        }
        if( pixel[2]== _instancia->escena.puertaDer->id){
            _instancia->puertaSeleccionada=1;
        }
        _instancia->modo = IGV_VISUALIZAR;

        glEnable(GL_LIGHTING);

    } else {
        // aplica las transformaciones en funci�n de los par�metros de la c�mara
        _instancia->camara.aplicar();
        // visualiza la escena
        _instancia->escena.visualizar();

        // refresca la ventana
        glutSwapBuffers();
    }


}

/**
 * M�todo para animar la escena
 */
void igvInterfaz::idleFunc() {

    if (_instancia->_animacionActiva) {
        _instancia->escena.playmobil->subeBrazoIzq(3);
        _instancia->escena.playmobil->subeBrazoDer(5);
        _instancia->escena.playmobil->giraCabeza(3);
        if (_instancia->cont == _instancia->ratio) {
            _instancia->escena.playmobil->sentadilla();
            _instancia->cont = 0;
        }
        glutPostRedisplay();
        _instancia->cont++;
    }
}


/**
 * M�todo para inicializar los callbacks GLUT
 */
void igvInterfaz::inicializa_callbacks() {
    glutKeyboardFunc(keyboardFunc);
    glutReshapeFunc(reshapeFunc);
    glutDisplayFunc(displayFunc);
    glutIdleFunc(idleFunc);
    glutMouseFunc(mouseFunc);
    glutMotionFunc(motionFunc);
}

/**
 * M�todo para consultar el ancho de la ventana de visualizaci�n
 * @return El valor almacenado como ancho de la ventana de visualizaci�n
 */
int igvInterfaz::get_ancho_ventana() {
    return ancho_ventana;
}

/**
 * M�todo para consultar el alto de la ventana de visualizaci�n
 * @return El valor almacenado como alto de la ventana de visualizaci�n
 */
int igvInterfaz::get_alto_ventana() {
    return alto_ventana;
}

/**
 * M�todo para cambiar el ancho de la ventana de visualizaci�n
 * @param _ancho_ventana Nuevo valor para el ancho de la ventana de visualizaci�n
 * @pre Se asume que el par�metro tiene un valor v�lido
 * @post El ancho de ventana almacenado en la aplicaci�n cambia al nuevo valor
 */
void igvInterfaz::set_ancho_ventana(int _ancho_ventana) {
    ancho_ventana = _ancho_ventana;
}

/**
 * M�todo para cambiar el alto de la ventana de visualizaci�n
 * @param _alto_ventana Nuevo valor para el alto de la ventana de visualizaci�n
 * @pre Se asume que el par�metro tiene un valor v�lido
 * @post El alto de ventana almacenado en la aplicaci�n cambia al nuevo valor
 */
void igvInterfaz::set_alto_ventana(int _alto_ventana) {
    alto_ventana = _alto_ventana;
}

void igvInterfaz::mouseFunc(GLint boton, GLint estado, GLint x,
                            GLint y) {


    if (boton == GLUT_LEFT_BUTTON) {

        if (estado == GLUT_DOWN) {
            _instancia->boton_retenido = true;
            _instancia->modo = IGV_SELECCIONAR;

        } else {
            _instancia->boton_retenido = false;
            _instancia->modo = IGV_VISUALIZAR;
            _instancia->puertaSeleccionada=-1;
        }
        _instancia->cursorX = x;
        _instancia->cursorY = y;

        glutPostRedisplay();
    }
}

void igvInterfaz::motionFunc(GLint x, GLint y) {  /* TODO: Apartado B: si el botï¿½n estï¿½ pulsado y hay algï¿½n objeto seleccionado,
      hay que comprobar el objeto seleccionado y la posiciï¿½n del ratï¿½n y rotar
      el objeto seleccionado utilizando el desplazamiento entre la posiciï¿½n
      inicial y final del ratï¿½n */



    if (_instancia->boton_retenido && _instancia->puertaSeleccionada != -1) {





            if(_instancia->puertaSeleccionada==0){

                    float anguloAntes = _instancia->escena.puertaIzq->angulo;
                    _instancia->escena.puertaIzq->angulo=
                            anguloAntes + (x - _instancia->cursorX);


            }
            if(_instancia->puertaSeleccionada==1){

                    float anguloAntes = _instancia->escena.puertaDer->angulo;
                    _instancia->escena.puertaDer->angulo=
                            anguloAntes + (x - _instancia->cursorX);

            }



        }



    _instancia->cursorX = x;
    _instancia->cursorY = y;

    glutPostRedisplay();
}
