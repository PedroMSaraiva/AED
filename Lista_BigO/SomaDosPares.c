// Exercio da Lista Big O
//Soma dos Pares: Dado um array de números inteiros e um valor
//alvo, determine se existem dois números no array que somem o
//valor alvo.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void somaDosPares(int arr[], int numAlvo, int tamanho){
    int contador = 0;
    for (int i = 0; i < tamanho - 1; i++){
        int *ptr_i = arr + i;
        for (int j = i ; j < tamanho; j++){
            int *ptr_j = arr +j;
            if (*ptr_i + *ptr_j == numAlvo){
                printf("\nUma soma para o numero alvo é %d e %d", *ptr_i, *ptr_j);
                contador ++;
            }
        }
    }
    printf("\n\nFoi achado cerca de %d soluções", contador);
}

// O nivel de complexidade desse código é O(n**2)
int main(){
    srand(time(NULL));
    clock_t t;
    t = clock();

       
    int randomNumber = rand() % 100 + 1;
    printf("Numero aleatorio escolhihdo para ser testado: %d", randomNumber);


    int arr[101] = {0}; 
    int siz = (sizeof(arr) / sizeof(arr[0]));
    for (int h = 0; h < siz; h++){
        arr[h] = h;
    }
    somaDosPares(arr, randomNumber, siz);

    float diff = ((float)(clock() - t)) / CLOCKS_PER_SEC;
    printf("\n\n diff=%f \n\n", diff);

    return 0;
}