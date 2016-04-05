/*
    Nombre: Tablero.h
    Autor: Jairo Vera, Sergio Cadavid
    Fecha Creacion: marzo 14 de 2016
    Fecha Modificación: abril 4 de 2016
    Versión : 1.0

    Clase: Tablero
    Responsabilidad:
    - Crear las variables y metodos que se usaran en los archivos .cpp
    Colaboracion:  Tablero.cpp
*/


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
