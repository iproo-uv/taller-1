//Debe escribir una cabecera de archivo con la plantilla CRC: Clase, Responsabilidad y Colaboracion


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
    void imprimirLiniaSuperior();
    void imprimirLiniaInferior();
    void imprimirLiniaDivision();
    void imprimirLiniaDeDatos();
    bool validarIntento(int fila, int columna);
    int calcularDistancia(int columna, int fila);
};

#endif /* ARBITRO_H_ */
