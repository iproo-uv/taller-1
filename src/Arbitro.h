//Clase: Arbitro
//Responsabilidad: Contiene las variables públicas y privadas de la clase Arbitro
//Colaboracion: se relaciona con la clase Tablero


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
    double calcularDistancia(int fila, int columna);
};

#endif /* ARBITRO_H_ */
