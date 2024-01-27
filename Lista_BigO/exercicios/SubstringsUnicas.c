#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Substrings Únicas: Dado uma string, encontre o número de 
// substrings únicas.

int isUniqueSubstring(char *start, int len, char **uniqueSubstrings, int count){
    for (int i = 0; i < count; i++){
        if (strncmp(uniqueSubstrings[i], start, len) == 0){
            return 0; // Substring não é unica
        }
    }
    return 1; // A substring é unica
}

int countUniqueSubstrings(char *str){
    int lenght = strlen(str);
    int count = 0;
    char **uniqueSubstrings = malloc(lenght*lenght*sizeof(char*));
    
    for (int i = 0; i < lenght; i++){
        for (int len = 1; len <= lenght - i; len++){
            if(isUniqueSubstring(&str[i], len, uniqueSubstrings, count)){
                uniqueSubstrings[count] = malloc((len+1)*sizeof(char));
                strncpy(uniqueSubstrings[count], &str[i], len);
                uniqueSubstrings[count][len] = '\0';
                count++;
            }
        }
    }

    for (int i = 0; i < count; i++){
        free(uniqueSubstrings[i]);
    }
    free(uniqueSubstrings);

    return count;
}


// Função para gerar uma string aleatória de um dado tamanho
void generateRandomString(char* str, int size) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyz"; // Definindo o conjunto de caracteres permitidos
    for (int i = 0; i < size; ++i) {
        int key = rand() % (int)(sizeof(charset) - 1);
        str[i] = charset[key];
    }
    str[size] = '\0'; // Adicionando o terminador de string
}
/* Complexidade Big O(n^3), sendo n o tamanho do input, isso ocorre
porque a função countUniqueSubstrings tem dois for juntos que leva um if,
esse if chama isUniqueSubstring que possui um for, então na verdade são 3 for juntos
por conta disso dizemos que é n^3*/




int main() {
    srand(time(NULL)); // Inicialização do gerador de números aleatórios
    clock_t t;
    t = clock();

    FILE *file = fopen("Dados_substringunicas.csv","w");
    if (file == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(1);
    }



    int MAX_SIZE = 100000; // Definir o tamanho máximo da string
    char str[MAX_SIZE + 1]; // +1 para o terminador de string

    for (int i = 0; i <= MAX_SIZE; i++){
    // Gerar uma string aleatória e contar as substrings únicas
        t = clock();
        generateRandomString(str, i);
        printf("String gerada: %s\n", str);
        printf("Numero de substrings unicas: %d\n", countUniqueSubstrings(str));
        float diff = ((float)(clock() - t)) / CLOCKS_PER_SEC;
        printf("\n diff=%f \n", diff);
        fprintf(file, "%d, %f\n", i, diff);
    }
    fclose(file);
    return 0;
}