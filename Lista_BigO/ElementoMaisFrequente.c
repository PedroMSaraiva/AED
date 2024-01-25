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
int main(){
    srand(time(NULL));
    clock_t t;
    t = clock();

       
    int randomNumber1 = rand() % 20 + 1;
    printf("Tamanho do array:\n %d\n", randomNumber1);


    int arr[randomNumber1]; 
    for (int i = 0; i <= randomNumber1; i++){
        int randomNumber2 = rand() % 20 + 1;
        arr[i] = randomNumber2;
    }

    for (int i = 0; i < randomNumber1; ++i) {
        printf("%d ", arr[i]);
    }

    int x = elementoMaisFrequente(arr, randomNumber1);
    printf("\nO elemento mais frequente é: %d", x);

    float diff = ((float)(clock() - t)) / CLOCKS_PER_SEC;
    printf("\n\n diff=%f \n\n", diff);

    return 0;
}