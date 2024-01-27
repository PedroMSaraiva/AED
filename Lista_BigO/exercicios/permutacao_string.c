#include <stdio.h>
#include <string.h>

/*Permutações de Strings: Escreva um algoritmo para imprimir 
todas as permutações possíveis de uma string.*/

void swap(char* x, char* y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void generatePermutations(char* str, int start, int end){
    if (start == end){
        printf("%s\n", str);
    } else {
        for (int i = start; i <= end; i++){
            swap(&str[start], &str[i]);
            generatePermutations(str, start + 1, end);
            swap(&str[start], &str[i]);
        }
    }
}

// A complexidade é O(n!) Isso ocorre porque ha recursão
int main(){
    char str[100];
    printf("Digite uma string: ");
    scanf("%s", str);

    int n = strlen(str);

    printf("Permutações possiveis da string: \n");
    generatePermutations(str, 0, n-1);

    return 0;
}