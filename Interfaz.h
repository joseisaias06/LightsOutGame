/** \file Interfaz.h
 * \brief Archivo que contiene los prototipos de las funciones encargadas de la gesti&oacute;n de las interface del programa.
 * \author Olmos, Ortiz y Partida
 * \date 29 / Mayo / 2020
 */
#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED


/**
* \brief Funci&oacute;n que realiza todos los procesos del men&uacute; principal del programa.
*
**/
int MenuPrincipal( );

/**
* \brief Funci&oacute;n que muestra la solicitud al usuario para saber si desea guardar el progreso actual de su tablero.
* \param short anchoPantalla El tama&ntilde;o del ancho actual de la ventana de ejecuci&oacute;n.
* \param short altoPantalla El tama&ntilde;o del alto actual de la ventana de ejecuci&oacute;n.
* \param const bool * const *Tablero Tablero que se guardar&aacute;.
* \param short lucesOn cantidad de luces encendidas en el tablero.
*
* \pre anchoPantalla mayor a 0
* \pre altoPantalla mayor a 0
**/
void solicitudGuardar( short anchoPantalla, short altoPantalla, const bool * const *Tablero, short lucesOn );

void solicitudCargar( short anchoPantalla, short altoPantalla);

/**
* \brief Funci&oacute;n que realiza todos los procesos del men&uacute; de opciones.
*
**/
short MenuOpciones( );

/**
* \brief Funci&oacute;n que realiza todos los procesos a la hora de empezar a jugar.
*
**/
void InterfazJugar(bool CargarPartida);

/**
* \brief Funci&oacute;n que realiza todos los procesos para mostrar las instrucciones del juego.
*
**/
void InterfazInstrucciones( );

/**
* \brief Funci&oacute;n que realiza todos los procesos para mostrar los cr&eacute;ditos del programa.
*
**/
void InterfazCreditos( );





#endif // INTERFAZ_H_INCLUDED
