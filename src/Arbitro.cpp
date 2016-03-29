//===============================================
//clase: Arbitro
//responsabilidad: el Arbitro se encarga de iniciar el juego, de dar explicacion al procedimiento del juego
//colaboracion: esta clase no tiene colaboracion
//===============================================
//Debe crear una cabecera de archivo tal como se indico en clase

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Arbitro.h"
using namespace std;

Arbitro::Arbitro() {
    juegoEnCurso = false;
    puntaje = 100.0;
    srand (time(NULL));
    filaBolita =0;
    columnaBolita = 0;
}

Arbitro::~Arbitro() {
    // TODO Auto-generated destructor stub
}

void Arbitro::iniciarJuego(){
	int n:
	cout << "ingrese la dimension del tablero" << endl;
	cin >> n;
	tablero  = Tablero (n);
	filaBolita = rand() % n;
	columnaBolita = rand() % n;
	tablero: setCasilla(filaBolita, columnaBolita, '0');
	juegoEnCurso = true;
	while()juegoEnCurso (
			imprimirTablero();
	        int fila= 1;
	        int columna =1;
	        cout << "ingrese la fila de su tablero:" << endl;
	        cin >> fila;
	        cout <<"ingrese la columna de su intento:" <<endl;
	        cin >> columna;
	        juegoEnCurso = validarIntento (fila. columna);
			)
    //Debe implementar un metodo que se encargue de iniciar el juego y controlar su desarrollo
    //Este metodo debe recibir las entradas del usuario, imprimir el tablero y validar los intentos
}

void Arbitro::imprimirTablero() {
	cout << " imprimir tablero ";
	for (int 1 = 0;)

    //Debe implementar un metodo que imprima el tablero en pantalla
    //Recuerde que el usuario no puede conocer la posicion de la bolita
}

int Arbitro::calcularDistancia(int fila, int columna){
	float distancia = sqrt ((pow((filaBolita-fila),2)+pow(columnaBolita-columna,2)));
	cout<<"Estas a" <<distancia<< "de encontrar la bolita Sigue intentando" <<endl;
    //Debe implmentar un metodo que calcula la distancia entre la posicion (fila, columna)
    //Y la posicion real de la bolita
}

bool Arbitro::validarIntento(int fila, int columna){
	if(fila==filaBolita&&columna==columnaBolita){
		cout<<"¡¡En Hora Buena Has Ganado!!" <<endl;
		cout<<"tu puntaje es" <<puntaje<<endl;
		juegoEnCurso=false;
		return true;
	}else	{
		      puntaje+== 5;
		      tablero.setCasillas(fila,columna);
		      return false;  
	        }  
	}
    //Este metodo debe validar el intento del usuario, debe informarle si fue correcto o no
    //Retorna verdadero si el intento es correcto y falso si no lo es
    //En caso de no serlo debe realizar los cambios correspondientes a las variables miembro
    //Y debe informar por pantalla cual fue la distancia del fallo y el puntaje restante
}

