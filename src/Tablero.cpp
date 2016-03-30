//Debe escribir una cabecera de archivo con las indicaciones dadas en clase
//============================================================================
 // Nombre                    : Tablero.cpp
 // Autores                   : Diego Delgado , Alejandro Becerra
 // Versi�n                   : 1.0.0
 // Fecha creaci�n            : 22/02/2016
 // Fecha �ltima modificaci�n : 28/03/2016
 //============================================================================


#include <iostream>
#include "Tablero.h"

using namespace std;

Tablero::Tablero() {
    casillas=NULL;
    dimension = 0;
}

Tablero::Tablero(int n) {
    dimension = n;
    casillas = new char*[n];
    for(int i=0; i<n ; i++)
    {
        casillas[i] = new char[n];
        for(int j=0; j<n; j++)
        {
            casillas[i][j]='x';
        }
    }
    //Debe realizar la inicializacion de las variables miembro de la clase Tablero considerando una entrada n
}

Tablero::~Tablero() {
    // TODO Auto-generated destructor stub
}

char Tablero::getCasilla(int x, int y) {
    //Debe devolver el valor de la posicion (x,y) del tablero
    return casillas[x][y];
}

void Tablero::setCasilla(int x, int y, char value) {
    //Debe asignarle un valor de entrada "value" a una casilla del tablero (x,y)
    casillas[x][y] = value;
}

int Tablero::getDimension() {
    //Debe devolver la dimension del Tablero
    return dimension;
}

