/*******************************************/
/* 		    minimaxAlum.h                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include "tictactoe.h"

valorMax(tNodo *t); 
valorMin(tNodo *t);
tNodo *jugadaAdversario(tNodo *t);
tNodo *minimax(tNodo *Nodo, int jugador);
