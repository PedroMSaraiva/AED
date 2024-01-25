#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Multiplicação de Matrizes: Implemente um algoritmo para 
// multiplicar duas matrizes.

#define MAX_DIM 100


// Nivel de complexidade do codigo é O(n^3)
int multiplicacaoMatrizes(int arr1[MAX_DIM][MAX_DIM], int arr2[MAX_DIM][MAX_DIM], int len1_linha, int len1_coluna, int len2_linha, int len2_coluna){
    int matriz_resultante[len1_linha][len2_coluna];
    if (len1_coluna == len2_linha){
        int matriz_resultante[MAX_DIM][MAX_DIM] = {{0}};
        
        for (int i = 0; i < len1_linha; i++){
            for (int j = 0; j < len2_coluna; j++){
                for (int k = 0; k < len1_coluna; k++){
                    matriz_resultante[i][j] += arr1[i][k] * arr2[k][j];  
                } 
            }
        }
        for (int i = 0; i< 3; i++){
            for (int j = 0; j<3;j++){
                printf("%d ", matriz_resultante[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("Essas matrizes não podem ser multiplicadas");
    }

    return 1;
}

int main(){
    srand(time(NULL));
    clock_t t;
    t = clock();

    int matriz1[MAX_DIM][MAX_DIM] = {{1,2,3},{4,5,6},{7,8,9}};
    int matriz2[MAX_DIM][MAX_DIM] = {{9,8,7},{6,5,4},{3,2,1}};

    size_t len1_linha = sizeof(matriz1)/sizeof(matriz1[0]);
    size_t len1_coluna = sizeof(matriz1[0])/sizeof(matriz1[0][0]);

    size_t len2_linha = sizeof(matriz2)/sizeof(matriz2[0]);
    size_t len2_coluna = sizeof(matriz2[0])/sizeof(matriz2[0][0]);

    multiplicacaoMatrizes(matriz1, matriz2, len1_linha, len1_coluna, len2_linha, len2_coluna);

    float diff = ((float)(clock() - t)) / CLOCKS_PER_SEC;
    printf("\n\n diff=%f \n\n", diff);

    return 0;
}