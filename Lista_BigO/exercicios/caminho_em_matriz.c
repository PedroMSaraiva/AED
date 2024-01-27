#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 100
#define COLS 100

typedef struct{
    int x, y; // Coordenadas da Celula
} Cell;

bool isValid(int x, int y, bool maze[ROWS][COLS], bool visited[ROWS][COLS]){
    return(x >= 0) && x < ROWS && y>= 0 && y < COLS && maze[x][y] && !visited[x][y];
}

bool findPath( bool maze[ROWS][COLS]){
    bool visited[ROWS][COLS] = {false};
    Cell queue[ROWS * COLS]; // Fila para BFS
    int front = 0, rear = 0; // Indices da Fila

    // Inicializar com a celula (0,0)
    queue[rear].x = 0;
    queue[rear].y = 0;
    rear++;

    // Vetores de deslocamento 
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    visited[0][0] =  true;

    while (front < rear){
        Cell current = queue[front];
        front++;

        // Verifique se chegou ao destino
        if (current.x == ROWS - 1 && current.y == COLS - 1){
            for (int h = 0; h < ROWS+7; h++){
                printf("─");
            }
            printf("\n");
            for(int i = 0; i < ROWS; i++){
                printf("│︎");
                for(int j = 0; j < COLS; j++){
                    printf("%d ", visited[i][j]);
                }
                printf("│︎\n");
            }
            for (int h = 0; h < ROWS+7; h++){
                printf("─");
            }
            printf("\n");
            return true; // Caminho encontrado
        }

        // Explorar as 4 direções
        for(int i = 0; i < 4; i++){
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if ( isValid(newX, newY, maze, visited)){
                // Marcar como visitada
                visited[newX][newY] = true;
                queue[rear].x = newX;
                queue[rear].y = newY;
                rear++;
            }
        }
    }
    return false; // Nenhum caminho encontrado
 }

// Função para gerar um labirinto aleatório
void generateRandomMaze(bool maze[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = rand() % 2;  // Gera 0 ou 1 aleatoriamente
        }
    }
    // Garantir que a entrada [0][0] e a saída [rows-1][cols-1] sejam true (caminho livre)
    maze[0][0] = true;
    maze[rows - 1][cols - 1] = true;
}


// Complexidade é O(n) sendo n = numero de colunas/linhas
int main() {
    srand(time(NULL));  // Inicialização do gerador de números aleatórios

    bool maze[ROWS][COLS];  // Definindo a matriz do labirinto

    FILE *file = fopen("Dados_caminho_em_matriz.csv","w");
    if (file == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(1);
    }

    // Loop para aumentar o tamanho do labirinto
    for (int size = 5; size <= ROWS; size++) {  // Incremento de 5 para exemplo
        for (int i = 0; i <= 3; i++){
        generateRandomMaze(maze, size, size);  // Gerando labirinto com tamanho atual

        clock_t start = clock();
        if (findPath(maze)) {
            printf("Caminho encontrado no Labirinto de tamanho %dx%d. \n", size, size);
        } else {
            printf("Nenhum caminho encontrado no Labirinto de tamanho %dx%d. \n", size, size);
        }
        clock_t end = clock();
        double time_spent = ((double) (end - start)) / CLOCKS_PER_SEC;
        fprintf(file, "%d, %f\n", size, time_spent);
        }
    }


    fclose(file);

    return 0;
}