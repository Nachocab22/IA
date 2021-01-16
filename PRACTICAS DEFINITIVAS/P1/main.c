#include <stdio.h>
#include "puzle.h"

int main()
{
    int op;
    tEstado *estado;
    estado = estadoInicial();

    printf("\nFila del 0: %d Columna del 0: %d\n", estado->fila[0], estado->col[0]);

    dispEstado(estado);

    if(testObjetivo(estado) == 1)
        printf("Si son iguales");
    else
        printf("No son iguales");
    
    do{
        printf("\nIntroduzca el operador que desea aplicar: ");
        scanf("%d",&op);

        if(esValido(op, estado) == 1){
            estado = aplicaOperador(op, estado);
            dispEstado(estado);
        }
        else
            printf("\nEl estado introducido no se puede aplicar");
    }while(op != 0);
    
    if(testObjetivo(estado) == 1)
        printf("\nEnhorabuena!!");
    else
        printf("\nJaja no, vuelve a intenarlo");
    
    return 0;
}