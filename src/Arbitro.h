//FICHA CRC:
//clase : Tablero
//Responsabilidad : Se encarga de comparar datos ingresados por el usuario y la posicion de la bolita.
//Colaboracion : tiene una relacion significativa con la clase tablero, estando incluida en este archivo.
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
}
;
#endif 
/* ARBITRO_H_ */


