//============================================================================
// Name        : main.cpp
// Author      : Neydor Avila Navarrete, Joan Sebastian Diaz Ocampo, John Cortez.
// Version     :0.0.0.1
// Copyright   : Neydor Avila Navarrete, Joan Sebastian Diaz Ocampo, John Cortez.
// Description : Programa del juego "Encontrar la Bolita"...
//============================================================================
#include <iostream>
#include <cstdlib>
#include "Arbitro.h"
using namespace std;

int main() {
	Arbitro arbitro = Arbitro();
	arbitro.iniciarJuego();
	return 0;
}
