#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

#define SIZE_DICT sizeof(struct Dictionary)

DICT create_node_dict(char letra, char repr[]) {
  DICT aux = (DICT) malloc(SIZE_DICT);
  aux->letra = letra;
  strcpy(aux->repr, repr);
  aux->next = aux->rear = NULL;
  return aux;
}

void insert_into_dictionary(DICT* dict, DICT new) {
  if (*dict == NULL) {
    *dict = new;
    return;
  }
  new->next = *dict;
  (*dict)->rear = new;
  *dict = new;
}

void show_dictionary(DICT dict) {
  while(dict != NULL) {
    printf("%c - %s\n", dict->letra, dict->repr);
    dict = dict->next;
  }
}

void write_in_file(DICT dict) {
  FILE *file = NULL;
  file = fopen("teste.bin", "wb");
  while(dict != NULL) {
    fwrite(dict, SIZE_DICT, 1, file);
    dict = dict->next;
  }
  fwrite(";", sizeof(char), 1, file);
  fclose(file);
  printf("Arquivo binário gravado\n");
}

void read_bin_file() {
  printf("Lendo o arquivo binário...\n");
  char ch;
  DICT inicio = (DICT) malloc(SIZE_DICT);
  FILE *file = fopen("teste.bin", "rb");
  if (file == NULL) {
    printf("File does not exist");
    return;
  }
  inicio = read_dict_from_file(file);
  fclose(file);
}

DICT read_dict_from_file (FILE* file) {
  printf("Lendo dicionário...\n");
  DICT inicio = NULL;
  while (!feof(file)) {
    DICT dict = (DICT) malloc(SIZE_DICT);
    dict->next = NULL;
    dict->rear = NULL;
    fread(dict, SIZE_DICT, 1, file);

    if (dict->letra == ';') break;
    // printf("%c - %s\n", dict->letra, dict->repr);

    if (inicio == NULL) {
      inicio = dict;
    } else {
      dict->next = inicio;
      inicio->rear = dict;
      inicio = dict;
    }
  }
  show_dictionary(inicio);
  return inicio;
}