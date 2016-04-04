//Debe escribir una cabecera de archivo con la plantilla CRC: Clase, Responsabilidad y Colaboracion
/*
Clase: Tablero.h
Responsabilidad: crea un objeto tipo tablero para guardar los datos, recibe las casillas, actualiza las casillas,
                 recibe las dimensiones del tablero.
Colaboración:
  */

#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_

class Tablero {
private:
    char** casillas; //casillas es un puntero q apunta a otro puntero
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
