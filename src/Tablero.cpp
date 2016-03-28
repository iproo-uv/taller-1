//Debe escribir una cabecera de archivo con las indicaciones dadas en clase
//============================================================================
// Name        : Tablero.cpp
// Author      : Neydor Avila Navarrete, Joan Sebastian Diaz Ocampo, John Cortez.
// Version     :0.0.0.1
// Copyright   : 
// Description : en este archivo se encuentran definidas varias funciones con sus respectivas variables
//gracias a todas estas funciones el juego de "encuentra la bolita" fue tomando su forma (tiene relacion con el archivo Tablero.h)
//============================================================================

#include <iostream>
#include "Tablero.h"

using namespace std;

Tablero::Tablero() {
	dimension = 0;
	casillas = NULL;
}

Tablero::Tablero(int n) {
	dimension = n;
	casillas = new char* [n];
	for (int i = 0; i < n; i++) {
		casillas [i] = new char [n];
		for (int j = 0; j< n; j++){
			casillas[i][j]= 'X';
		}
	}
    //Debe realizar la inicializacion de las variables miembro de la clase Tablero considerando una entrada n
}

Tablero::~Tablero() {
    // TODO Auto-generated destructor stub
}

char Tablero::getCasilla(int x, int y) {
   	return casillas[x][y];
}

void Tablero::setCasilla(int x, int y, char value) {
	casillas[x][y] = value;
    //Debe asignarle un valor de entrada "value" a una casilla del tablero (x,y)
}

int Tablero::getDimension() {
	return dimension;
    //Debe devolver la dimension del Tablero
}
