//Macros
#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4
#define NUM_OPERADORES 4
#define N 2

#define true 1
#define false 0

//Estructuras
#ifndef _tEstado_
#define _tEstado_

typedef struct
{
    int celdas[N][N];
    int fila[N*N], col[N*N];
}tEstado;

static int puzle_inicial[N][N]= 
{
  {0,1},
  {3,2}
};

static int puzle_final[N][N]= 
{
  {1,2},
  {0,3}
};

//Funciones
tEstado *crearEstado(int celdas[N][N]);
tEstado *estadoInicial();
int coste(unsigned op, tEstado *estado);
void dispEstado(tEstado *estado);
void dispOperador(unsigned op);
tEstado *estadoObjetivo();
int esValido(unsigned op, tEstado* estado);
tEstado *aplicaOperador(unsigned op, tEstado* estado);
int iguales(tEstado *s, tEstado *t);
int testObjetivo(tEstado *estado);

#endif