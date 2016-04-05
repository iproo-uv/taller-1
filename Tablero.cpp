/*
  Nombre: Tablero.cpp
  Autor: Jairo Vera, Sergio Cadavid
  Fecha Creacion: marzo 14 de 2016
  Fecha Modificación:  abril 4 de 2016
  Versión : 1.0

    Responsabilidad:
    - crear el tablero, resibir la posicion que ingresa el usuario y crear y ocultar la bolita
    Colaboracion:  Arbitro.cpp, tablero.h
*/

#include <iostream>
#include "Tablero.h"

using namespace std;

Tablero::Tablero()
{
    dimension =0;
    casillas = NULL;
}

Tablero::Tablero(int n)
{
    dimension = n;
    casillas = new char*[n];
    for (int i =0; i <n; i++)
    {
    	casillas[i] = new char [n];
    	for (int j=0; j < n; j++)
    	{
    		casillas [i][j] = 'X' ;
		}
	}
}

Tablero::~Tablero()
{
}

char Tablero::getCasilla(int x, int y)
{
    return casillas [x][y];
}

void Tablero::setCasilla(int x, int y, char value)
{
    casillas [x][y]= value;
}

int Tablero::getDimension()
{
    return dimension;
}
