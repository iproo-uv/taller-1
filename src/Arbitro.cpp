//Debe crear una cabecera de archivo tal como se indico en clase

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Arbitro.h"

using namespace std;

Arbitro::Arbitro(Tablero tablero1) 
{
	
    juegoEnCurso = false;
    puntaje = 100.0;
    srand(time(NULL));
    tablero = tablero1;
    filaBolita = rand()%tablero.getDimension();
    columnaBolita = rand()%tablero.getDimension();
}

Arbitro::~Arbitro() 
{
    // TODO Auto-generated destructor stub
    
}

void Arbitro::iniciarJuego() 
{
    //Debe implementar un metodo que se encargue de iniciar el juego y controlar su desarrollo
    //Este metodo debe recibir las entradas del usuario, imprimir el tablero y validar los intentos
    
	while(!juegoEnCurso)
	{
	imprimirTablero();
    int fila;
	int columna;
    cout << "Ingrese fila" << endl;
    cin >> fila;
    cout << "Ingrese columna" << endl;
	cin >> columna;
    juegoEnCurso = validarIntento(fila,columna);
	}
    
}

void Arbitro::imprimirTablero() 
{
    //Debe implementar un metodo que imprima el tablero en pantalla
    //Recuerde que el usuario no puede conocer la posicion de la bolita
    
	int dimension = tablero.getDimension();
	for (int x = 0; x < dimension; x++)
    {
		for (int y = 0; y < dimension; y++)
    	{
    		cout << tablero.getCasilla(x,y);
		}
		cout << endl;
	}
}

int Arbitro::calcularDistancia(int fila, int columna)
{
    /*Debe implmentar un metodo que calcula la distancia entre la posicion (fila, columna)
    Y la posicion real de la bolita*/

    int distancia= floor(sqrt((fila - filaBolita) * (fila - filaBolita)) + ((columna - columnaBolita) * (columna - columnaBolita)));
    return distancia;
}

bool Arbitro::validarIntento(int fila, int columna)
{
    //Este metodo debe validar el intento del usuario, debe informarle si fue correcto o no
    //Retorna verdadero si el intento es correcto y falso si no lo es
    //En caso de no serlo debe realizar los cambios correspondientes a las variables miembro
    //Y debe informar por pantalla cual fue la distancia del fallo y el puntaje restante
	
	bool respuesta = false;
	puntaje = puntaje - (100 /( tablero.getDimension() * tablero.getDimension() ));
    	if(fila == filaBolita && columna == columnaBolita)
    	{
    		cout << "**********************************" << endl;
    		cout << "* Felicidades Encontro La Bolita *" << puntaje <<endl;
    		cout << "**********************************" << endl;
			respuesta = true; 
		}
		else if(puntaje <= 0)
		{
			cout << "**************************" << endl;
			cout << "*       Tu pierdes       *" << endl;
			cout << "**************************" << endl;
			respuesta = false;
		}
		else 
		{
			cout<<"esta a una distancia de:  "<<calcularDistancia (fila,columna)<<endl;	
			cout<<"su puntaje es: "<<puntaje<<endl;
		}
		
		return respuesta;
}



