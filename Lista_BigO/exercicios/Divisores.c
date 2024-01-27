#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Divisores de um Número: Liste todos os divisores de um 
// número inteiro dado.

int divisores(int num){
    int div[num];

    for (int i = 1; i <= num; i++){
        if (num % i == 0){
            printf("%d", i);
        }
    }

}
// Complexidade O(n)

int main(){
    srand(time(NULL));
    clock_t t;
    t = clock();

    FILE *file = fopen("Dados_divisores.csv","w");
    if (file == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for (int i = 0; i <= 100000; i++){
        t = clock();
        divisores(i);
        float diff = ((float)(clock() - t)) / CLOCKS_PER_SEC;
        printf("\n diff=%f \n", diff);
        fprintf(file, "%d, %f\n", i, diff);
    }
    fclose(file);


    return 0;
}