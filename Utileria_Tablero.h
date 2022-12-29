/** \file Utileria_Tablero.h
 * \brief Archivo que contiene los prototipos de las funciones encargadas de crear, guardar y barajar el tablero.
 *
 * \author Olmos, Ortiz y Partida
 * \date 29 / Mayo / 2020
 */

#ifndef LIGHTSOUTNUEVO_UTILERIA_TABLERO_H
#define LIGHTSOUTNUEVO_UTILERIA_TABLERO_H

/** \brief Funci&oacute;n que crea un arreglo bidimensional din&aacute;mico, en el se que capturar&aacute; el tablero.
 *
 * \param m Cantidad de renglones de la matriz.
 * \param n Cantidad de columnas de la matriz.
 *
 * \pre Valor de renglones mayor a 0 y menor a 21
 * \pre Valor de columnas mayor a 0 y menor a 21
 */
bool **CrearTableroEstados( int m, int n );


/** \brief Funci&oacute;n que elimina el arreglo bidimensional din&aacute;mico y libera la memoria.
*
* \param **& Matriz Arreglo que se eliminar&aacute;.
* \param m Cantidad de renglones del arreglo que se eliminar&aacute;.
*/
void DestruirTableroEstados( bool **&Matriz, short m );

/** \brief Funci&oacute;n que guarda el progreso actual de un tablero en un archivo ".txt".
*
* \param const bool * const *Tablero Tablero que se guardar&aacute;
* \param short Luces Cantidad de luces encendidas del tablero a guardar
*/
bool GuardarProgresoTablero( const bool * const *Tablero, short Luces );


/** \brief Funci&oacute;n que captura los datos de un tablero desde un archivo.txt
 *
 * \param const char *numeroTablero Nombre del archivo.txt del que se capturar&aacute;n los datos.
 * \param bool * const *Tablero Arreglo en el que se cargarn&aacute; los elementos capturados del archivo.txt.
 * \param short &LucesEncendidas Cantidad de luces encendidas que se modificar&aacute;n una vez capturadas del archivo.txt
 */
void CapturarTablero(const char *numeroTablero, bool * const *Tablero, short &LucesEncendidas);

/**
*
*\brief Funci&oacute;n que barajea la cantidad de tableros resolubles disponibles.
*
*\param cantidadTableros cantidad de tableros resolubles disponibles.
*
*\pre cantidadTableros mayor a 0
*/
int BarajarTableros(int cantidadTableros);

#endif //LIGHTSOUTNUEVO_UTILERIA_TABLERO_H
