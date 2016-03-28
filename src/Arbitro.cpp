//============================================================================
// Name        : arbitro.cpp
// Author      : DIEGO ALEJANDRO RAMIREZ MESTIZO;JHONATAN DAVID CEBALLOS RIVERA 
// Version     :0.1
// Copyright   : la clase arbitro contiene los datos que permite
// Description : iniciar el juego,el tamaño (dimensiones),calcular la distancia,validar los intentos, establecer indicaciones que va tener el juego (puntaje entre otras )
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <sstream>
#include <math.h>
#include "Arbitro.h"
using namespace std;

Arbitro::Arbitro(int tamanio) {
    juegoEnCurso = false;
    puntaje = 98.0 + tamanio*2;
    srand(time(NULL));
    tablero = Tablero(tamanio);
    filaBolita = rand()%tamanio;
    columnaBolita = rand()%tamanio;
    
    cout<<"la pelota es en ::   fila "<< "filaBolita" <<" columna "<< "columnaBolita" <<endl;
}

Arbitro::~Arbitro() {
}

void Arbitro::iniciarJuego() {
    juegoEnCurso = true;
    printf("juego creado\n");
    printf("=================================\n");
    imprimirTablero();
}

void Arbitro::imprimirTablero() {
	tablero.ImprimirTablero();
}
	

void Arbitro::calcularDistancia(int fila, int columna){
	float distancia = sqrt((pow((filaBolita-fila),2)+pow(columnaBolita-columna,2)));//();
    cout<<"estas a "<<distancia<<" de tu objetivo"<<endl;
}

bool Arbitro::validarIntento(int fila, int columna){
	if(fila==filaBolita&&columna==columnaBolita){
		cout<<"Felicidades has gando !!!!"<<endl;
		cout<<"Tu puntaje es "<<puntaje<<endl;
		juegoEnCurso=false;
		return true;
	}else{
		puntaje+=-5;
		tablero.setCasilla(fila,columna);
    	return false;
	}
	
}

