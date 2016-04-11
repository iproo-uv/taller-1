//=====================================================================================
// Clase: Arbitro.
// Responsabilidad: La clase Arbitro inicializa el juego, muestra el puntaje despu�s
//                  de dar una posici�n y el n�mero de casillas si se err� en el tiro.
// Colaboraci�n: La clase Arbitro obtiene colaboraci�n de la clase Tablero.
//=====================================================================================

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
    Arbitro(Tablero);
    ~Arbitro();
    void iniciarJuego();
    void imprimirTablero();
    bool validarIntento(int fila, int columna);
    int calcularDistancia(int fila, int columna);
};

#endif /* ARBITRO_H_ */
