#ifndef HEADER
#define HEADER

struct Leaf {
  char letra;
  int qtd;
  struct Leaf* next;
};

struct Tree {
  int soma;
  struct Tree* right, struct Tree* left;
}

typedef struct Leaf* node;
typedef struct Tree* tree;

node create_node(char letra);
void insert_into_list(node* dict, char letra);
void mostrar(node dict);
FILE* abrir_arquivo(char *arquivo);

#endif