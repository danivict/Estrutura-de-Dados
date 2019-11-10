struct node{
    int data;
    struct node *next;
};
typedef struct node node;

typedef struct {
    node *begin;
} list;

list *createList();

void add(list *l, int v);

void printList(list *l);

int isEmpty(list *l); /* verifica se a lista esta vazia
                         se estiver vazia retorna 1 ou 0 caso contrario */

void removeBack(list *l);

int size(list *l); // quantidade de elementos da lista