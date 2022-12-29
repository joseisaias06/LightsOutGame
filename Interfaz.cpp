/*
Nombre: Interfaz.cpp
Autor: Olmos, Ortiz y Partida
Fecha: 29 de Mayo de 2020
Descripci�n: Archivo que contiene la implementaci�n de las funciones encargadas de la gesti�n de le las interfaces.
*/

#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<cstdio>
#include<cstring>
#include<time.h>

// Funcione y ennumeraciones de utiler�a general.
#include"Utileria.h"
// Funciones de utiler�a para crear, guardar y barajar los tableros.
#include"Utileria_Tablero.h"
// Funciones de proceso para cada interfaz.
#include"ProcesoInterfaz.h"
// Funciones con dise�o de los objetos
#include"Objetos.h"
// Funciones para manejo de m�rgenes de texto
#include"Texto.h"

using std::cin;
using std::bad_alloc;
using std::cout;
using std::endl;

//**************************************************************************************************************************
void InterfazCreditos (  )
{
    short anchoPantalla = 100, altoPantalla = 38;
    FormatoPantalla(anchoPantalla,altoPantalla,NEGRO,AMARILLO,APAGADO);

    CreditosActual( anchoPantalla, altoPantalla );
    while( true ){
        if(kbhit()){
            char tecla = getch();
            if( tecla == ESCAPE ){
                system("cls");
                break;
            }
        }
    }
}
//**************************************************************************************************************************
void InterfazInstrucciones(  )
{
    // Configuraci�n de pantalla
    short anchoPantalla = 100, altoPantalla = 38;
    FormatoPantalla(anchoPantalla, altoPantalla, NEGRO, AMARILLO, APAGADO);

    short pintarTodo = 1;
    short nPagina = 1;
    bool enter = false;
    bool foco = false;
    short flecha = 0;
    InstruccionesActual( anchoPantalla, altoPantalla, pintarTodo, nPagina, flecha, foco, enter );
    while( true ){
        if(kbhit()){
            char tecla = getch();
            if( tecla == ESCAPE ){
                system("cls");
                break;
            }
            if( tecla == ENTER ){
                enter = true;
                ( foco ) ? (foco = false) : (foco = true);
            }
            if( tecla == IZQUIERDA ){
                flecha = 1;
            }
            if( tecla == DERECHA ){
                flecha = 2;

            }
            if( tecla == ARRIBA ){
                flecha = 3;

            }
            if( tecla == ABAJO ){
                flecha = 4;
            }
            if( tecla == ZMAY || tecla == ZMIN ){
                if(nPagina != 1)
                    nPagina--;
                pintarTodo = 1;
            }
            if( tecla == XMAY || tecla == XMIN ){
                if(nPagina != 2)
                    nPagina++;
                pintarTodo = 1;
            }
            InstruccionesActual( anchoPantalla, altoPantalla, pintarTodo, nPagina, flecha, foco, enter  );
            pintarTodo = 0;
            flecha = 0;
            enter = false;
        }
    }

}

//**************************************************************************************************************************
int MenuPrincipal( )
{
    // Configuraci�n de pantalla
    short anchoPantalla = 100, altoPantalla = 38;
    FormatoPantalla(anchoPantalla, altoPantalla, AMARILLO, NEGRO,APAGADO);

    short opcion = 1; // Variable para guardar la opci�n del men� de inicio
    PrincipalActual( opcion, anchoPantalla, altoPantalla );
    while( true ){
        if(kbhit()){
            char tecla = getch();
            if( tecla == ENTER ){
                return opcion;
            }
            if( tecla == ARRIBA ){
                if( opcion != 1)
                    --opcion;
            }
            if( tecla == ABAJO ){
                if( opcion != 4 )
                    ++opcion;
            }
            PrincipalActual( opcion, anchoPantalla, altoPantalla );
        }
    }
}

//**************************************************************************************************************************
void solicitudGuardar( short anchoPantalla, short altoPantalla, const bool * const *Tablero, short tamTablero, short lucesOn )
{
    short opcion = 1; // Variable para guardar la opci�n del men� de inicio
    short pintarMarco = 1;
    bool guardar = 0;
    solicitudGuardarActual( opcion, anchoPantalla, altoPantalla, pintarMarco, guardar, Tablero, tamTablero, lucesOn );
    while( true ){
        if(kbhit()){
            char tecla = getch();
            if( tecla == ENTER ){
                if( opcion == 1){
                    guardar = 1;
                    solicitudGuardarActual( opcion, anchoPantalla, altoPantalla, pintarMarco, guardar, Tablero, tamTablero, lucesOn );
                    break;
                }
                if( opcion == 2 ) break;
            }
            if( tecla == IZQUIERDA ){
                if( opcion != 1)
                    --opcion;
            }
            if( tecla == DERECHA ){
                if( opcion != 2 )
                    ++opcion;
            }
            pintarMarco = 0;
            solicitudGuardarActual( opcion, anchoPantalla, altoPantalla, pintarMarco, guardar, Tablero, tamTablero, lucesOn );
        }
    }
}

//**************************************************************************************************************************
void solicitudCargar( short anchoPantalla, short altoPantalla, bool **&Tablero, short Filas)
{
    short opcion = 1; // Variable para guardar la opci�n del men� de inicio
    short pintarMarco = 1;
    bool cargar = 0;
    solicitudCargarActual( opcion, anchoPantalla, altoPantalla, pintarMarco, cargar, Tablero, Filas);
    while( true ){
        if(kbhit()){
            char tecla = getch();
            if( tecla == ENTER ){
                if( opcion == 1){
                    cargar = 1;
                    solicitudCargarActual( opcion, anchoPantalla, altoPantalla, pintarMarco, cargar, Tablero, Filas);
                    break;
                }
                if( opcion == 2 ) break;
            }
            if( tecla == IZQUIERDA ){
                if( opcion != 1)
                    --opcion;
            }
            if( tecla == DERECHA ){
                if( opcion != 2 )
                    ++opcion;
            }
            pintarMarco = 0;
            solicitudCargarActual( opcion, anchoPantalla, altoPantalla, pintarMarco, cargar, Tablero, Filas);
        }
    }
}

//**************************************************************************************************************************
short MenuOpciones( )
{
    // Configuraci�n de pantalla
    short anchoPantalla = 100, altoPantalla = 38;


    short opcion = 1; // Variable para guardar la opci�n del men� de inicio
    short pintarTitulo = 1;
    MenuOpcionesActual( opcion, anchoPantalla, altoPantalla, pintarTitulo );
    while( true ){
        if(kbhit()){
            char tecla = getch();
            if( tecla == ENTER ){
                return opcion;
            }
            if( tecla == ARRIBA ){
                if( opcion != 1)
                    --opcion;
            }
            if( tecla == ABAJO ){
                if( opcion != 4 )
                    ++opcion;
            }
            pintarTitulo = 0;
            MenuOpcionesActual( opcion, anchoPantalla, altoPantalla, pintarTitulo );
        }
    }
}

//**************************************************************************************************************************
void InterfazJugar(bool CargarPartida = false)
{
    // Configuraci�n de pantalla
    short anchoPantalla = 100;
    short altoPantalla = 38;
    FormatoPantalla(anchoPantalla, altoPantalla, AMARILLO, NEGRO, APAGADO);

    srand(time(NULL));
    bool **TableroJugable = NULL;
    try{
        short Filas = 5, Columnas = 5;
        TableroJugable = CrearTableroEstados( Filas, Columnas );
        short LucesEncendidas = 0;

        for( short i = 0; i < Filas; ++i){
            for( short j = 0; j < Columnas; ++j)
                TableroJugable[i][j] = false;
        }

        int Tablero = BarajarTableros(24);
        char NombreTablero[40];
        if(CargarPartida == false)
            sprintf(NombreTablero, "Tableros//Tablero%d.txt", Tablero );
        else
            strcpy(NombreTablero, "Tableros//Progreso.txt");

        CapturarTablero( NombreTablero, TableroJugable, LucesEncendidas );

        short opcMenu;
        short casillaActual = 0;
        short posFila = 0, posColumna = 0; // Posicion inicial de tablero
        short posFilaA = 2, posColumnaA = 2;
        short cont = 0;

        short pintarTablero = 1;
        JugarActual( anchoPantalla, altoPantalla, cont, pintarTablero, posFilaA, posColumnaA, casillaActual, TableroJugable, LucesEncendidas );
        while(true){
            if(kbhit()){
                char tecla = getch();

                if( tecla == ESCAPE ){ // Salir pantalla
                    opcMenu = MenuOpciones();
                    switch(opcMenu){
                        case 1: break;
                        case 2: solicitudGuardar( anchoPantalla, altoPantalla, TableroJugable, Filas, LucesEncendidas ); break;
                        case 3: InterfazInstrucciones(); break;
                        case 4:
                            FormatoPantalla(anchoPantalla, altoPantalla, AMARILLO, NEGRO, APAGADO);
                            solicitudGuardar(anchoPantalla, altoPantalla, TableroJugable, Filas, LucesEncendidas); return;
                    }
                    FormatoPantalla(anchoPantalla, altoPantalla, AMARILLO, NEGRO, APAGADO);
                    pintarTablero = 1;
                }
                if( tecla == ENTER){
                    cont++;
                    if(TableroJugable[posFila][posColumna] == 0){
                        TableroJugable[posFila][posColumna] = 1;
                        ++LucesEncendidas;
                    }else{
                        TableroJugable[posFila][posColumna] = 0;
                        --LucesEncendidas;
                    }
//                    TableroJugable[posFila][posColumna] = !TableroJugable[posFila][posColumna];
//                    LucesEncendidas += TableroJugable[posFila][posColumna] ? 1 : -1;
                    if(posColumna != 4){
                        if(TableroJugable[posFila][posColumna + 1] == 0)
                        {
                            TableroJugable[posFila][posColumna + 1] = 1;
                            ++LucesEncendidas;
                        }else{
                            TableroJugable[posFila][posColumna + 1] = 0;
                            --LucesEncendidas;
                        }
                    }
                    if(posColumna != 0){
                        if(TableroJugable[posFila][posColumna - 1] == 0)
                        {
                            TableroJugable[posFila][posColumna - 1] = 1;
                            ++LucesEncendidas;
                        }else{
                            TableroJugable[posFila][posColumna - 1] = 0;
                            --LucesEncendidas;
                        }
                    }
                    if(posFila != 0){
                        if(TableroJugable[posFila - 1][posColumna] == 0)
                        {
                            TableroJugable[posFila - 1][posColumna] = 1;
                            ++LucesEncendidas;
                        }else{
                            TableroJugable[posFila - 1][posColumna] = 0;
                            --LucesEncendidas;
                        }
                    }
                    if(posFila != 4){
                        if(TableroJugable[posFila + 1][posColumna] == 0)
                        {
                            TableroJugable[posFila + 1][posColumna] = 1;
                            ++LucesEncendidas;
                        }else{
                            TableroJugable[posFila + 1][posColumna] = 0;
                            --LucesEncendidas;
                        }
                    }
                }
                if( tecla == GMAY || tecla == GMIN ){
                    solicitudGuardar( anchoPantalla, altoPantalla, TableroJugable, Filas, LucesEncendidas );
                    FormatoPantalla(anchoPantalla, altoPantalla, AMARILLO, NEGRO, APAGADO);
                    pintarTablero = 1;
                }

                if( tecla == LMAY || tecla == LMIN ){
                    solicitudCargar( anchoPantalla, altoPantalla, TableroJugable, Filas);
                    FormatoPantalla(anchoPantalla, altoPantalla, AMARILLO, NEGRO, APAGADO);
                    pintarTablero = 1;
                }

                if( tecla == ARRIBA )
                    if( posFila != 0){
                        --posFila;
                    }
                if( tecla == ABAJO )
                    if( posFila != 4){
                        ++posFila;
                    }


                if( tecla == IZQUIERDA )
                    if( posColumna != 0){
                        --posColumna;
                    }


                if( tecla == DERECHA )
                    if( posColumna != 4){
                        ++posColumna;
                    }

                casillaActual = posFila*5+posColumna;
                if(!LucesEncendidas){
                    Felicitar(anchoPantalla,altoPantalla,-1,15, cont);
                    system("pause");
                    break;
                }
                JugarActual( anchoPantalla, altoPantalla, cont, pintarTablero, posFilaA, posColumnaA, casillaActual, TableroJugable, LucesEncendidas );
                pintarTablero = 0;
                posFilaA = posFila;
                posColumnaA = posColumna;
            }
        }

        DestruirTableroEstados(TableroJugable, Filas);
    }catch( bad_alloc &){
        cout << "Error: No hay memoria suficiente, int\x82ntelo de nuevo o reinicie su computador..." << endl;
    }catch(...){
        cout << "Error inesperado. El programa finalizar\xA0...";
    }
}
