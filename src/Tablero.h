//===============================================
//clase: tablero
//responsabilidad: el tablero se encarga de imprimir la cuadricula de juego
//colaboracion: esta clase no tiene colaboracion
//===============================================


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
