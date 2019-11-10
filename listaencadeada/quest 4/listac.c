#include "listac.h"
#include <stdlib.h>
#include <stdio.h>

list *createlist()
{
    list *l = (list *)malloc(sizeof(list));
    l->begin = NULL;
    l->end = l->begin;
    return l;
}

void insereIni(list *l, int v)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = v;
    n->before = NULL;
    n->next = l->begin;
    l->begin = n;
    if (l->end == NULL)
        l->end = n;
}

void insereFim(list *l, int v)
{
    node *n = (node*)malloc(sizeof(node));
    n->data = v;
    n->next = NULL;
    n->before = l->end;
    l->end->next = n;
    l->end = n;
}

void printList(list *l)
{
    printf("[");
    node *p = l->begin;
    node *a = NULL;
    while (p != NULL)
    {
        if (p->next != NULL)
            printf("%d, ", p->data);
        else
            printf("%d", p->data);
        p = p->next;
    }
    printf("]\n");
}

int hasElement(list *l, int v){
    node *p = l->begin;
    int pos = 0;
    while(p!=NULL){
        if(p->data == v) return pos;
        pos++;
        p = p->next;
    }
    return -1;
}

int removeElement(list *l, int v){
    int pos = hasElement(l, v);
    if(pos < 0) return pos;
    else{
        int i;
        node *p = l->begin;
        for(i = 0; i < pos; i++)
            p = p->next;

        if(p==l->begin){
            l->begin = p->next;
            l->begin->before = NULL;
        }
        else if(p==l->end){
            l->end = p->before;
            l->end->next = NULL;
        }
        else{
            p->next->before = p->before;
            p->before->next = p->next;
        }
        free(p);
        return pos;
    }
}

void becomeCircular(list *l){
    if(l->begin != NULL){
        l->begin->before = l->end;
        l->end->next = l->begin;
        // A lista circular só tem um início
    }
}

void printCircular(list *l){
    
    printf("[");
    if(l->begin!=NULL){
        node *a = l->begin;
        do{
            printf("%d, ", a->data);
            a = a->next;
        }while(a!=l->begin);
    }
    printf("]\n");
}

void insertCircular(list *l, int v){
    node *n = (node*)malloc(sizeof(node));
    n->data = v;
    if(l->begin!=NULL){
        n->next = l->begin;
        n->before = l->end;
        n->before->next = n;
        l->end = n;
    }
    else{
        l->begin = l->end = n;
        n->before = n->next = n;
    }
}