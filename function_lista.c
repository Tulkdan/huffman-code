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
  aux->qtd = 1;
  aux->next = NULL;
  aux->rear = NULL;
  printf("Nó criado de %c\n", letra);
  return aux;
}

void insert_into_list(node* dict, char letra) {
  node aux = *dict;
  while(aux != NULL) {
    if (aux->letra == letra) {
      aux->qtd++;
      return;
    }
    aux = aux->next;
  }
  aux = create_node(letra);
  aux->next = *dict;
  if (*dict != NULL)
    (*dict)->rear = aux;
  *dict = aux;
}

void mostrar(node dict) {
  if (dict != NULL) {
    mostrar(dict->next);
    printf("%c-", dict->letra);
    printf("%d\n", dict->qtd);
  }
}

int count_elements(node dict) {
  int i = 0;
  while(dict != NULL) {
    i++;
    dict = dict->next;
  }
  return i;
}

node min_in_dict(node* dict) {
  node aux = *dict;
  node min = aux;
  while(aux != NULL && aux->next != NULL) {
    if (aux->qtd < min->qtd) {
      min = aux;
    }
    aux = aux->next;
  }
  if (min->rear == NULL) {
    *dict = min->next;
    if (*dict != NULL)
      (*dict)->rear = NULL;
  } else {
    min->rear->next = min->next;
    min->next->rear = min->rear;
  }
  min->next = NULL;
  min->rear = NULL;
  printf("Minimo eh %c - %d\n", min->letra, min->qtd);
  return min;
}

void insert_final(node* dict, node new) {
  if (count_elements(*dict) == 0) {
    *dict = new;
    return;
  }

  node inicio = *dict;
  while(inicio != NULL && inicio->next != NULL)
    inicio = inicio->next;

  if (inicio == NULL) {
    *dict = new;
    (*dict)->rear = NULL;
    (*dict)->next = NULL;
  } else {
    inicio->next = new;
    new->rear = inicio;
    new->next = NULL;
  }
}