#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*N-ésimo Elemento: Dado uma lista vinculada, encontre o n-
ésimo elemento a partir do final.*/

struct Node {
    int data;
    struct Node* next;
};


// Função para inserir um novo no no inicio da lista 
/*void push(struct Node** head, int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}*/

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}


/*
int findNthFromEnd(struct Node* head, int n){
    if (head == NULL || n <= 0){
        printf("Lista vazia ou valor de n inválido. \n");
        return -1;
    }

    struct Node* current = head;
    struct Node* current1 = head; 
    int lenght = 0;

    while (current != NULL){
        lenght++;
        current = current->next;
    }


    if (n > lenght){
        printf("A lista não contem pelo menos %d elementos. \n", n);
        return -1; // Valor invalido para indicar que houve erro
    }

    current = head;
    for (int i = 0; i < lenght - n; i++){
        current = current->next;
        printf("%d", current->data);
    }

    return current->data;
}*/

int findNthFromStart(struct Node* head, int n) {
    struct Node* current = head;
    int count = 1;
    
    // Verifica se a lista está vazia
    if (head == NULL) {
        printf("Lista vazia.\n");
        return -1;
    }

    // Percorre a lista até chegar ao n-ésimo nó
    while (current != NULL) {
        if (count == n) {
            return current->data;
        }
        count++;
        current = current->next;
    }

    // Se n for maior do que o número de nós, retorne -1
    printf("%d é maior do que o número de nós na lista.\n", n);
    return -1;
}




// Complexidade O(n)
int main() {
    srand(time(NULL));

    FILE *file = fopen("Dados_n_esimo.csv","w");
    if (file == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for (int size = 1; size <= 500000; size += 10) { // Aumenta o tamanho em 10 a cada iteração
        struct Node* head = NULL;

        // Preenchendo a lista vinculada com elementos aleatórios
        for (int i = 0; i < size; i++) {
            push(&head, rand() % 100); // Números aleatórios entre 0 e 99
        }

        int n = size / 2; // Selecionando o n-ésimo elemento a partir do final

        clock_t start_time = clock();
        int result = findNthFromStart(head, n);
        clock_t end_time = clock();

        double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        printf("Lista de tamanho %d, tempo para encontrar o %d-ésimo elemento a partir do final: %f segundos\n", size, n, time_spent);
        fprintf(file, "%d, %f\n", size, time_spent);

        // Liberando a lista vinculada
        struct Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
    }
    fclose(file);

    return 0;
}