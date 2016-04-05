//===============================================
//clase: tablero
//responsabilidad: el tablero se encarga de imprimir la cuadricula de juego
//colaboracion: esta clase no tiene colaboracion
//===============================================

#include <iostream>
#include "Tablero.h"

using namespace std;

Tablero::Tablero() {
	dimension = 0;
	casillas = NULL;
   
}

Tablero::Tablero(int n) {
	dimension = 0;
	casillas = new char* [n];
	for (int i = 0; i < n; i++){
		casillas [i] = new char [n];
		for (int j = 0; j < n; j++){
			casillas[i][j] = 'X'; 
		}
	}
}

Tablero::~Tablero() {
	char Tablero::getCasilla(int x, int y){
		return casillas [x] [y];
	}
}

char Tablero::getCasilla(int x, int y) {
	return casillas [x][y];
}

void Tablero::setCasilla(int x, int y, char value) {
	casillas[x][y] = value;
}

int Tablero::getDimension() {
	return dimension;
}

