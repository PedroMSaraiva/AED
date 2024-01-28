#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cruzamento de Listas: Dado duas listas vinculadas, determine 
// se elas se cruzam em algum ponto.

struct Node {
    int data;
    struct Node* next;
};

// Adiciona nos a lista
void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Pega o tamanho da lista
int getSize(struct Node* head){
    int size = 0;
    while (head != NULL){
        size++;
        head = head->next;
    }
    return size;
}

// Verofica se ha intersecção
struct Node* getIntersectionNode(struct Node* head1, struct Node* head2){
    int size1 = getSize(head1);
    int size2 = getSize(head2);
    int diff = abs(size1-size2);

    if (size1 > size2){
        for (int i=0; i < diff; i++){
            head1 = head1->next;
        }
    } else {
        for (int i = 0; i< diff; i++){
            head2 = head2->next;
        }
    }

    while (head1 != NULL && head2 != NULL){
        if (head1 == head2){
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

// Gera uma lista randomica para testar
void generateRandomList(struct Node** head, int size){
    for (int i = 0; i < size; i++){
        push(head, rand() % 1000);
    }
}

// A complexidade Big O é O(n)
int main(){
    srand(time(NULL));
    clock_t start, end;
    double cpu_time_used;

    FILE *file = fopen("Dados_cruzamento.csv","w");
    if (file == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(1);
    }


    for (int size = 1; size <= 100000; size++){
        struct Node* head1 = NULL;
        struct Node* head2 = NULL;
        struct Node* intersection = NULL;

        generateRandomList(&head1, size);

        int intersectionPoint = rand()%size;
        struct Node* temp = head1;
        for (int i = 0; i < intersectionPoint; i++){
            temp = temp->next;
        }
        intersection = temp;

        generateRandomList(&head2, intersectionPoint);
        struct Node* temp2 = head2;
        if (temp2 != NULL){
            while (temp2->next != NULL){
                temp2 = temp2->next;
            }
            temp2->next = intersection;
        }
    
        start = clock();
        struct Node* intersect_node = getIntersectionNode(head1, head2);
        end = clock();
        cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
        printf("Tempo para tamanho %d: %f segundos\n", size, cpu_time_used);
        fprintf(file, "%d, %f\n", size, cpu_time_used);

        struct Node* current;
        while (head1 != intersection) {
            current = head1;
            head1 = head1->next;
            free(current);
        }
        while (head1 != NULL) {
            current = head1;
            head1 = head1->next;
            free(current);
        }

        head2 = NULL;
        
    }
    fclose(file);
    return 0;
}