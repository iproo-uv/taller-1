//============================================================================
// Name        : taller1.cpp
// Author      : Diana Marcela Rodriguez - Daniela Giraldo Mejia
// Version     : 0.0.1
//============================================================================

#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_



/*
   Clase: Tablero
   Responsabilidad: 
   - Crea la dimension y casillas del arreglo (tablero)
    
   Colaboracion: Ninguna
*/


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
};

#endif /* SRC_TABLERO_H_ */
