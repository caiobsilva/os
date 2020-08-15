#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

typedef struct p { 
    int topo; 
    unsigned capacidade; 
    char **str; 
} Pilha; 

void iniciarPilha(unsigned capacidade, Pilha *pilha) {
    pilha->capacidade = capacidade; 
    pilha->topo = -1;
    char lista[capacidade][50];
    pilha->str = lista;
}

void push(Pilha *pilha, char *item) {
    pilha->str[++pilha->topo] = item; 
    printf("%s foi inserido na pilha\n", item);
} 

char* pop(Pilha *pilha) {
    return pilha->str[pilha->topo--]; 
} 

int main(void) {
  Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
  iniciarPilha(100, pilha);

  printf("Digite o(s) nome(s):\n");

  while(1) {
    char *input = malloc(50*sizeof(char));
    scanf("%s", input);

    if(strcmp(input, "fim") == 0) {
      break;
    } else {
      push(pilha, input);
    }
  }

  printf("\n\nNome(s) digitado(s):\n"); 
  while(pilha->topo >= 0) {
    printf("%s\n", pop(pilha)); 
  }

  return 0;
}
