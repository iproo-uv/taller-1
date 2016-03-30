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
    srand(time(NULL));
    filaBolita = 0;
    columnaBolita = 0;
}

Arbitro::~Arbitro() {
    // TODO Auto-generated destructor stub
}

void Arbitro::iniciarJuego() {
    //Debe implementar un metodo que se encargue de iniciar el juego y controlar su desarrollo
    //Este metodo debe recibir las entradas del usuario, imprimir el tablero y validar los intentos
}

void Arbitro::imprimirTablero() {
    //Debe implementar un metodo que imprima el tablero en pantalla
    //Recuerde que el usuario no puede conocer la posicion de la bolita
}

int Arbitro::calcularDistancia(int fila, int columna){
    //Debe implmentar un metodo que calcula la distancia entre la posicion (fila, columna)
    //Y la posicion real de la bolita
}

bool Arbitro::validarIntento(int fila, int columna){
    //Este metodo debe validar el intento del usuario, debe informarle si fue correcto o no
    //Retorna verdadero si el intento es correcto y falso si no lo es
    //En caso de no serlo debe realizar los cambios correspondientes a las variables miembro
    //Y debe informar por pantalla cual fue la distancia del fallo y el puntaje restante
}

