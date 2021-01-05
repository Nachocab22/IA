/*******************************************/
/* 		      PUZLE.C                     */
/*						                         */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "puzle.h"



tEstado *crearEstado(int puzle[N][N])
{
   tEstado *estado = (tEstado *) malloc(sizeof(tEstado));
   int i, j, ficha;

   for (i=0;i<N;i++)
      for (j=0;j<N;j++)
      {
         ficha=puzle[i][j];
         estado->celdas[i][j]=ficha;
         estado->fila[ficha]=i;
         estado->col[ficha]=j;
      }
   return estado;
}


tEstado *estadoInicial()
{
   return crearEstado(puzle_inicial);
}


tEstado *estadoObjetivo()
{
   return crearEstado(puzle_final);
}

int coste(unsigned op, tEstado *estado)
{
   return 1;
}

/* VISUALIZACI�N DE ESTADOS Y OPERADORES*/


void dispEstado(tEstado *estado)
{
   int i,j;

   for (i=0; i<N; i++)
   {
      for (j=0; j<N; j++)
         printf("%d",estado->celdas[i][j]);
      printf("\n");
   }
   printf("\n");
}


void dispOperador(unsigned op)
{
   switch(op)
   {
      case ARRIBA:    printf("Movimiento ARRIBA:\n"); break;
      case ABAJO:     printf("Movimiento ABAJO:\n"); break;
      case IZQUIERDA: printf("Movimiento IZQUIERDA:\n"); break;
      case DERECHA:   printf("Movimiento DERECHA:\n"); break;
   }
}

// FUNCIONES QUE SE HAN DE IMPLEMENTAR EN LA PRACTICA 1

// Funci�n auxiliar para comprobar si dos puzles tienen las fichas colocadas en el mismo orden en el tablero
// Devuelve 1 si es igual y 0 si no lo es
int iguales(tEstado *s, tEstado *t)
{
   int i, j, n=1;
   for(i=0; i<N && n==1; i++){
      for(j=0; j<N && n==1; j++){
         if(s->celdas[i][j]!=t->celdas[i][j])
            n=0;
      }
   }
   return n;
}

// Devuelve 1 si es igual y 0 si no lo es
int testObjetivo(tEstado *estado)
{
   int i, j, n=1;
   for(i=0; i<N && n==1; i++){
      for(j=0; j<N && n==1; j++){
         if(estado->celdas[i][j] != puzle_final[i][j])
            n=0;
      }
   }
   return n;
}

// Devuelve 0 si es valido el operador y 1 si no lo es
int esValido(unsigned op, tEstado *estado)
{
   int n=1;
   switch (op)
   {
      case ARRIBA: if(estado->fila[0] == 1) n=0;break;
      case ABAJO: if(estado->fila[0] == 3) n=0; break;
      case IZQUIERDA: if(estado->col[0] == 1) n=0; break;
      case DERECHA: if(estado->col[0] == 3) n=0; break;
   }
   return n;
}


tEstado *aplicaOperador(unsigned op, tEstado *estado)
{
   int aux;
   tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
   memcpy(nuevo, estado,sizeof(tEstado));  // Hace una copia del estado
   switch(op)
   {
      case ARRIBA: aux = nuevo->celdas[nuevo->fila[0]-1][nuevo->col[0]]; nuevo->celdas[nuevo->fila[aux]][nuevo->col[aux]] = 0; 
      nuevo->celdas[nuevo->fila[0]][nuevo->col[0]] = aux; nuevo->fila[0]++; nuevo->fila[aux]--;break;
      case ABAJO: aux = nuevo->celdas[nuevo->fila[0]+1][nuevo->col[0]]; nuevo->celdas[nuevo->fila[aux]][nuevo->col[aux]] = 0; 
      nuevo->celdas[nuevo->fila[0]][nuevo->col[0]] = aux; nuevo->fila[0]--; nuevo->fila[aux]++;break;
      case IZQUIERDA: aux = nuevo->celdas[nuevo->fila[0]][nuevo->col[0]+1]; nuevo->celdas[nuevo->fila[aux]][nuevo->col[aux]] = 0;
      nuevo->celdas[nuevo->fila[0]][nuevo->col[0]] = aux; nuevo->col[0]--; nuevo->col[aux]++;break;
      case DERECHA: aux = nuevo->celdas[nuevo->fila[0]][nuevo->col[0]+1]; nuevo->celdas[nuevo->fila[aux]][nuevo->col[aux]] = 0;
      nuevo->celdas[nuevo->fila[0]][nuevo->col[0]] = aux; nuevo->col[0]++; nuevo->col[aux]--;break;
   }
   return nuevo;
}