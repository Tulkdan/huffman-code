#include <stdio.h>
#include <stdlib.h>
#include "head.h"

FILE* abrir_arquivo(char *arquivo) {
  FILE* file = fopen(arquivo, "r");
  if (file == NULL) {
    printf("Erro ao abrir o arquivo");
    return NULL;
  }
  return file;
}

node create_node(char letra) {
  node aux = (node) malloc(sizeof(struct Leaf));
  aux->letra = letra;
  printf("%d", letra);
  aux->qtd = 1;
  aux->next = NULL;
  printf("Nó criado de %c\n", letra);
  return aux;
}

void insert_into_list(node* dict, char letra) {
  node aux = *dict;
  while(aux != NULL) {
    if (aux->letra == letra) {
      aux->qtd++;
      // printf("Letra %c incrementada\n", letra);
      return;
    }
    aux = aux->next;
  }
  aux = create_node(letra);
  aux->next = *dict;
  *dict = aux;
}

void mostrar(node dict) {
  if (dict != NULL) {
    mostrar(dict->next);
    printf("%c-", dict->letra);
    printf("%d\n", dict->qtd);
  }
}