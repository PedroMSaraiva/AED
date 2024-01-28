// Exercio da Lista Big O
//Soma dos Pares: Dado um array de números inteiros e um valor
//alvo, determine se existem dois números no array que somem o
//valor alvo.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Verifica se dois elementos somados dão o elemento alvo
void somaDosPares(int arr[], int numAlvo, int tamanho){
    int contador = 0;
    for (int i = 0; i < tamanho - 1; i++){
        int *ptr_i = arr + i;
        for (int j = i ; j < tamanho; j++){
            int *ptr_j = arr +j;
            if (*ptr_i + *ptr_j == numAlvo){
                // printf("\nUma soma para o numero alvo é %d e %d", *ptr_i, *ptr_j);
                contador ++;
            }
        }
    }
    // printf("\n\nFoi achado cerca de %d soluções", contador);
}

// O nivel de complexidade desse código é O(n**2)
// Função para gerar um array ordenado de inteiros
void generateOrderedArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i; // ou outra lógica, se necessário
    }
}

int main() {
    FILE *file = fopen("Dados_somadospares.csv","w");
    if (file == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(1);
    }
    // Aumentar o tamanho do array em cada iteração e medir o tempo
    for (int size = 2; size <= 100000; size++) { // Por exemplo, dobrando o tamanho do array a cada iteração
        int* arr = malloc(size * sizeof(int)); // Alocando espaço para o array
        if (!arr) {
            printf("Falha na alocação de memória\n");
            exit(1);
        }

        generateOrderedArray(arr, size); // Preenchendo o array com números ordenados

        // Gerando um número alvo aleatório
        int randomNumber = rand() % (size * 2) + 1; // Garantindo que o número alvo seja alcançável
        printf("Numero aleatorio escolhido para ser testado: %d\n", randomNumber);

        clock_t t = clock();
        somaDosPares(arr, randomNumber, size);
        float diff = ((float)(clock() - t)) / CLOCKS_PER_SEC;
        fprintf(file, "%d, %f\n", size, diff);
        printf("Tamanho do array: %d, Tempo de execução: %f segundos\n", size, diff);

        free(arr); // Liberando a memória alocada para o array
    }
    fclose(file);
    return 0;
}