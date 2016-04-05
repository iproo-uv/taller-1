//===============================================
//clase: Arbitro
//responsabilidad: el Arbitro se encarga de iniciar el juego, de dar explicacion al procedimiento del juego
//colaboracion: esta clase no tiene colaboracion
//===============================================
//Debe crear una cabecera de archivo tal como se indico en clase

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Arbitro.h"
using namespace std;

Arbitro::Arbitro() {
    juegoEnCurso = false;
    puntaje = 100.0;
    srand (time(NULL));
    filaBolita =0;
    columnaBolita = 0; 
}


void Arbitro::iniciarJuego(){
	int n:
	cout << "ingrese la dimension del tablero" << endl;
	cin >> n;
	tablero  = Tablero (n);
	filaBolita = rand() % n;
	columnaBolita = rand() % n;
	tablero: setCasilla(filaBolita, columnaBolita, '0');
	juegoEnCurso = true;
	while(juegoEnCurso) {
			imprimirTablero();
	        int fila = 1;
	        int columna = 1;
	           cout << "ingrese la fila de su tablero:" << endl;
	        cin >> fila;
	           cout <<"ingrese la columna de su intento:" <<endl;
	        cin >> columna;
	        juegoEnCurso = validarIntento (fila. columna);
	}
}

void Arbitro::imprimirTablero() {
	cout << "imprimir tablero";
	for(int k=0; k<tablero.getDimension(); k++){
	 		cout<<k<<" ";
	 	}
	 	cout<<endl<<endl;
	 	for(int i=0; i<tablero.getDimension(); i++){
	 		cout<<i<<" ";
	 		for(int j=0; j<tablero.getDimension(); j++){
	 		
	 		if (tablero.getCasilla(i,j)=='B'){
	 			cout<< "X ";
	 			}
	 			 
	 		     else {
	 				   cout<<tablero.getCasilla(i,j)<<" ";
	 			      }
	 		}
	 		cout<<endl<<endl;
	 	}	

}

int Arbitro::calcularDistancia(int fila, int columna){
	float distancia = sqrt ((pow((filaBolita-fila),2)+pow(columnaBolita-columna,2)));
	    cout<<"Estas a" <<distancia<< "de encontrar la bolita Sigue intentando" <<endl;
}

bool Arbitro::validarIntento(int fila, int columna){
	if(fila==filaBolita&&columna==columnaBolita){
		cout<<"¡¡En Hora Buena Has Ganado!!" <<endl;
		cout<<"tu puntaje es" <<puntaje<<endl;
		juegoEnCurso=false;
		return true;
	}
	  else
	        {
		      puntaje+== 5;
		      tablero.setCasillas(fila,columna);
		      return false;  
	        }  
	}
  
}

