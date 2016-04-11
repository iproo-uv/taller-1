//============================================================================
// Nombre                    : Arbitro.cpp
// Autores                   : Cristhian Candelo, Laura Higuera
// Versión                   : 1.0.1
// Fecha creación            : 22/02/2016
// Fecha última modificación : 23/03/2016
//============================================================================


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
    filaBolita = 0;
    columnaBolita = 0;
    tablero = tablero1;

}

Arbitro::~Arbitro()
{
    // TODO Auto-generated destructor stub
}

void Arbitro::iniciarJuego()
{
    imprimirTablero();
    filaBolita = rand()% tablero.getDimension();
    columnaBolita = rand() % tablero.getDimension();
    int fila;
    int columna;
    cout << "¿DONDE ESTA LA BOLITA?" << endl;

    do
    {
        cout << "Ingrese fila" << endl;
        cin >> fila;
        cout << "Ingrese columna" << endl;
        cin>>columna;
        if (validarIntento(fila, columna)== true)
            {
               	juegoEnCurso = true;
            }

        else
            {
        	juegoEnCurso = false;
        	cout << "La bolita esta a " << calcularDistancia(fila,columna)<< " casillas. " << endl;
        	puntaje = (puntaje / (tablero.getDimension() * tablero.getDimension()));
        	cout << "Su puntaje es " << puntaje << endl;
        	cout << "Ingrese nuevo intento " << endl ;

        }

    }while (!juegoEnCurso);

    cout << "¡ACERTASTE! El juego ha terminado. ";
    cout << "Su puntaje es " << puntaje << endl;
}

void Arbitro::imprimirTablero(){

	int n = tablero.getDimension();
	for(int f=0; f<n; f++)
	{
		for(int c=0; c<n; c++)
		{
			cout<< tablero.getCasilla(f,c)<<" ";
		}
		cout<<endl;
	}
}

int Arbitro::calcularDistancia(int fila, int columna)
{
	int distancia;
    distancia = sqrt(((filaBolita-fila)*(filaBolita-fila))+ ((columnaBolita-columna)*(columnaBolita-columna)));

    return distancia;
}

bool Arbitro::validarIntento(int fila, int columna)
{
	bool aux;

     if (filaBolita == fila && columnaBolita == columna)
     {
    	 aux = true;
     }
     else
     {
    	aux = false;
     }

     return aux;
}
