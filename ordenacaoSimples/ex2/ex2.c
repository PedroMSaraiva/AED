#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Exercício 2: Quick Sort com Pivôs Diferentes 
 Implemente o algoritmo Quick Sort. Experimente com diferentes métodos de escolha 
de pivô (por exemplo, sempre o primeiro elemento, o elemento central, ou um 
elemento aleatório) e veja como a escolha do pivô afeta o desempenho do algoritmo 
em diferentes conjuntos de dados.*/

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // Pivô
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor que o pivô
        if (arr[j] < pivot) {
            i++;    // Incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int partitionRandom(int arr[], int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);

    // Troca o elemento aleatório com o último para usar a mesma lógica de partição
    swap(&arr[random], &arr[high]);

    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função de partição usando o primeiro elemento como pivô
int partitionFirstElement(int arr[], int low, int high) {
    int pivot = arr[low];  // Pivô é o primeiro elemento
    int i = low + 1;       // Começa a partir do elemento seguinte ao pivô

    for (int j = i; j <= high; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;  // Move o índice para a próxima posição
        }
    }
    swap(&arr[low], &arr[i - 1]);  // Coloca o pivô na posição correta
    return (i - 1);  // Retorna a posição do pivô
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Separadamente, ordena os elementos antes e depois da partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSortRandom(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionRandom(arr, low, high);

        // Separadamente, ordena os elementos antes e depois da partição
        quickSortRandom(arr, low, pi - 1);
        quickSortRandom(arr, pi + 1, high);
    }
}

void quickSortFirst(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionFirstElement(arr, low, high);

        // Separadamente, ordena os elementos antes e depois da partição
        quickSortFirst(arr, low, pi - 1);
        quickSortFirst(arr, pi + 1, high);
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

    FILE *file = fopen("Dados_quickSort.csv","w");
    if (file == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for (int i = 5; i < 10000; i++){
        int* randomArray1 = generateRandomArray(i);
        int* randomArray2 = generateRandomArray(i);
        int* randomArray3 = generateRandomArray(i);

        clock_t start1 = clock();
        quickSort(randomArray1, 0, i-1);
        clock_t end1 = clock();
        double time_spent1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;

        clock_t start2 = clock();
        quickSortRandom(randomArray2, 0, i-1);
        clock_t end2 = clock();
        double time_spent2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;

        clock_t start3 = clock();
        quickSortFirst(randomArray3, 0,i-1);
        clock_t end3 = clock();
        double time_spent3 = ((double) (end3 - start3)) / CLOCKS_PER_SEC;

        fprintf(file, "%d, %f, %f, %f\n", i, time_spent1, time_spent2, time_spent3);

        free(randomArray1);
        free(randomArray2);
        free(randomArray3);
    }

    return 0;
}
