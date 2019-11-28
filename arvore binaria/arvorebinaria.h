typedef struct node node;
struct node
{
    int valor;
    node *esq;
    node *dir;
};

node *criaNo(int v, node *e, node *d);

node *insertValue(node *raiz, int v);

node *findValue(node *raiz, int v);

void printTree(node *raiz);

int getHeight(node *raiz);

node *removeValue(node *raiz, int v);

int size(node *raiz);

int sumX(node *raiz, int v);