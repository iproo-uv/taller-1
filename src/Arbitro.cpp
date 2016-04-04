//Clase: Arbitro
//Responsabilidad: controla el juego, lo inicia, imprime el tablero, valida intentos y calcula la distancia
//Colaboracion: colabora con la clase Tablero

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Arbitro.h"
using namespace std;

Arbitro::Arbitro(){
    tablero = Tablero();
    juegoEnCurso = false;
    puntaje = 100.0;
    srand(time(NULL));
    filaBolita = 0;
    columnaBolita = 0;
}

Arbitro::~Arbitro() {
    // TODO Auto-generated destructor stub
}

void Arbitro::iniciarJuego(){
    int casillas;
    cout << "Ingrese las casillas del tablero:" << endl;
    cin >> casillas;
    tablero = Tablero(casillas);
    srand(time(0));
    filaBolita = rand()%casillas;
    columnaBolita = rand()%casillas;
    imprimirTablero();
	while(!juegoEnCurso){
		int fila;
		cout << "\nIngrese el numero de fila: " << endl;
		cin >> fila;
		int columna;
		cout << "Ingrese el numero de columna: " << endl;
		cin >> columna;
		if(validarIntento(fila-1,columna-1)){
            if(filaBolita == fila-1 && columnaBolita == columna-1){
            juegoEnCurso = true;
            tablero.setCasilla(fila-1,columna-1,'0');
            cout << "Has encontrado la bolita!!"
                 << "\nTu puntaje es: "
                 << puntaje << endl;
            }
            else{
                if(tablero.getCasilla(fila-1,columna-1) == '_'){
                    cout << "Ya se busco en la casilla" << endl;
                }
                else{
                    tablero.setCasilla(fila-1,columna-1,'_');
                    cout << "Esta a "
                         << calcularDistancia(fila-1,columna-1)
                         << " casillas de la bolita" << endl;
                    puntaje = puntaje - 100/(tablero.getDimension()*tablero.getDimension());
                }
            }
		}
		else{
            cout << "Posicion invalida" << endl;
		}
		system("pause");
		system("cls");
		imprimirTablero();
	}

}

void Arbitro::imprimirTablero() {
    for(int i=0;i<tablero.getDimension();i++){
        for(int j=0;j<tablero.getDimension();j++){
            cout << tablero.getCasilla(i,j);
        }
        cout << endl;
    }
}

double Arbitro::calcularDistancia(int fila, int columna){
    return sqrt(pow(fila-filaBolita,2)) +
    sqrt(pow(columna-columnaBolita,2));
}

bool Arbitro::validarIntento(int fila, int columna){
    bool intento = true;
    if(fila >= tablero.getDimension() ||
        columna >= tablero.getDimension()){
        intento = false;
    }
    return intento;
}
