#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Multiplicação de Matrizes: Implemente um algoritmo para 
// multiplicar duas matrizes.

#define MAX_DIM 500


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
                // printf("%d ", matriz_resultante[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("Essas matrizes não podem ser multiplicadas");
    }

    return 1;
}

// Função para gerar uma matriz aleatória de tamanho `linhas` x `colunas`
void gerarMatrizAleatoria(int matriz[MAX_DIM][MAX_DIM], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 100; // Gera números aleatórios de 0 a 9
        }
    }
}

// Nivel de complexidade do codigo é O(n^3)
int main() {
    srand(time(NULL));

    FILE *file = fopen("Dados_multiplicacao.csv","w");
    if (file == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for (int size = 1; size <= MAX_DIM; size++) {
        int matriz1[MAX_DIM][MAX_DIM], matriz2[MAX_DIM][MAX_DIM];

        gerarMatrizAleatoria(matriz1, size, size);
        gerarMatrizAleatoria(matriz2, size, size);

        clock_t t_inicio = clock();
        
        multiplicacaoMatrizes(matriz1, matriz2, size, size, size, size);

        clock_t t_fim = clock();

        float diff = ((float)(t_fim - t_inicio)) / CLOCKS_PER_SEC;
        fprintf(file, "%d, %f\n", size, diff);
        printf("Tempo para multiplicação de matrizes %dx%d: %f segundos\n", size, size, diff);
    }
    fclose(file);

    return 0;
}