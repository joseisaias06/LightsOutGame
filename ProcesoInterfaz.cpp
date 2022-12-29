/*
Nombre: ProcesoInterfaz.cpp
Autor: Olmos, Ortiz y Partida
Fecha: 29 de Mayo de 2020
Descripci�n: Archivo que contiene la implementaci�n de las funciones encargadas del proceso de las interfaces.
*/

#include<iostream>
#include<cstdlib>
#include<string>

// Funciones con dise�o de los objetos
#include"Objetos.h"
// Funciones de utiler�a para crear, guardar y barajar los tableros.
#include"Utileria_Tablero.h"
// Funcione y ennumeraciones de utiler�a general.
#include"Utileria.h"
// Funciones para manejo de m�rgenes de texto
#include"Texto.h"
#include"Interfaz.h"

using std::cin;
using std::bad_alloc;
using std::cout;
using std::endl;

//**************************************************************************************************************************
void CreditosActual( short anchoPantalla, short altoPantalla )
{
    // Dimensiones
    short anchoMarco = anchoPantalla-8;
    short alturaMarco = altoPantalla-8;

    // Marco limitante de la ventana
    short posX = posicionInicial(anchoPantalla,anchoMarco);
    short posY = posicionInicial(altoPantalla,alturaMarco);
    DibujarMarcoDobleSinFondo( anchoMarco, alturaMarco, posX, posY );

    // T�tulo
    gotoxy(5,5);
    CentrarTexto("CR\x45 \bDITOS",1,anchoPantalla);
    DibujarRectangulo(anchoMarco-10,alturaMarco-5,8,6);
    AlinearIzquierda("- Programado por:",3,7,5);
    AlinearIzquierda("  Olmos Morales Jos\xA82 Isa\xA1 \bas",3,10,5);
    AlinearIzquierda("  Ortiz Quintana Luis Gerardo",3,12,5);
    AlinearIzquierda("  Partida Peralta Jos\x82 Benjam\xA1n",3,14,5);
    AlinearIzquierda("- Presentaci\xA2n",3,17,5);
    AlinearIzquierda("  Somos alumnos de la Universidad de Sonora y este programa o juego forma",3,19,5);
    AlinearIzquierda("  parte de un proyecto de la materia de \"Programaci\xA2n de computadoras\".",3,20,5);

    // Mensaje para salir
    gotoxy(1, 1);
    cout << "ESC para salir";
}

//**************************************************************************************************************************
void InstruccionesActual( short anchoPantalla, short altoPantalla, bool primeraVez, short nPagina, short flecha, bool Foco, bool enter  )
{
    // Botones para cambiar de p�gina.
    EstablecerColor(AMARILLO,NEGRO);
    Boton("z",4,2,3,11);
    Boton("x",93,2,3,11);
    EstablecerColor(NEGRO,AMARILLO);

    // Teclas de movimiento
    DibujarFlechas( 16, 32, flecha);

    // Tecla de presionar
    if(primeraVez){
        // Cuadro de instrucciones
        cuadroInstrucciones( anchoPantalla, altoPantalla, primeraVez, 0, -5, nPagina );
        gotoxy(70,26);
        cout << "Accion";
        // Mensaje para salir
        gotoxy(1, 1);
        cout << "ESC para salir";
    }
    DibujarEnter( 68, 30, enter );
    DibujarFoco( 78, 30, Foco );
}

//**************************************************************************************************************************
void solicitudCargarActual( short opc, short anchoPantalla, short altoPantalla, bool pintarMarco, bool cargar, bool **&Tablero, short Filas)
{
    // Verificaci�n de estado de los botones (activos o inactivos).
    bool eSi = false, eNo = false;
    switch( opc ){
        case 1: eSi = true;   break;
        case 2: eNo = true;   break;

    }

    short anchoCuadro = 40;
    short altoCuadro = 8;
    short anchoBoton = 4;
    short altoBoton = 3;

    short posX = posicionInicial( anchoPantalla, anchoCuadro );
    short posY = posicionInicial( altoPantalla, altoCuadro );
    if(!cargar){
        if(pintarMarco){
            DibujarRectangulo( anchoCuadro, altoCuadro, posX, posY );
            DibujarMarcoSinFondo( anchoCuadro, altoCuadro, posX, posY );
            CentrarTextoEnObj("\xA8 \bDesea cargar su progreso anterior?", posY-2, anchoCuadro, posX, altoCuadro);
        }
        BotonesMenu( "Si", anchoPantalla, altoPantalla, anchoBoton, altoBoton, posY, eSi, -5, 3 );
        BotonesMenu( "No", anchoPantalla, altoPantalla, anchoBoton, altoBoton, posY, eNo, 5, 3 );
    } else{
        DestruirTableroEstados(Tablero, Filas);
        InterfazJugar(1);
    }
}

//**************************************************************************************************************************
void solicitudGuardarActual( short opc, short anchoPantalla, short altoPantalla, bool pintarMarco, bool guardar, const bool * const *Tablero, short tamTablero, short lucesOn )
{
    // Verificaci�n de estado de los botones (activos o inactivos).
    bool eSi = false, eNo = false;
    switch( opc ){
        case 1: eSi = true;   break;
        case 2: eNo = true;   break;

    }

    short anchoCuadro = 30;
    short altoCuadro = 8;
    short anchoBoton = 4;
    short altoBoton = 3;

    short posX = posicionInicial( anchoPantalla, anchoCuadro );
    short posY = posicionInicial( altoPantalla, altoCuadro );
    if(!guardar){
        if(pintarMarco){
            DibujarRectangulo( anchoCuadro, altoCuadro, posX, posY );
            DibujarMarcoSinFondo( anchoCuadro, altoCuadro, posX, posY );
            CentrarTextoEnObj("\xA8 \bDesea guardar su progreso?", posY-2, anchoCuadro, posX, altoCuadro);
        }
        BotonesMenu( "Si", anchoPantalla, altoPantalla, anchoBoton, altoBoton, posY, eSi, -5, 3 );
        BotonesMenu( "No", anchoPantalla, altoPantalla, anchoBoton, altoBoton, posY, eNo, 5, 3 );
    } else{
        GuardarProgresoTablero(Tablero,lucesOn);
    }
}

//**************************************************************************************************************************
void JugarActual( short anchoPantalla, short altoPantalla, short contadorIntentos, short primeraVez, short iAnt, short jAnt, short casillaActual, const bool * const *arregloEstados, short lucesOn )
{
    // Medidas de �reas.
    short AnchoP = anchoPantalla;
    short AltoP = altoPantalla;
    short AnchoA1 = anchoPantalla;
    short AltoA1 = 10;
    short AnchoAT = anchoPantalla;
    short AltoAT = altoPantalla-AltoA1;
    short AnchoAC = AnchoP;
    short AltoAC = altoPantalla-AltoA1;
    short AnchoACi= AnchoP/2;
    short AltoACi = altoPantalla-AltoA1;


    // Medidas de Objetos.
    short ladoCasilla = 5;
    short cantidadCasillas = 5;

    // Objetos
    Area( AnchoP, AltoP, AnchoAT, AltoAT ); // �rea para tablero.
    ImprimeTablero( ladoCasilla, cantidadCasillas, AnchoP, AltoP, AltoA1, primeraVez, iAnt, jAnt, casillaActual, arregloEstados ); // Tablero.

    Area( AnchoP, AltoP, AnchoAC, AltoAC ); // �rea de cuadros de intentos
    CuadroLuces("Luces encendidas: ", lucesOn, 22, 3, AnchoP, AltoP, 2*AnchoP/8, 0, primeraVez );
    CuadroIntentos("Intentos: ", contadorIntentos, 15, 3, AnchoP, AltoP, 2*AnchoP/8 - 4, 3, primeraVez );

    if(primeraVez){
        Area( AnchoP, AltoP, AnchoA1, AltoA1 ); // �rea para t�tulo.
        ImprimirTituloTren( AnchoP, AltoP ); // T�tulo.
        Area( AnchoP, AltoP, AnchoACi, AltoACi ); // �rea de cuadros de informaci�n
        CuadroInfo( AnchoP, AltoP, 1, 10 );
    }



}

//**************************************************************************************************************************
void MenuOpcionesActual( short opc, short anchoPantalla, short altoPantalla, bool pintarTitulo )
{
    // Medidas de �reas.
    short AnchoP = anchoPantalla;
    short AltoP = altoPantalla;
    short AnchoTitulo = anchoPantalla;
    short AltoTitulo = 10;
    short AnchoA1 = anchoPantalla;
    short AltoA1 = altoPantalla-16;

    // Medidas de objetos.
    short anchoBoton = 15;
    short alturaBoton = 3;
    short anchoFondo = 62;
    short altoFondo = 35;

    // Verificaci�n de estado de los botones (activos o inactivos).
    bool eContinuar = false, eInstrucciones = false, eGuardar = false, eSalir = false;
    switch( opc ){
        case 1: eContinuar = true;   break;
        case 2: eGuardar = true;   break;
        case 3: eInstrucciones = true;   break;
        case 4: eSalir = true;
    }

    if(pintarTitulo){
        Area( AnchoP, AltoP, AnchoTitulo, AltoTitulo );
        DibujarMarco( anchoFondo, altoFondo, 20, 2 );
        ImprimirTituloOpciones( AnchoTitulo, AltoTitulo, 0, 4);
    }


    Area( AnchoP, AltoP, AnchoA1, AltoA1 ); // �rea para botones.
    BotonesMenu( "Continuar", AnchoP, AltoP, anchoBoton, alturaBoton, AltoA1*1/9+2, eContinuar, 0, 10 );                 // Boton Jugar.
    BotonesMenu( "Guardar", AnchoP, AltoP, anchoBoton, alturaBoton, AltoA1*3/9+2, eGuardar, 0, 10 );                 // Boton Jugar.
    BotonesMenu( "Instrucciones", AnchoP, AltoP, anchoBoton, alturaBoton, AltoA1*5/9+2, eInstrucciones, 0, 10 ); // Boton Instrucciones.
    BotonesMenu( "Salir", AnchoP, AltoP, anchoBoton, alturaBoton, AltoA1*7/9+2, eSalir, 0, 10 );
}

//**************************************************************************************************************************
void PrincipalActual( short opc, short anchoPantalla, short altoPantalla )
{
    // Medidas de �reas.
    short AnchoP = anchoPantalla;
    short AltoP = altoPantalla;
    short AnchoA1 = anchoPantalla;
    short AltoA1 = 10;
    short AnchoA2 = anchoPantalla;
    short AltoA2 = AltoP - AltoA1;

    // Medidas de objetos.
    short anchoBoton = 15;
    short alturaBoton = 3;

    // Verificaci�n de estado de los botones (activos o inactivos).
    bool eJugar = false, eInstrucciones = false, eCreditos = false, eCerrar = false;
    switch( opc ){
        case 1: eJugar = true;   break;
        case 2: eInstrucciones = true;   break;
        case 3: eCreditos = true;    break;
        case 4: eCerrar = true;
    }

    // Objetos.
    Area( AnchoP, AltoP, AnchoA1, AltoA1 ); // �rea para t�tulo.
    ImprimirTituloTren( AnchoP, AltoP ); // T�tulo.

    Area( AnchoP, AltoP, AnchoA2, AltoA2 ); // �rea para botones.
    BotonesMenu( "Jugar", AnchoP, AltoP, anchoBoton, alturaBoton, AltoA2*1/9, eJugar, 0, AltoA1 );                 // Boton Jugar.
    BotonesMenu( "Instrucciones", AnchoP, AltoP, anchoBoton, alturaBoton, AltoA2*3/9, eInstrucciones, 0, AltoA1 ); // Boton Instrucciones.
    BotonesMenu( "Cr\202ditos", AnchoP, AltoP, anchoBoton, alturaBoton, AltoA2*5/9, eCreditos, 0, AltoA1 );        // Boton Cr�ditos.
    BotonesMenu( "Cerrar", AnchoP, AltoP, anchoBoton, alturaBoton, AltoA2*7/9, eCerrar, 0, AltoA1 );              // Boton Cerrar.
}
