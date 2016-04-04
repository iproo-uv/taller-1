#include <iostream>
#include "Tablero.h"

using namespace std;

Tablero::Tablero()
{
	dimension = 0;
	casillas = NULL;//NULL la función para saber la hora actual del sistema es time
}

Tablero::Tablero(int n)
{
	dimension = n;
	casillas = new char* [n];
	for (int i = 0; i < n; i++) 
	{
		casillas [i] = new char [n];
		for (int j = 0; j< n; j++)
		{
			casillas[i][j]= 'X';
		}
	}
// inicializacion de las variables miembro de la clase Tablero considerando una entrada n
}

Tablero::~Tablero() 
{//destructo, se encarga de destruir ó eliminar lo que el programa ya no necesita 
}

char Tablero::getCasilla(int x, int y) 
{
   	return casillas[x][y];
}

void Tablero::setCasilla(int x, int y, char value) 
{
	casillas[x][y] = value;
    //asigna un valor de entrada "value" a una casilla del tablero (x,y)
}

int Tablero::getDimension() //devuelve la dimencio((tamaño)) de nuestro tablero de juego
{
	return dimension;
}
