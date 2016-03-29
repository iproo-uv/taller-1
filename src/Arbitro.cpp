//0============================================================================
// Name        : taller1.cpp
// Author      : Duvan Quevedo 1561761 - Cristian Lancheros 1561814
// Version     : 1.0
// Copyright   :
// Description : Juego encontrar la bolita
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Arbitro.h"
 	#include <ctype.h> 
	#include <stdlib.h> 
	#include <string.h> 
	#include <stdio.h> 
using namespace std;

Arbitro::Arbitro() {
    juegoEnCurso = false;
    puntaje = 100.0;
    srand(time(NULL));
    filaBolita = 0;
    columnaBolita = 0;
}

Arbitro::~Arbitro() {
    // TODO Auto-generated destructor stub
}

void Arbitro::iniciarJuego() {
    //____________________________________pagina de donde se saco parte del codigo____________http://www.ehowenespanol.com/entrada-sea-entero-c-como_283817/
	juegoEnCurso = false;	
   	int dimension;
  	unsigned p; 
	char caracter[BUFSIZ]; 
	bool noNumero, validar, igual  ;
		validar = false; 
		while (!validar) {
			cout<< "INGRESE LA DIMENSION DEL TABLERO: "<< endl; 
				if (fgets (caracter, sizeof caracter, stdin) != NULL) {
					caracter[strlen(caracter)-1] = '\0'; 
		 		noNumero = false; 
		 		if (strlen(caracter) == 0) noNumero = true;
		 		for (p=0; p<strlen(caracter); p++) if (!isdigit(caracter[p])) noNumero = true;
			    dimension = atoi(caracter);// ATOI ES PARA CAMBIAR EL CHAR INGRESADO A INT.
				if (15 < dimension){
					noNumero = true;
					}
				if (dimension < 2){
					noNumero = true;
					}
				if (!noNumero) {
					validar = true; 
					}
		  		else 
		  	cout << "INGRESE UN NUMERO MAYOR O IGUAL A 2 Y MENOR QUE 15:" <<endl <<endl;
		  	}
	}	
		
Tablero tablerito (dimension);
	tablero = tablerito;
	filaBolita = rand ()% (tablero.getDimension());
	columnaBolita = rand ()% (tablero.getDimension());
	tablero.getCasilla(filaBolita,columnaBolita);
	cout<<endl;
	imprimirTablero();
	int ingresoX,ingresoY;
	while(puntaje > 0){
		
		  igual = true;
		  while (igual) {
		  	
		  validar = false;
		while (!validar) {
			cout<< "INGRESE LA FILA: "<< endl; 
			if (fgets (caracter, sizeof caracter, stdin) != NULL) {
			caracter[strlen(caracter)-1] = '\0'; 
		 	noNumero = false; 
		 	if (strlen(caracter) == 0) noNumero = true;
		 	for (p=0; p<strlen(caracter); p++) if (!isdigit(caracter[p])) noNumero = true;
			ingresoX = atoi(caracter);// ATOI ES PARA CAMBIAR EL CHAR INGRESADO A INT.
			if (ingresoX >=dimension){
		cout << "LA FILA TIENE QUE SER MENOR A" << (tablero.getDimension()) << endl;
				noNumero = true;
				}
				
			if (!noNumero) {
				validar = true; 
				}
		  	else 
		  	cout << "INGRESE NUMEROS MENORES A LA DIMENSION." <<endl <<endl;
		  	}
		  	}
		  	
		validar = false;
		while (!validar) {
		cout<< "INGRESE LA COLUMNA DONDE CREA QUE ESTA LA BOLITA:"<< endl; 
		if (fgets (caracter, sizeof caracter, stdin) != NULL) {
		caracter[strlen(caracter)-1] = '\0'; 
		 noNumero = false; 
		 if (strlen(caracter) == 0) noNumero = true;
		 for (p=0; p<strlen(caracter); p++) if (!isdigit(caracter[p])) noNumero = true;
		ingresoY = atoi(caracter);// ATOI ES PARA CAMBIAR EL CHAR INGRESADO A INT.
		if (ingresoY >=dimension){
		cout << "TIENE QUE INGRESAR UN NUMERO MENOR A LA DIMENSION."<< endl;
		noNumero = true;
		}
		if (!noNumero) {
		validar = true; 
		}
		  else 
		  cout << "Tiene que ingresar numeros..." <<endl <<endl;
		  }
		  }
		  
		  	if(tablero.getCasilla(ingresoX, ingresoY) !='O')
		  	{
		  	 
				igual=false; 
				break;
			}
			
			else{
			cout<< "INTENTE CON OTRA POSICION, ESA YA LA JUGO."<< endl;
			igual=true;
			} 
		  }
		  
	validarIntento(ingresoX ,ingresoY );
}
	//Debe implementar un metodo que se encargue de iniciar el juego y controlar su desarrollo
    //Este metodo debe recibir las entradas del usuario, imprimir el tablero y validar los intentos
}

void Arbitro::imprimirTablero() {
	cout <<" ";
		for (int y=0;y<tablero.getDimension();y++)
		{cout <<" "<<" "<< y<<"";
		}
		cout<<" " <<endl;
		
	for (int l=0; l< tablero.getDimension(); l++)
	{ cout <<endl<< l <<"  ";
	
		for (int a=0; a<tablero.getDimension();a++)
		{
				cout << tablero.getCasilla(l,a)<< "  ";
}

		
		cout<<endl;
}


//	cout << filaBolita<< "," << columnaBolita<< endl;	
    //Debe implementar un metodo que imprima el tablero en pantalla
    //Recuerde que el usuario no puede conocer la posicion de la bolita
}

int Arbitro::calcularDistancia(int fila, int columna){
	int distancia;
	distancia = abs(filaBolita - fila)+ abs(columnaBolita - columna);
	    //Debe implementar un metodo que calcula la distancia entre la posicion (fila, columna)
    //Y la posicion real de la bolita
}

bool Arbitro::validarIntento(int fila, int columna){
	
	//puntaje =  100.0;
	if (fila == filaBolita && columna == columnaBolita){
		cout<< "FELICIDADES! SU PUNTAJE FINAL ES: "<< puntaje;
		puntaje = 0;
	} 
	else {tablero.setCasilla(fila,columna,'O');
	puntaje = floor(puntaje-(100/(tablero.getDimension()*tablero.getDimension())));
	cout <<"NO ES LA POSICION DE LA BOLITA, SU PUNTAJE ES: "<<puntaje << endl;
	cout <<"DE LA DIMENSION INGRESADA, USTED ESTA A "<<calcularDistancia(fila,columna) <<" CASILLA DE LA BOLITA. "<< endl;
	imprimirTablero();
	}
	
	
    //Este metodo debe validar el intento del usuario, debe informarle si fue correcto o no
    //Retorna verdadero si el intento es correcto y falso si no lo es
    //En caso de no serlo debe realizar los cambios correspondientes a las variables miembro
    //Y debe informar por pantalla cual fue la distancia del fallo y el puntaje restante
}
