//Debe escribir una cabecera de archivo con la plantilla CRC: Clase, Responsabilidad y Colaboracion

#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_

class Tablero {
private:
    char** casillas;
    int dim;
   	char** matriz;
public:
    Tablero(int tm);
    ~Tablero();
    void ImprimirTablero();
    char getCasilla(int x, int y);
    void setCasilla(int x, int y);
    int getDim();
    
};

#endif /* SRC_TABLERO_H_ */
