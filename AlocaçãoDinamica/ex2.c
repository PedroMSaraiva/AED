#include <stdio.h>
#include <stdlib.h>

// Por Pedro Saraiva - 202303358

/*
Faça um programa que leia do teclado os dados de n alunos. Utilize vetor de registro 
para  armazenar  os  dados de  cada  aluno.  Esse  vetor  deve  ser  obtido  através  de  
uma alocação  dinâmica,  a  partir  do  valor  de  n  informado  pelo  usuário. O  registro  
contém NumMat  (tipo  inteiro) e  um  vetor  de  reais  de  tamanho  3 chamado 
NOTAS. Ao final, imprima seus dados, seguido da média das três notas de cada aluno e  
sua situação (aprovado – média>=7, reprovado – média < 3, exame final – média entre 
3 e 6);
*/

typedef struct{
    int NumMat;
    float NOTAS[3];
}Aluno;


int main(){
    int n;
    printf("Digite o numero de alunos: ");
    scanf("%d", &n);
    // Pega o numero de alunos

    Aluno *alunos = (Aluno *) malloc(n*sizeof(Aluno));
    // Aloca memoria e verifica se não houve problema
    if (alunos==NULL){
        printf("Problema na alocação de memoria!");
        return 1;
    }

    for (int i = 0; i < n; i++){ // Preenche as informações dos alunos
        printf("\nAluno %d\n", i+1);
        printf("Digite a matricula do aluno: ");
        scanf("%d",&alunos[i].NumMat); // Recebe a matricula do aluno

        printf("Digite as 3 notas do aluno: ");
        for (int j = 0; j < 3; j++){
            scanf("%f", &alunos[i].NOTAS[j]);
        }
    }

    // Mostra as informações dos alunos
    printf("\nInformações dos Alunos\n");
    for (int i = 0; i < n; i++){
        printf("\n Dados do Aluno %d:\n", i+1);
        printf("Numero de Matricula: %d\n", alunos[i].NumMat);
        printf("Notas: %.2f ; %.2f ; %.2f\n", alunos[i].NOTAS[0], alunos[i].NOTAS[1], alunos[i].NOTAS[2]);
        
        float media = (alunos[i].NOTAS[0] + alunos[i].NOTAS[2] + alunos[i].NOTAS[2]) / 3.0;
        printf("Media do Aluno: %.2f\n" ,media);

        if (media >= 7){
            printf("Situação: APROVADO\n");
        } else if (media < 3) {
            printf("Situação: REPROVADO\n");
        } else{
            printf("Situação: EXAME FINAL\n");
        }
    }


    free(alunos); // Liberar memoria

    return 0;
}