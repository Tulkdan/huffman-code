#ifndef HEADER
#define HEADER

struct Node {
  char letra;
  int qtd;
  struct Node* next;
};

typedef struct Node* node;

node create_node(char letra);
void insert_into_list(node* dict, char letra);
void mostrar(node dict);
FILE* abrir_arquivo(char *arquivo);

#endif