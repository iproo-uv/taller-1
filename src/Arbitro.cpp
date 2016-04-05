//===================================================================================================================
// Name                     : Arbitro.cpp
// Author                   : Jesus Alberto Ospina y Nelson galeano
// Version                  : 0.0.1
// Descripcion              : permite las entradas de usuario del jugador y organiza un juego por jugador...

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Arbitro.h"
using namespace std;

Arbitro::Arbitro() {
    juegoEnCurso = false;
    puntaje = 100.0;
    srand(time(NULL));
    filaBolita = 0;
    columnaBolita = 0;
}

Arbitro::~Arbitro() {
    // TODO Auto-generated destructor stub
    
}

void Arbitro::iniciarJuego() {
   
   int s, fila, columna; 
    cout << "**************** en donde esta la bolita ****************" <<endl;
    cout <<"ingrese un valor para las dimensiones del tablero **" <<endl;
    cin >> s;
    
	tablero = Tablero(s);
      
    imprimirTablero();
    cout << "ingrese una fila =" ;
    cin >> fila;
    cout << "ingrese una columna =";
    cin>>columna;
    
    if (validarIntento(fila, columna)== true){
    	
    	cout << "Felicidades Has encontrado la bolita"<<endl;
    	
	}else{
		cout << "estuviste a una distancia de " << calcularDistancia(fila,  columna)<<endl;
		
		cout <<"vuelve a intentarlo"<<endl;
	}
   

    
   
    //Debe implementar un metodo que se encargue de iniciar el juego y controlar su desarrollo
    //Este metodo debe recibir las entradas del usuario, imprimir el tablero y validar los intentos
}

void Arbitro::imprimirTablero() {
 
    int m , i, j, l;
    
     l=0;

	  

      m= tablero.getDimension();
      cout << endl;
      cout << "  ";
     
        
     for (int z=0; z<m; z++ ){
     	
     	cout <<" "<< z+1;
     	
	 }
	 cout <<endl;
     for (i=0; i<m;  i++){
        
		 cout << i+1 << "  ";   
		   	
     	for (j=0; j<m;  j++){
        
	      cout << tablero.getCasilla(i, j)<< " ";          
	    };

		cout <<endl;
	
	 }
    
       }
	

	
		    filaBolita= rand() % m;
			columnaBolita  =rand() % m;
			
	  
	      tablero.setCasilla(filaBolita, columnaBolita, 'O');
	     cout << "  ";
	        for (int x=0; x<m; x++){
	        	cout <<" "<< x+1;
			}
			cout <<endl;
		  
		  for (filaBolita =0; filaBolita<m; filaBolita++){
		         cout << filaBolita+1 << "  ";   
		      
	         for (columnaBolita=0; columnaBolita<m; columnaBolita++){
			      
	        cout << tablero.getCasilla(filaBolita, columnaBolita)<< " ";
	   
	   }
	  cout <<endl;
	}
	
}
	

	



	        
       	
	
	
	//Debe implementar un metodo que imprima el tablero en pantalla
    //Recuerde que el usuario no puede conocer la posicion de la bolita



int Arbitro::calcularDistancia(int fila, int columna){
    
	 int distancia;
	 
	 	 distancia = sqrt(pow (filaBolita-fila, 2)+ pow (columnaBolita-columna,2));
		 
		 return distancia;
	 
	 
	
	//Debe implmentar un metodo que calcula la distancia entre la posicion (fila, columna)
    //Y la posicion real de la bolita
}


bool Arbitro::validarIntento(int fila, int columna){
    
    double puntaje;
        if (fila == filaBolita && columna == columnaBolita){
        	
        	return true;
        	
		}else 
		return false;
		
		 
		
		
		
		
		
		
  
    //Este metodo debe validar el intento del usuario, debe informarle si fue correcto o no
    //Retorna verdadero si el intento es correcto y falso si no lo es
    //En caso de no serlo debe realizar los cambios correspondientes a las variables miembro
    //Y debe informar por pantalla cual fue la distancia del fallo y el puntaje restante
}

