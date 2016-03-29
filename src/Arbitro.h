//============================================================================
// Name        : taller1.cpp
// Author 1     : Magrel Londoño - 1556094
// Author 2     :Yohan Mesa  -1556227
// Version     : 1
// Copyright   : 
// Description : Arbitro.h
//============================================================================
#ifndef ARBITRO_H_
#define ARBITRO_H_

#include "Tablero.h"

class Arbitro {
private:
    Tablero tablero	;
    bool juegoEnCurso;
    double puntaje;
    int filaBolita;
    int columnaBolita;
public:
    Arbitro(Tablero);
    ~Arbitro();
    void iniciarJuego();
    void imprimirTablero();
    bool validarIntento(int fila, int columna);
    int calcularDistancia(int fila, int columna);
    void posicionBola();
    bool validarPosicionBola(int fila, int columna);
    
};

#endif /* ARBITRO_H_ */
