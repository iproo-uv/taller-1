//Debe crear una cabecera de archivo tal como se indico en clase
//Contrala el proceso durante el juego cuando comienzo lo que transcurre durante el juego y cuando termina


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
    //Debe implementar un metodo que se encargue de iniciar el juego y controlar su desarrollo
    //Este metodo debe recibir las entradas del usuario, imprimir el tablero y validar los intentos
    int tamano=0;
    cout<<"ingrese el tamano del tablero: ";
    cin>>tamano;

    
    tablero = Tablero(tamano);
    
    juegoEnCurso = true;
    filaBolita = rand()%tamano;
    columnaBolita= rand()%tamano;
    
    
    tablero.setCasilla(columnaBolita,filaBolita,'a'); 
    // el char 'X' significa que nohay intento fallido y que no esta la bolita
    //el char 'a' significa que esta la bolita
    //el char 'f' significa intento fallido
    
    
    imprimirTablero();
    int x=0;
    int y=0;
    //comienzo del juego
    while(juegoEnCurso){
        cout<<endl;
        cout<<"igresar numero de columna: ";
        cin>>x;
        cout<<endl;
        cout<<"ingresar numero de filas: ";
        cin>>y;
        cout<<endl;
        if(x<tamano & y<tamano)//este if parte para validar si el intento esta dentro del rango del tablero
        {
        if(validarIntento(x,y)==true){//este if me permite que juego determine si el usuario a ganado
                                cout<<"felicitaciones usted a ganado "<<endl;
                                cout<<"su puntacion fue de: "<<puntaje<<endl;
                                juegoEnCurso = 0;
                                }
       else{
            if(tablero.getCasilla(x,y)=='X'){//este if interpreta si el valor ingresado ya a sido fallido
            puntaje = floor (puntaje - (puntaje/(tamano*tamano)));
            cout<<"intento fallido"<<endl;
            cout<<"su puntacion es: "<<puntaje<<endl;
            cout<<"la bolita esta a "<<calcularDistancia(x,y)<<endl;
            
            tablero.setCasilla(x,y,'f');
            imprimirTablero();
            }
            else{
                 cout<<"columna y fila ya ingresados vuelva a intentarlo"<<endl;
                 }
            }                           
        }
        
        else{
             cout<<endl;
             cout<<"numero de columna o fila invalido"<<endl;
             }
    }
    
}

void Arbitro::imprimirLiniaSuperior(){
//diseña un marco al tablero en la linia superior
cout<<"  ";
for(int i=0;i < tablero.getDimension();i++){
        cout<<i<<" ";
        }
cout<<endl;
cout<<" "<<char(201);
 
for(int i=1;i <=tablero.getDimension();i++){
        cout<<char(205);
        if(i!=tablero.getDimension()){
                 cout<<char(203);
                 } 
        else{
             cout<<char(187);
             }
        }
cout<<endl;

     }

void Arbitro::imprimirLiniaInferior(){
//diesña un marco en la inferior
cout << " " << char(200);
for(int i=1;i <= tablero.getDimension();i++) {
    cout << char(205);
    if(i!= tablero.getDimension()){
           cout << char(202);
           }
           else{
                cout<<char(188);
                }
      }
}

void Arbitro::imprimirLiniaDivision(){
//diseña una linia donde separa la linia de datos con las demas
     cout << " " << char(204);
          for(int i=1;i <=tablero.getDimension();i++) {
                  cout << char(205);
                  if(i != tablero.getDimension()){
                       cout << char(206);
                       }
                        else{
                             cout<<char(185);
                             }
          }
cout<<endl;
}
    
void Arbitro::imprimirLiniaDeDatos(){
//rellena el tablero separadas por un diseño 
      for(int i=0;i < tablero.getDimension();i++){
            cout<<i<<char(186);
            for(int j=0;j < tablero.getDimension();j++){
                    if(tablero.getCasilla(i,j)=='a'){
                            cout<<"X"<<char(186);                        
                    }else{
                          cout<<tablero.getCasilla(i,j)<<char(186);
                          }
                    }
            if(i != (tablero.getDimension()- 1)){
                  cout<<endl;
                  imprimirLiniaDivision();
                  }
            else{
                 cout<<endl;
                 }
            }   
     }

void Arbitro::imprimirTablero() {
    //Debe implementar un metodo que imprima el tablero en pantalla
    //Recuerde que el usuario no puede conocer la posicion de la bolita
    cout<<endl;
    imprimirLiniaSuperior();          
    imprimirLiniaDeDatos();
    imprimirLiniaInferior();
    cout<<endl;
}

double Arbitro::calcularDistancia(int columna, int fila){
    //Debe implmentar un metodo que calcula la distancia entre la posicion (fila, columna)
    //Y la posicion real de la bolita
    int a=(columnaBolita - columna);
    int b=(filaBolita - fila);
    return(floor (sqrt (pow(a,2) + pow(b,2))));

}

bool Arbitro::validarIntento(int columna, int fila){
    //Este metodo debe validar el intento del usuario, debe informarle si fue correcto o no
    //Retorna verdadero si el intento es correcto y falso si no lo es
    //En caso de no serlo debe realizar los cambios correspondientes a las variables miembro
    //Y debe informar por pantalla cual fue la distancia del fallo y el puntaje restante
       if(tablero.getCasilla(columna,fila)=='a'){
       return true;
       }
       else{
       return false;
       }
}

