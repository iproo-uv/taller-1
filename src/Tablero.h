//=================================================================================
// Clase: Tablero.
// Responsabilidad: La clase Tablero se encarga de mostrar la dimensi�n del mismo.
// Colaboracion: La clase Tablero no interact�a con ninguna de las otras clases.
//=================================================================================

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
