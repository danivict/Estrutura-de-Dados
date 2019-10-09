#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define SIZE 1000 //tamanho do vetor

void swap(int *x, int *y){
    int temp = *y;
    *y = *x;
    *x = temp;
}

int intcmp(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

void printArray(int *v, int n) {
    int i = 0;
    for(i = 0; i < n; i++) {
        printf("%d ",v[i]);
    }
    printf("\n");
}

void preencheArray(int *v, int *v2, int *v3,  int *v4, int n) {
    int i = 0;
    for(i = 0; i < n; i++) {
        v[i] = rand()%100; //sorteia valor entre 0 e 99 e atribui ao elemento do vetor
        v2[i] = v[i];
        v3[i] = v[i];
    }
}

int checkSort(int *v, int n) {
    if(n <= 0) return -1;
    int ant = v[0];
    int i;
    for(i = 1; i < n; i++) {
        if(v[i] < ant) return 0;
        ant = v[i];
    }
    return 1;
}

void insertionsort(int *v, int n){
    int aux, i, j;
    for(i=1; i<n; i++){
        aux = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > aux){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}
void merge(int *v, int i, int f){
    int m = (i + f) / 2;
    int aux[f - i + 1];
    int e = i;
    int d = m + 1;
    int k = 0;
    while(e <= m || d <= f){
        if(e > m) aux[k++] = v[d++];
        else if(d > f) aux[k++] = v[e++];
        else if(v[e] < v[d]) aux[k++] = v[e++];
        else aux[k++] = v[d++];
    }
    for(k=i; k<=f; k++){
        v[k] = aux[k - i];
    }
}

void mergeSort(int *v, int i, int f){
    if(f > i){
        int m = (i + f) / 2;
        mergeSort(v, i, m);
        mergeSort(v, m+1, f);
        merge(v, i, f);
    }
}

int partition(int *v, int i, int f){
    int d = i-1;
    int j;
    int p = v[f];
    for(j = i; j <= f-1; j++){
        if(v[j] <= p){
            d = d+1;
            swap(&v[j], &v[d]);
        }
    }
    d = d + 1;
    swap(&v[f], &v[d]);
    return d;
}

void quicksort(int *v, int i, int f){
    if(f > i){
        int p = partition(v, i, f);
        quicksort(v, i, p-1);
        quicksort(v, p+1, f);
    }
}

int main() {
    int SIZE;
    
    printf("Informe o tamanho do array:\n");
    scanf("%d", &SIZE);
    
    srand(time(NULL)); //inicializa semente aleatoria
    
    //declara e preenche os arrays de forma aleatória
    int v[SIZE], v2[SIZE], v3[SIZE], v4[SIZE];
    preencheArray(v,v2,v3,v4,SIZE);
    
    clock_t ticks[2];
    
    ticks[0] = clock();
    mergeSort(v,0,SIZE-1);
    ticks[1] = clock();
    double tempo1 = (double)(ticks[1] - ticks[0])/ CLOCKS_PER_SEC;   
    printf("Tempo gasto - merge: %lf s.\n", tempo1);
       
    ticks[0] = clock();
    insertionsort(v2, SIZE);
    ticks[1] = clock();
    double tempo2 = (double)(ticks[1] - ticks[0])/ CLOCKS_PER_SEC;
    printf("Tempo gasto - insertion: %lf s.\n", tempo2);
    
    ticks[0] = clock();
    quicksort(v3, 0, SIZE-1);
  //  qsort(v3, SIZE, sizeof(int), intcmp);
    ticks[1] = clock();
    double tempo3 = (double)(ticks[1] - ticks[0])/ CLOCKS_PER_SEC;
    printf("Tempo gasto - quick: %lf s.\n", tempo3);

    
    ticks[0] = clock();
    qsort(v4, SIZE, sizeof(int), intcmp);
    ticks[1] = clock();
    double tempo4 = (double)(ticks[1] - ticks[0])/ CLOCKS_PER_SEC;
    printf("Tempo gasto - qsort: %lf s.\n", tempo4);
    
    printf("%lf %lf %lf %lf\n",tempo1, tempo2, tempo3, tempo4);

    
    //Verifica se o array final ficou ordenado
    int r = checkSort(v,SIZE);
    printf("Check merge: %d\n",r);
    r = checkSort(v2,SIZE);
    printf("Check insertion: %d\n",r);
    r = checkSort(v3,SIZE);
    printf("Check quick: %d\n",r);
    r = checkSort(v4,SIZE);
    printf("Check qsort: %d\n",r);
        
    return 0;
}
