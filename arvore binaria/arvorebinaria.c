#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"

node *criaNo(int v, node *e, node *d)
{
    node *novo = (node *)malloc(sizeof(node));
    novo->valor = v;
    novo->esq = e;
    novo->dir = d;
    return novo;
}

node *insertValue(node *raiz, int v)
{
    if (raiz == NULL)
    {
        raiz = (node *)malloc(sizeof(node));
        raiz->valor = v;
        raiz->esq = NULL;
        raiz->dir = NULL;
    }
    else if (v < raiz->valor)
    {
        raiz->esq = insertValue(raiz->esq, v);
    }
    else
    {
        raiz->dir = insertValue(raiz->dir, v);
    }
}

node *findValue(node *raiz, int v)
{
    if (raiz == NULL || raiz->valor == v)
    {
        return raiz;
    }
    else if (v < raiz->valor)
    {
        return findValue(raiz->esq, v);
    }
    else
    {
        return findValue(raiz->dir, v);
    }
}

void printTree(node *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->valor);
        printTree(raiz->esq);
        printTree(raiz->dir);
    }
}

int getHeight(node *raiz)
{
    if (raiz == NULL)
        return -1;
    else
    {
        int ae = getHeight(raiz->esq);
        int ad = getHeight(raiz->dir);
        if (ae > ad)
            return ae + 1;
        else
            return ad + 1;
    }
}

node *removeValue(node *raiz, int v)
{
    if (raiz == NULL)
        return NULL;
    else if (v < raiz->valor)
        return removeValue(raiz->esq, v);
    else if (v > raiz->valor)
        return removeValue(raiz->dir, v);
    else
    {
        if (raiz->esq == NULL && raiz->dir == NULL)
        {
            free(raiz);
            return NULL;
        }
        else if (raiz->dir == NULL)
        {
            node *t = raiz;
            raiz = raiz->esq;
            free(t);
        }
        else if (raiz->esq == NULL)
        {
            node *t = raiz;
            raiz = raiz->dir;
            free(t);
        }
        else
        {
            node *f = raiz->esq;
            while (f->dir != NULL)
                f = f->dir;
            raiz->valor = f->valor;
            f->valor = v;
            raiz->esq = removeValue(raiz->esq, v);
        }
    }
    return raiz;
}

int size(node *raiz)
{
    if (raiz != NULL)
    {
        int e = size(raiz->esq) + 1;
        int d = size(raiz->dir);
        return e + d;
    }
}

int sumX(node *raiz, int v)
{
    if (raiz == NULL)
        return 0;
    else if (raiz->valor > v)
    {
        int e = sumX(raiz->esq, v);
        int d = sumX(raiz->dir, v);
        return raiz->valor + e + d;
    }
    return sumX(raiz->esq, v) + sumX(raiz->dir, v);
}