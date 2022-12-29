/*
Nombre: main.cpp
Autor: Olmos, Ortiz y Partida
Fecha: 29 de Mayo de 2020
Descripci�n: Archivo principal. Programa que representa un juego llamado Lights Out.
*/

#include <iostream>
#include <cstdlib>
#include <conio.h>

#include"Utileria.h"
#include "Interfaz.h"


using namespace std;

int main()
{
    int opcion; // Opci�n que ser� seleccionada por el usuario.
    do{
        opcion = MenuPrincipal();
        switch(opcion){
            case 1: InterfazJugar(0);
                break;
            case 2: InterfazInstrucciones();
                break;
            case 3: InterfazCreditos();
        }
    }while( opcion != 4 );

    return 0;
}
