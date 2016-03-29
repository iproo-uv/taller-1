//Debe escribir una cabecera de archivo con la plantilla CRC: Clase, Responsabilidad y Colaboracion

#ifndef ARBITRO_H_
#define ARBITRO_H_

#include "Tablero.h"

class Arbitro {
private:
    Tablero tablero = Tablero(0);
    bool juegoEnCurso;
    double puntaje;
    int filaBolita;
    int columnaBolita;
public:
    Arbitro(int tamanio);
    ~Arbitro();
    void iniciarJuego();
    void imprimirTablero();
    bool validarIntento(int fila, int columna);
    void calcularDistancia(int fila, int columna);
};

#endif /* ARBITRO_H_ */
