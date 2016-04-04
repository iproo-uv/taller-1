//============================================================================
// Name        : Arbitro.h
// Author      : Diana Marcela Rodriguez - Daniela Mejia
// Version     : 0.0.1
//============================================================================
#ifndef ARBITRO_H_
#define ARBITRO_H_
#include "Tablero.h"
/*
   Clase: Arbitro
   Responsabilidad:
    - iniciar el juego
    - imprimir el tablero
    - Calcular puntaje
    - calcular la distancia del lugar donde se hizo un intento hasta donde se encuentra la bolita
   Colaboracion: Tablero.h
*/
class Arbitro {
private:
    Tablero tablero;
    bool juegoEnCurso;
    int puntaje;
    int filaBolita;
    int columnaBolita;
    int oportunidades;
    int fila;
    int columna;
public:
    Arbitro();
    ~Arbitro();
    void iniciarJuego();
    void imprimirTablero();
    void setPuntaje(int);
    bool validarIntento(int fila, int columna);
    int calcularDistancia(int fila, int columna, int oport);


};
#endif /* ARBITRO_H_ */
