/*
Nombre: Utileria.cpp
Autor: Olmos, Ortiz y Partida
Fecha: 29 de Mayo de 2020
Descripci�n: Archivo que contiene la implementaci�n de las funciones de ayuda para el formato de la pantalla.
*/

#include <iostream>
#include <windows.h>
#include "Utileria.h"

using namespace std;


//*************************************************************************************************************************
bool AjustarVentana(int Ancho, int Alto) {
    _COORD Coordenada;
    Coordenada.X = Ancho;
    Coordenada.Y = Alto;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Right = Ancho - 1;
    Rect.Bottom = Alto - 1;

    // Obtener el handle de la consola
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

    // Ajustar el buffer al nuevo tama�o
    SetConsoleScreenBufferSize(hConsola, Coordenada);

    // Cambiar tama�o de consola a lo especificado en el buffer
    SetConsoleWindowInfo(hConsola, TRUE, &Rect);
    return TRUE;
}
void CambiarCursor(EstadoCursor estado, ModoCursor modo /* = NORMAL*/)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info = {modo,estado};
    SetConsoleCursorInfo(consoleHandle, &info);
}

//*************************************************************************************************************************

void EstablecerTamVentana(short ancho, short alto)
{
    _COORD coord = {--ancho, --alto};
    _SMALL_RECT rect = {0,0,ancho,alto};
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(hConsola, coord);
    SetConsoleWindowInfo(hConsola, true, &rect);
}

//*************************************************************************************************************************

void EstablecerColor(Color colorFondo, Color colorTexto)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorFondo*16 + colorTexto);
}

//*************************************************************************************************************************
void gotoxy(short x,short y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x,y};
    SetConsoleCursorPosition(handle,coord);
}

//*************************************************************************************************************************
void FormatoPantalla (short anchoPantalla, short altoPantalla, Color colorFondo, Color colorTexto, EstadoCursor eMouse )
{
    AjustarVentana( anchoPantalla, altoPantalla ); // Tama�o
    EstablecerColor(colorFondo,colorTexto); // Color
    system("cls");
    CambiarCursor(eMouse); // Cursor
}

