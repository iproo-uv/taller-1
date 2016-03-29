//============================================================================
// Name        : taller1.cpp
// Author 1     : Magrel Londoño - 1556094
// Author 2     :Yohan Mesa  -1556227
// Version     : 1
// Copyright   : 
// Description : main.cpp
//============================================================================

#include <iostream>
#include "Arbitro.h"
#include <stdlib.h>
#include"Tablero.h"

using namespace std;

int main() {
    int dim=0;
    cout<<"dimension del tablero : ";
    cin>>dim;
    Tablero t(dim);
    
    Arbitro arbitro = Arbitro(t);
    arbitro.posicionBola();
    arbitro.iniciarJuego();
    system ("pause");
	return 0;
	
	
}
