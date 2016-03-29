//Clase: Tablero.
//Responsabilidad: Se encarga de crear el tablero del juego, sus dimensiones y numero de casillas.
//Colaboración: La clase tablero no utiliza otra clase.

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
