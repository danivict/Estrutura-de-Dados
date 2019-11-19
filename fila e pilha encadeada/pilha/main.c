#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

int main(){
    pilha *p = cria_pilha();
    for(int i = 0; i<5; i++) push(p, i);
    print_pilha(p);
    printf("\n%d\n",pop(p));
    print_pilha(p);
    return 0;
}