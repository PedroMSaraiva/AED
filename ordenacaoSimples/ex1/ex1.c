#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*Exercício 1: Comparação de Algoritmos 
 Implemente os algoritmos Bubble Sort, Insertion Sort e Selection Sort. Em seguida, crie 
um conjunto de dados (pode ser um array com números aleatórios) e use este mesmo 
conjunto para ordenar com cada um dos algoritmos. Meça o tempo de execução de 
cada algoritmo e compare seus desempenhos. Discuta em quais cenários cada 
algoritmo seria mais eficiente. */

void bubbleSort(int* array, int size) {
    for (int step = 0; step < size - 1; ++step) {
        int swapped = 0;
        for (int i = 0; i < size - step - 1; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}


void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

// Função para gerar um array de inteiros aleatórios
int* generateRandomArray(int size) {
    // Aloca memória para o array
    int* array = (int*)malloc(size * sizeof(int));

    // Verifica se a alocação de memória foi bem-sucedida
    if (array == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1); // Encerra o programa se a alocação de memória falhar
    }

    // Preenche o array com números aleatórios
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100; // Gera um número aleatório entre 0 e 99
    }

    return array; // Retorna o ponteiro para o array
}


// Função para imprimir o array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    FILE *file = fopen("Dados_ordenacao.csv","w");
    if (file == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for (int i = 5; i < 10000; i++){
        int* randomArray1 = generateRandomArray(i);
        int* randomArray2 = generateRandomArray(i);
        int* randomArray3 = generateRandomArray(i);

        clock_t start1 = clock();
        // O(n) no melhor cenário e O(n²) no pior cenário.
        bubbleSort(randomArray1, i); // Chama a função Bubble Sort
        clock_t end1 = clock();
        double time_spent1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;

        clock_t start2 = clock();
        // O(n) no melhor cenário e O(n²) no pior cenário.
        insertionSort(randomArray2, i); // Chama a função Insertion Sort
        clock_t end2 = clock();
        double time_spent2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;

        clock_t start3 = clock();
        // O(n²) tanto no melhor quanto no pior cenário.
        selectionSort(randomArray3, i); // Chama a função Selection Sort
        clock_t end3 = clock();
        double time_spent3 = ((double) (end3 - start3)) / CLOCKS_PER_SEC;

        fprintf(file, "%d, %f, %f, %f\n", i, time_spent1, time_spent2, time_spent3);

        free(randomArray1);
        free(randomArray2);
        free(randomArray3);
    }

    return 0;
}