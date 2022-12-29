/*
Nombre: .cpp
Autor: Olmos, Ortiz y Partida
Fecha: 29 de Mayo de 2020
Descripci�n: Archivo que contiene la implementaci�n de las funciones encargadas de crear, guardar y barajar el tablero.
*/
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<fstream>
#include<ctime>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::bad_alloc;
using std::ifstream;
using std::ofstream;
using std::cerr;


//*******************************************************
// Funci�n que crea un arreglo bidiminsional en el heap(De manera din�mica).
bool **CrearTableroEstados( int m, int n )
{
    bool **Matriz = NULL;
    try{
        Matriz = new bool *[m];
        for( int i = 0; i < m; ++i ) Matriz[i] = new bool [n];
        return Matriz;
    }catch( bad_alloc &){
        cout << "Error: No hay memoria suficiente, int\x82ntelo de nuevo o reinicie su computador..." << endl;
        return Matriz;
    }catch(...){
        cout << "Error inesperado. El programa finalizar\xA0...";
        return Matriz;
    }
}
//*******************************************************
// Funci�n que elimina un arreglo bidiminsional del heap y lo anula.
void DestruirTableroEstados( bool **&Matriz, short m )
{
    for( int i = 0; i < m; ++i) delete[] Matriz[i];
    delete [] Matriz;
    Matriz = NULL;
}

//Funci�n que guarda el progreso de un tablero.
bool GuardarProgresoTablero( const bool * const *Tablero, short Luces)
{
    ofstream GuardarTablero;

    GuardarTablero.open("Tableros//Progreso.txt");

    // Si existen problemas al momento de guardar la matriz en el archivo se sale de la funci�n.
    if(!GuardarTablero){
        system("pause");
        return false;
    }

    GuardarTablero << Luces << '\n';

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
//            ( Tablero[i][j] ) ? (GuardarTablero << setw(6) << 1 ): ( GuardarTablero << setw(6) << 0 );
            GuardarTablero << Tablero[i][j];
            GuardarTablero << ' ';
            if(!GuardarTablero){
                cerr << "Ocurri\242 un error guardando el progreso..." << endl;
                GuardarTablero.close();
                system("pause");
                return false;
            }
        }
        GuardarTablero << endl;
    }
    GuardarTablero.close();
    return true;
}
//Funci�n que ingresa los datos de un tablero resoluble.
void CapturarTablero(const char *numeroTablero, bool * const *Tablero, short &LucesEncendidas)
{

    ifstream archivoTablero;

    //Si existen errores en la captura, devuelve true, como error.
    archivoTablero.open(numeroTablero);
    if(!archivoTablero){
        cout << "Error: el archivo ' " << numeroTablero << " ' no puede ser abierto..." << endl;
        system("pause");
    }

    archivoTablero >> LucesEncendidas;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            archivoTablero >> Tablero[i][j];
            if(!archivoTablero){
                cout << "Error capturando datos del archivo ' " << numeroTablero << " ' ... " << endl;
                archivoTablero.close();
                system("pause");
            }
            cerr << endl;
        }
    }
    archivoTablero.close();
}

int BarajarTableros(int cantidadTableros)
{
    int Tableros[cantidadTableros];
    int estalibre[cantidadTableros];
    int TablerosDesordenado[cantidadTableros];

    //semilla para el rand
    srand(time(NULL));

    int i,pos;

    //inicializacion de los arrays
    for(i = 0; i < cantidadTableros; i++) {
        Tableros[i] = i + 1;
        estalibre[i] = 1;//1 -> libre, 0 -> ocupado
    }

    for(i = 0; i < cantidadTableros; i++)
    {
        pos = rand()%10;
        //este bucle evita que dos elementos sean guardados en la misma posicion
        while (estalibre[pos]==0)
            pos=rand()%cantidadTableros;
        TablerosDesordenado[pos]= Tableros[i];
        estalibre[pos]=0;
    }

    return TablerosDesordenado[0];
}
