/*
    Nombre: abritro.h
    Autor: Jairo Vera, Sergio Cadavid
    Fecha Creacion: marzo 14 de 2016
    Fecha Modificación: abril 4 de 2016
    Versión : 1.0

    Clase: Abritro
    Responsabilidad:
    - Crear las variables y metodos que se usaran en los archivos .cpp
    Colaboracion:  arbitro.cpp
*/


#ifndef ARBITRO_H_
#define ARBITRO_H_
#include "Tablero.h"

class Arbitro
{
private:
    Tablero tablero;
    bool juegoEnCurso;
    double puntaje;
    int filaBolita;
    int columnaBolita;
    int filausuario;
    int columnausuario;
    int dist;

public:
    Arbitro();
    ~Arbitro();
    void iniciarJuego();
    void imprimirTablero();
    bool validarIntento(int fila, int columna);
    int calcularDistancia(int fila, int columna);
};

#endif /* ARBITRO_H_ */
