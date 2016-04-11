//============================================================================
// Nombre                    : main.cpp
// Autores                   : Cristhian Candelo, Laura Higuera
// Versi�n                   : 1.0.1
// Fecha creaci�n            : 22/02/2016
// Fecha �ltima modificaci�n : 23/03/2016
//============================================================================

#include <iostream>
#include "Arbitro.h"
using namespace std;

int main() {
	int dim;
    	cout<<"Ingrese la dimension "<<endl;
		cin>>dim;
		Tablero tablero(dim);

    Arbitro arbitro = Arbitro(tablero);
    arbitro.iniciarJuego();
	return 0;
}
