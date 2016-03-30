//Debe escribir una cabecera de archivo con la plantilla CRC: Clase, Responsabilidad y Colaboracion
//=====================================================================================
 // Clase: Arbitro.h
 // Responsabilidad: La clase pone en masrcha el juego, crea el tablero, y controla el puntaje
 // Colaboraci�n: La clasenecesita colaboracion de la clase Tablero.h
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
    Arbitro();
    ~Arbitro();
    void iniciarJuego();
    void imprimirTablero();
    bool validarIntento(int fila, int columna);
    int calcularDistancia(int fila, int columna);
};

#endif /* ARBITRO_H_ */
