#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Elemento Mais Frequente: Encontre o elemento mais frequente 
// em um array de inteiros.


int elementoMaisFrequente(int *arr, int len){
    int elementoFrequente;
    int maiorFrequencia = 1;
    for (int i = 0; i <= len; i++){
        int contador_i = 1;
        for (int j = i+1; j<= len; j++){
            if (arr[i] == arr[j]){
                contador_i += 1;
            }
        }
        if (contador_i > maiorFrequencia){
            maiorFrequencia = contador_i;
            elementoFrequente = arr[i];
        }
    }
    return elementoFrequente;
}
// O nivel de complexidade desse código é O(n**2)
int main() {
    FILE *file = fopen("Dados_elementoMaisFrequente.csv","w");
    if (file == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(1);
    }
    srand(time(NULL));  // Inicialização do gerador de números aleatórios

    for (int size = 1; size <= 10000; size++) {  // Incremento de tamanho do array
        int* arr = malloc(size * sizeof(int)); // Alocação dinâmica do array
        if (arr == NULL) {
            printf("Falha na alocação de memória\n");
            return 1;
        }

        // Preenchendo o array com números aleatórios
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 20 + 1; // Números aleatórios entre 1 e 20
        }

        clock_t t = clock(); // Início da medição de tempo

        int x = elementoMaisFrequente(arr, size);
        printf("\nO elemento mais frequente é: %d", x);

        float diff = ((float)(clock() - t)) / CLOCKS_PER_SEC; // Cálculo do tempo de execução
        fprintf(file, "%d, %f\n", size, diff);

        free(arr); // Liberando o array
    }
    fclose(file);

    return 0;
}