#include <stdio.h>

/* 
Pequeno comentario, para comentar é so usar "//"
A função main execute o codigo, todo o codigo deve estar dentro dela
Como ha "int" antes de main(), no final, devera retornar um valor inteiro
Não é necessario colocar "return 0" no final, se for "void main()"/ Void -> Vazio 
*/

int main() {
  int num; // Declaração de variaveis de entrada
  int cubo;

  printf("\tHello World!\n\n");
  printf("\tThis is my first C program.\n\n");

  //Calculadora de cubo
  printf("Digite um numero: ");
  scanf("%d", &num);
  cubo = num*num*num;
  printf("\nCubo de %d -> %d\n\n", num, cubo);

  return 0;  // Declaração de variavel de saída
} 