#include <stdio.h>
#include <stdlib.h>

typedef struct  Elemento{
    int valor;
    struct Elemento* next;
} Elemento;


typedef struct Lista {
    Elemento* head;
} Lista;

Lista * criaLista(){ //Função que cria a lista
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    if (novaLista == NULL){
        printf("Erro: problema de alocação de memoria. \n");
        exit(1);
    }
    novaLista->head = NULL;
    return novaLista;
}

//verifica se a lista esta vazia
int vazia(Lista* list){
    return(list->head == NULL);
}

//Faz fica vazio
void flvazia(Lista *list){
    list->head = NULL;
}

void flvaziaLibera(Lista* list){
    Elemento* current = list->head;
    while (current != NULL){ //Percorre a lista liberando os elementos
        Elemento* temp = current;
        current = current->next;
        free(temp);
    }
    free(list); //Libera o resto da lista
}

void insereInicio(Lista* list, int valor) {
    Elemento *novoElemento = (Elemento*)malloc(sizeof(Elemento));
    if (novoElemento == NULL) { //Verifica se foi possivel alocar a memoria
        printf("Erro: falha na alocação de memória.\n");
        exit(1);
    }
    novoElemento->valor = valor; //Insere no inicio
    novoElemento->next = list->head;
    list->head = novoElemento;
}

void insereFim(Lista* list, int valor) {
    Elemento *novoElemento = (Elemento*)malloc(sizeof(Elemento));
    if (novoElemento == NULL) { //Verifica se foi possivel alocar a memoria
        printf("Erro: falha na alocação de memória.\n");
        exit(1);
    }
    novoElemento->valor = valor;
    novoElemento->next = NULL;

    if (vazia(list)) { //Verifica se a lista é vazia
        list->head = novoElemento;
    }
    else{
        Elemento* current = list->head;
        while(current->next != NULL){ //Percorre a lista ate o fim
            current = current->next;
        }
        current->next = novoElemento;
    }

}

void inserePos(Lista *list, int valor, int pos){
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    if (novoElemento == NULL) { //Verifica se foi possivel alocar a memoria
        printf("Erro: falha na alocação de memória.\n");
        exit(1);
    }
    novoElemento->valor = valor;

    if (pos == 0 || vazia(list)){ //Inse o valor no incio caso a lista seja vazia ou seja a primeira posicao desejada
        insereInicio(list, valor);
    }
    else{
        Elemento* current = list->head;
        for (int i = 0; i < pos - 1 && current->next; ++i) {
            current = current->next;
        }
        novoElemento->next = current->next;
        current->next = novoElemento; //Atribui o valor
    }
}

void insereAnt(Lista* list, int novoValor, int valorAlvo) {
    if (!list) return;
    
    // Se a lista está vazia ou o valor alvo é o primeiro, insere no início.
    if (vazia(list) || list->head->valor == valorAlvo) {
        insereInicio(list, novoValor);
        return;
    }

    Elemento* current = list->head;
    while (current->next != NULL && current->next->valor != valorAlvo) {
        current = current->next;
    }

    if (current->next == NULL) {
        // Valor alvo não encontrado na lista.
        printf("Valor alvo %d não encontrado na lista.\n", valorAlvo);
        return;
    }

    // Insere novo elemento antes do elemento com valorAlvo.
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    if (!novoElemento) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return;
    }
    novoElemento->valor = novoValor;
    novoElemento->next = current->next;
    current->next = novoElemento;
}

//Imprime a lista na tela
void imprime(Lista* list) {
    if (vazia(list)){
        printf("Lista vazia, não ha oque printar \n");
        return;
    }

    Elemento *current = list->head;
    if (current == NULL){
        printf("A lista esta vazia! \n");
    } else {
        while (current != NULL) { //Percorre a lista printando cada elemento
            printf("%d ", current->valor);
            current = current->next;
        }
    printf("\n");
    }
}


//remove o elemento no incio da lista
void removeInicio(Lista* list) {
    if (!vazia(list)) {
        Elemento* temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
}

//remove o elemento no fim da lista
void removeFim(Lista* list) {
    if (!vazia(list)) { // Verifica se a lista esta vazia ou o inicio é nulo
        if (list->head->next == NULL){
            free(list->head);
            list->head = NULL;
        }
        else{
            Elemento* current = list->head;
            while(current->next->next != NULL){
                current = current->next; //Percorre a lista ate chegar no final
            }
            free(current->next);
            current->next = NULL;
        }
    }
}

//retorna qual o elemento no inicio da lista
Elemento *elementoInicio(Lista *list){
    return list->head;
}

//retorna qual o  elemento no fim da lista
Elemento *elementoFim(Lista *list){
    if (vazia(list)){
        return NULL;
    }
    Elemento* current = list->head;
    while(current->next != NULL){ //Percorre a lista ate o final
        current = current->next;
    }
    return current;
}

//retorna qual o elemento na posicao solicitada
Elemento* elementoPosic(Lista *list, int posicao){
    Elemento* current = list->head;
    for(int i = 0; i < posicao && current; i++){
        current = current->next; //Percorre a lista ate a posicao desejada
    }
    return current;
}

int main() {
    //Esse codigo na main demonstra que as funções fazem oque foi pedido

    Lista* minhaLista = criaLista(); //Cria a lista
    printf("Lista esta vazia?: ");
    if (vazia(minhaLista) == 1){
        printf("Não\n");
    } else {
        printf("Sim\n");
    }
    printf("Inserindo Listas no início:\n"); // Demonstração que é possivel inserir elementos no inicio
    for (int i = 0; i < 10; i++) {
        insereInicio(minhaLista,i);
    }
    imprime(minhaLista);

    printf("Removendo o primeiro e ultimo elemento da Lista:\n"); //Demonstração que é possivel remover o primeiro e ultimo elemento da lista
    removeInicio(minhaLista);
    removeFim(minhaLista);
    imprime(minhaLista);

    printf("Inserindo Listas no final:\n"); // Demonstração que é possivel inserir elementos no fim
    for (int i = 10; i < 20; i++) {
        insereFim(minhaLista, i);
    }
    imprime(minhaLista);

    for (int i = 0; i < 12; i+=2){ // Demonstração que ele acha qualquer elemento na posição desejada
        printf("O elemento na posicao %d é %d\n", i, elementoPosic(minhaLista, i)->valor);
    }

    //Demonstracao de ele acha o primeiro e ultimo elemento da lista
    imprime(minhaLista);
    printf("O primeiro elemento da lista: %d\n", elementoInicio(minhaLista)->valor);
    printf("O ultimo elemento da lista: %d\n", elementoFim(minhaLista)->valor);
    imprime(minhaLista);

    for (int i = 0; i < 15; i+=2){ //Demonstração da inserção de elementos em posicões especificas
        inserePos(minhaLista, i*3, i); 
    }
    printf("Apos a insercção de elementos e algumas posicoes especificas\n");
    imprime(minhaLista);

    // Demonstração da inserção de um elemento antes de um outro elemento especifico
    printf("Inserindo o valor 0 antes do 12\n");
    insereAnt(minhaLista, 0, 12);
    printf("Inserindo o valor 0 antes do 18\n");
    insereAnt(minhaLista, 0, 18);
    printf("Inserindo o valor 0 antes do 16\n");
    insereAnt(minhaLista, 0, 16);
    imprime(minhaLista);

    //Aqui demonstra que esvazia a lista
    flvazia(minhaLista);
    imprime(minhaLista);

    flvaziaLibera(minhaLista);
    imprime(minhaLista);

    return 0;
}
