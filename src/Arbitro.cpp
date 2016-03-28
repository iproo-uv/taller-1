//===============================================================================
// Name        : Arbitro.cpp
// Author      : Neydor Avila Navarrete, Joan Sebastian Diaz Ocampo, John Cortez.
// Version     :0.0.0.1
// Copyright   : este archivo contiene varios metodos los cuales nos permiten :
//iniciar el juego,pedir datos al usuario,imprimir el tablero,validar intentos,entre otras cosas.
//===============================================================================
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
	cout << "BIENVENIDO AL JUEGO DE ADIVINAR LA POSICION DE LA BOLITA!"<< endl;
	cout << "En cuantos intentos podra adivinar la posicion de la bolita?"<< endl;	
   	cout << "Primero..."<< endl;
	int dimension;
  	unsigned n; 
	char letra[BUFSIZ]; 
	bool noNumero;
   	//_________________________________________________________________http://www.ehowenespanol.com/entrada-sea-entero-c-como_283817/
	while (!juegoEnCurso) {
		cout<< "Ingrese la dimension que desea en el tablero de juego: "<< endl; 
		if (fgets (letra, sizeof letra, stdin) != NULL) {
			letra[strlen(letra)-1] = '\0'; 
	 		noNumero = false; 
	 		if (strlen(letra) == 0) noNumero = true;
	 		for (n=0; n<strlen(letra); n++) if (!isdigit(letra[n])) noNumero = true;
		    dimension = atoi(letra);// ATOI ES PARA CAMBIAR EL CHAR INGRESADO A INT.
			if (20 < dimension){
				noNumero = true;
			}
			if (dimension < 2){
				noNumero = true;
			}
			if (!noNumero) {
				juegoEnCurso = true; 
			}
	  		else {
			cout << "Ingrese un numero natural mayor de uno y menor que 20..." <<endl <<endl;
			}	
		}	
	}
	system("cls");
	cout << "Este es su tablero de juego de " << dimension << " por " << dimension << "..." <<endl <<endl;
	Tablero tablerito (dimension);
	tablero = tablerito;
	filaBolita = rand ()% (tablero.getDimension());
	columnaBolita = rand ()% (tablero.getDimension());
	tablero.getCasilla(filaBolita,columnaBolita);
	cout<<endl;
	imprimirTablero();
	cout<<endl;
	int ingresoX,ingresoY;
	while(puntaje > 0){
		validarIntento(ingresoX,ingresoY);
	}
	//Debe implementar un metodo que se encargue de iniciar el juego y controlar su desarrollo
    //Este metodo debe recibir las entradas del usuario, imprimir el tablero y validar los intentos
}	

void Arbitro::imprimirTablero() {
	cout <<" ";
	for (int y=0;y<tablero.getDimension();y++){
		cout <<" "<<" "<< y+1<<"";
	}
	cout<<" " <<endl;
	for (int l=0; l< tablero.getDimension(); l++){
		cout <<endl<< l + 1<<"  ";
	for (int a=0; a<tablero.getDimension();a++){
		cout << tablero.getCasilla(l,a)<< "  ";
	}
		cout<<endl;
	}
    //Debe implementar un metodo que imprima el tablero en pantalla
    //Recuerde que el usuario no puede conocer la posicion de la bolita
}

int Arbitro::calcularDistancia(int fila, int columna){
	int distancia;
	distancia = abs(filaBolita - fila)+ abs(columnaBolita - columna);//abs es valor absoluto...
	//Debe implementar un metodo que calcula la distancia entre la posicion (fila, columna)
    //Y la posicion real de la bolita
}

bool Arbitro::validarIntento(int fila, int columna){
	bool validar = false,noNumero = false;
	int n;
	char letra [BUFSIZ];
	juegoEnCurso = true;
	while (juegoEnCurso){
		validar=false;
		while (!validar) {
				cout<< "Ingrese la FILA donde usted cree que esta la bolita: "<< endl; 
				if (fgets (letra, sizeof letra, stdin) != NULL) {	
					letra[strlen(letra)-1] = '\0'; 
		 			noNumero = false; 
		 			if (strlen(letra) == 0) noNumero = true;
		 			for (n=0; n<strlen(letra); n++) if (!isdigit(letra[n])) noNumero = true;
					fila= atoi(letra);// ATOI ES PARA CAMBIAR EL CHAR INGRESADO A INT.
					if (fila > tablero.getDimension()){
						noNumero = true;
					}
					if (fila == 0){
						noNumero = true;
					}	
					if (!noNumero) {
						validar = true; 
					}
		  			else 
		  			cout << "Tiene que ingresar numeros menores a la dimension ("<< tablero.getDimension()<< ") ingresada..." <<endl <<endl;
		  		}		
		  	}
		validar = false;
		while (!validar) {
				cout<< "Ingrese la COLUMNA donde usted cree que esta la bolita: "<< endl; 
				if (fgets (letra, sizeof letra, stdin) != NULL) {
					letra[strlen(letra)-1] = '\0'; 
		 			noNumero = false; 
		 			if (strlen(letra) == 0) noNumero = true;
		 			for (n=0; n<strlen(letra); n++) if (!isdigit(letra[n])) noNumero = true;
					columna = atoi(letra);// ATOI ES PARA CAMBIAR EL CHAR INGRESADO A INT.
					if (columna > tablero.getDimension()){
						noNumero = true;
					}
					if (columna == 0){
						noNumero = true;
					}
					if (!noNumero) {
						validar = true; 
					}
		  			else 
		  			cout << "Tiene que ingresar numeros menores a la dimension ("<< tablero.getDimension()<< ") ingresada..." <<endl <<endl;
		  		}
		  	}
		if (tablero.getCasilla(fila-1 ,columna-1) == 'X'){
			juegoEnCurso = false;
			break;
		}
		else {
			system ("cls");
			cout<< "Esa posicion ya se jugo..."<<endl;

			//cout<< "Ingrese una posicion diferente a la jugada anteriormente..."<< endl;
			imprimirTablero();
			juegoEnCurso = true;
		}
	}
	if (fila-1 == filaBolita && columna-1 == columnaBolita){
		cout<< "GANO! Su puntaje final es: "<< puntaje<< endl;
		cout<< " _______                             _"<< endl;
		cout<< "|  ___  |                           | |"<< endl;
		cout<< "| |   |_|                           | |"<< endl;
		cout<< "| |                                 | |"<< endl;
		cout<< "| |  ___    __ _   _ ___    __/_    | |"<< endl;
		cout<< "| | |_	|  | _` | | '_  |  | _  |   |_|" << endl;
		cout<< "| |___| |  ||_| | | | | |  ||_| |    _ "<< endl;
		cout<< "|_______|  |__,_| |_| |_|  |____|   |_|"<< endl << endl;
			cout <<"     ___---------__"<<endl;
			cout <<"    /              )____"<<endl;
			cout <<"   /                   )"<<endl;
			cout <<"  | ___  ___           )"<<endl;
			cout <<" / /  |/   |            ) "<<endl;
			cout <<" |( X |( X ||           |"<<endl;
			cout <<" | (_// \\_/ |           |"<<endl;
			cout <<" |_| (||)   |_______|   |"<<endl;
			cout <<" |  ||     | _  / /   |"<<endl;
			cout <<" |_________|| )/ /   /"<<endl;
			cout <<"  |_|_|_|_|/|  _/___/"<<endl;
			cout <<"   _ _/_ _ /  |"<<endl;
			cout <<"  .|_|_|_|_|   |"<<endl;
			cout <<"  |           / "<<endl;
			cout <<"  |__________/  "<<endl;
		puntaje = 0;
	} 
	else {tablero.setCasilla(fila-1,columna-1,'O');
	system ("pause");
	system("cls");
	puntaje = floor(puntaje-(100/(tablero.getDimension()*tablero.getDimension())));
	cout <<"Intento invalido... Su puntaje es: "<<puntaje << endl;
	cout <<"Su distancia a la bolita es de: "<<calcularDistancia(fila-1,columna-1)<< endl;
	imprimirTablero();
	cout<< endl;
	}//Este metodo debe validar el intento del usuario, debe informarle si fue correcto o no
    //Retorna verdadero si el intento es correcto y falso si no lo es
    //En caso de no serlo debe realizar los cambios correspondientes a las variables miembro
    //Y debe informar por pantalla cual fue la distancia del fallo y el puntaje restante
}

