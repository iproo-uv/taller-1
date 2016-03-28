//===============================================================================
// Name        : Arbitro.h
// Author      : Neydor Avila Navarrete, Joan Sebastian Diaz Ocampo, John Cortez.
// Version     : 0.0.0.1
// Copyright   : en este archivo se encuentra la clase Arbitro la cual tiene relacion con el archivo 
//Tablero.h, aqui se encontrarán varias funciones que se utilizarán en el archivo Arbitro.cpp
//===============================================================================
#ifndef ARBITRO_H_
#define ARBITRO_H_

#include "Tablero.h"

class Arbitro {
private:
    Tablero tablero;
    bool juegoEnCurso;
    double puntaje;
    int filaBolita;
    int columnaBolita;
public:
    Arbitro();
    ~Arbitro();
    void iniciarJuego();
    void imprimirTablero();
    bool validarIntento(int fila, int columna);
    int calcularDistancia(int fila, int columna);
};

#endif /* ARBITRO_H_ */
