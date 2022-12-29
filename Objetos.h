/** \file Objetos.h
 * \brief Archivo que contiene los prototipos de las funciones encargadas de la creaci&oacute;n de los objetos del programa(dise&ntilde;o).
 * \author Olmos, Ortiz y Partida
 * \date 29 / Mayo / 2020
 */

#ifndef LIGHTSOUTNUEVO_OBJETOS_H
#define LIGHTSOUTNUEVO_OBJETOS_H


//****************************************************************************************************************************
/** \brief Funci&oacute;n
 *
 * \param anchoPantalla short& Tama&ntilde;o horizontal de la pantalla actual.
 * \param altoPantalla short& Tama&ntilde;o vertical de la pantlla actual.
 * \param tamHorizontal short Espacio horizontal en la cual se centrar&aacute; el objeto
 * \param tamVertical short Espacio vertical en la cual se centrar&aacute; el objeto
 * \return void
 *
 */
void Area( short &anchoPantalla, short &altoPantalla, short tamHorizontal, short tamVertical );
//**************************************************************************************************************************
/** \brief Funci&oacute;n que dibuja un cuadro del color de la pantalla actual.
*
* \param ancho Ancho del  marco
* \param alto Alto del marco
* \param x coordenada en X
* \param y coordenada en Y

* \pre Ancho y alto mayores a 1
*
*/
void DibujarRectangulo( short ancho, short alto, short x, short y);

//****************************************************************************************************************************
/** \brief Funci&oacute;n que dibuja un marco con fondo transparente.
*
* \param ancho Ancho del  marco
* \param alto Alto del marco
* \param x coordenada en X
* \param y coordenada en Y

* \pre Ancho y alto mayores a 1
*
*/
void DibujarMarcoSinFondo(short ancho, short alto, short x, short y );

//****************************************************************************************************************************
/** \brief Funci&oacute;n que dibuja un marco con fondo lleno.
*
* \param ancho Ancho del  marco
* \param alto Alto del marco
* \param x coordenada en X
* \param y coordenada en Y

* \pre Ancho y alto mayores a 1
*
*/
void DibujarMarco(short ancho, short alto, short x, short y );

/** \brief Funci&oacute;n que dibuja un marco con doble l&iacute;nea.
 *
 * \param ancho short Ancho del marco.
* \param alto Alto del marco.
* \param x coordenada en X.
* \param y coordenada en Y.
 * \return void
 *
 */
void DibujarMarcoDobleSinFondo( short ancho , short alto, short x, short y );

//**************************************************************************************************************************
/** \brief Funci&oacute;n que dibuja un cuadro con texto centrado.
 *
 * \param opcion const char* Nombre del bot&oacute;n.
 * \param posX short Posici&oacute;n en x de el bot&oacute;n.
 * \param anchoBoton short Ancho del cuadro.
 * \param alturaBoton short Alto del cuadro.
 * \param coordY short Posici&oacute;n en y del bot&oacute;n.
 * \return void
 *
 */
void Boton( const char *opcion, short posX, short anchoBoton, short alturaBoton, short coordY );

//**************************************************************************************************************************
/** \brief Funci&oacute;n que imprime botones de un color. Este depende de si est&aacute; seleccionado o no.
 *
 * \param opcion const char* Nombre del bot&oacute;n.
 * \param anchoPantalla short Tama&ntilde;o horizontal de la pantalla actual.
 * \param alturaPantalla short Tama&ntilde;o vertical de la pantlla actual.
 * \param anchoBoton short Ancho del cuadro.
 * \param alturaBoton short Alto del cuadro.
 * \param coordY short Posici�n de la altura a la que se quiere posicionar el t&iacute;tulo.
 * \param estado bool "Interruptor" que avisa si el bot&oacute;n est&aacute; activo.
 * \param posIX short Posici&oacute;n inicial en x de los botones.
 * \param posIY short Posici&oacute;n inicial en y de los botones.
 * \return void
 *
 */
void BotonesMenu( const char *opcion, short anchoPantalla, short alturaPantalla, short anchoBoton, short alturaBoton, short coordY, bool estado, short posIX, short posIY );

//**************************************************************************************************************************
/** \brief Funci&oacute;n que imprime el t&iacute;tulo principal.
 *
 * \param anchoPantalla short Tama&ntilde;o horizontal de la pantalla actual.
 * \param coordY short Posici�n de la altura a la que se quiere posicionar el t&iacute;tulo.
 * \param short posIX=0 Posici&oacute;n inicial en x del t&iacute;tulo de inicio.
 * \param short posIY=0 Posici&oacute;n inicial en y del t&iacute;tulo de inicio.
 * \return void
 *
 */
void ImprimirTituloTren( short anchoPantalla, short coordY, short posIX = 0, short posIY = 0);

//**************************************************************************************************************************
/** \brief Funci&oacute;n que imprime el t&iacute;tulo de men&uacute; de opciones.
 *
 * \param anchoPantalla short Tama&ntilde;o horizontal de la pantalla actual.
 * \param coordY short Posici�n de la altura a la que se quiere posicionar el t&iacute;tulo.
 * \param short posIX=0 Posici&oacute;n inicial en x del t&iacute;tulo de opciones.
 * \param short posIY=0 Posici&oacute;n inicial en y del t&iacute;tulo de opciones.
 * \return void
 *
 */
void ImprimirTituloOpciones( short anchoPantalla, short coordY, short posIX = 0, short posIY = 0 );

//**************************************************************************************************************************
/** \brief Funci&oacute;n que imprime un t&iacute;tulo felicitando si el usuario gana.
 *
 * \param anchoPantalla short Tama&ntilde;o horizontal de la pantalla actual.
 * \param altoPantalla short Tama&ntilde;o vertical de la pantlla actual.
 * \param posIX short Posici&oacute;n inicial en x del t&iacute;tulo de felicitar.
 * \param posIY short Posici&oacute;n inicial en y del t&iacute;tulo de felicitar.
 * \return void
 *
 */
void Felicitar( short anchoPantalla, short altoPantalla, short posIX, short posIY, int Intentos);

//**************************************************************************************************************************
/** \brief Funci&oacute;n que imprime el cuadro de instruccines de men&uacute; de instruccines.
 *
 * \param anchoPantalla short Tama&ntilde;o horizontal de la pantalla actual.
 * \param altoPantalla short Tama&ntilde;o vertical de la pantlla actual.
 * \param primeraVez bool Variable booleana que avisa si se imprime todo por primera vez.
 * \param posIX short Posici&oacute;n inicial en x del cuadr de instrucciones.
 * \param posIY short Posici&oacute;n inicial en y del cuadr de instrucciones.
 * \param nPagina short N&uacute;mero de p&aacute;gina actual.
 * \return void
 *
 */
void cuadroInstrucciones( short anchoPantalla, short altoPantalla, bool primeraVez, short posIX, short posIY, short nPagina );

//**************************************************************************************************************************
/** \brief Funci&oacute;n que imprime el cuadro de intentos de men&uacute; de jugar.
 *
 * \param texto const char* Texto mostrado en cuadro intentos.
 * \param contadorIntentos short Contador de las veces que se da click a Enter.
 * \param ancho short Ancho del cuadro.
 * \param altura short Alto del cuadro.
 * \param espacioHor short Espacio horizontal en la cual se centrar&aacute; el objeto
 * \param espacioVer short Espacio vertical en la cual se centrar&aacute; el objeto
 * \param posIX short Posici&oacute;n inicial en x del cuadro de intentos.
 * \param posIY short Posici&oacute;n inicial en y del cuadro de intentos.
 * \param primeraVez bool  "Interruptor" que avisa si se imprime el cuadro por primera vez.
 * \return void
 *
 */
void CuadroIntentos( const char *texto, short contadorIntentos, short ancho, short altura, short espacioHor, short espacioVer, short posIX, short posIY, bool primeraVez );

//**************************************************************************************************************************
/** \brief Funci&oacute;n que imprime el cuadro de luces encencidas de men&uacute; de jugar.
 *
 * \param texto const char*
 * \param contadorLuces short
 * \param ancho short  Ancho del cuadro.
 * \param altura short Alto del cuadro.
 * \param espacioHor short Espacio horizontal en la cual se centrar&aacute; el objeto
 * \param espacioVer short Espacio VERTICAL en la cual se centrar&aacute; el objeto
 * \param posIX short Posici&oacute;n inicial en x del cuadro de luces.
 * \param posIY short Posici&oacute;n inicial en y del cuadro de luces.
 * \param primeraVez bool "Interruptor" que avisa si se imprime el cuadro por primera vez.
 * \return void
 *
 */
void CuadroLuces( const char *texto, short contadorLuces, short ancho, short altura, short espacioHor, short espacioVer, short posIX, short posIY, bool primeraVez  );

//**************************************************************************************************************************
/** \brief Funci&oacute;n que imprime el cuadro de informaci&oacute;n de men&uacute; de jugar.
 *
 * \param espacioHor short Espacio horizontal en el cual se dibujar&aacute; el cuadro.
 * \param espacioVer short Espacio vertical en el cual se dibujar&aacute; el cuadro.
 * \param posIX short Posici&oacute;n inicial en x del cuadro de informaci&acute;n.
 * \param posIY short Posici&oacute;n inicial en y del cuadro de informaci&acute;n.
 * \return void
 *
 */
void CuadroInfo( short espacioHor, short espacioVer, short posIX, short posIY  );

//**************************************************************************************************************************
/** \brief Funci&oacute;n que dibuja la tecla enter.
 *
 * \param posX short Posici&oacute;n en x de las flechas.
 * \param posY short Posici&oacute;n en y de las flechas.
 * \param Presionar bool "Interruptor" que avisa si se presiona la tecla enter.
 * \return void
 *
 */
void DibujarEnter( short posX, short posY, bool Presionar );

//**************************************************************************************************************************
/** \brief Funci&oacute;n que dibuja un foco.
 *
 * \param posX short Posici&oacute;n en x de las flechas.
 * \param posY short Posici&oacute;n en y de las flechas.
 * \param Presionar bool "Interruptor" que avisa si se presiona la acci&oacute;n del foco.
 * \return void
 *
 */
void DibujarFoco( short posX, short posY, bool Presionar );

//**************************************************************************************************************************
/** \brief Funci&oacute;n que dibuja las teclas de flechas.
 *
 * \param posX short Posici&oacute;n en x de las flechas.
 * \param posY short Posici&oacute;n en y de las flechas.
 * \param Presionar short  "Interruptor" que avisa si se presiona alguna flecha.
 * \return void
 *
 */
void DibujarFlechas( short posX, short posY, short Presionar );


//**************************************************************************************************************************
/** \brief Funci&oacute;n que dibuja el tablero
 *
 * \param tamCuadroTab short Tama&ntilde;o  de las casillas del tablero.
 * \param tamTab short Tama&ntilde;o del tablero.
 * \param anchoPantalla short Tama&ntilde;o horizontal de la pantalla actual.
 * \param alturaPantalla short Tama&ntilde;o vertical de la pantlla actual.
 * \param posIY short Posicion inicial en y del tablero.
 * \param primeraVez short "Interruptor" que avisa si se imprime el tablero por primera vez.
 * \param iAnt short Posici&oacute; en renlones de casilla anterior.
 * \param jAnt short Posici&oacute; en columnas de casilla anterior.
 * \param casillaActual short N&uacute;mero que representa la casilla en la que se encuentre.
 * \param const bool * const *arregloEstados Arreglo que contiene los estados de las casillas del tablero.
 * \return void
 *
 */
void ImprimeTablero( short tamCuadroTab, short tamTab, short anchoPantalla, short alturaPantalla, short posIY, short primeraVez, short iAnt, short jAnt, short casillaActual, const bool * const *arregloEstados );



#endif //LIGHTSOUTNUEVO_OBJETOS_H
