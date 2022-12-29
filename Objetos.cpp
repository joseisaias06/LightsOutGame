/*
Nombre: Objetos.cpp
Autor: Olmos, Ortiz y Partida
Fecha: 29 de Mayo de 2020
Descripci�n: Archivo que contiene la implementaci�n de las funciones encargadas de el dise�o de los objetos visibles del programa.
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <windows.h>

// Funcione y ennumeraciones de utiler�a general
#include "Utileria.h"
// Funciones para manejo de m�rgenes de texto
#include "Texto.h"

using std::cout;
using std::endl;

//**************************************************************************************************************************
void Area( short &anchoPantalla, short &altoPantalla, short tamHorizontal, short tamVertical )
{
    anchoPantalla = tamHorizontal; // Cambio del tama�o horizontal de la pantalla
    altoPantalla = tamVertical; // Cambio del tama�o vertical de la pantalla
}

//**************************************************************************************************************************
void DibujarRectangulo( short ancho , short alto, short posX, short posY )
{
    gotoxy (posX,posY);
    for(int i = 1; i <= alto; ++i){
        for(int j = 0; j < ancho; ++j){
            cout << " ";
        }
        gotoxy( posX, posY+i );
    }
}
//**************************************************************************************************************************
void DibujarMarcoSinFondo( short ancho , short alto, short x, short y )
{
    gotoxy (x,y);
    int i;
    // Techo
    cout << char(ESQ_SUP_IZQ);
    for (i = 2; i < ancho; ++i ){
        cout << char(BARRA_H);
    }
    cout << char(ESQ_SUP_DER) << endl;

    // Pared
    gotoxy(x,y+1);
    for (i = 2; i < alto; ++i) {
        y+=1;
        gotoxy(x,y);
        cout << char(BARRA_V);
        gotoxy(x+ancho-1, y);
        cout << char(BARRA_V) << endl;
    }
    // Piso
    gotoxy(x,y);
    cout << char(ESQ_INF_IZQ);

    for (i = 2; i < ancho; ++i ){
        cout << char(BARRA_H);
    }
    cout << char(ESQ_INF_DER);

}
//**************************************************************************************************************************
void DibujarMarcoDobleSinFondo( short ancho , short alto, short x, short y )
{
    gotoxy (x,y);
    int i;
    // Techo
    cout << char(ESQ_SUP_IZQD);
    for (i = 2; i < ancho; ++i ){
        cout << char(BARRA_HD);
    }
    cout << char(ESQ_SUP_DERD) << endl;

    // Pared
    gotoxy(x,y+1);
    for (i = 2; i < alto; ++i) {
        y+=1;
        gotoxy(x,y);
        cout << char(BARRA_VD);
        gotoxy(x+ancho-1, y);
        cout << char(BARRA_VD) << endl;
    }
    // Piso
    gotoxy(x,y);
    cout << char(ESQ_INF_IZQD);

    for (i = 2; i < ancho; ++i ){
        cout << char(BARRA_HD);
    }
    cout << char(ESQ_INF_DERD);

}
//**************************************************************************************************************************
void DibujarMarco( short ancho , short alto, short x, short y )
{
    gotoxy (x,y);
    int i,j;
    // Techo
    cout << char(ESQ_SUP_IZQ);
    for (i = 2; i < ancho; ++i ){
        cout << char(BARRA_H);
    }
    cout << char(ESQ_SUP_DER) << endl;

    // Pared
    gotoxy(x,y+1);
    for (i = 2; i < alto; ++i) {
        y+=1;
        gotoxy(x,y);
        cout << char(BARRA_V);
        for (j = 2; j < ancho; ++j){
            cout << ESPACIO;
        }
        cout << char(BARRA_V) << endl;
    }
    // Piso
    gotoxy(x,y);
    cout << char(ESQ_INF_IZQ);

    for (i = 2; i < ancho; ++i ){
        cout << char(BARRA_H);
    }
    cout << char(ESQ_INF_DER);

}
//**************************************************************************************************************************
void Boton( const char *opcion, short posX, short anchoBoton, short alturaBoton, short coordY )
{
    DibujarRectangulo( anchoBoton, alturaBoton, posX , coordY );

    CentrarTextoEnObj( opcion, coordY, anchoBoton, posX, alturaBoton );
}
//**************************************************************************************************************************
void CuadroIntentos( const char *texto, short contadorIntentos, short ancho, short altura, short espacioHor, short espacioVer, short posIX, short posIY, bool primeraVez  )
{
    EstablecerColor( AMARILLO, NEGRO );
    int posX = posicionInicial( espacioHor, ancho ) + posIX;
    int posY = posicionInicial( espacioVer, altura ) + posIY;

    char tamTexto = strlen(texto);
    if(primeraVez){
        DibujarMarcoSinFondo( ancho+2, altura+1, posX, posY );
        CentrarTextoEnObj( texto, posY, ancho, posX, altura );
    }
    CentrarVariableEnObj( contadorIntentos, tamTexto, posY, ancho, posX-3, altura);
}
//**************************************************************************************************************************
void CuadroLuces( const char *texto, short contadorLuces, short ancho, short altura, short espacioHor, short espacioVer, short posIX, short posIY, bool primeraVez  )
{
    EstablecerColor( AMARILLO, NEGRO );
    int posX = posicionInicial( espacioHor, ancho ) + posIX;
    int posY = posicionInicial( espacioVer, altura ) + posIY;

    char tamTexto = strlen(texto);

    if(contadorLuces < 10)
        DibujarRectangulo( 1, 1, posX+21, posY+1 );

    if(primeraVez){
        DibujarMarcoSinFondo( ancho+2, altura+1, posX, posY );
        CentrarTextoEnObj( texto, posY, ancho, posX, altura );
    }
    CentrarVariableEnObj( contadorLuces, tamTexto, posY, ancho, posX, altura);
}
//**************************************************************************************************************************
void CuadroInfo( short espacioHor, short espacioVer, short posIX, short posIY  )
{
    EstablecerColor( AMARILLO, NEGRO );
    short ancho =  22;
    short altura = 23;
    int posX = posicionInicial( espacioHor, ancho ) + posIX;
    int posY = posicionInicial( espacioVer, altura ) + posIY;

    DibujarMarcoSinFondo( ancho, altura, posX, posY );
    AlinearIzquierda( "- Informaci\xA2n -",  posX, posY+2, 2 );
    AlinearIzquierda( "Encendido: ",  posX, posY+4, 2 );
    gotoxy(posX+13, posY+4);
    EstablecerColor(BLANCO, NEGRO);
    cout << " ";
    EstablecerColor(AMARILLO, NEGRO);
    AlinearIzquierda( "Apagado: ", posX, posY+6, 2 );
    gotoxy(posX+13, posY+6);
    EstablecerColor(NEGRO, NEGRO);
    cout << " ";
    EstablecerColor(AMARILLO, NEGRO);
    AlinearIzquierda( "Selector: ",  posX, posY+8, 2 );
    gotoxy(posX+12, posY+8);
    EstablecerColor(AMARILLOCLARO, NEGRO);
    cout << "[]";
    EstablecerColor(AMARILLO,NEGRO);
    AlinearIzquierda( "- Teclas -",  posX, posY+11, 2 );
    AlinearIzquierda( "ESC: Men\xA3 opciones",  posX, posY+13, 2 );
    AlinearIzquierda( "G: Guardar partida",  posX, posY+15, 2 );
    AlinearIzquierda("L: Cargar partida", posX, posY+17, 2);
}
void DibujarEnter( short posX, short posY, bool Presionar )
{
    if( Presionar ){
        EstablecerColor( AMARILLOCLARO, NEGRO );
        DibujarMarcoSinFondo(7, 6,posX,posY);
        Sleep(200);
    }
    EstablecerColor(NEGRO, AMARILLO);
    DibujarMarcoSinFondo(7, 6,posX,posY);
    CentrarTextoEnObj("Enter",posY,7,posX,4);
    CentrarTextoEnObj("<--",posY+1,7,posX,4);
}

void DibujarFoco( short posX, short posY, bool Presionar )
{
    DibujarMarcoSinFondo(5,5, posX, posY);
    ( Presionar ) ? EstablecerColor( BLANCO, AMARILLO ) : EstablecerColor(NEGRO, AMARILLO);
    DibujarRectangulo(3,2,posX+1,posY+1);
    EstablecerColor(NEGRO, AMARILLO);
}

void DibujarFlechas( short posX, short posY, short Presionar )
{
    gotoxy(posX+3,posY-6);
    cout << "Movimiento";
    if( Presionar == 3 ){
        EstablecerColor( AMARILLOCLARO, NEGRO );
        DibujarMarcoSinFondo(5,5, posX+5, posY-4);
        Sleep(200);
    }
    EstablecerColor( NEGRO, AMARILLO );
    DibujarMarcoSinFondo(5,5, posX+5, posY-4);
    CentrarTextoEnObj("^",posY-4,5,posX+5,5);

    if( Presionar == 2 ){
        EstablecerColor( AMARILLOCLARO, NEGRO );
        DibujarMarcoSinFondo(5,5, posX+10, posY);
        Sleep(200);
    }
    EstablecerColor( NEGRO, AMARILLO );
    DibujarMarcoSinFondo(5,5, posX+10, posY);
    CentrarTextoEnObj(">",posY,5,posX+10,5);

    if( Presionar == 4 ){
        EstablecerColor( AMARILLOCLARO, NEGRO );
        DibujarMarcoSinFondo(5,5, posX+5, posY);
        Sleep(200);
    }
    EstablecerColor( NEGRO, AMARILLO );
    DibujarMarcoSinFondo(5,5, posX+5, posY);
    CentrarTextoEnObj("v",posY,5,posX+5,5);

    if( Presionar == 1 ){
        EstablecerColor( AMARILLOCLARO, NEGRO );
        DibujarMarcoSinFondo(5,5, posX, posY);
        Sleep(200);
    }
    EstablecerColor( NEGRO, AMARILLO );
    DibujarMarcoSinFondo(5,5, posX, posY);
    CentrarTextoEnObj("<",posY,5,posX,5);
}
//**************************************************************************************************************************
void cuadroInstrucciones( short anchoPantalla, short altoPantalla, bool primeraVez, short posIX, short posIY, short nPagina )
{
    EstablecerColor( NEGRO, AMARILLO );
    short ancho = anchoPantalla - 6;
    short altura = 22;
    int posX = posicionInicial( anchoPantalla, ancho ) + posIX;
    int posY = posicionInicial( altoPantalla, altura ) + posIY;

    if(primeraVez){
        CentrarTexto("INSTRUCCIONES", 1, anchoPantalla);
        DibujarMarcoDobleSinFondo(ancho, altura, posX, posY);
        CentrarTexto("CONTROLES", 25, anchoPantalla);

    }
    switch(nPagina){
        case 1:
            DibujarRectangulo(ancho-10,altura-5,8,5);
            AlinearIzquierda("- Lights Out consiste en un tablero de luces de 5x5.",3,6,5);
            AlinearIzquierda("- Cualquiera de las luces puede estar en uno de dos estados, encendida o apagada.",3,8,5);
            AlinearIzquierda("- Al comenzar el juego un n\xA3mero aleatorio de estas luces se encontrar\xA0",3,10,5);
            AlinearIzquierda("  encendidas.",3,11,5);
            AlinearIzquierda("- El jugador puede seleccionar una casilla individual utilizando las flechas en",3,13,5);
            AlinearIzquierda("  el teclado y al pulsar la tecla Enter, dicha luz se alternar\xA0 junto con las",3,14,5);
            AlinearIzquierda("  4 luces adyacentes, cambiando su estado. ",3,15,5);
            AlinearIzquierda("- Si la luz estaba encendida, ser\xA0 apagada, y viceversa. ",3,17,5);
            AlinearIzquierda("- El objetivo del juego es apagar todas las luces, con el menor n\xA3mero de ",3,19,5);
            AlinearIzquierda("  movimientos.",3,20,5);
            CentrarTexto("1/2",22,anchoPantalla);
            break;
        case 2:
            DibujarRectangulo(ancho-10,altura-5,8,6);
            AlinearIzquierda("- Historia:",3,5,5);
            AlinearIzquierda("  Lights Out es un juego electr\xA2nico, publicado por Tiger Toys en 1995 ",3,7,5);
            AlinearIzquierda("  (comprado por Hasbro en 1998).",3,8,5);
            AlinearIzquierda("  Se desarrollaron varias versiones a trav\xA82s de los a\xA4os, Mini Lights Out,",3,10,5);
            AlinearIzquierda("  con un tablero de 4x4, Lights Out Deluxe, de 6x6, etc. En 1997, Tiger",3,11,5);
            AlinearIzquierda("  sac\xA2 a la venta el Game.com, un competidor del Gameboy de Nintendo,",3,12,5);
            AlinearIzquierda("  y Lights Out fue uno de los juegos publicados para la consola.",3,13,5);
            AlinearIzquierda("  Aunque Tiger recibi\xA2 una patente para Lights Out, no fueron los primeros",3,15,5);
            AlinearIzquierda("  en producir este tipo de rompecabezas. Merlin, producido por los Hermanos",3,16,5);
            AlinearIzquierda("  Parker en 1978, ten\xA1 \ba diferentes juegos en su tablero electr\xA2nico,",3,17,5);
            AlinearIzquierda("  incluyendo uno llamado �Magic Square�. Era parecido a Lights Out, pero",3,18,5);
            AlinearIzquierda("  con un tama\xA4o de 3x3, e inclu\xA1 \ba botones con diferentes efectos.",3,19,5);
            CentrarTexto("2/2",22,anchoPantalla);
            break;
    }
}
//**************************************************************************************************************************
void BotonesMenu( const char *opcion, short anchoPantalla, short alturaPantalla, short anchoBoton, short alturaBoton, short coordY, bool estado, short posIX, short posIY )
{
    ( estado ) ? EstablecerColor(  AMARILLOCLARO, NEGRO ) : EstablecerColor( AMARILLO, NEGRO ) ;

    short posX = posicionInicial( anchoPantalla, anchoBoton ) + posIX;

    Boton( opcion, posX, anchoBoton, alturaBoton, coordY+posIY );
}

//**************************************************************************************************************************
void ImprimirTituloTren( short anchoPantalla, short altoPantalla, short posIX, short posIY )
{
    // Propiedades del t�tulo
    short anchoTitulo = strlen(" {======|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"'\"|_|\"\"\"\"\"| {======|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|");
    short posX = posicionInicial( anchoPantalla , anchoTitulo ) + posIY;
    short posY = posicionInicial( altoPantalla , 9) + posIX;
    EstablecerColor( AMARILLO, NEGRO );
    DibujarMarcoSinFondo( 93, 9, posX, posY );
    gotoxy(++posX, ++posY);
    cout << "            _        _      __ _   _        _                         ___             _   ";
    gotoxy(posX, posY+1);
    cout << "    o O O  | |      (_)    / _` | | |_     | |_      ___      o O O  / _ \\   _  _    | |_  ";
    gotoxy(posX, posY+2);
    cout << "   o       | |__    | |    \\__, | | ' \\    |  _|    (_-<     o      | (_) | | +| |   |  _| ";
    gotoxy(posX, posY+3);
    cout << "  TS__[O]  |____|  _|_|_   |___/  |_||_|   _\\__|    /__/_   TS__[O]  \\___/   \\_,_|   _\\__| ";
    gotoxy(posX, posY+4);
    cout << " {======|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"'\"|_|\"\"\"\"\"| {======|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|";
    gotoxy(posX, posY+5);
    cout << "./o--000'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-' ./o--000'\"`-0-0-'\"`-0-0-'\"`-0-0-'";
}
//**************************************************************************************************************************
void ImprimirTituloOpciones( short anchoPantalla, short altoPantalla, short posIX, short posIY )
{
    // Propiedades del t�tulo
    short anchoTitulo = strlen("| | | | '_ \\ / __| |/ _ \\| '_ \\ / _ / __|");
    short posX = posicionInicial( anchoPantalla , anchoTitulo ) + posIX;
    short posY = posicionInicial( altoPantalla , 10) + posIY;
    EstablecerColor( AMARILLO, NEGRO );
    DibujarMarcoSinFondo( anchoTitulo+2, 10, posX, posY );
    gotoxy(++posX, ++posY);
    cout << " _____            _                      ";
    gotoxy(posX, posY+1);
    cout << "|  _  |          (_)                     ";
    gotoxy(posX, posY+2);
    cout << "| | | |_ __   ___ _  ___  _ __   ___ ___ ";
    gotoxy(posX, posY+3);
    cout << "| | | | '_ \\ / __| |/ _ \\| '_ \\ / _ / __|";
    gotoxy(posX, posY+4);
    cout << "\\ \\_/ | |_) | (__| | (_) | | | |  __\\__ \\";
    gotoxy(posX, posY+5);
    cout << " \\___/| .__/ \\___|_|\\___/|_| |_|\\___|___/";
    gotoxy(posX, posY+6);
    cout << "      |_|                                ";

}
//**************************************************************************************************************************
void Felicitar( short anchoPantalla, short altoPantalla, short posIX, short posIY, int Intentos)
{
    // Propiedades del t�tulo
    short anchoTitulo = strlen(" {======|_| \"\"\" |_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| ");
    short posX = posicionInicial( anchoPantalla , anchoTitulo ) + posIX;
    short posY = posicionInicial( altoPantalla , altoPantalla) + posIY;
    EstablecerColor( NEGRO, AMARILLO );
    DibujarMarco( anchoTitulo+2, 12, posX, posY );
    gotoxy(++posX, ++posY);
    cout << "             ___             _       _               _        _               _                   ";
    gotoxy(posX, posY+1);
    cout << "    o O O   | __|   ___     | |     (_)     __      (_)    __| |   __ _    __| |    ___     ___   ";
    gotoxy(posX, posY+2);
    cout << "   o        | _|   / -_)    | |     | |    / _|     | |   / _` |  / _` |  / _` |   / -_)   (_-<   ";
    gotoxy(posX, posY+3);
    cout << "  TS__[O]  _|_|_   \\___|   _|_|_   _|_|_   \\__|_   _|_|_  \\__,_|  \\__,_|  \\__,_|   \\___|   /__/_  ";
    gotoxy(posX, posY+4);
    cout << " {======|_| \"\"\" |_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| ";
    gotoxy(posX, posY+5);
    cout << "./o--000'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-' ";
    gotoxy(posX+20, posY+6);
    cout << "Terminaste el tablero en un total de: " << Intentos << " Intentos." << endl;
    gotoxy(posX+5, posY+7);
    cout << "Lo has hecho muy bien! Seguro que puedes lograrlo en un menor n\243mero de Intentos!";
    gotoxy(posX+30, posY+8);


}
//**************************************************************************************************************************
void ImprimeTablero( short tamCuadroTab, short tamTab, short anchoPantalla, short alturaPantalla, short posIY, short primeraVez, short iAnt, short jAnt, short casillaActual, const bool * const *arregloEstados  )
{
    // Propiedades objeto
    int tamTotalY = tamTab*(tamCuadroTab-1);
    int tamTotalX = tamTab*tamCuadroTab;
    int posX = posicionInicial( anchoPantalla, tamTotalX);
    int posY = posicionInicial( alturaPantalla, tamTotalY) + posIY;
    EstablecerColor( NEGRO, BLANCO );
    DibujarMarcoSinFondo( tamTotalX+2, tamTotalY+3, posX-1, posY-1 );

    // Ciclo para verificar los estados de las casillas e imprimir los cambios de estado.
    short verificaCasilla = 0;
    for( int i = 0; i < tamTab; ++i ){
        for( int j = 0; j < tamTab; ++j ){
            ( arregloEstados[i][j] ) ? EstablecerColor( BLANCO, NEGRO ) : EstablecerColor( NEGRO, NEGRO) ;
            DibujarRectangulo( tamCuadroTab-2, tamCuadroTab-3, ( posX + tamCuadroTab*j+1 ), posY+(tamCuadroTab-1)*i+1  );
            verificaCasilla = i*5+j;
        }
    }

    // Ciclo que imprime las orillas de las casillas (condici�n: que se imprima solo la primera vez)
    if(primeraVez){
        for( int i = 0; i < tamTab; ++i ){
            for( int j = 0; j < tamTab; ++j ){
                if( verificaCasilla == casillaActual) continue;
                EstablecerColor( NEGRO,AMARILLO );
                DibujarMarcoSinFondo( tamCuadroTab, tamCuadroTab, ( posX + tamCuadroTab*j ), posY+(tamCuadroTab-1)*i  );
            }
        }
    }
    // Ciclo que verifica cu�l es la casilla actual, la resalta de otro color y borra la posici�n anterior
    short verificaCasillaAnterior = iAnt*5+jAnt;
    for( int i = 0; i < tamTab; ++i ){
        for( int j = 0; j < tamTab; ++j ){
            verificaCasilla = i*5+j;
            if( verificaCasilla == casillaActual ){
                EstablecerColor( AMARILLOCLARO, NEGRO);
                DibujarMarcoSinFondo( tamCuadroTab, tamCuadroTab, ( posX + tamCuadroTab*j ), posY+(tamCuadroTab-1)*i  );
            }
            if( verificaCasillaAnterior != casillaActual){
                EstablecerColor( NEGRO,AMARILLO );
                DibujarMarcoSinFondo( tamCuadroTab, tamCuadroTab, ( posX + tamCuadroTab*jAnt ), posY+(tamCuadroTab-1)*iAnt  );
            }
        }
    }
}

