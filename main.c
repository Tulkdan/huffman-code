#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Digite o nome do arquivo!");
    exit(1);
  }
  node tree = NULL;
  DICT dict = NULL;
  char ch, repr[10];
  FILE *file;
  file = abrir_arquivo(argv[1]);
  
  while((ch = fgetc(file)) != EOF) {
    insert_into_list(&tree, ch);
  }
  mostrar(tree);

  create_tree(&tree);

  printf("Arvore criada\n");

  show_tree(tree, repr, &dict);

  printf("Dicionário criado\n");

  // show_dictionary(dict);

  write_in_file(dict);
  read_bin_file();

  fclose(file);

  return 0;
}
