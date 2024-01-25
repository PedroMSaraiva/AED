#include <stdio.h>
#include <string.h>

int contaSubstringsUnicas(char str[], int tamanho) {
    int caractereIndex[256]; // Armazena o índice mais recente de cada caractere na string
    memset(caractereIndex, -1, sizeof(caractereIndex)); // Inicializa todos os índices como -1

    int resultado = 0; // Número total de substrings únicas
    int inicio = 0; // Início da janela deslizante

    for (int fim = 0; fim < tamanho; fim++) {
        inicio = (caractereIndex[str[fim]] >= inicio) ? caractereIndex[str[fim]] + 1 : inicio;

        resultado += (fim - inicio + 1);

        caractereIndex[str[fim]] = fim;
    }

    return resultado;
}

int main() {
    char str[] = "abcabcbb";
    int tamanho = strlen(str);

    int resultado = contaSubstringsUnicas(str, tamanho);

    printf("O número de substrings únicas é: %d\n", resultado);

    return 0;
}
