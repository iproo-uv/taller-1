//===================================================================================================================
// Name                     : Arbitro.h
// Author                   : Jesus Alberto Ospina y Nelson galeano
// Version                  : 0.0.1
// Descripcion              : me permite tener los metodos atributos y variables miembro de una clase arbitro mediante una jugada


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
