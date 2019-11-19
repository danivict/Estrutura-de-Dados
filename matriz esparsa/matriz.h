#include <stdlib.h>

typedef struct no
{
    int valor;
    int coluna;
    struct no *next;
} node;

typedef node *pont;

typedef struct
{
    pont *begin;
    int linhas;
    int colunas;
    int d; // valor default
} matriz;

int inserir(matriz *m, int lin, int col, int v);
// inserir o valor "default" para exclusao

int acess(matriz *m, int lin, int col);

matriz *cria_matriz(int lin, int col, int def);