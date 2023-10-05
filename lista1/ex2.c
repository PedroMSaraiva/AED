/*
Crie um aplicativo bancário em C que pede o valor do depósito inicial, 
o valor do investimento mensal e o número de meses que o dinheiro vai ficar rendendo na poupança.
Após isso, calcule o lucro obtido, sabendo que os juros da poupança são de 0,5%.
*/

#include <stdio.h>

void main(){
    float valorInicial, valorInvestMensal, juros=1.05, soma;
    int numMeses, i = 1;


    printf("Digite o valor incial de investimento: ");
    scanf("%f", &valorInicial);
    printf("Digite o valor de investimento mensal: ");
    scanf("%f", &valorInvestMensal);
    printf("Digite o numero de meses que ficara rendendo: ");
    scanf("%d", &numMeses);

    soma = valorInicial;

    while (i<=numMeses){
        soma *= juros;
        soma += valorInvestMensal;
        
        printf("O valor do montante no mes %d: R$%.2f\n", i,soma);
        i++;
    }
    printf("O lucro obtido é de: R$%.2f\n\n", soma-(valorInicial+valorInvestMensal*numMeses));
}