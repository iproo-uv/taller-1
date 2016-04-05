/*
  Nombre: Arbitro.cpp
  Autor: Jairo Vera, Sergio Cadavid
  Fecha Creacion: marzo 14 de 2016
  Fecha Modificación: abril 4 de 2016
  Versión : 1.0

    Responsabilidad:
    - Iniciar el juego, imprimir el tablero, decirle al usuario si acerto la posisicion de la bolita
    y si no acerto mostrar la distancia que le falto y restarle el puntaje
    Colaboracion:  Arbitro.h, tablero.cpp, tablero.h
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Arbitro.h"
#include "Tablero.h"

using namespace std;

Arbitro::Arbitro()
{
    juegoEnCurso = false;
    puntaje = 100.0;
    srand(time(NULL));
    filaBolita = 0;
    columnaBolita = 0;
    filausuario=0;
    columnausuario=0;
    dist=0;
}

Arbitro::~Arbitro()
{
}

void Arbitro::iniciarJuego()
{

  int valorusuario = 0;
    cout << "Ingrese valor matriz" << endl;
    cin >> valorusuario;
    while(valorusuario<=0)
    {
        cout <<"El tablero tiene que ser mayor a 0" <<endl;
        cout << "Ingrese valor matriz" << endl;
        cin >> valorusuario;
    }

   Tablero matrizusuario(valorusuario);
   tablero = matrizusuario;
   imprimirTablero();
   cout << endl;

   filaBolita=rand()%valorusuario;
   columnaBolita=rand()%valorusuario;

   tablero.setCasilla(filaBolita, columnaBolita, 67);
   juegoEnCurso = true;
while(juegoEnCurso)
	{
 	cout << "Ingrese fila" << endl;
 	cin >> filausuario;

 	cout <<"Ingrese columna" << endl;
 	cin >> columnausuario;


	calcularDistancia(filausuario, columnausuario);
	validarIntento(filausuario, columnausuario);
	}

}

void Arbitro::imprimirTablero()
{
	int imprimir2=tablero.getDimension();
	for (int fila =0; fila<imprimir2; fila++)
    {
        for(int col=0; col<imprimir2; col++)
        {
            cout << tablero.getCasilla(fila, col) << " ";
        }
        cout << endl;
    }

}

int Arbitro::calcularDistancia(int fila, int columna)

{
   if (fila != filaBolita && columna != columnaBolita)
   {
	dist = floor(sqrt(((fila - filaBolita)*(fila - filaBolita)) + (columna - columnaBolita)*(columna - columnaBolita)));
	cout << "No acerto la posisicon de la bolita por ";
	cout << dist;
	cout << " posiciones" <<endl;
   }
	if (fila == filaBolita && columna == columnaBolita)
		{
	 		juegoEnCurso = false;
			 cout << "Encontro la bolita" << endl;
			 cout << puntaje << endl;
		}
	else if(puntaje<=0)
		{
    		juegoEnCurso = false;
    		cout << "Puntaje menor a 0, ha perdido!"<<endl;
		}


	return 0;
}

bool Arbitro::validarIntento(int fila, int columna)
{

		 puntaje = floor (puntaje - (puntaje / (tablero.getDimension() * tablero.getDimension())));
		 cout << "Su puntaje es: ";
		 cout << puntaje << endl;

}
