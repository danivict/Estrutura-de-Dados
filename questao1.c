#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isRealNumber(char x[]){
	int i=0, cont = 0,cont2=0, tam = 0;
	while(1){
		if(x[tam]=='\0'){
			break;
		}
		if(x[tam]=='.'){
			cont++;
		}
		else if(x[tam]<'0'||x[tam] > '9' ) cont2++;
		tam++;
	}
	while(1){
		if(cont>=2){
			return 0;
			break;
		}
		else if(x[0]=='.'){
			return 0;
			break;
		}
		else if((x[i]<'0') || (x[i]>'9')){
			return 0;
			break;
		}
		else if(cont2>=1){
			return 0;
			break;
		}
		else if(x[tam-1]=='.'){
			return 0;
			break;
		}
		else{
			return 1;
			break;
		}
		i++;
	}
}

int atoi2(char x[]){
int i = 0, cont = 0, c = 0, temp = 0;
    while (1){
        if (x[c] == '\0') break;
        c++;
    }
    while (1){
        if (x[i] == '.'){
            cont++;
            return 0;
            break;
        }
        else if(x[i] - '0' > 31 && x[i] - '0' < 127){
            cont++;
            return 0;
            break;
        }
        else if (x[i] == '\0') break;
        i++;
    }
    if(cont==0){
        int po = pow(10, c-1);
        for(i=0; i<c; i++){
            temp = temp + (x[i] - '0') * po;
            po = po/10;
        }
    }
    return temp;
}

int main(){
	char string1[] = "323", string2[] = "32a3", string3[] = ".435";
    // teste funcao isRealNumber
	printf("%d\n", isRealNumber(string1));
    printf("%d\n", isRealNumber(string2));
    printf("%d\n", isRealNumber(string3));
    printf("\n");
    // teste funcao atoi2
    printf("%d\n", atoi2(string1));
    printf("%d\n", atoi2(string2));
    printf("%d\n", atoi2(string3));
	return 0;
}
