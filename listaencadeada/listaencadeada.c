#include <stdlib.h>
#include "listaencadeada.h"

list *createList(){
     list *l = (list*)malloc(sizeof(list));
    l -> begin = NULL;
     return l;
}

void add(list *l, int v){
    node *novo = (node*)malloc(sizeof(node));
    novo -> data = v;
    novo -> next = NULL;
    node *p = l -> begin;
    node *a = NULL;
    while(p != NULL){
        a = p;
        p = p -> next;
    }
    if (a == NULL){
        l -> begin = novo;
    }
    else{
        a -> next = n;
        free(p);
    }
}