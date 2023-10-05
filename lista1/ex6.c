/* 
Crie uma função capaz de multiplicar uma linha de uma matriz por um dado número.
Faça o mesmo para uma coluna.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    int multi, tamanhoMatrizI, tamanhoMatrizL, escolha, posicao, i, l, number;

    printf("Escolha o tamanho das dimensões da matriz\nNumero de colunas: ");
    scanf("%d",&tamanhoMatrizI);
    printf("Numero de linhas: ");
    scanf("%d", &tamanhoMatrizL);

    tamanhoMatrizI -= 1;
    tamanhoMatrizL -= 1;
    srand(time(NULL));

    int matriz[tamanhoMatrizI][tamanhoMatrizL];
    for (i=0; i<=tamanhoMatrizI; i++){
        for (l=0; l<=tamanhoMatrizL; l++){
            matriz[i][l] = rand()%100; //Estabeleci (por questões esteticas) um limite ate 100 dos numeros aleatorios
            printf("%d\t", matriz[i][l]);
        }
        printf("\n");
    }


    printf("\n\nVocê quer multiplicar uma coluna(1) ou uma linha(2): ");
    scanf("%d", &escolha);
    printf("\nPor qual numero você quer multiplicar? ");
    scanf("%d", &multi);
    
    if (escolha == 1){
        printf("Qual coluna você quer multiplicar?");
        scanf("%d",&posicao);
        posicao -= 1;
        for (i=0; i<=tamanhoMatrizI; i++){
            matriz[i][posicao] *= multi;
            printf("%d", matriz[i][posicao]);
        } 
    }else{
        printf("Qual linha você quer multiplicar?");
        scanf("%d",&posicao);
        posicao -= 1;
        for (l=0; l<=tamanhoMatrizL; l++){
            matriz[posicao][l] *= multi;
            printf("%d", matriz[posicao][i]);
        } 
    }
    
    for (int k=0; k<=tamanhoMatrizI; k++){
        for (int x=0; x<=tamanhoMatrizL; x++){
            printf("%d\t", matriz[k][x]);
        }
        printf("\n");
    }
}