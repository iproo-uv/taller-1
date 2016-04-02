//Debe escribir una cabecera de archivo con la plantilla CRC: Clase, Responsabilidad y Colaboracion
//Clase: 			Tablero.h
//Responsabilidad:	El tablero se encaga de la dimension
//Colaboracion:  	none

#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_

class Tablero 
{
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
    	
};

#endif /* SRC_TABLERO_H_ */

