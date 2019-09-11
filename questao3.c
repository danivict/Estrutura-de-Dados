#include <stdio.h>
#include <math.h>

int pali(char s[],int i,int f){ // funcao palindromo
    if(i == f) return 1;
    if(f - i == 1) return s[i] == s[f];
    else return s[i] == s[f] && pali(s, i+1, f-1);
}


long int seq(int n){ // funcao sequencia
    if(n<=1) return 2;
    else return seq(n-1) * seq(n-2);
}


int soma(int n){ // funcao soma de cubos
    if(n==1) return 1;
    else return pow(n, 3) + soma(n-1);
}


int main(){
    // testes palindromo
    char frase1[] = "dopod", frase2[] = "palind";
    printf("%d\n", pali(frase1, 0, 4));
    printf("%d\n", pali(frase2, 0, 5));

    // testes funcao sequencia
    int i;
    printf("\n");
    for(i=1;i<11;i++){
        printf("%ld\n", seq(i));
    }

    // testes funcao soma de cubos
    int int1 = 4, int2 = 8;
    printf("\n");
    printf("%d\n%d\n", soma(int1), soma(int2));
    return 0;
}