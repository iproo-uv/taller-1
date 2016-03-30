//Debe escribir una cabecera de archivo con la plantilla CRC: Clase, Responsabilidad y Colaboracion
/*
Clase: Arbitro.
Responsabilidad: La clase Arbitro se encarga de iniciar el juego y llevar un control sobre éste como imprimiendo el tablero de juego,
                validando posiciones, manejo del puntaje, dar indicios al jugador de la posición de la bola y mostrando
                mensajes al jugador durante el transcurso del juego.
Colaboración: La clase Arbitro necesita de la clase Tablero.
*/

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
