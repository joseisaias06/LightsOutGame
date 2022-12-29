/** \file Texto.h
 * \brief Archivo que contiene los prototipos de las funciones de ayuda para el manejo del texto.
 *
 * \author Olmos, Ortiz y Partida
 * \date 29 / Mayo / 2020
 */
#ifndef LIGHTSOUTNUEVO_TEXTO_H
#define LIGHTSOUTNUEVO_TEXTO_H

//**************************************************************************************************************************
/**
 * \brief Funci&oacute;n que obtiene la posici&oacute;n inicial donde se cituar&aacute; un objeto
 *
 * \param short espacioTotal Espacio en donde de colocar&aacute; un objeto.
 * \param short espacioObjeto Espacio del objeto que ser&aacute; colocado.
 *
 */
int posicionInicial( short espacioTotal, short espacioObjeto );

//**************************************************************************************************************************

/**
 * \brief Funci&oacute;n que centrar un texto en un espacio determinado.
 *
 * \param const char* texto Texto que ser&aacute; centrado.
 * \param short coordY Coordenada en y en la cual ser&aacute; centrado.
 * \param short espacioHor Espacio horizontal en la cual se centrar&aacute; el objeto.
 *
 */
void CentrarTexto( const char *texto, short coordY, short espacioHor );

//**************************************************************************************************************************

/**
* \brief Funci&oacute;n que centra un texto que se encuentra dentro de un objeto.
*
* \param const char *texto Texto a centtar
* \param short coordY posici�n de la altura a la que se quiere centrar el texto.
* \param short anchoObjeto Tama&ntilde;o del ancho del objeto en el que se encuentra el texto
* \param short alturaObjeto Tama&ntilde;o del alto del objeto en el que se encuentra el texto
* \param short coordXObjeto posici&oacute;n, respecto al ancho de la ventana de ejecuci&oacute;n, en el que se encuentra el objeto.
*
**/
void CentrarTextoEnObj( const char *texto, short coordY, short anchoObjeto, short coordXObjeto, short alturaObjeto );

//**************************************************************************************************************************

/**
* \brief Funci&oacute;n que centra un texto que se encuentra dentro de un objeto.
*
* \param const char *texto Texto a centtar
* \param short coordY Posici&oacute;n de la altura a la que se quiere centrar el texto.
* \param short anchoObjeto Tama&ntilde;o del ancho del objeto en el que se encuentra el texto
* \param short alturaObjeto Tama&ntilde;o del alto del objeto en el que se encuentra el texto
* \param short coordXObjeto posici�n, respecto al ancho de la ventana de ejecuci�n, en el que se encuentra el objeto.
*
**/
void CentrarVariableEnObj( short variable, short tamTexto, short coordY, short anchoObjeto, short coordXObjeto, short alturaObjeto );

//**************************************************************************************************************************

/**
* \brief Funci&oacute;n que alinea un texto hacia la izquierda.
*
* \param const char *texto Texto a centtar
* \param short coordY posici&oacute;n de la altura a la que se quiere centrar el texto.
* \param short anchoObjeto Tama&ntilde;o del ancho del objeto en el que se encuentra el texto
* \param short alturaObjeto Tama&ntilde;o del alto del objeto en el que se encuentra el texto
* \param short coordXObjeto posici&oacute;n respecto al ancho de la ventana de ejecuci�n en el que se encuentra el objeto.
*
**/
void AlinearIzquierda( const char *texto, short coordY, short posX, short  margen );

#endif //LIGHTSOUTNUEVO_TEXTO_H

