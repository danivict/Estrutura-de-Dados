#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.c"

int main()
{
    node *raiz = criaNo(10,
                        criaNo(20, NULL, NULL),
                        criaNo(30, NULL, NULL));
    printf("Valores dos nos da arvore: ");
    printTree(raiz);
    printf("\n");
    printf("Altura da arvore: %d\n", getHeight(raiz));
    printf("Quantidade de nos: %d\n", size(raiz));
    printf("Soma dos valores da arvore: %d\n", sumX(raiz, 0));
    printf("**Valor 40 inserido na arvore**\n");
    insertValue(raiz, 40);
    printf("Valores dos nos da arvore: ");
    printTree(raiz);
    printf("\n");
    printf("Altura da arvore: %d\n", getHeight(raiz));
    printf("Quantidade de nos: %d\n", size(raiz));
    printf("Soma dos valores da arvore: %d\n", sumX(raiz, 0));
    return 0;
}