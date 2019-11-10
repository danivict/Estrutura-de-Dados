#include <stdio.h>
#include "operacoes.c"

int main(){
    int i;
    printf("Lista criada: ");
    list *l = createList();
    for(i = 0; i<5; i++){
        insertPosition(l, i, i);
    }
    printList(l);
    printf("Elemento na posicao 4: ");
    printf("%d\n", hasElement(l, 4));
    removePos(l, 2);
    printf("Lista apos remocao do elemento na posicao 2: ");
    printList(l);
    removeElement(l, 1);
    printf("Lista apos a remocao do elemento 1: ");
    printList(l);
    return 0;
}