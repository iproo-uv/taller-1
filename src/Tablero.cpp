//============================================================================
// Name        : taller1.cpp
// Author 1     : Magrel Londoño - 1556094
// Author 2     :Yohan Mesa  -1556227
// Version     : 1
// Copyright   : 
// Description : Tablero.cpp
//============================================================================

#include <iostream>
#include "Tablero.h"
#include <stdlib.h>

using namespace std;

Tablero::Tablero() {
    //Debe realizar la inicializacion por defecto de las variables miembro de la clase Tablero
   casillas=NULL;
   dimension=0;
   
    
}

Tablero::Tablero(int n) {
    //Debe realizar la inicializacion de las variables miembro de la clase Tablero considerando una entrada n
   dimension=n;
   
    casillas=new char*[n];
    cout<<" ";
    for(int m=0; m<n; m++)
    {
    	cout<<" "<<m;
	}
	cout<<endl;
    cout<<" "<<endl;
    for(int x=0; x<n; x++)
     {
     	casillas[x]=new char[n];
     	cout<<x<<" ";
     	for(int y=0; y<n; y++)
     	 {
     	
     	 	casillas [x][y]='+';
     	 	cout<<casillas [x][y]<<" ";
     	 	
     	 
		  }
		  cout<<endl<<endl;

   }
   
} 
   

Tablero::~Tablero() {
    // TODO Auto-generated destructor stub
}

char Tablero::getCasilla(int x, int y) 
{
	
    //Debe devolver el valor de la posicion (x,y) del tablero
  
   return casillas [x][y];
  	
}

void Tablero::setCasilla(int x, int y, char value) {
    //Debe asignarle un valor de entrada "value" a una casilla del tablero (x,y)
    
    casillas [x][y]=value;
    
}

int Tablero::getDimension()
{

    return dimension;
    
}
