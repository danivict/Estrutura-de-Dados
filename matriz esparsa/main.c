#include <stdio.h>
#include "matriz.c"

int main(){
    matriz *m = cria_matriz(3, 3, 0);
    for(int i = 0; i<3; i++)
        for(int j = 0; j<3; j++)
            insere(m, i, j, i);
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++)
            printf("%d ",acess(m, i, j));
        printf("\n");
    }
    insere(m, 1, 1, 0);
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++)
            printf("%d ",acess(m, i, j));
        printf("\n");
    }
    return 0;
}
