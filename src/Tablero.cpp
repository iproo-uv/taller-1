//============================================================================
// Nombre                    : Tablero.cpp
// Autores                   : Cristhian Candelo, Laura Higuera
// Versión                   : 1.0.1
// Fecha creación            : 22/02/2016
// Fecha última modificación : 23/03/2016
//============================================================================

#include <iostream>
#include "Tablero.h"

using namespace std;

Tablero::Tablero() {
	dimension = 0;
	casillas = NULL;
}

Tablero::Tablero(int n) {
	dimension =n;
	casillas = new char* [n];
	for (int i =0; i < n; i++)
	{
		casillas[i] = new char[n];
		for (int j = 0; j < n; j++)
		{
		     casillas[i][j] = 'O';
		}
	}
}

Tablero::~Tablero() {
    // TODO Auto-generated destructor stub
}

char Tablero::getCasilla(int x, int y){
	return casillas[x][y];
}

void Tablero::setCasilla(int x, int y, char value) {
	casillas [x][y] = value;
}

int Tablero::getDimension() {
	return dimension;
}
