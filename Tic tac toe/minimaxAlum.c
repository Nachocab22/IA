/*******************************************/
/* 		    minimaxAlum.c                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tictactoe.h"

//Falta implementar min, max y utilidad -> funcion heuristica que da una "nota"

int valorMax(tNodo *t) {
      int valor_max, jugada, jugador=1;

      if(terminal(t))
            valor_max= utilidad(t);
      else{
            valor_max= -100000;
            for(jugada=0; jugada < 9; ++jugada)
                  if(esValida(t, jugada))
                        valor_max= max(valor_max, valorMin(aplicaJugada(t, jugador, jugada)));
      }
      return valor_max;
}

int valorMin(tNodo *t){
      int valor_min, jugada, jugador= -1;

      if(terminal(t))
            valor_min = utilidad(t);
      else {
            valor_min = 100000;
            for(jugada=0; jugada < 9; ++jugada)
                  if(esValida(t, jugada))
                        valor_min = min(valor_min, valorMax(aplicaJugada(t, jugador, jugada)));
      }
      return valor_min;
}

tNodo *minimax(tNodo *t, int jugador) {
      int max = -10000, max_actual;
      int mejorJugada = -1, jugada;
      tNodo *intento;
      tNodo *intento=malloc(sizeof(tNodo));
      printf("\n Mi turno: \n");
      for(jugada = 0; jugada < 9; ++jugada){
            if (esValida(t,jugada)) {
                  intento=aplicaJugada(t,jugador,jugada); //Intenta jugada
                  max_actual =valorMin(intento); // Calcula el valor minimax
                  if(max_actual > max) {
                  max = max_actual;
                  mejorJugada = jugada;
                  }
            }}//for
            t=aplicaJugada(t,1,mejorJugada);
            return t;
}

tNodo *jugadaAdversario(tNodo *t) {
     int jugada = 0;
     printf("\nJugada ([0..8])?: ");
     scanf("%d", &jugada);
     while (!esValida(t,jugada))
     {
        printf("\n Intenta otra posicion del tablero \n");
        printf("\n");
        printf("\nJugada ([0..8])?: ");
        scanf("%d", &jugada);
     }
     t=aplicaJugada(t,-1,jugada);
     return t;
}


