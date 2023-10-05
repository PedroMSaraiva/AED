/*
    Desafio do diamante de asteriscos:
    Escreva um aplicativo em C que peça um número inteiro ímpar ao usuário e desenhe um diamante 
no seguinte formato:

    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *

    Nesse caso, o número é 9, pois há 9 colunas e 9 asteriscos na linha central.
*/

#include <stdio.h>

int main(){
    int num, i, j;

    printf("Digite um numero impar: ");
    scanf("%d", &num);

    if (num % 2 == 1){
        for (i=1; i<=num; i+=2){
            for (j=1; j<=(num-i)/2; j++){
                printf(" ");
            }
            for (j=1; j<=i; j++){
                printf("*");
            }
            printf("\n");
        }
        for (i=1; i<=num-1; i+=2){
            for (j=num; j>=(num-i); j-=2){
                printf(" ");
            }
            for (j=(num-i)*2; j>=3; j-=2){
                printf("*");
            }
            printf("\n");
        }
    }
    else{
        printf("\nIsso e um digito par\n\n");
        return 0;
    }
    return 0;
}