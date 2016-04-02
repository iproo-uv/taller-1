//Debe escribir una cabecera de archivo con la plantilla CRC: Clase, Responsabilidad y Colaboracion
//Clase: 			arbitro.h
//Responsabilidad: 	El arbitro inicializa el juego y se encaga de la debida funcion del tablero 
//Colaboracion: 	la clase arbitro utiliza la clase tablero 

#ifndef ARBITRO_H_
#define ARBITRO_H_

#include "Tablero.h"

class Arbitro 
{
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
O_H_ */
