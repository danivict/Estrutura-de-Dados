#include <stdlib.h>
#include "pilha.h"

pilha *cria_pilha(){
    pilha *p = (pilha*)malloc(sizeof(pilha));
    p -> topo = NULL;
    return p;
}

void push(pilha *p, int v){
    no *novo = (no*)malloc(sizeof(no));
    novo -> valor = v;
    novo -> next = p -> topo;
    p -> topo = novo;
}

int pop(pilha *p){
    no *atual;
    int ret;
    if(p -> topo != NULL){
        atual = p -> topo;
        ret = atual -> valor;
        p -> topo = atual -> next;
        free(atual);
    }
    return ret;
}

int quantidade(pilha *p){
    if(p -> topo == NULL) return 0;
    no *atual;
    int qtd = 0;
    while(atual -> next != NULL){
        atual = atual -> next;
        qtd++;
    }
    return qtd;
}

void print_pilha(pilha *p){
    no *atual = p -> topo;
    while(atual != NULL){
        printf("%d ", atual -> valor);
        atual = atual -> next;
    }
}