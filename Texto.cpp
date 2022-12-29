/*
Nombre: Texto.cpp
Autor: Olmos, Ortiz y Partida
Fecha: 29 de Mayo de 2020
Descripci�n: Archivo que contiene la implementaci�n de las funciones de ayuda para el uso de m�rgenes de texto.
*/

#include<iostream>
#include<cstring>

// Funcione y ennumeraciones de utiler�a general.
#include"Utileria.h"

using std::cout;
using std::endl;

//**************************************************************************************************************************
int posicionInicial( short espacioTotal, short espacioObjeto )
{
    int posicion;
    posicion = (espacioTotal/2)-(espacioObjeto/2);
    return posicion;
}

//****************************************************************************************************************************
void CentrarTexto( const char *texto, short coordY, short espacioHor  )
{
    int tamTexto = strlen(texto);
    int posX = posicionInicial(espacioHor, tamTexto);

    if( tamTexto%2 == 0){
        gotoxy( posX, coordY );
    } else{
        gotoxy( posX, coordY );
    }
    cout << texto;
}
//****************************************************************************************************************************
void CentrarTextoEnObj( const char *texto, short coordY, short anchoObjeto, short coordXObjeto, short alturaObjeto )
{
    int tamTexto = strlen(texto);
    int posX = posicionInicial(anchoObjeto, tamTexto);

    if( tamTexto%2 == 0){
        gotoxy( posX+coordXObjeto, coordY+(alturaObjeto/2 ) );
    } else{
        gotoxy( posX+coordXObjeto, coordY+(alturaObjeto/2) );
    }
    cout << texto;
}
//****************************************************************************************************************************
void CentrarVariableEnObj( short variable, short tamTexto, short coordY, short anchoObjeto, short coordXObjeto, short alturaObjeto )
{
    int posX = posicionInicial(anchoObjeto, 2) ;

    if( tamTexto%2 == 0){
        gotoxy( posX+coordXObjeto+10, coordY+(alturaObjeto/2 ) );
    } else{
        gotoxy( posX+coordXObjeto+10, coordY+(alturaObjeto/2) );
    }
    cout << variable;
}

//****************************************************************************************************************************
void AlinearIzquierda( const char *texto, short posX, short coordY, short  margen )
{
    int tamTexto = strlen(texto);

    gotoxy( posX + margen, coordY);
    cout << texto;
}

