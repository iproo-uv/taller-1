//============================================================================
// Name        : taller1.cpp
// Author 1     : Magrel Londoño - 1556094
// Author 2     :Yohan Mesa  -1556227
// Version     : 1
// Copyright   : 
// Description : Arbitro.cpp
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include "Arbitro.h"
#include <stdlib.h>
#include "Tablero.h"
using namespace std;

Arbitro::Arbitro(Tablero tablerito) {
    juegoEnCurso = false;
    puntaje = 100.0;
    srand(time(NULL));
    tablero = tablerito;
}

Arbitro::~Arbitro() {
    // TODO Auto-generated destructor stub
}

void Arbitro::iniciarJuego() 
{	
     cout<<columnaBolita<<filaBolita<<endl;
	 int fila=0,columna=0;
	 bool encontrado=false;
	 while(!encontrado)
	 {    
	    
	 	cout<<"Por favor ingrese la columna a destapar: "<<endl;
    	cin>>columna;
	 	cout<<"Por favor ingrese la fila a destapar: "<<endl;
    	cin>>fila;
    	calcularDistancia(columna,fila);

    	if((validarIntento(fila,columna))==true && (validarPosicionBola(fila,columna))==false)
    	{
    		system("cls");
    		tablero.setCasilla(fila,columna,'N');
    		imprimirTablero();
    		cout<<endl<<endl;
    		cout<<"Fallaste, vuelve a intentarlo "<<endl;
    		cout<<endl<<endl;
    	    
    	
    		
    	} 
    	else
    	{
    		if((validarIntento(fila,columna))==true && (validarPosicionBola(fila,columna))==true)
    		{
    			system("cls");
    			encontrado=true;
		  	    tablero.setCasilla(filaBolita, columnaBolita, char(2));
		  	    imprimirTablero();
		  	    cout<<endl<<endl;
		  	    cout<<"FELICIDADES HAS ADIVINADO"<<endl;
		  	    cout<<endl<<endl;
    		}
    		else 
    		{
    			system("cls");
    			cout<<endl<<endl;
    			cout<<endl<<endl;
    		    cout<<"Fallaste, la casilla ya esta ocupada o no existe en la dimension,"<<endl; 
    		    cout<<"VUELVE A INTENTARLO. "<<endl;
    		    cout<<endl<<endl;
    		    imprimirTablero();
    		    cout<<endl<<endl;
    		}

    	}
    	
    	calcularDistancia(columna,fila);
    	cout<<"Puntaje Restante: "<<puntaje<<endl;
    	cout<<endl<<endl;


	 }

		

	
    //Debe implementar un metodo que se encargue de iniciar el juego y controlar su desarrollo
    //Este metodo debe recibir las entradas del usuario, imprimir el tablero y validar los intentos
    
    
}

void Arbitro::imprimirTablero()
 {
    //Con este metodo se Imprimira el tablero.
    int dimen=tablero.getDimension();
    cout<<" ";
    for(int m=0; m<dimen; m++)
    {
    	cout<<" "<<m;
	}
	cout<<endl;
   for(int i=0; i<dimen; i++)
   {
   	 cout<<i<<" ";
   	  for(int j=0; j<dimen; j++)
   	  {
   	  	
   	  	cout<<tablero.getCasilla(i,j)<<" ";
		
			 	
	  }
	  cout<<endl;
   }
   
    
}

int Arbitro::calcularDistancia(int fila, int columna)
{
	
    //Con este metodo se calcula la distancia entre la posision del usuario y la de la bolita.     

	double distanciaF=0;
	int distanciaEntera=0;
	distanciaF = hypot(fila-columnaBolita, columna-filaBolita);
	distanciaEntera=floor(distanciaF);
	cout<<"Distancia: "<<distanciaEntera;
	cout<<endl;
}

bool Arbitro::validarIntento(int fila, int columna)
{
	//En este metodo se valida si la casilla esta desocupada o no, TAmbien se validad si lo que el usuario ingreso sea menor a la dimension.

    int	dimension=tablero.getDimension();

	if (fila<dimension && columna<dimension && (tablero.getCasilla(fila,columna))=='+')
	{
			return true;
	}
	else
	{	
	  if((fila<dimension && columna<dimension && (tablero.getCasilla(fila,columna))=='N') || (fila>=dimension && columna>=dimension) )
	  {
	  	return false;
	  }
		    	    
	}

	
	
    //Este metodo debe validar el intento del usuario, debe informarle si fue correcto o no
    //Retorna verdadero si el intento es correcto y falso si no lo es
    //En caso de no serlo debe realizar los cambios correspondientes a las variables miembro
    //Y debe informar por pantalla cual fue la distancia del fallo y el puntaje restante
}

void Arbitro::posicionBola()
{
	//En este metodo se hace "Aleatoriamente" la posicion de la bolita.
	int n = tablero.getDimension();
    srand(time(NULL));
    filaBolita=rand()%n;
    columnaBolita=rand()%n;
   
}
bool Arbitro::validarPosicionBola(int fila,int columna)
{
	//En este metodo se valida si fue acertada la bolita y debera retornar true, de lo contrario debera retornar false y
	//restarle al puntaje segun las reglas.
	int nume = tablero.getDimension();
	double restante=0;
	if(fila==filaBolita && columna==columnaBolita)
	return true;
	else
	restante=100/(nume*nume);
	puntaje=puntaje-restante;
	return false;
}

