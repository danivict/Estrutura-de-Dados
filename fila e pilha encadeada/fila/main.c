#include <stdio.h>
#include <stdlib.h>
#include "fila.c"

int main(){
    fila *f = cria_fila();
    int *a = (int*)malloc(sizeof(int));
    for (int i = 0; i<5; i++) insere_fim(f, i);
    printfila(f);
    printf("\n");
    remove_inicio(f, a);
    printf("%d\n", *a);
    printfila(f);
    return 0;
}