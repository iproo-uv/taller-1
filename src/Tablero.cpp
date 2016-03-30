//Debe escribir una cabecera de archivo con las indicaciones dadas en clase
#include <iostream>
#include "Tablero.h"

using namespace std;

Tablero::Tablero() {
    //Debe realizar la inicializacion por defecto de las variables miembro de la clase Tablero
}

Tablero::Tablero(int n) {
    //Debe realizar la inicializacion de las variables miembro de la clase Tablero considerando una entrada n
}

Tablero::~Tablero() {
    // TODO Auto-generated destructor stub
}

char Tablero::getCasilla(int x, int y) {
    //Debe devolver el valor de la posicion (x,y) del tablero
}

void Tablero::setCasilla(int x, int y, char value) {
    //Debe asignarle un valor de entrada "value" a una casilla del tablero (x,y)
}

int Tablero::getDimension() {
    //Debe devolver la dimension del Tablero
}

