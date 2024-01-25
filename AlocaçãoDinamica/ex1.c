#include <stdio.h>
#include <stdlib.h>

// Por Pedro Saraiva - 202303358

/*
Crie   uma   estrutura   que   represente   uma   pessoa, contendo   nome,  data   de 
nascimento  e  CPF.  Crie uma variável que é um ponteiro para esta  estrutura  (no 
programa  principal).  Depois crie uma função que receba este ponteiro  e  preencha  
os dados da estrutura e também uma função que receba este ponteiro e imprima os 
dados da estrutura. Na função principal pergunte ao usuário o número n de pessoas a 
serem representadas e utilize  "n"  para  alocar  a  memória  para  seu  ponteiro  de 
estrutura.  Ao final  das  chamadas  das  funções,  não  esqueça  de  liberar  a  memória 
alocada!
*/

// Definição da struct Pessoa
typedef struct{
    char nome[100];
    char cpf[15]; 
    char data[11]; // DD-MM-AAAA
} Pessoa;

// Função que preenche as informações das pessoas
void preencherpessoa(Pessoa *p){
    printf("Digite o nome: ");
    scanf("%s", p->nome);
    printf("Digite o CPF: ");
    scanf("%s", p->cpf);
    printf("Digite a Data de nascimento: ");
    scanf("%s", p->data);
}

// Função que imprime os dados das pessoas
void printarpessoa(Pessoa *p){
    printf("Nome: %s\n", p->nome);
    printf("CPF: %s\n", p->cpf);
    printf("Data: %s\n", p->data);
}


int main(){
    int n; 
    printf("Digite o numero de pessoas: ");
    scanf("%d", &n);
    // Pega o numero de pessoas a serem criadas

    Pessoa *pessoas = (Pessoa *)malloc(n*sizeof(Pessoa));
    // Alocacao de memoria

    if (pessoas==NULL){
        printf("\nHouve problema na alocação de memoria!");
        return 1;
    } // Verifica se esta tudo ok

    for (int i=0; i < n; i++){
        printf("\nPessoa %d: \n", i+1);
        preencherpessoa(&pessoas[i]);
    } // Faz oque é pedido no enunciado

    for (int i=0; i < n; i++){
        printf("\nPessoa %d: \n", i+1);
        printarpessoa(&pessoas[i]);
    }
    // E possivel juntar os dois for, mas por questões esteticas deixarei assim

    free(pessoas);
    // Libera a memoria


    return 0;
}