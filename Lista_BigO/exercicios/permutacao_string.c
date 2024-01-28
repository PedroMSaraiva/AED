#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*Permutações de Strings: Escreva um algoritmo para imprimir 
todas as permutações possíveis de uma string.*/

// Troca os caracteres
void swap(char* x, char* y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Gera as permutações possives
void generatePermutations(char* str, int start, int end){
    if (start == end){
        printf("%s\n", str);
    } else {
        for (int i = start; i <= end; i++){
            swap(&str[start], &str[i]);
            generatePermutations(str, start + 1, end);
            swap(&str[start], &str[i]);
        }
    }
}

// Gera strings randomicas
void generateRandomString(char *str, int size) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < size; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        str[i] = charset[key];
    }
    str[size] = '\0'; // Adiciona o caractere nulo no final para terminar a string
}

// A complexidade é O(n!) Isso ocorre porque ha recursão
int main() {
    srand(time(NULL)); // Inicialização do gerador de números aleatórios
    
    FILE *file = fopen("Dados_permutacao.csv","w");
    if (file == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for (int size = 1; size <= 10; size++) { // Altere o 10 para o tamanho máximo desejado
        char str[size + 1]; // +1 para o caractere nulo

        generateRandomString(str, size);

        //printf("String aleatória gerada: %s\n", str);

        clock_t start_time = clock(); // Início da medição de tempo

        generatePermutations(str, 0, size - 1);

        clock_t end_time = clock(); // Fim da medição de tempo

        double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Calcula o tempo gasto
        printf("%lf\n", time_spent);
        fprintf(file, "%d, %f\n", size, time_spent);
    }
    fclose(file);

    return 0;
}