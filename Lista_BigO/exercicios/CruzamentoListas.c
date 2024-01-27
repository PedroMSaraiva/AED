#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cruzamento de Listas: Dado duas listas vinculadas, determine 
// se elas se cruzam em algum ponto.

int cruzamentoListas(){
    
    return 1;
}

int main(){
    srand(time(NULL));
    clock_t t;
    t = clock();

    cruzamentoListas();

    float diff = ((float)(clock() - t)) / CLOCKS_PER_SEC;
    printf("\n\n diff=%f \n\n", diff);

    return 0;
}