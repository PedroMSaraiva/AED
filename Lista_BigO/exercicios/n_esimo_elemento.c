#include <stdio.h>
#include <stdlib.h>

/*N-ésimo Elemento: Dado uma lista vinculada, encontre o n-
ésimo elemento a partir do final.*/

struct Node {
    int data;
    struct Node* next;
};


// Função para inserir um novo no no inicio da lista 
void push(struct Node** head, int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

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
}


// Complexidade O(n)
int main(){
    struct Node* head = NULL;
    int n, data;

    printf("Quantos elementos deseja adicionar á lista vinculada?");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("Digite o valor do elemento %d: ", i+1);
        scanf("%d", &data);
        push(&head, data);
    }

    //Perguntamos pelo valor de n
    printf("Digite o valor de n-esimo elemento para encontrarmos a partir do final: ");
    scanf("%d", &n);

    int result = findNthFromEnd(head, n);
    if (result != -1){
        printf("O %d-ésimo elemento a partir do final é: %d\n", n, result);
    }

    return 0;
}