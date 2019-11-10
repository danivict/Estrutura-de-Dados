#include <stdio.h>
#include "listaencadeada.c"

int main(){
    int i;
    list *l = createList();
    for(i = 0; i<5; i++){
        add(l, i);
    }
    printf("Lista: ");
    printList(l);
    printf("Quantidade de elementos da lista: %d\n", size(l));
    for(i = 0; isEmpty(l) == 0; i++){
        printList(l);
        removeBack(l);
    }
    printf("Quantidade de elementos da lista: %d\n", size(l));
    return 0;
}