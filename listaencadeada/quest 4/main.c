#include "listac.c"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    list *l = createlist();
    insereIni(l, 2);
    insereIni(l, 7);
    insereFim(l, 3);
    insereFim(l, 312);
    insereFim(l, 4);
    insereFim(l, 13);
    printList(l);

    printf("Buscando 2: %d\n", hasElement(l, 2));
    printf("Buscando 131: %d\n", hasElement(l,131));
    
    printf("Remove 7 na posicao: %d\n", removeElement(l, 7));
    printList(l);

    printf("Remove 312 na posicao: %d\n", removeElement(l, 312));
    printList(l);

    printf("Remove 13 na posicao: %d\n", removeElement(l, 13));
    printList(l);

    printf("Transformando a lista em circular\n");
    becomeCircular(l);
    printCircular(l);

    printf("Adicionando 98 na lista circular\n");
    insertCircular(l, 98);
    printCircular(l);

    printf("Criando uma lista circular vazia\n");
    list *l2 = createlist();
    becomeCircular(l2);
    printCircular(l2);

    insertCircular(l2, 1);
    insertCircular(l2, 312);
    insertCircular(l2, 12);
    insertCircular(l2, 32);

    printCircular(l2);

    return 0;
}