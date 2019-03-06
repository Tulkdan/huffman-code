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
  fclose(file);
  mostrar(tree);

  create_tree(&tree);

  printf("Arvore criada\n");

  show_tree(tree, repr, &dict);

  printf("Dicionário criado\n");

  // show_dictionary(dict);

  file = abrir_arquivo(argv[1]);
  write_in_file(dict, file);
  fclose(file);
  read_bin_file();


  return 0;
}
