/* Faça um programa que crie um vetor de pessoas. 
Os dados de uma pessoa devem ser armazenados em uma variável do tipo struct. 
O programa deve permitir que o usuário digite o nome de 3 pessoas e a seguir imprime os dados 
de todas as pessoas. A struct deve armazenar os dados de idade, peso e altura. */

#include <stdio.h>

struct Pessoa
{
    int idade;
    float peso;
    float altura;
};
typedef struct Pessoa Pessoa;

void CriaVetor ();

Pessoa CriaPessoa(Pessoa A){

    printf("Digite a altura: ");
    scanf("%f", &A.altura);
    printf("Digite a idade: ");
    scanf("%d", &A.idade);
    printf("Digite o peso: ");
    scanf("%f", &A.peso);
    printf("\n");

    return A;
}

void PrintaPessoa(Pessoa A){
    printf("\nAltura: %.2f", A.altura);
    printf("\nIdade: %d", A.idade);
    printf("\nPeso: %.2f", A.peso);
};

void main(){ //TENHO QUE MELHORAR ESSES FILHA DA PUTA, CODIGO FEIO
    printf("Digite os dados da primeira pessoa\n");
    Pessoa Pessoa1 = CriaPessoa(Pessoa1);
    printf("Digite os dados da segunda pessoa\n");
    Pessoa Pessoa2 = CriaPessoa(Pessoa2);
    printf("Digite os dados da terceira pessoa\n");
    Pessoa Pessoa3 = CriaPessoa(Pessoa3);

    printf("__________________________________");
    
    printf("\nDados da primeira pessoa");
    PrintaPessoa(Pessoa1);
    printf("\n\nDados da segunda pessoa");
    PrintaPessoa(Pessoa2);
    printf("\n\nDados da terceira pessoa");
    PrintaPessoa(Pessoa3);
    printf("\n\n");
}