/*******************************************/
/*             MAIN.C                      */
/*                                         */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "puzzle.h"
#include "listaia.h"
#include "busqueda.h"

int main(){
    solucionFin(busqueda());
    return 0;
}
