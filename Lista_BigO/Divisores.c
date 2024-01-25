#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Divisores de um Número: Liste todos os divisores de um 
// número inteiro dado.

int divisores(int num){
    int div[num];

    for (int i = 1; i <= num; i++){
        if (num % i == 0){
            printf("%d\n", i);
        }
    }

}

int main(){
    srand(time(NULL));
    clock_t t;
    t = clock();

    
    divisores(10);

    float diff = ((float)(clock() - t)) / CLOCKS_PER_SEC;
    printf("\n\n diff=%f \n\n", diff);

    return 0;
}