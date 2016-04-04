//============================================================================
// Name        : Arbitro.cpp
// Author      : Danna Brigitt Lopez Saavedra - Gianlucca Aguado Rendon
// Version     : 1.0
// Copyright   :
// Description :inicia el juego, genera los numeros aleatorios para la bolita, nos da el puntaje del jugador, imprime el tablero,
//              si una coordenada ya existe nos dice que ya esta, valida que los datos ingresados correspondan a la dimension del
//              tablero, calcula la distancia en donde se encuentre la bolita.

//============================================================================

//Debe crear una cabecera de archivo tal como se indico en clase

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include "Arbitro.h"
#include "Tablero.h"
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

    int n, x, y;
    cout << " Donde esta la bolita?" << endl;
    cout << endl;
    cout << "ingrese la dimension del tablero: " << endl;
    cout << endl;
    cin >> n;
    tablero = Tablero(n);

    //Asigna posicion aleatoria de la bolita
    filaBolita = 0 + rand() % n;
    columnaBolita = 0 + rand() % n;
    tablero.setCasilla(filaBolita, columnaBolita, 'v');

    do{
        system("cls");
        cout << "Puntaje -->" << puntaje << endl << endl;

        imprimirTablero();
        cout << endl;

        bool salida=true;
        do{
        cout << "Ingrese la coordenada en X:";
        cin >> y;
        cout << "Ingrese la coordenada en Y:";
        cin >> x;

        //Se le reduce 1 a las coordenadas para que quede más pro
        y--;
        x--;

        system("cls");


        // validar si las coordenadas ya fueron ingresadas
	        if(x < n && x >= 0 && y >= 0 && y < n)
			{
			    //valida si el dato ingresado es ya existe
				if(tablero.getCasilla(x, y ) =='O')
	       		{
                    //salida = false;
					//system("cls");
					cout << "Puntaje --> "<< puntaje << endl << endl;
					imprimirTablero();
					cout << endl <<"el dato que ud ingreso ya existe, ingrese nuevamente las coordenadas" << endl;
					cout << endl;
				}
				else{
					salida = false;
					tablero.setCasilla(x, y, 'O');
					system("cls");
					cout << "Puntaje --> "<< puntaje << endl << endl;
					imprimirTablero();
				}
			}
			else

			{
				system("cls");
				cout << "Puntaje --> "<< puntaje << endl << endl;
				imprimirTablero();
				cout << endl << "el dato que ud ingreso es invalido, ingrese nuevamente las coordenadas" << endl << endl;
				cout << endl;
			}

		}while(salida);


        if(validarIntento(x, y))
        {
            system("cls");
            cout << "Feliciadades" << endl;
            cout << "Su puntaje es --> "<< puntaje << endl << endl;
        }
        else{
            puntaje = puntaje - (100/(tablero.getDimension() * tablero.getDimension()));
            system("cls");
            cout << "Lo lamento, fallaste perdedor" << endl;
            cout << "Va es bajando el puntaje jajaja, " << "Puntaje --> "<< puntaje << setw(2) << endl << endl;
            cout << endl;
            imprimirTablero();
            cout << endl<< "La bolita se encuentra a " <<  calcularDistancia(x, y) << " casillas de la bolita " << endl; //esto es para que no salga un error antes de ejecutar

            system("pause");
            system("cls");
        }

        }while(!validarIntento(x, y) && puntaje > 0);


    //Debe implementar un metodo que se encargue de iniciar el juego y controlar su desarrollo
    //Este metodo debe recibir las entradas del usuario, imprimir el tablero y validar los intentos
}

void Arbitro::imprimirTablero() {

     int n = tablero.getDimension();

        for(int i=0; i < n; i++)
       {
            cout << setw(2);
           for (int j = 0; j < n; j++)
           {
              if(tablero.getCasilla(i, j)=='v') cout << 'X' << setw(2) ;
              else cout << tablero.getCasilla(i, j) << setw(2) ;
           }
           cout << endl;
       }


    //Debe implementar un metodo que imprima el tablero en pantalla
    //Recuerde que el usuario no puede conocer la posicion de la bolita
}


int Arbitro::calcularDistancia(int fila, int columna){

    /*
    int x = filaBolita - fila;
    int y = columnaBolita - columna;
    int distancia = sqrt( pow(fila-filaBolita) + pow(columna-columnaBolita));
    */

    //esto es nuevo lo hice en monitoria
    int x = filaBolita - fila;
    int y = columnaBolita - columna;
    int distancia = floor(sqrt( pow(x, 2) + pow(y,2)));

    //esto es nuevo lo hice en monitoria

    return distancia;

    //Debe implmentar un metodo que calcula la distancia entre la posicion (fila, columna)
    //Y la posicion real de la bolita


}

bool Arbitro::validarIntento(int fila, int columna){

    if(fila == filaBolita && columna == columnaBolita)
        return true;
    else
        return false;

    //Este metodo debe validar el intento del usuario, debe informarle si fue correcto o no
    //Retorna verdadero si el intento es correcto y falso si no lo es
    //En caso de no serlo debe realizar los cambios correspondientes a las variables miembro
    //Y debe informar por pantalla cual fue la distancia del fallo y el puntaje restante
}

