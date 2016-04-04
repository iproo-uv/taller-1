//============================================================================
// Name        : taller1.cpp
// Author      : Diana Marcela Rodriguez - Daniela Giraldo Mejia
// Version     : 0.0.1
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Arbitro.h"
using namespace std;

Arbitro::Arbitro() {
    juegoEnCurso = false;
    puntaje = 100.0;
    srand(time(NULL));
    filaBolita = 0;
    columnaBolita = 0;
}

Arbitro::~Arbitro()
{

    // TODO Auto-generated destructor stub
}

void Arbitro::iniciarJuego()
{
    juegoEnCurso = true;

    filaBolita = rand()&5;
    columnaBolita = rand()&5;
    oportunidades = 25;





    Tablero tablero(5);
	for(int fila = 0;  fila < 5; fila++)
	{
		cout << fila << " "; // muestra numero de las filas
		for (int columna = 0; columna < 5; columna++)
		{
			cout << " " << tablero.getCasilla(fila, columna) << " ";
			// Imprime lo que esta en la funcion getCasilla de la clase tablero (el tablero)
		}
		cout << endl;
	}
	
    //Debe implementar un metodo que se encargue de iniciar el juego y controlar su desarrollo
    //Este metodo debe recibir las entradas del usuario, imprimir el tablero y validar los intentos
    
   for (int i = 0; i< oportunidades; i++)
   Arbitro::calcularDistancia(filaBolita, columnaBolita, i);
    
}


void Arbitro::setPuntaje(int punt){
    puntaje = punt - 4;
}
//Calcula el puntaje del jugador


int Arbitro::calcularDistancia(int fila, int columna, int oport)
{

    if (oport<25){
    cout << "Introduzca el numero de la fila" << endl;
	cin >> fila;
	cout << "Introduzca el numero de la columna" << endl;
    cin >> columna;


    if (filaBolita == fila and columnaBolita == columna)
        {
        cout << "Ganaste" << endl;
        oportunidades = oport;
        }
    else{
        int filaLocal=(filaBolita - fila); // FilaLocal es igual a la distancia entre filas
        int columnaLocal=(columnaBolita - columna); // ColumnaLocal es igual a la distancia entre columnas
        if (filaLocal<0)
            filaLocal=filaLocal*-1;
        if (columnaLocal<0)
            columnaLocal=columnaLocal*-1;

        int res=filaLocal+columnaLocal;
         cout << "Esta a  " << res << " posiciones" << endl;
         
    //Debe implmentar un metodo que calcula la distancia entre la posicion (fila, columna)
    //Y la posicion real de la bolita
       
        setPuntaje(puntaje); // imprima el puntaje del jugador
        cout << "Su puntaje es " << puntaje << endl;


        
    }
    }
    
       



    

}


