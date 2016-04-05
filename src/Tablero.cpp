//===================================================================================================================
// Name                     : Tablero.cpp
// Author                   : Jesus Alberto Ospina y Nelson galeano
// Version                  : 0.0.1
// Descripcion              : me permite crear un arreglo de un tablero n*n en base a una dimension n
#include <iostream>
#include "Tablero.h"

using namespace std;

Tablero::Tablero() {
   
   casillas = NULL;
   dimension=0;
   
    //Debe realizar la inicializacion por defecto de las variables miembro de la clase Tablero
}

Tablero::Tablero(int n) {
  
 
 dimension = n;
 
 
 casillas = new char*[n];
 for (int i=0; i<n; i++){
 	
 	casillas[i]= new char[n];
 
 	for(int j=0; j<n; j++){
 		
		 
		 casillas[i][j]= 'X';
		 
		
		
	 }
 }
  


   
      
   
    //Debe realizar la inicializacion de las variables miembro de la clase Tablero considerando una entrada n
}

Tablero::~Tablero() {
    // TODO Auto-generated destructor stub
}

char Tablero::getCasilla(int x, int y) {
   
  
   return casillas[x][y];
    //Debe devolver el valor de la posicion (x,y) del tablero
}

void Tablero::setCasilla(int x, int y, char value) {
  
casillas[x][y] = value;
  

  
  
    //Debe asignarle un valor de entrada "value" a una casilla del tablero (x,y)
}

int Tablero::getDimension() {
   
   return dimension;
   
    //Debe devolver la dimension del Tablero
}

