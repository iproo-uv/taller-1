//Debe escribir una cabecera de archivo con la plantilla CRC: Clase, Responsabilidad y Colaboracion
/*
Clase: Tablero.
Responsabilidad: La clase Tablero se encarga del dise�o del tablero de juego, en sus dimensiones y casillas.
Colaboraci�n: La clase Tablero no necesita colaboraci�n de alguna otra clase.
*/

#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_

class Tablero {
private:
    char** casillas;
    int dimension;
public:
    Tablero(); // Constructor.
    Tablero(int n); // Constructor con parametros.
    ~Tablero();
    char getCasilla(int x, int y);
    void setCasilla(int x, int y, char value);
    int getDimension();
};

#endif /* SRC_TABLERO_H_ */
