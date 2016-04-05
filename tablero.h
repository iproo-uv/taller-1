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
 
/*
Ficha CRC:
clase : Tablero 
 
responsabilidad:es la funcion encargada de dotar
a nuestros demas archivos de funciones que son esenciales para
el buen funcinamiento de nuestro juego  "\250DONDE ESTA LA BOLITA?".
Colaboracion: esta tiene una gran ligadura ó relacion  con "Arbitro"  que da al juego su forma((estilo)) y diseño la manera en la cua vamos a organizar nuestro juego

*/
 
 #endif /* SRC_TABLERO_H_ */
