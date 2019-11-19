#include <stdlib.h>

struct no{
    int valor;
    struct no *next;
};
typedef struct no no;

typedef struct {
    no *topo;
} pilha;

pilha *cria_pilha();

int pop(pilha *p);

void push(pilha *p, int v);

int quantidade(pilha *p);

void print_pilha(pilha *p);