//============================================================================
// Name        : taller1.cpp
// Author      : Diana Marcela Rodriguez - Daniela Giraldo Mejia
// Version     : 0.0.1
//============================================================================

#include <iostream>
#include "Tablero.h"

using namespace std;

Tablero::Tablero()
{
	dimension = 0;
	casillas = NULL;

}

Tablero::Tablero(int n)
{
    dimension = n;
	casillas = new char* [n];
	for (int i = 0; i < n; i++)
	{
		casillas [i] = new char[n];
		for (int j = 0; j < n; j++)
		{

		if(i==0){
                casillas [i][j]= j ;
                }
            else{
                casillas [i][j]= 'x';
            }
		}
	} //Debe realizar la inicializacion de las variables miembro de la clase Tablero considerando una entrada n
}

Tablero::~Tablero() {
    // TODO Auto-generated destructor stub
}

char Tablero::getCasilla(int x, int y)
{
	return casillas[x][y];
    //Debe devolver el valor de la posicion (x,y) del tablero
}

void Tablero::setCasilla(int x, int y, char value)
{
	casillas[x][y] = value;

    //Debe asignarle un valor de entrada "value" a una casilla del tablero (x,y)
}

int Tablero::getDimension()
{
    return dimension;
	//Debe devolver la dimension del Tablero
}
