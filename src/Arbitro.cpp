//Debe crear una cabecera de archivo tal como se indico en clase.
//Controla todo el proceso del juego.

#include <iostream>
#include "Arbitro.h"
#include "Tablero.h"
#include <cstdlib> // Libreria que genera el numero aleatorio.
#include <stdlib.h>
#include <ctime> // Obtene y manipula informacion de fecha y hora.
#include <cmath> // Calcula las operaciones y transformaciones matematicas comunes.
#include <math.h>

using namespace std;

Arbitro::Arbitro() {
    juegoEnCurso = false;
    puntaje = 100.0;
    srand (time(NULL));
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


    cout << "Juego Iniciado" << endl;
    cout << endl;
    cout << "Ingrese la dimension del tablero" << endl;
    cout << endl;
    cin >> n;
    system ("cls"); // Realiza una limpieza de la consola para mejor visualización.

    filaBolita = rand()%(n-1);
    columnaBolita = rand()%(n-1);
    Tablero tablero(n);

    cout << "Juego Iniciado" << endl;
    cout << endl;

    while (juegoEnCurso) {
        for (int h = 0; h <= n; h ++) {
            if ((h-1) <0) {
                cout << "   " ;
            }
            else {
                cout << h-1 << " ";
            }
        }
        cout << endl;
        for (int fila = 0; fila < n ; fila ++) {
            if (fila < 10) {
                cout << fila << "  ";
            }
            else {
                cout << fila << " ";
            }
            for( int columna = 0; columna <n ; columna ++) {
                if(columna >= 10) {
                    cout << " ";
                    cout << tablero.getCasilla(fila, columna)<< " ";
                }
                else
                    cout << tablero.getCasilla(fila, columna)<< " ";
            }
            cout << endl;
        }

        int f = 0;
        int c = 0;

        cout << "Ingrese fila: " << endl;
        cin >> f;
        while(f >= n) {
            cout << "Fila invalida"<< endl;
            cout << "Ingrese fila: " << endl;
            cin >> f;
            cout << endl;
        }

        cout << "Ingrese columna: "<< endl;
        cin >> c;
        while (c >= n) {
            cout << "Columna invalida"<< endl;
           cout << "Ingrese columna: " << endl;
            cin >> c;
            cout << endl;
        }

        if ((tablero.getCasilla(f , c))== 'N') {
            cout << "Esta coordenada ya fue ingresada" << endl;
        }
        else {
            if (calcularDistancia(f , c)!= 0) {
                tablero.setCasilla(f , c , 78);
                cout << "Tiene un fallo de: " << calcularDistancia(f , c) << endl;
                puntaje -= (puntaje / (n*n));
                cout << "Su puntaje es de: " << puntaje << endl;
                cout << endl;
                cout << "** Nuevo Intento **"<< endl;
            }
            else {
                system ("cls");
                tablero.setCasilla (f, c, 223);
                cout << "***** Ha ganado *****" << endl;
                cout << endl;
                for (int h = 0 ; h <= n ; h ++) {
                    if ((h-1) < 0) {
                        cout <<"   " ;
                    }
                    else {
                        cout << h-1 << " ";
                    }
                }
                cout << endl;
                for (int fila = 0; fila < n ; fila ++) {
                    if (fila < 10) {
                        cout << fila << "  ";
                    }
                    else {
                        cout << fila << " ";
                    }
                    for (int columna = 0; columna < n ; columna ++) {
                        if (columna >= 10) {
                            cout << " ";
                            cout << tablero.getCasilla (fila, columna)<< " ";
                        }
                        else
                        cout << tablero.getCasilla (fila, columna) << " ";
                    }
                    cout << endl;
                }
                cout << "Su puntaje es de: " << puntaje << endl;
                juegoEnCurso = false;
            }
        }

    }
    //Debe implementar un metodo que imprima el tablero en pantalla
    //Recuerde que el usuario no puede conocer la posicion de la bolita
}

int Arbitro::calcularDistancia(int fila, int columna){

    int a = fila - filaBolita;
    int b = columna - columnaBolita;
    int distancia = floor (sqrt ((pow(a, 2)) + (pow(b, 2))));
    return distancia;
    //Debe implmentar un metodo que calcula la distancia entre la posicion (fila, columna)
    //Y la posicion real de la bolita
}

bool Arbitro::validarIntento (int fila, int columna){

    if (calcularDistancia (fila, columna) == 0)     {
        return true;
    }
    else {
        return false;
    }
    //Este metodo debe validar el intento del usuario, debe informarle si fue correcto o no
    //Retorna verdadero si el intento es correcto y falso si no lo es
    //En caso de no serlo debe realizar los cambios correspondientes a las variables miembro
    //Y debe informar por pantalla cual fue la distancia del fallo y el puntaje restante

}
