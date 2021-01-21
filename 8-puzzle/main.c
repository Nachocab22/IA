#include <stdio.h>
#include <stdlib.h>
#include "puzle.h"

int main()
{
    tEstado *actual= (tEstado *) malloc(sizeof(tEstado));
    tEstado *objetivo= (tEstado *) malloc(sizeof(tEstado));

    actual = estadoInicial();
    dispEstado(actual);

    return 0;
}
