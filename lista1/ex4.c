/*
Crie um programa capaz de ler os dados de uma matriz quadrada de inteiros.
Ao final da leitura o programa deverá imprimir o número da linha que contém o menor dentre todos
os números lidos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    int tamanhoMatriz, i, l, menorI, menorL, number, menorValor;

    printf("Esse algoritmo mostra qual o menor valor de uma matriz quadrada gerada aleatoriamente\n");
    printf("Escolha qual o tamanho da matriz a ser analizada: ");
    scanf("%d", &tamanhoMatriz);
    printf("\n\n");
    tamanhoMatriz -= 1;
    srand(time(NULL)); //gera a seed para valores aleatorios

    //Gera o uma matriz do tamanho escolhido com os elemento em valores aleatorios de 0 a 100
    int matriz[tamanhoMatriz][tamanhoMatriz];
    for (i=0; i<=tamanhoMatriz; i++){
        for (l=0; l<=tamanhoMatriz; l++){
            number = rand()%100; //Estabeleci (por questões esteticas) um limite ate 100 dos numeros aleatorios
            matriz[i][l] = number;
            printf("%d\t", number);
        }
        printf("\n");
    }
    printf("\n\n");

    // Declaracao das variaveis inicializadas para comparação
    menorValor = matriz[0][0];
    menorI = 0;
    menorL = 0;

    // Loops com dois "fors" para percorrer a matriz e comparar os valores.
    for (i=0; i<=tamanhoMatriz; i++){
        for (l=0; l<=tamanhoMatriz; l++){
            // Se o valor for menor, ele salva o novo elemente menor, senão o loop continua.
            if (matriz[i][l] < menorValor){ 
                menorValor = matriz[i][l];
                menorI = i;
                menorL = l;
            }
            else{
                continue;
            }
        }
    }
    printf("O menor valor na matriz e %d, estando na posição[%d][%d].\n\n", menorValor, menorI, menorL);
}

/* 
Esse codigo, ate o momento que foi desenvolvido pode contar elementos menores repetidos
e suas respectivas posições.
*/