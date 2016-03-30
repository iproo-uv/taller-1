//Debe crear una cabecera de archivo tal como se indico en clase
//============================================================================
 // Nombre                    : Arbitro.cpp
 // Autores                   : Diego Delgado , Alejandro Becerra
 // Versión                   : 1.0.0
 // Fecha creación            : 22/02/2016
 // Fecha última modificación : 28/03/2016
 //============================================================================



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Arbitro.h"
#include "Tablero.h"
#include <math.h>
#include <stdlib.h>
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

    imprimirTablero();
    //Debe implementar un metodo que se encargue de iniciar el juego y controlar su desarrollo
    //Este metodo debe recibir las entradas del usuario, imprimir el tablero y validar los intentos
}

void Arbitro::imprimirTablero() {


    juegoEnCurso = true;
    int n;


    cout << "Inicia el juego." << endl;
    cout << endl;
    cout << "Ingrese dimension" << endl;
    cout << endl;
    cin >> n;
    system("cls");

    filaBolita = rand()%(n-1);
    columnaBolita = rand()%(n-1);
    Tablero tablero(n);
    double puntaje1 = (puntaje/(n*n));
    double puntaje2 = puntaje;
    double puntajeT;


    cout << "     Juego iniciado" << endl;
    cout << endl;

    while(juegoEnCurso)
    {
        for(int h=0; h<=n; h++)
        {
            if((h-1)<0)
            {
                cout <<"   " ;
            }
            else
            {
                cout << h-1 << " ";
            }
        }
        cout << endl;
        for(int fila = 0; fila<n; fila++)
        {
            if(fila < 10)
            {
                cout << fila << "  ";
            }
            else
            {
                cout << fila << " ";
            }
            for(int columna=0; columna<n; columna++)
            {
                if(columna>=10)
                {
                    cout << " ";
                    cout << tablero.getCasilla(fila, columna)<< " ";
                }
                else
                    cout << tablero.getCasilla(fila, columna)<< " ";
            }
            cout << endl;
        }

        int f=0;
        int c=0;

        cout << "Ingrese fila: " << endl;
        cin >> f;
        while(f>=n)
        {
            cout << "Numero invalido"<< endl;
            cout << "Ingrese fila: " << endl;
            cin >> f;
            cout << endl;
        }

        cout << "Ingrese columna: "<< endl;
        cin >> c;
        while(c>=n)
        {
            cout << "Numero invalido"<< endl;
           cout << "Ingrese columna: " << endl;
            cin >> c;
            cout << endl;
        }

        if ((tablero.getCasilla(f, c))== 'F')
        {
            cout << "Coordenada ya utilizada" << endl;
        }
        else
        {
            if(calcularDistancia(f, c)!= 0)
            {
                tablero.setCasilla(f, c, 70);
                cout << "Tiene un fallo de: " << calcularDistancia(f, c) << endl;
                puntajeT = puntaje2 - puntaje1;
                cout << "su puntaje es: " << puntajeT << endl;
                cout << endl;
                cout << "!!!Intenta con otra coordenada¡¡¡"<< endl;
                puntaje2 = puntajeT;
            }
            else
            {
                system("cls");
                tablero.setCasilla(f, c, 219);
                cout << "    GANASTE     " << endl;
                cout << endl;
                for(int h=0; h<=n; h++)
                {
                    if((h-1)<0)
                    {
                        cout <<"   " ;
                    }
                    else
                    {
                        cout << h-1 << " ";
                    }
                }
                cout << endl;
                for(int fila = 0; fila<n; fila++)
                {
                    if(fila < 10)
                    {
                        cout << fila << "  ";
                    }
                    else
                    {
                        cout << fila << " ";
                    }
                    for(int columna=0; columna<n; columna++)
                    {
                        if(columna>=10)
                        {
                            cout << " ";
                            cout << tablero.getCasilla(fila, columna)<< " ";
                        }
                        else
                        cout << tablero.getCasilla(fila, columna)<< " ";
                    }
                    cout << endl;
                }
                cout << "Felicitaciones usted es ganador: " << endl;
                cout << "Puntaje -> " << puntajeT << endl;
                juegoEnCurso = false;
            }
        }
    }
    //Debe implementar un metodo que imprima el tablero en pantalla
    //Recuerde que el usuario no puede conocer la posicion de la bolita
}

int Arbitro::calcularDistancia(int fila, int columna){

    int difB = fila - filaBolita;
    int difC = columna - columnaBolita;
    int diferencia = (floor(sqrt((pow(difB, 2))+(pow(difC, 2)))));
    return diferencia;
    //Debe implmentar un metodo que calcula la distancia entre la posicion (fila, columna)
    //Y la posicion real de la bolita
}

bool Arbitro::validarIntento(int fila, int columna){

    if(calcularDistancia(fila, columna)== 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    //Este metodo debe validar el intento del usuario, debe informarle si fue correcto o no
    //Retorna verdadero si el intento es correcto y falso si no lo es
    //En caso de no serlo debe realizar los cambios correspondientes a las variables miembro
    //Y debe informar por pantalla cual fue la distancia del fallo y el puntaje restante

}
