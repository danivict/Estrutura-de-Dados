#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ifatorial(int x){
    int fat = 1, i;
    for(i=2;i<=x;i++){
        fat = fat * i;
    }
    return fat;
}


int rfatorial(int x){
    if(x==1) return 1;
    else return x * rfatorial(x-1);
}


double iseno(double x, int qt){
    int i;
    double soma = x, temp;
    for(i=1;i<qt;i++){
        temp = pow(x, 2*i+1)/ifatorial((2*i)+1);
        soma = (i % 2) ? soma - temp : soma + temp;
    }
    return soma;
    
}


double rseno(double x, int qt){
    int se=qt*2-1;
    if (qt == 1) return x;
    else if (qt%2==0) return rseno(x, qt-1) - (pow(x, se)/rfatorial(se));
    else return rseno(x, qt-1) + (pow(x, se)/rfatorial(se));
}


int main(){
    printf("Fatorial iterativa: %d\n", ifatorial(4));
    printf("Fatorial recursiva: %d\n", rfatorial(4));
    printf("Seno recursiva: %f\n", rseno(3.14, 8));
    printf("Seno iterativa: %f\n", iseno(3.14, 8));
    printf("Seno funcao sin(math.h): %f", sin(3.14));
    return 0;
}