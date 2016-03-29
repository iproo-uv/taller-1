//============================================================================
// Name        : taller1.cpp
// Author 1     : Magrel Londoño - 1556094
// Author 2     :Yohan Mesa  -1556227
// Version     : 1
// Copyright   : 
// Description : Tablero.h
//============================================================================

#ifndef TABLERO_H
#define TABLERO_H
class Tablero {
private:
	
    char** casillas;
    int dimension;
    
public:
    Tablero();
    Tablero(int n);
    ~Tablero();
    char getCasilla(int x, int y);
    void setCasilla(int x, int y, char valu);
    int getDimension();
};

#endif /* SRC_TABLERO_H_ */
