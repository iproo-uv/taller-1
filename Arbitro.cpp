//============================================================================
// TALLER 1.0
// Name        : Arbitro.cpp 
// Author      : Geraldine Lopez Villaneda- Maria Alejandra Bernal Toro
// Version     : 0.2
// Copyright   : Geraldine Lopez - Alejandra Bernal 
// Description : juego ¿Donde esta la bolita? en c++
//============================================================================
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Arbitro.h"
#include <stdlib.h>
#include <conio.h>
#include <string.h> 
#include <stdio.h>

using namespace std;
Arbitro::Arbitro() {
	puntaje = 100.0;
	srand(time(NULL));
	filaBolita = 0;
	columnaBolita = 0;
}

Arbitro::~Arbitro() {
	// TODO Auto-generated destructor stub
}

void Arbitro::iniciarJuego() {
	int dimension = 1;
	int ingresoX=-1,ingresoY=-1;
	system("cls");
	cout << "            BIENVENIDO AL JUEGO: "<< endl;
	cout << "         Donde esta la bolita.... ? "<< endl<< endl<< endl;
	cout << "Ingrese la dimension del tablero (Mayor a 1) ";
	dimension=validaEntrada(2, 10000);
	Tablero tablerito (dimension);
	tablero = tablerito;
	filaBolita = rand ()% tablero.getDimension();
	columnaBolita = rand ()% tablero.getDimension();
	tablero.setCasilla(filaBolita,columnaBolita, 'B');
	system("cls");
	//si desea que se imprima el tablero en cada jugada, comentelo.
	
	imprimirTablero();
	
	while(puntaje > 0) {
		cout << "Ingrese la fila: ";
		ingresoX=validaEntrada(0, tablero.getDimension());
		cout << "Ingrese la columna: ";
		ingresoY=validaEntrada(0, tablero.getDimension());
		validarIntento(ingresoX,ingresoY);
	}
	//Debe implementar un metodo que se encargue de iniciar el juego y controlar su desarrollo
	//Este metodo debe recibir las entradas del usuario, imprimir el tablero y validar los intentos
}

void Arbitro::imprimirTablero() {
	system("cls");
	cout<< "Juego en proceso"<<endl<<endl;
	cout<< "Intente adivinar la ubicacion de la bolita en el tablero "<<endl<<endl<<endl;
	cout<<"  ";
	
	for (int k=0; k<tablero.getDimension(); k++) {
		cout<<k<<" ";
	}
	cout<<endl<<endl;
	
	for (int i=0; i<tablero.getDimension(); i++) {
		cout<<i<<" ";
		
		for (int j=0; j<tablero.getDimension(); j++) {
			
			if (tablero.getCasilla(i,j)=='B') {
				cout<< "X ";
			} 
			else {
				cout<<tablero.getCasilla(i,j)<<" ";
			}
		}
		cout<<endl<<endl;
	}
	//cout << filaBolita<< "," << columnaBolita<< endl; // si desea que la posicion sea impresa en el tablero descomente.
	cout<<endl;
	//Debe implementar un metodo que imprima el tablero en pantalla
	//Recuerde que el usuario no puede conocer la posicion de la bolita
}

bool Arbitro::validarIntento(int fila, int columna) {
	//	system("cls");
	
	if (tablero.getCasilla(fila,columna)=='B') {
		cout<< endl << "Felicitaciones, usted ha ganado el juego!... su puntaje es: "<< puntaje <<endl;
		tablero.setCasilla(fila,columna,'©');
		puntaje = 0;
	} 
	else {
		
		if (tablero.getCasilla(fila,columna)=='F') {
			cout<< endl << "Usted ya ha jugado esta posicion... su puntaje es: "<< puntaje;
			cout << endl << "Juega nuevamente"<< endl;
		} 
		else {
			tablero.setCasilla(fila,columna,'F');
			puntaje = floor(puntaje-(100/(tablero.getDimension()*tablero.getDimension())));
			cout << endl << "Fallaste! su intento esta a:  "<<calcularDistancia(fila,columna)<<" posiciones."<< endl;
			cout << "Su puntaje es: "<<puntaje <<endl <<  "Juega nuevamente" << endl;
		}
		//if (tablero.getCasilla(fila,columna) > dimension){
		//cout << "La FILA tiene que ser menor a la dimension ingresada... "<< endl;
	}
	cout << "presione cualquier tecla para continuar...";
	getch();
	imprimirTablero();
	//Este metodo debe validar el intento del usuario, debe informarle si fue correcto o no
	//Retorna verdadero si el intento es correcto y falso si no lo es
	//En caso de no serlo debe realizar los cambios correspondientes a las variables miembro
	//Y debe informar por pantalla cual fue la distancia del fallo y el puntaje restante
}

int Arbitro::calcularDistancia(int fila, int columna) {
	int distancia;
	distancia = abs(filaBolita - fila) + abs(columnaBolita - columna);
	//Debe implementar un metodo que calcula la distancia entre la posicion (fila, columna)
	//Y la posicion real de la bolita
}

int Arbitro::validaEntrada(int inf, int sup) {
	
	char dato[10];
	int bandera;
	
	do {
		bandera = 0;
		fgets (dato, sizeof dato, stdin);
		
		for (int n=0; n<strlen(dato)-1; n++) {
			
			if (!isdigit(dato[n])) {
				bandera = 1;
				n=strlen(dato);
			}
		}
		
		if( bandera == 1 || atoi(dato) < inf || atoi(dato) > sup) {
			cout<<endl<<"No es un dato valido..." << endl<< "Intentelo de nuevo : ";
			bandera = 1;
		}
	}
	
	while(bandera == 1);
	
	return atoi(dato);
	//Metodo para validar la entrada de valores numericos enteros dentro de un rango.
}
