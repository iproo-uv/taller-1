//Clase: Tablero
//Responsabilidad: Inicializa las variables de la clase, obtiene el valor de las posiciones y la dimension del mismo
//Colaboracion: colabora con la clase Arbitro

#include <iostream>
#include "Tablero.h"

using namespace std;

Tablero::Tablero() {
    dimension =0;
    casillas =NULL;

}

Tablero::Tablero(int n) {
    dimension = n;
    casillas = new char*[n];
    for (int i = 0; i < n; i++){
    	casillas [i] = new char [n];
    	for (int j = 0; j < n; j++){
    		casillas[i][j] = 'X';
    	}
    }
}

Tablero::~Tablero() {
    // TODO Auto-generated destructor stub
}

char Tablero::getCasilla(int x, int y) {
    return casillas[x][y];
}

void Tablero::setCasilla(int x, int y, char value) {
    casillas[x][y] = value;
}

int Tablero::getDimension() {
    return dimension;
}
