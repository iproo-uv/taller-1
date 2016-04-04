//============================================================================
// TALLER 1.0
// Name        : main.cpp
// Author      : Geraldine Lopez Villaneda- Maria Alejandra Bernal Toro
// Version     : 0.1
// Copyright   : Geraldine Lopez - Alejandra Bernal 
// Description : juego ¿Donde esta la bolita? en c++
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
