//Clase: Abitro
//Responsablidad: Es el encargado de realizar y controlar el juego 
//Colaboración:  la clase arbitro utiliza la clase tablero.

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
    int validaEntrada(int inf, int sup); // metodo implementado para validar las entradas de numeros enteros.
};

#endif /* ARBITRO_H_ */
