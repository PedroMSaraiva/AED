#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Substrings Únicas: Dado uma string, encontre o número de 
// substrings únicas.


int substringsUnicas(char *str, int tamanho){
    for (int i = 0; i <= tamanho; i++){
        for (int h = 0; h <= i; h++){
            for(int j = h; j <= i; j++){
                printf("%c",str[j]);
            }
            printf("\n");
        }
    }
    return 1;
}

int main(){
    clock_t t;
    t = clock();

    char str[] = "ashuahbs";
    int tamanho = strlen(str);

    int resul;
    resul = substringsUnicas(str, tamanho);
    printf("%d", resul);

    float diff = ((float)(clock() - t)) / CLOCKS_PER_SEC;
    printf("\n\n diff=%f \n\n", diff);

    return 0;
}