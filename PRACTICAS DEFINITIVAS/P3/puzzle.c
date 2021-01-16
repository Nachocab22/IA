#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "puzzle.h"

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

/* VISUALIZACIÓN DE ESTADOS Y OPERADORES*/


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

// Función auxiliar para comprobar si dos puzles tienen las fichas colocadas en el mismo orden en el tablero
int iguales(tEstado *s, tEstado *t)  //
{
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(s->celdas[i][j]!=t->celdas[i][j])
                return 0;
        }
    }
    return 1;
}

int testObjetivo(tEstado *estado)
{
    int i,j;
    bool comp=true;
    for(i=0; i<N && comp==true; i++){
        for(j=0; j<N && comp==true; j++){
            if(estado->celdas[i][j]!=puzle_final[i][j])
                comp=false;
        }
    }
    if(comp==true)
        return 1;
    else 
        return 0;
}


int esValido(unsigned op, tEstado *estado)
{
    switch (op)
    {
    case ARRIBA: if(estado->fila[0]>0)
        return 1;
        else
            return 0;
    case ABAJO: if(estado->fila[0]<2)
        return 1;
        else
            return 0;
    case IZQUIERDA: if(estado->col[0]>0)
        return 1;
        else
            return 0;
    case DERECHA: if(estado->col[0]<2)
        return 1;
        else 
            return 0;
    default:break;
    }
}


tEstado *aplicaOperador(unsigned op, tEstado *estado)
{
    tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
    memcpy(nuevo, estado,sizeof(tEstado));  // Hace una copia del estado
    switch (op) {
    case ARRIBA:
      --nuevo->fila[0];
      break;
    case ABAJO:
      ++nuevo->fila[0];
      break;
    case IZQUIERDA:
      --nuevo->col[0];
      break;
    case DERECHA:
      ++nuevo->col[0];
      break;
  }
  nuevo->celdas[estado->fila[0]][estado->col[0]] = nuevo->celdas[nuevo->fila[0]][nuevo->col[0]];
  nuevo->celdas[nuevo->fila[0]][nuevo->col[0]] = 0;
return nuevo;
}