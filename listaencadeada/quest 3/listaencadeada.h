#include <stdio.h>
#include <stdlib.h>

struct node{
    int v;
    struct node *next;
};
typedef struct node node;

typedef struct{
    struct node *begin;
    int size;
}list;

list *createList();

void add(list *l, int v);

int isEmpaty(list *l);

void printList(list *l);

void removeBack(list *l);

int size(list *l);

int hasElement(list *l, int v);

int insertPosition(list *l, int v, int pos);

int removePosition(list *l, int pos);

int removeElement(list *l, int v);

int get(list *l, int pos, int *vret);