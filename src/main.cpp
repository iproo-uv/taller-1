//============================================================================
 // Nombre                    : main.cpp
 // Autores                   : Diego Delgado , Alejandro Becerra
 // Versión                   : 1.0.0
 // Fecha creación            : 22/02/2016
 // Fecha última modificación : 28/03/2016
 //============================================================================
#include <iostream>
#include "Arbitro.h"
using namespace std;

int main() {
    Arbitro arbitro = Arbitro();
    arbitro.iniciarJuego();
	return 0;
}
