#include <stdio.h>

#define max 100

typedef struct
{
    int topo;
    int vet[max];
} pilha;

pilha *cria_pilha()
{
    pilha *p = (pilha *)malloc(sizeof(pilha));
    p->topo = 0;
}

int push(pilha *p, int v)
{
    if (p->topo < max)
    {
        p->vet[p->topo] = v;
        p->topo++;
    }
}

int pop(pilha *p)
{
    int ret;
    if (p->topo > 0)
    {
        int aux = p->vet[p->topo - 1];
        p->topo--;
    }
    return ret;
}

int size(pilha *p)
{
    return p->topo;
}

int is_empty(pilha *p)
{
    return p->topo == 0;
}

int is_full(pilha *p)
{
    return p->topo == max;
}

int main(void)
{

    return 0;
}
