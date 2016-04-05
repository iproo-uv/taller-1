//===================================================================================================================
// Name                     : Tablero.h
// Author                   : Jesus Alberto Ospina y Nelson galeano
// Version                  : 0.0.1
// Descripcion              : Esta clase es donde se guardan y se utilizan todas las variables miembro  los metodos y atributos
//                            de la clase Tablero y lo que permite es Dibujar un tablero 

#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_

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
