#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Verifica se o array possui elementos que estao crescendo
bool isIncreasing(int arr[], int size){
    int count = 0;

    for (int i = 1; i < size; i++){
        if(arr[i] < arr[i - 1]){
            count++;
        }
        if (count > 1){
            return false;
        }
    }
    if (count <= 1){
        return true;
    }
}

// Função para gerar um array aleatório de um tamanho específico
void generateRandomArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Números aleatórios entre 0 e 99
    }
}

// Complexidade O(n)
int main() {
    // Inicializar o gerador de números aleatórios
    srand(time(NULL));

    FILE *file = fopen("Dados_ordenamento.csv","w");
    if (file == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(1);
    }

    // Variar o tamanho do array de inputs aleatórios e medir o tempo de execução
    for (int size = 1; size <= 100000; size++) { // Exemplo: Tamanhos de array dobram a cada iteração
        int* arr = (int*)malloc(size * sizeof(int)); // Alocar memória para o array
        if (!arr) {
            printf("Falha na alocação de memória\n");
            exit(1);
        }
        
        generateRandomArray(arr, size); // Preencher o array com números aleatórios

        // Medir o tempo de execução de isIncreasing
        clock_t start = clock();
        if (isIncreasing(arr, size)) {
            printf("É possível obter uma sequência crescente removendo um elemento\n");
        } else {
            printf("Não é possível obter uma sequência crescente removendo um elemento\n");
        }
        clock_t end = clock();

        // Calcular e imprimir o tempo de execução
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC; // Tempo em milissegundos
        printf("\n diff=%f \n", time_spent);
        fprintf(file, "%d, %f\n", size, time_spent);


        free(arr); // Liberar a memória alocada
    }
    fclose(file);

    return 0;
}