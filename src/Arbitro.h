/*
 * Clase: Arbitro
 * Responsabilidad: El Arbitro inicia el juego se encarga de...
 * Colaboración: La clase Arbitro utiliza la clase Tablero
 * */

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
