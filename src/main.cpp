//============================================================================
// Name        : taller1.cpp
// Author      : Edward cedeño ruiz
// Version     :
// Copyright   : 
// Description : 
//============================================================================

#include <iostream>
#include "Arbitro.h"
using namespace std;

int main() {
	Tablero tablero (5);
	for (int fila = 0; fila < 5; fila++)
    {
		cout  << fila << " ";
	 for (int columna = 0 ; columna < 5; columna++)
	 {
		 cout << " "<<tablero.getcasillas(fila, columna) << " ";
	 }
	cout << endl;
     }
    Arbitro arbitro = Arbitro();
    arbitro.iniciarJuego();
	return 0;
}
