#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Arbitro.h"
#include <ctype.h> //libreria para usar la validacion de entrada osea para validar si lo que ingreso son numeros o letras 
#include <stdlib.h> //libreria para el uso de rand()
#include <string.h> //libreria para que la entrada de nuestro programa sea solo un entero
#include <stdio.h> // libreria basica para entrada y salida 

using namespace std;

  
Arbitro::Arbitro()
{
	system ("color 3");
	 juegoEnCurso = false;
     puntaje = 100.0;//Este sera el punta principal, de ser correcta la respusta la primeras vez.
     srand(time(NULL));//Aquí crenos los numeros aleatorios, partiendo de una semilla Dinamica(srand) que en este caso sera la hora del sistema en segundos(NULL).
     filaBolita = 0;
     columnaBolita = 0;
 } 

 
Arbitro::~Arbitro() 
{
     
}//Este es el auto destructor, queda sin funciones ni variables 
  
void Arbitro::iniciarJuego() 
{
//metodo que se encargue de iniciar el juego y controlar su desarrollo
cout << "           HOLA ESTE ES EL JUEGO  \250DONDE ESTA LA BOLITA?"<< endl<<endl;//impimira al comienzo del juego el texto en azul "HOLA ESTE ES EL JUEGO ¿DONDE ESTA LA BOLITA?"
cout << "\250Cuanto te costara encontrarla?"<< endl;	                               
cout << "empecemos.   "<< endl<<endl;
int dimension;
unsigned n; 
char letra[BUFSIZ]; 
bool noNumero;
//Aqui estamos abligando a que la entrada sea solo un entero 
while (!juegoEnCurso) 
{
	
cout<<" #####                          "<< endl;
cout<<"#     #   ##   #    # ######    "<< endl;
cout<<"#        #  #  ##  ## #         "<< endl;
cout<<"#  #### #    # # ## # #####     "<< endl;
cout<<"#     # ###### #    # #         "<< endl;
cout<<"#     # #    # #    # #         "<< endl;
cout<<" #####  #    # #    # ######    "<< endl;
cout<< "                               "<< endl;

cout<< "            Suerte!            "<< endl; 
cout<< " _____________________________ "<< endl;
cout<< "|                             |"<< endl;
cout<< "|          .nd888bn.          |"<< endl;
cout<< "|        .d888888888b.        |"<< endl;
cout<< "|        8888888888888        |"<< endl;
cout<< "|        8888888888888        |"<< endl;
cout<< "|        8888888888888        |"<< endl;
cout<< "|        `+888888888+'        |"<< endl;
cout<< "|          `'+888+'''         |"<< endl; 
cout<< "|_____________________________|"<< endl;
cout<< "                               "<< endl;



cout<< "Ingresa el tama\xA4o del tablero de juego: "<< endl;//imprimira el tamaño del cual queremos nuestro tablero de juego "dimencion"  
if (fgets (letra, sizeof letra, stdin) != NULL) //estamos  validando si mi entrada es un tipo de letra ó es un numero 
{
letra[strlen(letra)-1] = '\0'; 
noNumero = false; 
if (strlen(letra) == 0) noNumero = true;
for (n=0; n<strlen(letra); n++) if (!isdigit(letra[n])) noNumero = true;
dimension = atoi(letra);//atoi nos permite modificar el char ingresado y convertirlo a un int 
if (10 < dimension)//el tablero debe ser maximo de 10 x 10
{
noNumero = true;
}
if (dimension < 2)//el tamaño del tablero como minimo debe ser de 2 x 2
{
noNumero = true;
}
if (!noNumero) 
{
juegoEnCurso = true; 
}
else 
{
cout << "\n\nEl numero debe ser mayor de 1 y menor que 10." <<endl <<endl;//imprimira el mensaje en azul para avisar al jugador que debe ingresar un numero mayor2 y menor10
}	
}	
}
system("cls");
cout << "Este es le tama\xA4o de tu tablero de juego " << dimension << " X " << dimension << "..." <<endl <<endl;//imprime el tamaña de nuestro tablero
Tablero tablerito (dimension);
tablero = tablerito;
filaBolita = rand ()% (tablero.getDimension());
columnaBolita = rand ()% (tablero.getDimension());
tablero.getCasilla(filaBolita,columnaBolita);
cout<<endl;
imprimirTablero();
cout<<endl;
int ingresoX,ingresoY;
while(puntaje > 0)
{
validarIntento(ingresoX,ingresoY);//valida el intento del jugador para descubrir donde esta la bolita, validando fila y columna 
}
//recibe las entradas del usuario, imprimir el tablero y validar los intentos
}
	
  
void Arbitro::imprimirTablero() 
{
cout <<" ";
for (int y=0;y<tablero.getDimension();y++)
{
cout <<" "<<" "<< y+1<<"";
}
cout<<" " <<endl;
for (int l=0; l< tablero.getDimension(); l++)
{
cout <<endl<< l + 1<<"  ";
for (int a=0; a<tablero.getDimension();a++)
{
cout << tablero.getCasilla(l,a)<< "  ";
}
cout<<endl;
}//imprime el tablero en pantalla
}
  
int Arbitro::calcularDistancia(int fila, int columna)
{
//calcula la distancia entre la posicion ingresada por el usuario ((fila y columna)) Y la posicion real de la bolita
int distancia;
distancia = abs(filaBolita - fila)+ abs(columnaBolita - columna);//ABS((abs)) es valor absoluto de la posicion 
}
  
bool Arbitro::validarIntento(int fila, int columna)
{
//valida el intento del usuario e imprime un mensaje avisando si fue o no correcto su intento 
bool validar = false,noNumero = false;
int n;
char letra [BUFSIZ];
juegoEnCurso = true;
while (juegoEnCurso)
{
validar=false;// de no acertar la posicion, a continuacion le pedira nuevamente la fila en la que cree esta la posicion correcta 
while (!validar) 
{
cout<< "\250En cual fila esta la bolita? : "<< endl; 
if (fgets (letra, sizeof letra, stdin) != NULL) //estamos  validando si mi entrada es un tipo de letra ó es un numero 
{	
letra[strlen(letra)-1] = '\0'; 
noNumero = false; 
if (strlen(letra) == 0) noNumero = true;
for (n=0; n<strlen(letra); n++) if (!isdigit(letra[n])) noNumero = true;
fila= atoi(letra);//atoi nos permite modificar el char ingresado y convertirlo a un int
if (fila > tablero.getDimension())
{
noNumero = true;
}
if (fila == 0)
{
noNumero = true;
}	
if (!noNumero) 
{
validar = true; 
}
else 
cout << "El numero es mayor al tama\xA4o de tu tablero ["<< tablero.getDimension()<< "] corrige..." <<endl <<endl;//imprimira el mensaje en azul para avisar al jugador que debe ingresar un numero mayor2 y menor10
}		
}
validar = false;
while (!validar) 
{
cout<< "En que columna esta la bolita?: "<< endl;//pregunta al ususario en que columna cree que esta la bolita 
if (fgets (letra, sizeof letra, stdin) != NULL) //estamos  validando si mi entrada es un tipo de letra ó es un numero 
{
letra[strlen(letra)-1] = '\0'; 
noNumero = false; 
if (strlen(letra) == 0) noNumero = true;
for (n=0; n<strlen(letra); n++) if (!isdigit(letra[n])) noNumero = true;
columna = atoi(letra);//atoi nos permite modificar el char ingresado y convertirlo a un int
if (columna > tablero.getDimension())
{
noNumero = true;
}
if (columna == 0)
{
noNumero = true;
}
if (!noNumero) 
{
validar = true; 
}
else 
cout << "El numero es mayor al tama\xA4o de tu tablero ["<< tablero.getDimension()<< "] corrige..." <<endl <<endl;//imprimira el mensaje en azul para avisar al jugador que debe ingresar un numero mayor2 y menor10
}
}
if (tablero.getCasilla(fila-1 ,columna-1) == 'X')
{
juegoEnCurso = false;
break;
}
else 
{
system ("cls");//se encarga de limpiar la pantalla 
cout<< " La casilla ya jugo "<<endl<<endl;//imprime "La casilla ya jugo" en caso de que valide que el usuario esta ingresando una posicion que ya jugo anteriormente
imprimirTablero();
juegoEnCurso = true;
}
}
if (fila-1 == filaBolita && columna-1 == columnaBolita)//cuando la posiscion ingresada por el usuario es correcta 
{
cout<< "\n\         HAS GANADO TU PUNTAJE FINAL ES: "<< puntaje<<"PUNTOS"<<endl;//mensaje de que el ususario ha ganado el juego, en este caso se llama la funcion<<puntaje la encargada
cout<<"..........................................................."<<endl;     //de calcular la puntuacion de jugador((usuario)) y la imprime

cout<<"..........................................................."<<endl;

cout<<"..........................................................."<<endl;

cout<<".........................--------.........................."<<endl;

cout<<".................:++:::++++*+::--...--::++:................"<<endl;

cout<<"...............-:*-.*+-++++++:--....--:+.-*:-.............."<<endl;

cout<<"...............::--*=:-+++++::--....--+**--::.............."<<endl;

cout<<"...............:::...--+++++::---...---...:::.............."<<endl;

cout<<"...............-::...--++++::----...---...::-.............."<<endl;

cout<<"................:::..--++++::-----..---..:::..............."<<endl;

cout<<".................+:-.::+++++::----..-::.-:+................"<<endl;

cout<<"..................++--:**+++:::---.-::--++................."<<endl;

cout<<"...................++::+****+::---.-:+-++.................."<<endl;

cout<<"....................:=++=***++:::--:++*:..................."<<endl;

cout<<".....................-=**=*=*++::--+**-...................."<<endl;

cout<<".......................+*====*+++:+*:......................"<<endl;

cout<<".........................+===***+*+........................"<<endl;

cout<<"...........................===**+-........................."<<endl;

cout<<"...........................-*+++-.........................."<<endl;

cout<<"...........................:*++::.........................."<<endl;

cout<<"...........................-=*:--.........................."<<endl;

cout<<"..........................+==+:-::........................."<<endl;

cout<<"........................:==**+::--::......................."<<endl;

cout<<"......................+**++*+:::----++....................."<<endl;

cout<<"..................+####=====****++++****=:................."<<endl;

cout<<"..................+@@=-:*=***+++:-...:+*=:................."<<endl;

cout<<"..................+@@=-:*=***+++:-...:+*=:................."<<endl;

cout<<".................:@@###====******++++***=:................."<<endl;

cout<<".................:@@###::::********:::**:=:................"<<endl;

cout<<"..........................................................."<<endl;//imagen de un trafeo como señal de que el jugador gano
         
puntaje = 0;
} 
else {tablero.setCasilla(fila-1,columna-1,'O');
system("pause");
system("cls");
puntaje = floor(puntaje-(100/(tablero.getDimension()*tablero.getDimension())));
cout <<" Su intento es fallido puntaje actual: "<<puntaje <<"puntos"<< endl<<endl;//en caso de que el intento se fallido muestra la puntuacion actual del jugador 
cout <<" La bolita esta a: "<<calcularDistancia(fila-1,columna-1)<<"casillas"<<endl<<endl;//imprime la funcion calcularDistancia, y le indica al jugador a que distancia esta de la
imprimirTablero();                                                                       //posicion verdadera de la bolita 
cout<<endl;
}
}


