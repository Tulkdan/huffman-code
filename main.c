#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Digite o nome do arquivo!");
    exit(1);
  }
  node dict = NULL;
  char ch, repr[10];
  FILE *file;

  file = abrir_arquivo(argv[1]);
  
  while((ch = fgetc(file)) != EOF) {
    insert_into_list(&dict, ch);
  }
  mostrar(dict);

  create_tree(&dict);

  show_tree(dict, repr);

  printf("Arvore criada\n");

  fclose(file);

  return 0;
}
