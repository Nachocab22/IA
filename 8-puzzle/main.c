#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "puzzle.h"

int main(){
    //pruebas del código generado
    int op;
    tEstado *n,*a;
    a=estadoInicial();
    printf("ESTADO INICIAL\n");
    dispEstado(a);
    for(op=1; op<=NUM_OPERADORES; op++){
        dispOperador(op);
        if(esValido(op, a)){
            n=aplicaOperador(op, a);
            dispEstado(n);
        }//fin_if
        else
            printf("\n Operador no valido\n");
    }//fin_for
}//fin_main