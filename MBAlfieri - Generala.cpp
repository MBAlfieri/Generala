#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <stdio.h>
using namespace std;

//----------------------------------------------------------------------------------------------------------------

//Variables del Main
int dados[5]; //Acá guardo los valores de los 5 dados.
int puntos = 0; //Acá van los puntos que se van ganando en cada mano.
int puntosfinales[4]; //Acá van los puntos finales de cada jugador.
int jugadores[4]; //Di un límite de jugadores, para que no se pueda poner un número exagerado.
string nombrejugador[4]; //Define los nombres de los jugadores del juego. El máximo es 4.
int numerojugadores = 0; //Permite definir el numero de jugadores que va a tener el juego. El máximo es 4.
int manos = 0; //Define la cantidad de manos que va a tener el juego. En este caso, cuando llega a 9, se termina el juego.

//----------------------------------------------------------------------------------------------------------------

//Cabeceras de las Funciones, las cuales se encuentran desarrolladas y explicadas debajo del Main.
int tirada(int tirada[5]);
int cambiodados(int deshecho[5]);
void muestrodados(int muestro[5]);
int numerouno(int sumatoria[5],int &puntostotales);
int numerodos(int sumatoria[5],int &puntostotales); 
int numerotres(int sumatoria[5],int &puntostotales);
int numerocuatro(int sumatoria[5],int &puntostotales);
int numerocinco(int sumatoria[5],int &puntostotales);
int numeroseis(int sumatoria[5],int &puntostotales);
int full(int sumatoria[5],int &puntostotales);
int escalera(int sumatoria[5],int &puntostotales);
int poker(int sumatoria[5],int &puntostotales);
int generala(int sumatoria[5],int &puntostotales);
void ordenarray(int a[]);
string nombres(int numerodejugadores, string nombres[4]);
void muestropuntaje(int muestro[4],int jugadores);
void ordenpuntajes(int a[]);

//----------------------------------------------------------------------------------------------------------------

//Bool para el funcionamiento del juego.
bool bnumerouno = false; //Estos Bool me permiten revisar si es que un juego ya se ha realizado o no. 
bool bnumerodos = false;
bool bnumerotres = false; 
bool bnumerocuatro = false; 
bool bnumerocinco = false; 
bool bnumeroseis = false; 
bool bfull = false; 
bool bescalera = false;
bool bpoker = false; 
bool bgenerala = false; 
bool juego = true; 

//----------------------------------------------------------------------------------------------------------------

//Main
int main(int argc, char *argv[]) {
	srand (time(NULL));
	
	system("Color 0C"); //Le cambié el color para que sea un poco más... vistoso :P
	
	//Introducción	
	cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;
	cout << "                    ¡¡Bienvenido a la Generala Virtual!!                        " << endl;
	cout << "                            ¿Que desea hacer?                                   " << endl << endl;
	cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
	
	while((juego == true)){ //Menú principal del juego.
		
		cout << endl;
		cout << "            ¡Presione la tecla -A- para iniciar una partida!                    " << endl;
		cout << "            ¡Presione la tecla -B- para leer las reglas!                        " << endl;
		cout << "            ¡Presione la tecla -C- para ver los créditos                        " << endl;
		cout << "            ¡Presione la tecla -D- para salir!                                  " << endl << endl;
		cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;
		
		switch(getch()){
		case 'a': case 'A':
			system ("CLS"); //Lo usé para "limpiar" la pantalla. Es estético, nada más.
			cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
			cout << "                       ¡Ha iniciado una partida!                                " << endl << endl;
			cout << "         ¡Por favor, ingrese con números la cantidad de jugadores!              " << endl << endl;
			cout << "                (Pueden jugar hasta -4- personas máximo)                        " << endl << endl;
			cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;
			
			cout << "-->";
			
			cin >> numerojugadores; //Define la cantidad de jugadores que se quieren.
			
			if(numerojugadores>4){ //En caso de que el jugador ingrese un número de participantes mayor a 4.
				system ("CLS");
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "                 ¡Opción incorrecta! Por favor, tenga más cuidado.              " << endl;
				cout << "                         Volvamos al menú principal...                          " << endl << endl; 
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;
				break;
			}
			
			system ("CLS");
			
			nombres(numerojugadores, nombrejugador); //Guardo los nombres de los jugadores.
			
			for(int i=0;i<numerojugadores;i++){
				
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "                          ¡" << nombrejugador[i] << "! ¡Es tu turno!            " << endl << endl;
				
				while(manos<9){ //Con ésto hago que el juego entero dure 9 manos por cada jugador.
					cout << endl;
					cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;
					cout << "                      ¡Procederé a tirar los dados!                             " << endl;
					cout << "                                   ...                                          " << endl;
					cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
					
					cout << "   Entonces, tus Dados son: " << endl << endl;
					tirada(dados);
					for(int i=0;i<3;i++) //Con ésto hago que el jugador lanze/cambie los dados solo 3 veces por ronda.	
					{
						cambiodados(dados);
						system ("CLS");
						
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   Entonces, tus Dados son: " << endl << endl;
						
						muestrodados(dados); 
					}
					
					ordenarray(dados);
					cout << endl;
					cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
					cout << "                      ¡Es hora de elegir tu juego!                              " << endl << endl;
					
					//Usé todos éstos if para simular el efecto presente en el .exe que sirvió de ejemplo
					//Basicamente, la opcion será visible siempre y cuando no se la haya usado anteriormente.
					if(bnumerouno == false){
						cout <<"   Presiona la tecla -1- para el Uno!" << endl;}
					if(bnumerodos == false){
						cout <<"   Presiona la tecla -2- para el Dos!" << endl;}
					if(bnumerotres== false){
						cout <<"   Presiona la tecla -3- para el Tres!" << endl;}
					if(bnumerocuatro == false){
						cout <<"   Presiona la tecla -4- para el Cuatro!" << endl;}
					if(bnumerocinco == false){
						cout <<"   Presiona la tecla -5- para el Cinco!" << endl;}
					if(bnumeroseis == false){
						cout <<"   Presiona la tecla -6- para el Seis!" << endl;}
					if(bfull == false){
						cout <<"   Presiona la tecla -F- para el Full!" << endl;}
					if(bescalera == false){
						cout <<"   Presiona la tecla -E- para la Escalera!" << endl;}
					if(bpoker == false){
						cout <<"   Presiona la tecla -P- para el Poker!" << endl;}
					if(bgenerala == false){
						cout <<"   Presiona la tecla -G- para la Generala!" << endl;}
					
					switch(getch()){
					case '1': //El Uno
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Uno!!" << endl << endl ;
						
						numerouno(dados, puntos);
						
						if(puntos>1){
							cout << "   ¡¡¡Has ganado " << puntos <<" puntos!!! "<< endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						
						bnumerouno = true; //Como ya se ha utilizado esta jugada, se vuelve true
						break;
						
					case '2': //El Dos
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Dos!!" << endl << endl ;
						
						numerodos(dados, puntos);
						
						if(puntos>1){
							cout << "   ¡¡¡Has ganado " << puntos <<" puntos!!!" << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						
						bnumerodos = true; //Como ya se ha utilizado esta jugada, se vuelve true
						break;
						
					case '3': //El tres
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Tres!!" << endl << endl ;
						
						numerotres(dados, puntos);
						
						if(puntos>1){
							cout << "   ¡¡¡Has ganado " << puntos <<" puntos!!!" << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						
						bnumerotres = true;
						
						break;
						
					case '4': //El cuatro
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Cuatro!!" << endl << endl ;
						numerocuatro(dados, puntos);
						
						if(puntos>1){
							cout << "   ¡¡¡Has ganado " << puntos <<" puntos!!!" << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						bnumerocuatro = true;
						break;
						
					case '5': //El Cinco
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Cinco!!" << endl << endl ;
						
						numerocinco(dados, puntos);
						
						if(puntos>1){
							cout << "   ¡¡¡Has ganado " << puntos <<" puntos!!!" << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						bnumerocinco = true;
						break;
						
					case '6': //El Seis.
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Seis!!" << endl << endl ;
						numeroseis(dados, puntos);
						
						if(puntos>1){
							cout << "   ¡¡¡Has ganado " << puntos <<" puntos!!!" << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						
						bnumeroseis = true;
						break;
						
					case 'f': case 'F': //Full
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Full!!" << endl << endl ;
						full(dados, puntos);
						
						if(puntos>1){
							cout << "   ¡¡¡Has ganado " << puntos <<" puntos!!!" << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						
						bfull = true;
						break;
						
					case 'e': case 'E': //Escalera
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado la Escalera!!" << endl << endl ;
						
						escalera(dados, puntos);
						
						if(puntos>1){
							cout << "   ¡¡¡Has ganado " << puntos <<" puntos!!!" << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						
						bescalera = true;
						break;
						
					case 'p': case 'P': //Poker
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Poker!!" << endl << endl ;
						
						poker(dados, puntos);
						
						if(puntos>1){
							cout << "   ¡¡¡Has ganado " << puntos <<" puntos!!!" << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						
						bpoker = true;
						break;
						
					case 'g': case 'G': //Generala
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado la Generala!!" << endl << endl ;
						generala(dados, puntos);
						
						if(puntos>1){
							cout << "   ¡¡¡Has ganado " << puntos <<" puntos!!!" << endl;
							cout << "   ¡¡¡¡¡¡¡¡¡Felicitaciones!!!!!!!!!!           " << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						bgenerala = true;
						break;
						
					}
					manos++; // Cuenta cada mano que se realiza. Cuando éste llega a 9, se termina la mano del jugador.
					puntosfinales[i] += puntos; // Deposito los puntos ganados en la ubicación correspondiente al jugador que éste jugando.
					puntos = 0; // Como ya deposité los puntos en el array, los inicializo así no los acarreo en la proxima mano.
					cout << endl;
					cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
					cout << "                          Fin de la ronda número "<< manos << endl;
					cout << "                    ¡Tus puntos totales hasta ahora son: " << puntosfinales[i] << "!" << endl << endl;
				}
				//En caso de que arranque otro jugador o se quiera iniciar otra partida, inicializo todos los valores así se pueden usar de nuevo.
				//No lo transformé en una función, ya que quedaba una cabecera muy extensiva.
				manos = 0;
				bnumerouno = false;
				bnumerodos = false; 
				bnumerotres = false; 
				bnumerocuatro = false;
				bnumerocinco = false;
				bnumeroseis = false; 
				bfull = false; 
				bescalera = false; 
				bpoker = false; 
				bgenerala = false;
			}
			
			if(numerojugadores==1){ //Final del juego, si es un sólo jugador.
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "                       ¡¡¡¡Se ha terminado el juego!!!!                         " << endl;
				cout << "                   ¡" << nombrejugador[0] <<", tu puntaje final es : " << puntosfinales[0] <<" puntos!" << endl;
				cout << "                               ¡¡Muy Bien!!                                      " << endl;
				cout << "                       ¿Te ha resultado divertido?                              " << endl;
				cout << "               ¡Puedes volver a jugar cuantas veces quieras!                    " << endl;
				cout << "               ¿Que tal si la próxima invitas a unos amigos?                    " << endl; 
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "                        Volvamos al menú principal...                           " << endl << endl; 
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				
			}
			
			else{ //Final del juego, si son 2 o más jugadores.
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "                       ¡¡¡¡Se ha terminado el juego!!!!                         " << endl;
				cout << "                   ¿Están listos para ver los puntajes finales?                 " << endl;
				cout << "                           ¡Buena suerte a todos!                               " << endl;
				cout << "                                   ...                                          " << endl << endl;
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				
				
				
				for(int i=0;i<numerojugadores;i++){ //Muestro todos los nombres y puntajes guardados
				cout <<"      ¡El jugador " << nombrejugador[i] << " ha obtenido: " << puntosfinales[i] <<" puntos! " << endl;
				}
				
				cout << endl;
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~ " << endl;
				cout << "                   El orden de los ganadores es...                               " << endl;
				
				
				ordenpuntajes(puntosfinales); //Ordeno los puntajes, de mayor a menor.
				cout << endl;
				muestropuntaje(puntosfinales, numerojugadores); //Muesto los puntajes.
				cout << endl;
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "                            ¡¡¡Felicidades!!!                                   " << endl;
				cout << "                            ¿Se han divertido?                                  " << endl;
				cout << "               ¡Pueden volver a jugar cuantas veces quieran!                    " << endl;
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "                        Volvamos al menú principal...                           " << endl << endl; 
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				break;
			}	
			break;
			
		case 'b': case 'B':
			system ("CLS");
			cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
			cout << "                                  Reglas                                        " << endl << endl;
			cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
			cout << " ¡Muchas gracias por jugar a la Generala Virtual!                               " << endl;
			cout << " Primero, deberá ingresar cuántas personas van a jugar. Luego, escriba el nombre" << endl;
			cout << " de el/los jugador/es. (El límite son 4 jugadores)                              " << endl;
			cout << " La Generala se juega con 5 dados. Cada jugador puede lanzarlos hasta 3 veces   " << endl; 
			cout << " por mano, pudiendo guardar o dejar los dados que se deseen.                    " << endl;	
			cout << " El juego dura 9 rondas en total por jugador.                                   " << endl;
			cout << " En el transcurso, se deben formar los siguientes juegos:                       " << endl;
			cout << " --> Número 1: se suman todos dados con 1. El puntaje es la sumatoria.          " << endl;
			cout << " --> Número 2, 3, 4, 5, 6: Idem al juego 1.                                     " << endl;
			cout << " --> Full: 3 Dados iguales y 2 dados iguales.                                   " << endl;
			cout << " --> Escalera: 1, 2, 3, 4, 5 o bien 2, 3, 4, 5, 6.                              " << endl;			
			cout << " --> Poker: 4 Dados iguales.                                                    " << endl;
			cout << " --> Generala: Todos los dados iguales:                                         " << endl;
			cout << " A medida que se van realizando los juegos, éstos no se pueden repetir.         " << endl;
			cout << " Si no se cumple con ningún juego, se debe elegir un juego cualquiera,  y en ese" << endl;
			cout << " se le asignan cero puntos.                                                     " << endl;
			cout << " El ganador será aquel que poseea la mayor cantidad de puntos, en caso de ser   " << endl;
			cout << " más de un jugador.                                                             " << endl;
			cout << "              ¡¡Anímese a jugar!! ¡¡Es más fácil de lo que parece!!             " << endl;
			cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
			cout << "                        Volvamos al menú principal...                           " << endl << endl; 
			cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
			break;
			
		case 'c': case 'C':
			system ("CLS");
			cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
			cout << "                                 Créditos                                       " << endl << endl;
			cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
			cout << "--> Alumna: Micaela B. Alfieri                                                  " << endl;
			cout << "--> Carrera: TEC en Diseño y Programación de Videojuegos.                       " << endl;
			cout << "--> Materia: Introducción a la Programación.                                    " << endl;
			cout << "--> Institución: Universidad Nacional del Litoral.                              " << endl;
			cout << "--> Año: 2019                                                                   " << endl;
			cout << "--> Agradecimientos especiales: a mis ratas Marta y Baby, las fans número uno   " << endl;
			cout << "    del Queso Mendicrim (sponsor no oficial).                                   " << endl;
			cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
			cout << "                        Volvamos al menú principal...                           " << endl << endl; 
			cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
			break;
			
		case 'd': case 'D':
			system ("CLS");
			cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
			cout << "                                 ¿Quieres salir?                                " << endl;
			cout << "             ¡¡¡Muchas gracias por haber jugado a la Generala Virtual!!!        " << endl;
			cout << "                            ¡¡¡Nos vemos la próxima!!!                          " << endl;
			cout << "                                    (^_°)/                                      " << endl << endl;
			cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
			return 0;
		}
	}
	return 0;
}
//----------------------------------------------------------------------------------------------------------------
//Funciones:

//Funcion que guarda los nombres de los jugadores y los muestra.
string nombres(int numerodejugadores, string nombres[4]){
	for(int i=0;i<numerodejugadores;i++){
		cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
		cout << "                 ¡Ingrese el nombre del jugador "<< i+1 <<"!:                " <<endl << endl;
		cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
		cout << "-->";
		cin >> nombres[i];
		system ("CLS");
	}
	system ("CLS");
	cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;
	cout << "                            ¡¡Mucho gusto!!                                     " << endl;
	cout << "                              Entonces...                                       " << endl << endl;
	cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;
	
	{
		for(int i = 0; i<numerodejugadores;i++){
			cout<<"                       El jugador "<<i+1<<" se llama: "<<nombres[i]<<endl;} 
	}
	
	cout << endl;
	cout << "                          ¡Empecemos el juego!                                  " << endl;
	cout << "                            ¡¡Buena Suerte!!                                    " << endl;
	cout << "                  ¡Presiona cualquier tecla para comenzar!                      " << endl << endl;
	cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;
	system ("pause"); //Lo usé para que el programa "espere" antes de "limpiar" la pantalla.
	system ("CLS");
	
	return nombres[4];
	
}

//Ésta funcion ve a generar una tirada de los 5 dados para la primera ronda, exclusivamente.
int tirada(int tirada[5]){
	for(int i = 0; i<5;i++){
		tirada[i] = rand()%6+1;
		
		cout<<"   Valor del Dado "<<i+1<<": "<<tirada[i]<<endl;}
	return tirada[5];	
}

//Ésta funcion me deja deshacerme de los dados que no quiero.
int cambiodados(int deshecho[5]){
	
	for(int i = 0; i<5;i++){
		cout << endl;
		cout<<"   ¿Quieres quedarte con el Dado "<<i+1<<"? (Éste vale "<<deshecho[i]<< "): s/n" << endl;
		
		switch(getch()){
		case 's': case 'S':
			cout << endl;
			cout << "-->¡Te has quedado con el dado!" << endl;
			break;
			
		case 'n': case 'N':
			deshecho[i] = rand()%6+1;
			cout << endl;
			cout<<"-->¡Te has deshecho del dado!" << endl;
			break;
		}
	}	
	return deshecho[5];
}

//Ésta funcion me deja ver el valor de los Dados.
void muestrodados(int muestro[5]){
	for(int i = 0; i<5;i++){
		cout<<"   Valor del Dado "<<i+1<<": "<<muestro[i]<<endl;}
}

//Ésta es la funcion de la jugada del Uno
int numerouno(int sumatoria[5],int &puntostotales){
	for(int i=0;i<5;i++){
		if(sumatoria[i]==1){
			puntostotales++;
		}
	}
	return puntostotales;
}

//Ésta es la funcion de la jugada del Dos
int numerodos(int sumatoria[5],int &puntostotales){
	for(int i=0;i<5;i++){
		if(sumatoria[i]==2){
			puntostotales += 2;
		}
	}
	return puntostotales;
}

//Ésta es la funcion de la jugada del Tres
int numerotres(int sumatoria[5],int &puntostotales){
	for(int i=0;i<5;i++){
		if(sumatoria[i]==3){
			puntostotales += 3;
		}
	}
	return puntostotales;
}

//Ésta es la funcion de la jugada del Cuatro
int numerocuatro(int sumatoria[5],int &puntostotales){
	for(int i=0;i<5;i++){
		if(sumatoria[i]==4){
			puntostotales += 4;
		}
	}
	return puntostotales;
}

//Ésta es la funcion de la jugada del Cinco
int numerocinco(int sumatoria[5],int &puntostotales){
	for(int i=0;i<5;i++){
		if(sumatoria[i]==5){
			puntostotales += 5;
		}
	}
	return puntostotales;
}

//Ésta es la funcion de la jugada del Seis
int numeroseis(int sumatoria[5],int &puntostotales){
	for(int i=0;i<5;i++){
		if(sumatoria[i]==6){
			puntostotales += 6;
		}
	}
	return puntostotales;
}

//Ésta es la funcion de la jugada del Full
int full(int sumatoria[5],int &puntostotales){
	
	if( ((sumatoria[0] == sumatoria[1]) && (sumatoria[2] == sumatoria[3]) && (sumatoria[3] == sumatoria[4])) || ((sumatoria[0] == sumatoria[1]) && (sumatoria[1] == sumatoria[2]) && (sumatoria[3] == sumatoria[4])))
	{
		puntostotales = 30;
	}
	else {
		puntostotales = 0;
	}
	
	return puntostotales;
}

//Ésta es la funcion de la jugada de la Escalera
int escalera(int sumatoria[5],int &puntostotales){
	if( ((sumatoria[0]== 1) && (sumatoria[1]== 2) && (sumatoria[2]== 3) && (sumatoria[3]== 4) && (sumatoria[4]== 5)) || ((sumatoria[0]== 2) && (sumatoria[1]== 3) && (sumatoria[2]== 4) && (sumatoria[3]== 5) && (sumatoria[4]== 6))){
		puntostotales += 40;
	}
	else {
		puntostotales = 0;
	}
	
	return puntostotales;
}

//Ésta es la funcion de la jugada del Poker.
int poker(int sumatoria[5],int &puntostotales){
	if( ((sumatoria[0] == sumatoria[1]) && (sumatoria[1] == sumatoria[2]) && (sumatoria[2] == sumatoria[3])) || ((sumatoria[1] == sumatoria[2]) && (sumatoria[2] == sumatoria[3]) && (sumatoria[3] == sumatoria[4]) ) )
	{
		puntostotales += 50;
	}
	else {
		puntostotales = 0;
	}
	
	return puntostotales;
}

//Ésta es la funcion de la jugada de la Generala.
int generala(int sumatoria[5],int &puntostotales){
	if( ((sumatoria[0] == sumatoria[1]) && (sumatoria[1] == sumatoria[2]) && (sumatoria[2] == sumatoria[3])&& (sumatoria[3] == sumatoria[4])) )
	{
		puntostotales += 60;
	}
	else {
		puntostotales = 0;
	}
	
	return puntostotales;
}

//Ésta es la funcion que se nos dio para ordenar arreglos. Lo he modificado apenas para que funcione con mi código.
void ordenarray(int a[]) {
	int i, j, min, temp;
	for (i = 0; i < 7 - 1; i++) {
		min = i;
		for (j = i + 1; j < 5; j++)
			if (a[j] < a[min])
				min = j;
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}

//Ordena los puntajes finales, de más grande a más chico.
void ordenpuntajes(int a[]) {
	int i, j, max, temp;
	for (i = 0; i < 5 - 1; i++) {
		max = i;
		for (j = i + 1; j < 4; j++)
			if (a[j] > a[max])
				max = j;
		temp = a[i];
		a[i] = a[max];
		a[max] = temp;
	}
}

//Muestra los puntajes finales.
void muestropuntaje(int muestro[4],int jugadores){
	for(int i=0; i<jugadores;i++){
		cout<<"      Puesto número "<< i+1  <<": " << muestro[i] <<" puntos." << endl;}
}
