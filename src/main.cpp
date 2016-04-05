//===================================================================================================================
// Name                     : main.cpp
// Author                   : Jesus Alberto Ospina y Nelson galeano
// Version                  : 0.0.1
// Descripcion              : Este programa representa un juego de en donde esta la bolita

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <iostream>
#include "Arbitro.h"

using namespace std;
int main() {
	
	
	Arbitro arbitro = Arbitro();
    arbitro.iniciarJuego();
	return 0;
	
	
}
