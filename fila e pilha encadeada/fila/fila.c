#include <stdlib.h>
#include "fila.h"

fila *cria_fila(){
    fila *f = (fila*)malloc(sizeof(fila));
    f -> fim = NULL;
    f -> inicio = NULL;
    return f;
}

void insere_fim(fila *f, int v){
    no *novo = (no*)malloc(sizeof(no));
    novo -> next = NULL;
    novo -> valor = v;
    if(f -> fim != NULL){
        f -> fim -> next = novo;
        f -> fim = novo;
    }
    else{
        f -> inicio = novo;
        f -> fim = novo;
    }
}

int remove_inicio(fila *f, int *vret){
    no *atual;
    if(f -> inicio == NULL) return -1;
    else{
        atual = f -> inicio;
        *vret = atual -> valor;
        f -> inicio = f -> inicio -> next;
        if(f -> inicio == NULL){
            f -> fim = NULL;
        }
        free(atual);
        return 0;
    }
}

void limpafila(fila *f){
    no *atual, *ant;
    atual = f -> inicio;
    ant = NULL;
    while(atual != NULL){
        ant = atual;
        atual = atual -> next;
        free(ant);
    }
    f -> fim = f -> inicio = NULL;
}

void printfila(fila *f){
    no *atual = f -> inicio;
    while(atual != NULL){
        printf("%d ", atual -> valor);
        atual = atual -> next;
    }
}