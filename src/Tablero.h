//Debe escribir una cabecera de archivo con la plantilla CRC: Clase, Responsabilidad y Colaboracion

#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_

//FICHA CRC:

//clase : Tablero

//responsabilidad : tiene como funcion principal dotar
//a los demas archivos de funciones que serán de mucha
// ayuda para desarrollar el juego "encuentra la bolita".
 
//colaboracion : tiene una relacion significativa 
//con la clase "Arbitro" la cual tiene varias funciones 
//que le dan al juego un orden y un estilo.

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
