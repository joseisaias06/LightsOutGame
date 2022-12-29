/** \file Utileria.h
 * \brief Archivo que contiene los prototipos de las funciones y ennumeraciones de ayuda para el formato del programa.
 *
 * \author Olmos, Ortiz y Partida
 * \date 29 / Mayo / 2020
 */
#ifndef LIGHTSOUTNUEVO_UTILERIA_H
#define LIGHTSOUTNUEVO_UTILERIA_H

#define ESPACIO ' '

//*************************************************************************************************************************
/** Asignaci&oacute;n del n�mero representante de teclas a constantes */

#define ESCAPE 27       /**< Tecla Escape */
#define ARRIBA 72       /**< Tecla Arriba */
#define IZQUIERDA 75    /**< Tecla Izquierda */
#define DERECHA 77      /**< Tecla Derecha */
#define ABAJO 80        /**< Tecla Abajo */
#define ENTER 13        /**< Tecla Enter */
#define GMAY 71         /**< Tecla G may&uacute;scula */
#define GMIN 103        /**< Tecla G min&uacute;scula */
#define XMAY 88         /**< Tecla X may&uacute;scula */
#define XMIN 120        /**< Tecla X min&uacute;scula */
#define ZMAY 90         /**< Tecla Z may&uacute;scula */
#define ZMIN 122        /**< Tecla Z min&uacute;scula */
#define LMIN 108        /**< Tecla L min&uacute;scula */
#define LMAY 76         /**< Tecla L may&uacute;scula */

//*************************************************************************************************************************
/** Asignaci&oacute;n de colores de consola y letra a una lista */
enum Color{
    NEGRO,          /**< Color negro */
    AZUL,           /**< Color azul fuerte */
    VERDE,          /**< Color verde oscuro */
    AGUAMARINA,     /**< Color azul verde */
    ROJO,           /**< Color rojo oscuro */
    PURPURA,        /**< Color morado */
    AMARILLO,       /**< Color amarillo */
    GRISCLARO,      /**< Color gris claro */
    GRIS,           /**< Color gris oscuro */
    AZULCLARO,      /**< Color azul cielo */
    VERDECLARO,     /**< Color verde claro */
    AGUAMARINACLARO,/**< Color azul verde claro */
    ROJOCLARO,      /**< Color rojo claro */
    MAGENTA,        /**< Color rosa fuerte */
    AMARILLOCLARO,  /**< Color amarillo claro */
    BLANCO          /**< Color blanco */
};

//*************************************************************************************************************************
/** Estados del cursor */
enum EstadoCursor{
    APAGADO,        /**< Cursor no visible */
    ENCENDIDO       /**< Cursor visible */
};

//*************************************************************************************************************************
/** Modos o tama&ntilde;os del cursor */
enum ModoCursor{
    MINI = 5,       /**< Tama&ntilde;o de cursor peque&ntilde;o */
    NORMAL = 20,    /**< Tama&ntilde;o de cursor mediano  */
    SOLIDO = 80     /**< Tama&ntilde;o de cursor grande */
};

//*************************************************************************************************************************
/** Caracteres para dibujar un marco simple */
enum {BARRA_V = 179, ESQ_SUP_DER = 191, ESQ_INF_IZQ, BARRA_H = 196, ESQ_INF_DER = 217, ESQ_SUP_IZQ};

//*************************************************************************************************************************
/** Caracteres para dibujar un marco doble */
enum {BARRA_VD = 186, ESQ_SUP_DERD, ESQ_INF_DERD, ESQ_INF_IZQD = 200, ESQ_SUP_IZQD, BARRA_HD = 205 };

//*************************************************************************************************************************
bool AjustarVentana(int Ancho, int Alto);
/**
 * \brief Modifica el estado del cursor.
 *
 * \param estado Estado del cursor a establecer. Puede ser un valor de la enumeraci&oacute;n EstadoCursor
 * \param modo Tama&ntilde;o del indicador del cursor. Puede ser un valor de la enumeraci&oacute;n ModoCursor. Si se omite, tomar&aacute; el valor NORMAL.
 **/
void CambiarCursor(EstadoCursor estado, ModoCursor modo = NORMAL);

//*************************************************************************************************************************

/**
 * \brief Establece el tama&ntilde;o de la ventana de ejecuci&oacute;n.
 *
 * \param ancho Valor entero para el ancho de la ventana.
 * \param alto Valor entero para el alto de la ventana.
 **/
void EstablecerTamVentana(short ancho, short alto);

//*************************************************************************************************************************

/** \brief Establece el color de fondo y texto para impresi&oacute;n. Despu&eacute;s de establecer el color, lo que se imprima aparecer&aacute; con esta combinaci&oacute;n de colores.
 *
 * \param colorFondo El color de fondo del texto a imprimir
 * \param colorTexto Color del texto a imprimir
 *
 * \pre Tanto el color del fondo y del texto deben ser no negativos. Son valores de la enumeraci&oacute;n tipo Color.
 */
void EstablecerColor(Color colorFondo, Color colorTexto);

//**************************************************************************************************************************

/** \brief Mueve el cursor a una posicion (x,y)
*
* \param x Coordenada en x.
* \param y Coordenada en y.
*
* \pre x Debe ser mayor a 0 y menor al tama&ntilde;o de la pantalla.
* \pre y Debe ser mayor a 0 y menor al tama&ntilde;o de la pantalla.
*/
void gotoxy(short x,short y);

/** \brief Funcion que cambia de formato a la pantalla actual.
 *
 * \param anchoPantalla Anchura a la cual se adaptar&aacute; la pantalla.
 * \param altoPantalla Altura a la cual se adaptar&aacute; la pantalla.
 * \param colorFondo El color de fondo del texto a imprimir.
 * \param colorTexto Color del texto a imprimir.
 * \param eMouse Estado del mouse. Puede ser ENCENDIDO o APAGADO.
 * \return
 *
 */
void FormatoPantalla (short anchoPantalla, short altoPantalla, Color colorFondo, Color colorTexto, EstadoCursor eMouse );


#endif //LIGHTSOUTNUEVO_UTILERIA_H