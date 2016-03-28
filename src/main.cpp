//============================================================================
// Name        : taller1.cpp
// Author      : DIEGO ALEJANDRO RAMIREZ MESTIZO;JHONATAN DAVID CEBALLOS RIVERA 
// Version     :0.1
// Copyright   : 
// Description : 
//============================================================================

#include <iostream>
#include <stdio.h>
#include "Arbitro.h"
using namespace std;

int main() {
	bool ganador;
	int fila,columna,dimension;
	cout<<"ingrese la dimesion deseada"<<endl;
	cin>> dimension;
	
	Arbitro arbitro = Arbitro(dimension);
	arbitro.iniciarJuego();
	system("Color b1"); 

	do{
	cout<<"Es tu turno para lanzar"<<endl;
	cout<<"Ingresa la fila"<<endl;
	cin>> fila;
	cout<<"Imgresa la columna"<<endl;
	cin>> columna;
	printf("=================================\n");	
	
	ganador = arbitro.validarIntento(fila,columna);
	
	if(ganador == false ){
	arbitro.imprimirTablero();
	arbitro.calcularDistancia(fila,columna);
	printf("=================================\n");	
	}
	
	}while(ganador!=true);
	
	return 0;
}
