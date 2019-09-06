#include <stdio.h>
#include <string.h>

int strrchr2(char x[], char c){
    int i = 0, *pont;
    while(1){
        if(x[i] == c){
            pont = &x[i];
            return pont;
            break;
        }
        else if(x[i] == '\0') break;
        i++;
    }
    return NULL;
}

int main(){
    char string[1024], z, *p;
    scanf("%s %c", string, &z);
    p = strrchr2(string, z);
    printf(p);
    //printf("%c", strrchr(string, z));
    return 0;
}
