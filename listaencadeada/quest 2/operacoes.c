#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"

list *createList()
{
    list *l = (list *)(malloc(sizeof(list)));
    l->begin = NULL;
    return l;
}

void add(list *l, int v)
{
    node *n = (node *)(malloc(sizeof(node)));
    n->v = v;
    n->next = NULL;
    node *p = l->begin;
    node *a = NULL;
    while (p != NULL)
    {
        a = p;
        p = p->next;
    }
    if (a == NULL)
        l->begin = n;
    else
        a->next = n;
}

void printList(list *l)
{
    printf("[");
    node *p = l->begin;
    node *a = NULL;
    while (p != NULL)
    {
        if (p->next != NULL)
            printf("%d, ", p->v);
        else
            printf("%d", p->v);
        p = p->next;
    }
    printf("]\n");
}

int isEmpaty(list *l)
{
    return (1 ? l->begin == NULL : 0);
}

void removeBack(list *l)
{
    node *p = l->begin;
    node *a = NULL;
    while (p != NULL && p->next != NULL)
    {
        a = p;
        p = p->next;
    }
    if (a == NULL)
        l->begin = NULL;
    else
    {
        a->next = NULL;
    }
    free(p);
}

int size(list *l)
{
    int c = 0;
    node *p = l->begin;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

int hasElement(list *l, int v)
{
    node *n = l->begin;
    int pos = 0;
    while (n != NULL)
    {
        if (n->v == v)
            return pos;
        pos++;
        n = n->next;
    }
    return -1;
}

int insertPosition(list *l, int v, int pos)
{
    if (pos < 0 || pos > size(l))
        return -1;
    else
    {
        int c;
        node *n = l->begin;
        node *a = NULL;
        node *p = (node *)(malloc(sizeof(node)));
        p->v = v;
        for (c = 0; c < pos; c++)
        {
            a = n;
            n = n->next;
        }

        p->next = n;
        if(a==NULL) l->begin = p;
        else a->next = p;

        return 0;
    }
}

int removePos(list *l, int pos){
    if (pos < 0 || pos > size(l))
        return -1;
    else{
        int c;
        node *n = l->begin;
        node *a = NULL;
        for (c = 0; c < pos; c++)
        {
            a = n;
            n = n->next;
        }
        node *k = n->next;
        if(a!=NULL)
            a->next = k;

        else
            l->begin = k;

        free(n);
        return 0;
    }
}

int removeElement(list *l, int v){
    int pos = hasElement(l, v);
    if(pos < 0) return -1;
    else{
        removePos(l, pos);
        return pos;
    }
}

int get(list *l, int pos, int *vret){
    if(pos < 0 || pos > size(l)) return -1;
    else{
        node *n = l->begin;
        int i;
        for(i = 0; i < pos; i++)
            n = n->next;
        *vret = n->v;
        return 0;
    }
}