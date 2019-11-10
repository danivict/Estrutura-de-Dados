#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.c"

int main(){
    list *l = createList();
    add(l, 2);
    add(l, 112);
    add(l, 4);
    add(l, 6);
    add(l, 7);
    add(l, 1);
    add(l, 98);

    printf("TAMANHO DA LISTA EM O(1)\n");
    printList(l);
    printf("Tamanho da lista: %d\n", size(l));

    printf("Remove o ultimo...\n");
    removeBack(l);
    printList(l);
    printf("Tamanho da lista: %d\n", size(l));


    printf("Removendo o item do índice 1...\n");
    removePos(l, 1);
    printList(l);
    printf("Tamanho da lista: %d\n", size(l));


    insertPosition(l, 3122, 3);
    printf("Inserindo número...\n");
    printList(l);
    printf("Tamanho da lista: %d\n", size(l));



    return 0;
}