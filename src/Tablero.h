#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_
//FICHA CRC:
//clase : Tablero
//Responsabilidad : tiene como funcion principal dotar
//A los demas archivos de funciones que serán de mucha
//Ayuda para desarrollar el juego "encuentra la bolita".
//Colaboracion : tiene una relacion significativa 
//Con la clase "Arbitro" la cual tiene varias funciones 
//Que le dan al juego un orden y un estilo.

class Tablero {
	private:
		    char** casillas;
	int dimension;
	public:
		    Tablero();
	Tablero(int n);
	~Tablero();
	char getCasilla(int x, int y);
	void setCasilla(int x, int y, char value);
	int getDimension();
}
;
#endif 
/* SRC_TABLERO_H_ */
