//============================================================================
// Name        : tablero.cpp
// Author      : DIEGO ALEJANDRO RAMIREZ MESTIZO;JHONATAN DAVID CEBALLOS RIVERA 
// Version     :0.1
// Copyright   : la clase tablero contiene los funciones que va tener el programa
// Description : crear la matriz (las dimensiones del tablero "filas,columbas )en la cual el programa toda su forma y su estructura al momento de iniciarlo
//============================================================================

#include <iostream>
#include "Tablero.h"

using namespace std;

Tablero::Tablero(int tm) {
	dim = tm;
	//matriz dinamica
    matriz=new char*[dim];//aqui definimos el primer apuntador como que tendra las filas
    for(int j=0;j<dim;j++){//ahora hacemos que el doble aputnador se asocie con las culumnas
		matriz[j]=new char [dim];//aqui difinimos el segundo apuntador , las filas de la matriz
    }
    

}

Tablero::~Tablero() {
	for(int i=0; i<dim; i++){
    	for(int j=0; j<dim; j++){
     	   matriz[i][j]='O';
    	}	
   	}

}


void Tablero::ImprimirTablero(){
	
	for(int x=0; x<dim; x++){
   		for(int y=0; y<dim; y++){
    	    std::cout << matriz[x][y];
    	}
    	std::cout << "\n";
  	}
}


char Tablero::getCasilla(int x, int y) {
	return casillas [x][y];  
}

void Tablero::setCasilla(int x, int y) {
   matriz[x][y]='X';
}

int Tablero::getDim() {
  return dim;
}




