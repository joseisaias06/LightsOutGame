/** \file ProcesoInterfaz.h
 * \brief Archivo que contiene los prototipos de las funciones encargadas de los procesos de las interface del programa.
 * \author Olmos, Ortiz y Partida
 * \date 29 / Mayo / 2020
 */
#ifndef PROCESOINTERFAZ_H_INCLUDED
#define PROCESOINTERFAZ_H_INCLUDED

/** \brief Funci&oacute;n que realiza el proceso de la interfaz de Creditos.
 *
 * \param anchoPantalla short
 * \param altoPantalla short
 * \return void
 *
 */
void CreditosActual( short anchoPantalla, short altoPantalla );

/** \brief Funci&oacute;n que realiza el proceso de la interfaz de Instrucciones.
 *
 * \param anchoPantalla short
 * \param altoPantalla short
 * \param primeraVez bool
 * \param nPagina short
 * \param flecha short
 * \param foco bool
 * \param enter bool
 * \return void
 *
 */
void InstruccionesActual( short anchoPantalla, short altoPantalla, bool primeraVez, short nPagina, short flecha, bool foco, bool enter );

/** \brief Funci&oacute;n que realiza el proceso de la interfaz de juego.
 *
 * \param anchoPantalla short
 * \param altoPantalla short
 * \param contadorIntentos short
 * \param pintarTablero short
 * \param iAnt short
 * \param jAnt short
 * \param casillaActual short
 * \param const bool * const *arregloEstados
 * \param lucesOn short
 * \return void
 *
 */
void JugarActual( short anchoPantalla, short altoPantalla, short contadorIntentos,short pintarTablero, short iAnt, short jAnt, short casillaActual, const bool * const *arregloEstados, short lucesOn );

/** \brief Funci&oacute;n que realiza el proceso de la interfaz para guardar al partida.
 *
 * \param opc short Opci&oacute;n en la cual est&eacute; posicionado el usuario.
 * \param anchoPantalla short Tama&ntilde;o horizontal de la pantalla actual.
 * \param altoPantalla short Tama&ntilde;o vertical de la pantalla actual.
 * \param pintarMarco bool "Interruptor" que avisa a la funci&oacute;n si se pintar&aacute; el marco o no.
 * \param guardar bool "Interruptor" que avisa a la funci&oacute;n si se guardar&aacute; el tablero o no.
 * \param const bool * const *Tablero Tablero de la partida actual del juego.
 * \param tamTablero short Tama�o del tablero
 * \param lucesOn short Cantidad de luces encencidas actuales
 * \return void
 *
 */
void solicitudGuardarActual( short opc, short anchoPantalla, short altoPantalla, bool pintarMarco, bool guardar, const bool * const *Tablero, short tamTablero, short lucesOn );

void solicitudCargarActual( short opc, short anchoPantalla, short altoPantalla, bool pintarMarco, bool cargar, bool **&Tablero, short Filas);


/** \brief Funci&oacute;n que realiza el proceso de la interfaz del menu de opciones.
 *
 * \param opc short Opci&oacute;n en la cual est&eacute; posicionado el usuario.
 * \param anchoPantalla short Tama&ntilde;o horizontal de la pantalla actual.
 * \param altoPantalla short Tama&ntilde;o vertical de la pantalla actual.
 * \param pintarTitulo bool "Interruptor" que avisa a la funci&oacute;n si se pintar&aacute; el t&iacute;lo o no.
 * \return void
 *
 */
void MenuOpcionesActual( short opc, short anchoPantalla, short altoPantalla, bool pintarTitulo );

/** \brief Funci&oacute;n que realiza el proceso de la interfaz del menu principal.
 *
 * \param opc short Opci&oacute;n en la cual est&eacute; posicionado el usuario.
 * \param anchoPantalla short Tama&ntilde;o horizontal de la pantalla actual.
 * \param altoPantalla short Tama&ntilde;o vertical de la pantalla actual.
 * \return void
 *
 */
void PrincipalActual( short opc, short anchoPantalla, short altoPantalla );

#endif // PROCESOINTERFAZ_H_INCLUDED
