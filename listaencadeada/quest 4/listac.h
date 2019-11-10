#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *before;
};

typedef struct node node;

typedef struct{
    node *begin;
    node *end;
}list;

list *createlist();

void printList(list *l);

void printCircular(list *l);

void insereIni(list *l, int v);

void insereCircular(list *l, int v);

void insereFim(list *l, int v);

int hasElement(list *l, int v);

int removeElement(list *l, int v);

int removeElementCircular(list *l, int v);

void becomeCircular(list *l);