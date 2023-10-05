#include <stdio.h>

void main(){
    int myNum;
    float myFloatNum;
    char myLetter;

    printf("Digite o seu numero inteiro: ");
    scanf("%d", &myNum);
    printf("\nDigite o seu numero float: ");
    scanf("%f", &myFloatNum);
    printf("\nDigite a sua letra: ");
    scanf("%c", &myLetter);

    printf("\nSeu numero inteiro é: %d\nSeu numero floar é: %f\nSua letra é:%c", myNum, myFloatNum, myLetter);
}