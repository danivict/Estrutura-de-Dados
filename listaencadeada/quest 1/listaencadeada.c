#include <stdlib.h>
#include "listaencadeada.h"
#include <stdio.h>

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
        a -> next = novo;
        free(p);
    }
}

void printList(list *l){
    printf("{");
    node *p = l -> begin;
    while(p != NULL){
        if(p -> next != NULL) printf("%d ", p -> data);
        else printf("%d", p -> data);
        p = p -> next;
    }
    printf("}\n");
}

int isEmpty(list *l){
    if(l -> begin == NULL) return 1;
    else return 0;
}

void removeBack(list *l){
    node *p = l -> begin;
    node *a = NULL;
    while(p != NULL && p -> next != NULL){
        a = p;
        p = p -> next;
    }
    if(a == NULL){
        l -> begin = NULL;
    }
    else{
        a -> next = NULL;
    }
    free(p);
}

int size(list *l){
    int qtd = 0;
    for(node *p = l -> begin; p != NULL; p = p -> next){
        qtd++;
    }
    return qtd;
}