//============================================================================
// Name        : taller1.cpp
// Author      : Luisa Mar�a Gallego Ni�o/Carlos Alejandro Tamayo Ria�o
// Version     :
// Copyright   : 
// Description : 
//============================================================================

#include <iostream>
#include "Arbitro.h"

using namespace std;

int main() 
{
    int dim;
    cout<< "                    ***************************************"<< endl;
    cout<< "                    *        �Donde esta la bolita?       *"<< endl;
    cout<< "                    ***************************************"<< endl;
    cout<< endl;
    cout<< "Ingrese un numero para su dimension "<<endl;
    cin>> dim;
    Tablero tablero(dim);
  
	Arbitro arbitro = Arbitro (tablero);
    arbitro.iniciarJuego();
	return 0;
}


