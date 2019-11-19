typedef struct no {
    int valor;
    struct no *next;
} no;

typedef struct no no;

typedef struct {
    no *inicio;
    no *fim;
} fila;

fila *cria_fila();

void insere_fim(fila *f, int v);

int remove_inicio(fila *f, int *vret);

void limpafila(fila *f);

void printfila(fila *f);